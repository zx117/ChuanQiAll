
#pragma once
#include <coretypes/binarydata_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline BinaryDataPtr BinaryData(const SizeT size)
{
    BinaryDataPtr obj(BinaryData_Create(size));
    return obj;
}

inline BinaryDataPtr BinaryData(char* data, const SizeT size)
{
    BinaryDataPtr obj(BinaryData_Create(size));
    if (data != nullptr)
        memcpy(obj.getAddress(), data, size);
    return obj;
}

END_NAMESPACE_CQDAQ
