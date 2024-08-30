#include "fw_custom_request_handler.h"

#define EXTENSION_FUNCTIONS
#include "fw_property_list_utils.h"
#include "base_if_host.h"

namespace cq
{
namespace framework
{

    std::uint64_t CustomRequestHandler::pluginMessage(cq::PluginMessageId id, std::uint64_t key, const cq::IfValue* param, const cq::IfValue** ret)
    {
        if (id == cq::plugin_msg::CUSTOM_QML_REQUEST)
        {
            std::uint64_t ret_code = std::numeric_limits<uint64_t>::max();
            //limit to range that is safe for qml and reserve other uses
            if (key > 0 && key <= std::numeric_limits<std::int32_t>::max())
            {
                auto lid = static_cast<std::uint16_t>(key);
                auto it = m_functions.find(lid);
                if (it != m_functions.end())
                {
                    ret_code = it->second(m_host, param, ret);
                }
            }
            return ret_code;
        }
        return std::numeric_limits<uint64_t>::max();
    }

    void CustomRequestHandler::setHost(cq::IfHost* host)
    {
        m_host = host;
    }

    void CustomRequestHandler::registerFunction(std::uint16_t id, const char* name, std::function<PropertyListFunction> func)
    {
        auto f =
            [func](cq::IfHost* host, const cq::IfValue* param, const cq::IfValue** ret) -> std::uint64_t
            {
            try {
                cq::PropertyList param_list;
                if (param)
                {
                    if (!cq::framework::utils::convertToPropertyList(param, param_list))
                    {
                        return cq::error_codes::INVALID_INPUT_PARAMETER;
                    }
                }
                cq::PropertyList ret_list;
                auto ret_code = func(param_list, ret_list);
                if (!ret_list.empty())
                {
                    *ret = cq::framework::utils::convertToXMLValue(host, ret_list);
                }
                return ret_code;
            }
            catch (const std::exception&)
            {
                return cq::error_codes::UNHANDLED_EXCEPTION;
            }
            catch (...)
            {
                return cq::error_codes::UNHANDLED_EXCEPTION;
            }
            };
        registerFunction(id, name, f);
    }

    void CustomRequestHandler::registerFunction(std::uint16_t id, const char* name, std::function<PropertyListToXMLFunction> func)
    {
        auto f =
            [func](cq::IfHost* host, const cq::IfValue* param, const cq::IfValue** ret) -> std::uint64_t
            {
            try {
                cq::PropertyList param_list;
                if (param)
                {
                    if (!cq::framework::utils::convertToPropertyList(param, param_list))
                    {
                        return cq::error_codes::INVALID_INPUT_PARAMETER;
                    }
                }
                auto xml = host->createValue<cq::IfXMLValue>();
                auto ret_code = func(param_list, *xml);
                if (xml->getLength() > 0)
                {
                    *ret = xml.detach();
                }
                return ret_code;
            }
            catch (const std::exception&)
            {
                return cq::error_codes::UNHANDLED_EXCEPTION;
            }
            catch (...)
            {
                return cq::error_codes::UNHANDLED_EXCEPTION;
            }
            };
        registerFunction(id, name, f);
    }

    void CustomRequestHandler::registerFunction(std::uint16_t id, const char* name, std::function<GenericHandlerFunction> func)
    {
        CQ_UNUSED(name);
        m_functions[id] = func;
    }

}
}
