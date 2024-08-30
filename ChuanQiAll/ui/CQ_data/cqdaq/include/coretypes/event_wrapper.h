
#pragma once
#include <coretypes/delegate.hpp>
#include <coretypes/common.h>
#include <coretypes/event_ptr.h>
#include <coretypes/event_handler_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TSender, typename TEventArgs>
class Event
{
public:
    using Subscription = delegate<void(TSender&, TEventArgs&)>;
    using HandlerPtr = EventHandlerPtr<TSender, TEventArgs>;
    using EventHandlerImplType = EventHandlerImpl<TSender, TEventArgs>;

    Event(EventPtr<TSender, TEventArgs> ptr)
        : eventPtr(std::move(ptr))
    {
    }

    void operator+=(Subscription&& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized control.");
        }

        HandlerPtr handler;
        ErrCode err = createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        checkErrorInfo(err);

        eventPtr.addHandler(handler);
    }

    void operator+=(const Subscription& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        HandlerPtr handler;
        ErrCode err = createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        checkErrorInfo(err);

        eventPtr.addHandler(handler);
    }

    Event& operator =(std::nullptr_t)
    {
        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        eventPtr.clear();
        return *this;
    }

    void operator-=(const Subscription& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        HandlerPtr handler;
        createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        eventPtr.removeHandler(handler);
    }

    void operator-=(Subscription&& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized control.");
        }

        HandlerPtr handler;
        ErrCode err = createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        checkErrorInfo(err);

        eventPtr.removeHandler(handler);
    }

    SizeT getListenerCount()
    {
        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        return eventPtr.getListenerCount();
    }

    void mute() const
    {
        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        eventPtr.mute();
    }

    void unmute() const
    {
        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        eventPtr.unmute();
    }

    Event& operator|=(Subscription&& sub)
    {
        muteListener(std::forward<decltype(sub)>(sub));
        return *this;
    }

    void muteListener(Subscription&& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        HandlerPtr handler;
        ErrCode err = createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        checkErrorInfo(err);

        eventPtr->muteListener(handler);
    }

    Event& operator&=(Subscription&& sub)
    {
        unmuteListener(std::forward<decltype(sub)>(sub));
        return *this;
    }

    void unmuteListener(Subscription&& sub)
    {
        if (!sub)
        {
            throw InvalidParameterException("Must bind to a valid callable.");
        }

        if (!eventPtr.assigned())
        {
            throw InvalidParameterException("Invalid or uninitialized event.");
        }

        HandlerPtr handler;
        ErrCode err = createObjectForwarding<IEventHandler, EventHandlerImplType>(&handler, sub);
        checkErrorInfo(err);

        eventPtr->unmuteListener(handler);
    }

    explicit operator bool() const
    {
        return eventPtr.assigned();
    }

    operator IEvent*() const
    {
        return eventPtr;
    }

private:
    friend EventEmitter<TSender, TEventArgs>;

    EventPtr<TSender, TEventArgs> eventPtr;
};

END_NAMESPACE_CQDAQ
