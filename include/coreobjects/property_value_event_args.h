#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/event_args.h>
#include <coreobjects/property.h>

BEGIN_NAMESPACE_CQDAQ

enum class PropertyEventType : EnumType
{
    Update,
    Clear,
    Read
};

/*#
 * [interfaceSmartPtr(IEventArgs, EventArgsPtr, "<coretypes/event_args_ptr.h>")]
 */
DECLARE_CQDAQ_INTERFACE(IPropertyValueEventArgs, IEventArgs)
{
    virtual ErrCode INTERFACE_FUNC getProperty(IProperty** property) = 0;
    virtual ErrCode INTERFACE_FUNC getValue(IBaseObject** value) = 0;
    virtual ErrCode INTERFACE_FUNC setValue(IBaseObject* value) = 0;
    virtual ErrCode INTERFACE_FUNC getPropertyEventType(PropertyEventType* changeType) = 0;
    virtual ErrCode INTERFACE_FUNC getIsUpdating(Bool* isUpdating) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, PropertyValueEventArgs,
    IProperty*, prop,
    IBaseObject*, value,
    PropertyEventType, type,
    Bool,
    isUpdating
)

END_NAMESPACE_CQDAQ
