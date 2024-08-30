
#pragma once
#include <coretypes/integer.h>
#include <coretypes/baseobject_impl.h>
#include <coretypes/convertible.h>
#include <coretypes/comparable.h>
#include <coretypes/coretype.h>
#include <coretypes/coretype_traits.h>
#include <coretypes/serializable.h>

BEGIN_NAMESPACE_CQDAQ

template <class V, class Intf, class ... Intfs>
class OrdinalObjectImpl : public ImplementationOf<Intf, IConvertible, ICoreType, IComparable, ISerializable, Intfs...>
{
public:
    OrdinalObjectImpl(V value);

    // IBaseObject
    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // Intf
    ErrCode INTERFACE_FUNC getValue(V* val) override;
    ErrCode INTERFACE_FUNC equalsValue(V val, Bool* equals) override;

    // IConvertible
    ErrCode INTERFACE_FUNC toFloat(Float* val) override;
    ErrCode INTERFACE_FUNC toInt(Int* val) override;
    ErrCode INTERFACE_FUNC toBool(Bool* val) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IComparable
    ErrCode INTERFACE_FUNC compareTo(IBaseObject* obj) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;

    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* /*id*/) const override
    {
        return CQDAQ_ERR_NOTIMPLEMENTED;
    }

protected:
    V value;
};

template <class V, class Intf, class ... Intfs>
OrdinalObjectImpl<V, Intf, Intfs ...>::OrdinalObjectImpl(const V value)
    : value(value)
{
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::equals(IBaseObject* other, Bool* equal) const
{
    if (equal == nullptr)
    {
        return daq::makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equal output parameter must not be null.", nullptr);
    }

    *equal = false;

    Intf* otherObj;
    if (CQDAQ_SUCCEEDED(other->borrowInterface(Intf::Id, reinterpret_cast<void**>(&otherObj))))
    {
        V otherValue;
        ErrCode err = otherObj->getValue(&otherValue);

        if (CQDAQ_FAILED(err))
        {
            return CQDAQ_SUCCESS;
        }

        *equal = otherValue == this->value;
    }
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::getValue(V* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *val = value;
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::equalsValue(const V val, Bool* equals)
{
    if (equals == nullptr)
        return this->makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equals parameter must not be null.");

    *equals = value == val;
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::getHashCode(SizeT* hashCode)
{
    if (hashCode == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

#if UINTPTR_MAX == UINT64_MAX
    *hashCode = static_cast<SizeT>(value);
#else
    *hashCode = static_cast<SizeT>(static_cast<uint64_t>(value) | ((static_cast<uint64_t>(value)) >> 32));
#endif
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::toString(CharPtr* str)
{
    if (str == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    std::ostringstream os;
    CoreTypeHelper<V>::Print(os, value);

    return daqDuplicateCharPtr(os.str().c_str(), str);
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::toFloat(Float* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *val = static_cast<Float>(value);
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::toInt(Int* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *val = static_cast<Int>(value);
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::toBool(Bool* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (value)
        *val = True;
    else
        *val = False;

    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::getCoreType(CoreType* coreType)
{
    if (coreType == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *coreType = CoreTypeHelper<V>::GetCoreType();
    return CQDAQ_SUCCESS;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::compareTo(IBaseObject* obj)
{
    if (obj == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    V otherValue;

    Intf* typeObj;
    ErrCode err = obj->borrowInterface(Intf::Id, reinterpret_cast<void**>(&typeObj));
    if (CQDAQ_FAILED(err))
    {
        IConvertible* convObj;
        err = obj->borrowInterface(IConvertible::Id, reinterpret_cast<void**>(&convObj));
        if (CQDAQ_FAILED(err))
            return err;

        err = CoreTypeHelper<V>::FromConvertible(otherValue, convObj);
        if (CQDAQ_FAILED(err))
            return err;
    }
    else
    {
        err = typeObj->getValue(&otherValue);
        if (CQDAQ_FAILED(err))
            return err;
    }

    if (value > otherValue)
        return  CQDAQ_GREATER;
    else if (value < otherValue)
        return  CQDAQ_LOWER;
    else
        return  CQDAQ_EQUAL;
}

template <class V, class Intf, class ... Intfs>
ErrCode OrdinalObjectImpl<V, Intf, Intfs ...>::serialize(ISerializer* serializer)
{
    return CQDAQ_ERR_NOTIMPLEMENTED;
}

END_NAMESPACE_CQDAQ
