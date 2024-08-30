
#pragma once
#include <coretypes/event.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TSender, typename TEventArgs>
class EventPtr;

template <typename TSender, typename TEventArgs>
EventPtr<TSender, TEventArgs> EventObject()
{
    return EventPtr<TSender, TEventArgs>(Event_Create());
}

END_NAMESPACE_CQDAQ
