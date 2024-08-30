
#pragma once
#include <coretypes/intfs.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TPtr, typename... TArgs>
class ObjectDecorator : public ImplementationOf<TArgs...>
{
public:
    using Super = ImplementationOf<TArgs...>;

    explicit ObjectDecorator(const TPtr& object)
        : object(object)
    {
    }

    explicit ObjectDecorator(TPtr&& object)
        : object(std::move(object))
    {
    }

    virtual daq::ErrCode INTERFACE_FUNC dispose() override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        return this->object->dispose();
    }

    virtual daq::ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        return this->object->getHashCode(hashCode);
    }

    virtual daq::ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        return this->object->equals(other, equals);
    }

    virtual daq::ErrCode INTERFACE_FUNC toString(CharPtr* str) override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        return this->object->toString(str);
    }

    virtual daq::ErrCode INTERFACE_FUNC queryInterface(const IntfID& id, void** intf) override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        if (!intf)
            return CQDAQ_ERR_ARGUMENT_NULL;

        auto errCode = Super::queryInterface(id, intf);
        if (errCode == CQDAQ_ERR_NOINTERFACE)
            return this->object->queryInterface(id, intf);

        return errCode;
    }

    virtual daq::ErrCode INTERFACE_FUNC borrowInterface(const IntfID& id, void** intf) const override
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        if (!intf)
            return CQDAQ_ERR_ARGUMENT_NULL;

        auto errCode = Super::borrowInterface(id, intf);
        if (errCode == CQDAQ_ERR_NOINTERFACE)
            return this->object->borrowInterface(id, intf);

        return errCode;
    }

protected:
    TPtr object;
};

END_NAMESPACE_CQDAQ
