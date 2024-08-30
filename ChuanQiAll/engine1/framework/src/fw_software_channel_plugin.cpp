
#include "fw_software_channel_plugin.h"

#include "fw_version_check.h"

namespace cq
{
namespace framework
{
    static const char* REQUIRED_CHUANQI_VERSION = "1.0";

    SoftwareChannelPluginBase::SoftwareChannelPluginBase()
        : m_plugin_channels(std::make_shared<cq::framework::PluginChannels>())
        , m_custom_requests(std::make_shared<cq::framework::CustomRequestHandler>())
    {
        addMessageHandler(m_plugin_channels);
        addMessageHandler(m_custom_requests);
    }

    std::uint64_t SoftwareChannelPluginBase::init(std::string& error_message)
    {
        if (!checkChuanQiCompatibility())
        {
            error_message = "Current version of ChuanQi is not supported.";
            return cq::error_codes::UNSUPPORTED_VERSION;
        }

        registerResources();
        registerSoftwareChannel();
        return cq::error_codes::OK;
    }

    bool SoftwareChannelPluginBase::deinit()
    {
        getPluginChannels()->pauseTasks();
        unregisterSoftwareChannel();
        return true;
    }

    void SoftwareChannelPluginBase::registerSoftwareChannel()
    {
        const auto telegram = getSoftwareChannelInfo();
        auto xml_msg = getHost()->template createValue<cq::IfXMLValue>();
        xml_msg->set(telegram.generate().c_str());
        getHost()->messageSync(cq::host_msg::SOFTWARE_CHANNEL_REGISTER, 0, xml_msg.get(), nullptr);
    }

    void SoftwareChannelPluginBase::updateSoftwareChannel()
    {
        const auto telegram = getSoftwareChannelInfo();
        auto xml_msg = getHost()->template createValue<cq::IfXMLValue>();
        xml_msg->set(telegram.generate().c_str());
        getHost()->messageSync(cq::host_msg::SOFTWARE_CHANNEL_UPDATE, 0, xml_msg.get(), nullptr);
    }

    void SoftwareChannelPluginBase::unregisterSoftwareChannel()
    {
        auto channel_id = getHost()->template createValue<cq::IfStringValue>();
        const auto telegram = getSoftwareChannelInfo();
        channel_id->set(telegram.m_service_name.c_str());
        getHost()->messageSync(cq::host_msg::SOFTWARE_CHANNEL_UNREGISTER, 0, channel_id.get(), nullptr);
    }

    bool SoftwareChannelPluginBase::checkChuanQiCompatibility()
    {
        auto name = getHost()->getValue<cq::IfStringValue>(cq::queries::PluginHost, cq::queries::PluginHost_Name);
        auto version = getHost()->getValue<cq::IfStringValue>(cq::queries::PluginHost, cq::queries::PluginHost_VersionString);
        if (name && version)
        {
            if (std::string("ChuanQi") == name->getValue())
            {
                if (compareVersionStrings(REQUIRED_CHUANQI_VERSION, version->getValue()) <= 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    PluginChannelsPtr SoftwareChannelPluginBase::getPluginChannels()
    {
        return m_plugin_channels;
    }

    std::shared_ptr<CustomRequestHandler> SoftwareChannelPluginBase::getCustomRequestHandler()
    {
        return m_custom_requests;
    }

}
}

