#include "fw_property_list_utils.h"

#define EXTENSION_FUNCTIONS
#include "base_api_object_ptr.h"
#include "base_basic_values.h"
#include "uni_xpugixml.h"
#include "base_if_host.h"

namespace cq
{
namespace framework
{
namespace utils
{

    bool convertToPropertyList(const cq::IfValue* param, cq::PropertyList& properties)
    {
        if (param->getType() == cq::IfValue::Type::TYPE_XML)
        {
            auto param_xml = static_cast<const cq::IfXMLValue*>(param);

            pugi::xml_document doc;
            auto status = doc.load_string(param_xml->getValue());
            if (status.status != pugi::status_ok)
            {
                return false;
            }

            auto node = doc.document_element();
            if (!node)
            {
                return false;
            }

            if (!cq::strequal(node.name(), "PropertyList"))
            {
                return false;
            }

            if (!properties.readFrom(node, {}))
            {
                return false;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    cq::IfValue* convertToXMLValue(cq::IfHost* host, const cq::PropertyList& properties)
    {
        auto ret_xml = host->createValue<cq::IfXMLValue>();
        pugi::xml_document ret_doc;
        auto root = ret_doc.append_child("PropertyList");
        properties.appendTo(root);
        ret_xml->set(xpugi::toXML(ret_doc).c_str());
        return ret_xml.detach();
    }

}
}
}

