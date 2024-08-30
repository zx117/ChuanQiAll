
#pragma once
#include <coretypes/boolean.h>
#include <coretypes/ordinalobject_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <>
inline ErrCode OrdinalObjectImpl<Bool, IBoolean>::toBool(Bool* val)
{
    if (val == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (value != 0)
        *val = True;
    else
        *val = False;

    return CQDAQ_SUCCESS;
}

template <>
inline ErrCode OrdinalObjectImpl<Bool, IBoolean>::getHashCode(SizeT* hashCode)
{
    if (hashCode == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (value)
        *hashCode = 1;
    else
        *hashCode = 0;

    return CQDAQ_SUCCESS;
}

template <>
inline ErrCode OrdinalObjectImpl<Bool, IBoolean>::serialize(ISerializer* serializer)
{
    if (serializer == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    serializer->writeBool(value);

    return CQDAQ_SUCCESS;
}

using BooleanImpl = OrdinalObjectImpl<Bool, IBoolean>;

END_NAMESPACE_CQDAQ
