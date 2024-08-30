
#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/event_handler.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_event_handler
 * @{
 */

template <typename TSender = IBaseObject, typename TEventArgs = IEventArgs>
class EventHandlerPtr;

using EventHandler = EventHandlerPtr<>;

template <>
struct InterfaceToSmartPtr<IEventHandler>
{
    typedef EventHandlerPtr<> SmartPtr;
};

template <typename TSender, typename TEventArgs>
class EventHandlerPtr : public ObjectPtr<IEventHandler>
{
public:
    using SenderPtr = typename InterfaceToSmartPtr<TSender>::SmartPtr;
    using EventArgsPtr = typename InterfaceToSmartPtr<TEventArgs>::SmartPtr;

    using ObjectPtr<IEventHandler>::ObjectPtr;

    EventHandlerPtr()
        : ObjectPtr<IEventHandler>()
    {
    }

    EventHandlerPtr(ObjectPtr<IEventHandler>&& ptr)
        : ObjectPtr<IEventHandler>(ptr)
    {
    }

    EventHandlerPtr(const ObjectPtr<IEventHandler>& ptr)
        : ObjectPtr<IEventHandler>(ptr)
    {
    }

    EventHandlerPtr(const EventHandlerPtr& other)
        : ObjectPtr<IEventHandler>(other)
    {
    }

    EventHandlerPtr(EventHandlerPtr&& other) noexcept
        : ObjectPtr<IEventHandler>(std::move(other))
    {
    }

    EventHandlerPtr& operator=(const EventHandlerPtr& other)
    {
        if (this == &other)
            return *this;

        ObjectPtr<IEventHandler>::operator =(other);
        return *this;
    }

    EventHandlerPtr& operator=(EventHandlerPtr&& other) noexcept
    {
        if (this == std::addressof(other))
            return *this;
        ObjectPtr<IEventHandler>::operator =(std::move(other));
        return *this;
    }

    void handleEvent(const SenderPtr& sender, const EventArgsPtr& eventArgs) const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        auto errCode = this->object->handleEvent(sender, eventArgs);
        checkErrorInfo(errCode);
    }
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
