
#pragma once
#include <coretypes/integer.h>
#include <coretypes/number_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <>
inline ErrCode OrdinalObjectImpl<Int, IInteger, INumber>::serialize(ISerializer* serializer)
{
    if (serializer == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    serializer->writeInt(value);

    return CQDAQ_SUCCESS;
}

using IntegerImpl = NumberImpl<Int, IInteger>;

END_NAMESPACE_CQDAQ
