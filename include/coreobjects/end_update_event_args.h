#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/event_args.h>
#include <coreobjects/property.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IEventArgs, EventArgsPtr, "<coretypes/event_args_ptr.h>")]
 */
DECLARE_CQDAQ_INTERFACE(IEndUpdateEventArgs, IEventArgs)
{
    // [elementType(properties, IString)]
    virtual ErrCode INTERFACE_FUNC getProperties(IList** properties) = 0;
    virtual ErrCode INTERFACE_FUNC getIsParentUpdating(Bool* isParentUpdating) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, EndUpdateEventArgs,
    IList*, properties,
    Bool, isParentUpdating
)

END_NAMESPACE_CQDAQ
