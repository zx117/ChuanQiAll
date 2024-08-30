
#pragma once
#include <cqdaq/component_holder_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ComponentHolderPtr ComponentHolder(const StringPtr& id, const StringPtr& parentGlobalId, const ComponentPtr& component)
{
    ComponentHolderPtr obj(ComponentHolderWithIds_Create(id, parentGlobalId, component));
    return obj;
}

inline ComponentHolderPtr ComponentHolder(const ComponentPtr& component)
{
    ComponentHolderPtr obj(ComponentHolder_Create(component));
    return obj;
}

END_NAMESPACE_CQDAQ
