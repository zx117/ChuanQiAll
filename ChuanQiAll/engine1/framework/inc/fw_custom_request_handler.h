#pragma once

#include "fw_if_message_handler.h"
#include "api_property_list_xml.h"
#include "base_basic_values.h"

#include <map>

namespace cq
{
namespace framework
{

    class CustomRequestHandler : public IfMessageHandler
    {
    public:

        //custom request the uses property lists as input and output
        using PropertyListFunction = std::uint64_t(const cq::PropertyList& params, cq::PropertyList& returns);
        
        //custom request the uses a property list as input and return an XML document
        using PropertyListToXMLFunction = std::uint64_t(const cq::PropertyList& params, cq::IfXMLValue& return_xml);

        using GenericHandlerFunction = std::uint64_t(cq::IfHost* host, const cq::IfValue* param, const cq::IfValue** ret);

        void registerFunction(std::uint16_t id, const char* name, std::function<PropertyListFunction> func);
        void registerFunction(std::uint16_t id, const char* name, std::function<PropertyListToXMLFunction> func);
        void registerFunction(std::uint16_t id, const char* name, std::function<GenericHandlerFunction> func);

    private:
        std::uint64_t pluginMessage(
            cq::PluginMessageId id,
            std::uint64_t key,
            const cq::IfValue* param,
            const cq::IfValue** ret) final;

        void setHost(cq::IfHost* host) final;

        cq::IfHost* m_host = nullptr;
        std::map<std::uint16_t, std::function<GenericHandlerFunction>> m_functions;
    };

}
}
