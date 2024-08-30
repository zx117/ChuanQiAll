
#pragma once
#include <coretypes/event_factory.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TSender, typename TEventArgs>
class Event;

template <typename TSender, typename TEventArgs>
class EventEmitter : public EventPtr<TSender, TEventArgs>
{
public:
    using EventPtr<TSender, TEventArgs>::EventPtr;

    EventEmitter()
        : EventPtr<TSender, TEventArgs>(Event_Create())
    {
    }

    EventEmitter(Event<TSender, TEventArgs> ev) : EventPtr<TSender, TEventArgs>(ev.eventPtr)
    {
    }

    EventEmitter& operator=(IEvent* other)
    {
        EventPtr<TSender, TEventArgs>::operator =(other);
        return *this;
    }
};

END_NAMESPACE_CQDAQ
