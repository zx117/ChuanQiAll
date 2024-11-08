
#pragma once

BEGIN_NAMESPACE_CQDAQ

enum class ChannelType : EnumType
{
    CH_SYNC = 0,
    CH_ASYNC,
    CH_SINGLE_VALUE,
    CH_NEVER,
    CH_INVALID,
};

enum class SampleValueType : EnumType
{
    SV_INVALID = 0,
    SV_SCALAR,
    SV_CAN_MESSAGE,
    SV_VECTOR,
    SV_COMPLEX_VECTOR,
    SV_VIDEO,
    SV_STRING,
    SV_FLEXRAY_MESSAGE,
    SV_BYTE_VECTOR,
};

END_NAMESPACE_CQDAQ