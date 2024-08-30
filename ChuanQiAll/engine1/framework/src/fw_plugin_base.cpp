#include "fw_plugin_base.h"

#include "api_utils.h"
#include "base_basic_values.h"
#include "base_if_host.h"
#include "base_message_return_value_holder.h"

std::uint64_t PLUGIN_API cq::framework::PluginBase::pluginMessage(cq::PluginMessageId id, std::uint64_t key, const cq::IfValue* param, const cq::IfValue** ret)
{
    std::uint64_t ret_code = 0;
    if (handleMessage(id, key, param, ret, ret_code))
    {
        return ret_code;
    }

    for (auto& handler : m_message_handlers)
    {
        ret_code = handler->pluginMessage(id, key, param, ret);
        if (ret_code != cq::error_codes::NOT_IMPLEMENTED)
        {
            return ret_code;
        }
    }

    switch (id)
    {
        case cq::plugin_msg::INIT:
        {
            std::string error_message;
            auto error_code = init(error_message);
            if (error_code != cq::error_codes::OK && ret && m_host && error_message.empty())
            {
                auto err_val = m_host->createValue<cq::IfErrorValue>();
                if (err_val)
                {
                    err_val->set(error_code, error_message.c_str());
                    *ret = err_val.detach();
                }
            }
            return error_code;
        }
        case cq::plugin_msg::DEINIT:
            return deinit() ? cq::error_codes::OK : cq::error_codes::INTERNAL_ERROR;
    }
    return std::numeric_limits<uint64_t>::max();
}

bool cq::framework::PluginBase::addTranslation(const char* translation_xml)
{
    cq::MessageReturnValueHolder<cq::IfErrorValue> ret_error;
    if (sendSyncXMLMessage(getHost(), cq::host_msg::ADD_TRANSLATION, 0, translation_xml, strlen(translation_xml) + 1, ret_error.data()))
    {
        if (ret_error)
        {
            auto error_message = ret_error->getDescription();
            CQ_UNUSED(error_message);
        }
        return false;
    }
    return true;
}

bool cq::framework::PluginBase::addQtResources(const void* rcc_data, std::uint64_t rcc_size)
{
    cq::MessageReturnValueHolder<cq::IfErrorValue> ret_error;

    if (getHost()->messageSyncData(cq::host_msg::ADD_RESOURCES, 0, rcc_data, rcc_size) != cq::error_codes::OK)
    {
        if (ret_error)
        {
            auto error_message = ret_error->getDescription();
            CQ_UNUSED(error_message);
        }
        return false;
    }
    return true;
}
