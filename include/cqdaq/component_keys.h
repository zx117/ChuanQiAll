
#pragma once
#include <coreobjects/object_keys.h>
#include <cqdaq/component_ptr.h>

BEGIN_NAMESPACE_CQDAQ

struct ComponentHash
{
    size_t operator()(const ComponentPtr& component) const
    {
        return std::hash<StringPtr>().operator()(component.getGlobalId());
    }
};

struct ComponentEqualTo
{
    bool operator()(const ComponentPtr& a, const ComponentPtr& b) const
    {
        return std::equal_to<StringPtr>().operator()(a.getGlobalId(), b.getGlobalId());
    };
};

END_NAMESPACE_CQDAQ

namespace std
{
    template <>
    struct hash<daq::ComponentPtr> : daq::ComponentHash
    {
    };

    template <>
    struct equal_to<daq::ComponentPtr> : daq::ComponentEqualTo
    {
    };
}
