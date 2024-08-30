
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/event_args.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_events
 * @defgroup types_event_handler EventHandler
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IEventHandler, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC handleEvent(IBaseObject* sender, IEventArgs* eventArgs) = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
