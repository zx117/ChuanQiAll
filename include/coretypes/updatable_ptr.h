
#pragma once
#include <coretypes/updatable.h>
#include <coretypes/objectptr.h>
#include <coretypes/serialized_object_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class UpdatablePtr;

template <>
struct InterfaceToSmartPtr<IUpdatable>
{
    typedef UpdatablePtr SmartPtr;
};

/*!
 * @addtogroup types_updatable
 * @{
 */

class UpdatablePtr : public ObjectPtr<IUpdatable>
{
public:
    using daq::ObjectPtr<IUpdatable>::ObjectPtr;

    UpdatablePtr()
    {
    }

    UpdatablePtr(daq::ObjectPtr<IUpdatable>&& ptr)
        : daq::ObjectPtr<IUpdatable>(std::move(ptr))
    {
    }

    UpdatablePtr(const daq::ObjectPtr<IUpdatable>& ptr)
        : daq::ObjectPtr<IUpdatable>(ptr)
    {
    }

    UpdatablePtr(const UpdatablePtr& other)
        : daq::ObjectPtr<IUpdatable>(other)
    {
    }

    UpdatablePtr(UpdatablePtr&& other) noexcept
        : daq::ObjectPtr<IUpdatable>(std::move(other))
    {
    }

    UpdatablePtr& operator=(const UpdatablePtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IUpdatable>::operator=(other);
        return *this;
    }

    UpdatablePtr& operator=(UpdatablePtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }

        daq::ObjectPtr<IUpdatable>::operator=(std::move(other));
        return *this;
    }

    void update(const SerializedObjectPtr& update) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->update(update);
        daq::checkErrorInfo(errCode);
    }

    void serializeForUpdate(const ObjectPtr<ISerializer>& serializer) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->serializeForUpdate(serializer);
        daq::checkErrorInfo(errCode);
    }

    void updateEnded() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->updateEnded();
        daq::checkErrorInfo(errCode);
    }

};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
