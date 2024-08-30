
#pragma once
#include <coretypes/common.h>
#include <coretypes/json_deserializer.h>
#include <coretypes/deserializer_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline DeserializerPtr JsonDeserializer()
{
    return DeserializerPtr(JsonDeserializer_Create());
}

END_NAMESPACE_CQDAQ
