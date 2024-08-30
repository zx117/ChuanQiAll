
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [templated]
 */

/*!
 * @ingroup types_events
 * @defgroup types_event_args EventArgs
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IEventArgs, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC getEventId(Int* id) = 0;
    virtual ErrCode INTERFACE_FUNC getEventName(IString** name) = 0;
};

/*!
 * @}
 */

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, EventArgs, Int, eventId, IString*, eventName)

END_NAMESPACE_CQDAQ
