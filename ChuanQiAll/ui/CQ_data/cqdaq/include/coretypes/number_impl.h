
#pragma once
#include <coretypes/ordinalobject_impl.h>
#include <coretypes/number.h>

BEGIN_NAMESPACE_CQDAQ

template <class V, class Intf>
class NumberImpl : public OrdinalObjectImpl<V, Intf, INumber>
{
public:
    NumberImpl(V value);

    // INumber
    ErrCode INTERFACE_FUNC getFloatValue(Float* value) override;
    ErrCode INTERFACE_FUNC getIntValue(Int* value) override;
};

template<class V, class Intf>
inline NumberImpl<V, Intf>::NumberImpl(V value)
    : OrdinalObjectImpl<V, Intf, INumber>(value)
{
}

template<class V, class Intf>
inline ErrCode INTERFACE_FUNC NumberImpl<V, Intf>::getFloatValue(Float* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *val = static_cast<Float>(this->value);
    return CQDAQ_SUCCESS;
}

template<class V, class Intf>
inline ErrCode INTERFACE_FUNC NumberImpl<V, Intf>::getIntValue(Int* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *val = static_cast<Int>(this->value);
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
