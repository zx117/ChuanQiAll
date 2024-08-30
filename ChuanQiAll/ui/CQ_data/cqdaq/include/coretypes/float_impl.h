

#pragma once
#include <coretypes/float.h>
#include <coretypes/number_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <>
inline ErrCode OrdinalObjectImpl<Float, IFloat, INumber>::toBool(Bool* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (value != 0.0)
        *val = True;
    else
        *val = False;

    return CQDAQ_SUCCESS;
}

template <>
inline ErrCode OrdinalObjectImpl<Float, IFloat, INumber>::serialize(ISerializer* serializer)
{
    if (serializer == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    serializer->writeFloat(value);

    return CQDAQ_SUCCESS;
}

using FloatImpl = NumberImpl<Float, IFloat>;

END_NAMESPACE_CQDAQ
