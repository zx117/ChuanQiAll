
#pragma once
#include <cqdaq/component.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(IComponentHolder, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC getLocalId(IString** localId) = 0;
    virtual ErrCode INTERFACE_FUNC getParentGlobalId(IString** parentId) = 0;
    virtual ErrCode INTERFACE_FUNC getComponent(IComponent** component) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, ComponentHolder,
    IComponent*, component
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, ComponentHolderWithIds, IComponentHolder,
    IString*, id,
    IString*, parentGlobalId,
    IComponent*, component
)

END_NAMESPACE_CQDAQ
