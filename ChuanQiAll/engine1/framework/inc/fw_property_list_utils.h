#pragma once

#include "base_if_value.h"
#include "api_property_list_xml.h"

namespace cq
{
    class IfHost;

namespace framework
{
namespace utils
{

    bool convertToPropertyList(const cq::IfValue* param, cq::PropertyList& properties);

    cq::IfValue* convertToXMLValue(cq::IfHost* host, const cq::PropertyList& properties);
}
}
}

