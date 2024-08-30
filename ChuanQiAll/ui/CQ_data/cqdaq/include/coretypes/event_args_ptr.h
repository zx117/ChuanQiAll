
#pragma once
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/event_args.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_event_args
 * @{
 */

template <typename Interface = IEventArgs>
class EventArgsPtr;

template <>
struct InterfaceToSmartPtr<IEventArgs>
{
    typedef EventArgsPtr<IEventArgs> SmartPtr;
};

template <typename Interface>
class EventArgsPtr : public ObjectPtr<Interface>
{
public:
    using ObjectPtr<Interface>::ObjectPtr;

    EventArgsPtr()
        : ObjectPtr<Interface>()
    {
    }

    EventArgsPtr(ObjectPtr<Interface>&& ptr)
        : ObjectPtr<Interface>(std::move(ptr))

    {
    }

    EventArgsPtr(const ObjectPtr<Interface>& ptr)
        : ObjectPtr<Interface>(ptr)
    {
    }

    EventArgsPtr(const EventArgsPtr& other)
        : ObjectPtr<Interface>(other)
    {
    }

    EventArgsPtr(EventArgsPtr&& other) noexcept
        : ObjectPtr<Interface>(std::move(other))
    {
    }

    EventArgsPtr& operator=(const EventArgsPtr& other)
    {
        if (this == &other)
            return *this;

        ObjectPtr<Interface>::operator=(other);
        return *this;
    }

    EventArgsPtr& operator=(EventArgsPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }

        ObjectPtr<Interface>::operator=(std::move(other));
        return *this;
    }

    Int getEventId() const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        Int id;
        auto errCode = this->object->getEventId(&id);
        checkErrorInfo(errCode);

        return id;
    }

    StringPtr getEventName() const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        StringPtr name;
        auto errCode = this->object->getEventName(&name);
        checkErrorInfo(errCode);

        return name;
    }
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
