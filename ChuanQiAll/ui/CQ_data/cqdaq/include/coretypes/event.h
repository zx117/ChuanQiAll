
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/event_handler.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_events
 * @defgroup types_event Event
 * @{
 */

typedef std::size_t HandlerId;

DECLARE_CQDAQ_INTERFACE(IEvent, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC addHandler(IEventHandler* eventHandler) = 0;
    virtual ErrCode INTERFACE_FUNC removeHandler(IEventHandler* eventHandler) = 0;

    virtual ErrCode INTERFACE_FUNC trigger(IBaseObject* sender, IEventArgs* args) = 0;

    virtual ErrCode INTERFACE_FUNC clear() = 0;
    virtual ErrCode INTERFACE_FUNC getSubscriberCount(SizeT* count) = 0;

    virtual ErrCode INTERFACE_FUNC mute() = 0;
    virtual ErrCode INTERFACE_FUNC unmute() = 0;

    virtual ErrCode INTERFACE_FUNC muteListener(IEventHandler* eventHandler) = 0;
    virtual ErrCode INTERFACE_FUNC unmuteListener(IEventHandler* eventHandler) = 0;
};

/*!
 * @}
 */

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, Event)

END_NAMESPACE_CQDAQ
