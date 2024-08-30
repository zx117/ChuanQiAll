
#pragma once
#include <coretypes/common.h>
#include <coretypes/serializer.h>
#include <coretypes/json_serializer.h>
#include <coretypes/serializer_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline SerializerPtr JsonSerializer(Bool pretty = False)
{
    return SerializerPtr(JsonSerializer_Create(pretty));
}

END_NAMESPACE_CQDAQ
