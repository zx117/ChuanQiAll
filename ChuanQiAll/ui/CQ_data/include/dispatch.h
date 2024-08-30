
#pragma once

#include <cqdaq/sample_type.h>

#define SAMPLE_TYPE_DISPATCH(ST, Func, ...)               \
switch (ST)                                           \
    {                                                     \
        case SampleType::Int8:                            \
            Func<SampleType::Int8>(__VA_ARGS__);          \
            break;                                        \
        case SampleType::Int16:                           \
            Func<SampleType::Int16>(__VA_ARGS__);         \
            break;                                        \
        case SampleType::Int32:                           \
            Func<SampleType::Int32>(__VA_ARGS__);         \
            break;                                        \
        case SampleType::Int64:                           \
            Func<SampleType::Int64>(__VA_ARGS__);         \
            break;                                        \
        case SampleType::UInt8:                           \
            Func<SampleType::UInt8>(__VA_ARGS__);         \
            break;                                        \
        case SampleType::UInt16:                          \
            Func<SampleType::UInt16>(__VA_ARGS__);        \
            break;                                        \
        case SampleType::UInt32:                          \
            Func<SampleType::UInt32>(__VA_ARGS__);        \
            break;                                        \
        case SampleType::UInt64:                          \
            Func<SampleType::UInt64>(__VA_ARGS__);        \
            break;                                        \
        case SampleType::Float32:                         \
            Func<SampleType::Float32>(__VA_ARGS__);       \
            break;                                        \
        case SampleType::Float64:                         \
            Func<SampleType::Float64>(__VA_ARGS__);       \
            break;                                        \
            default:                                          \
            assert(false);                                \
    }
