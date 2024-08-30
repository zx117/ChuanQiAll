
#pragma once
#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

enum class SampleType : EnumType
{
    Invalid = 0,
    Undefined = 0,
    Float32,
    Float64,
    UInt8,
    Int8,
    UInt16,
    Int16,
    UInt32,
    Int32,
    UInt64,
    Int64,
    RangeInt64,
    ComplexFloat32,
    ComplexFloat64,
    Binary,
    String,
    Struct,
    // ReSharper disable once CppInconsistentNaming
    _count
};

#define SAMPLE_TYPE_COUNT (EnumType) SampleType::_count

#define INVALID_SAMPLE_TYPE SampleType::Invalid

enum class ScaledSampleType : EnumType
{
    Invalid = 0,
    Float32,
    Float64,
};

#define INVALID_SCALED_SAMPLE_TYPE ScaledSampleType::Invalid

/////////////////////

END_NAMESPACE_CQDAQ
