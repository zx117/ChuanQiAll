
#pragma once
#include <coretypes/common.h>
#include <coretypes/serialized_object.h>
#include <coretypes/string_ptr.h>
#include <coretypes/complex_number_factory.h>

BEGIN_NAMESPACE_CQDAQ

namespace coretype_utils
{
// Serialization utils

template <typename T>
ErrCode write(ISerializer* serializer, const T& value)
{
    return serializer->writeInt(Int(value));
}

template <typename T>
ErrCode read(ISerializedObject* serializedObj, T& valueOut)
{
    return CQDAQ_ERR_NOTIMPLEMENTED;
}

template <typename T>
ErrCode read(ISerializedObject* serializedObj, const StringPtr& key, T& valueOut)
{
    Int outInt;
    ErrCode status = serializedObj->readInt(key, &outInt);
    if (CQDAQ_SUCCEEDED(status))
        valueOut = T(outInt);
    return status;
}

template <>
inline ErrCode write<Float>(ISerializer* serializer, const Float& value)
{
    return serializer->writeFloat(value);
}

template <>
inline ErrCode read<Float>(ISerializedObject* serializedObj, const StringPtr& key, Float& valueOut)
{
    ErrCode status = serializedObj->readFloat(key, &valueOut);
    if (CQDAQ_SUCCEEDED(status))
        return status;

    Int intOut;
    status = serializedObj->readInt(key, &intOut);
    if (CQDAQ_SUCCEEDED(status))
        valueOut = Float(intOut);

    return status;
}

template <>
inline ErrCode write<ComplexFloat64>(ISerializer* serializer, const ComplexFloat64& value)
{
    serializer->startObject();
    serializer->key("real");
    serializer->writeFloat(value.real);
    serializer->key("imaginary");
    serializer->writeFloat(value.imaginary);
    serializer->endObject();
    return CQDAQ_SUCCESS;
}

template <>
inline ErrCode read<ComplexFloat64>(ISerializedObject* serializedObj, ComplexFloat64& valueOut)
{
    ErrCode status;

    status = serializedObj->readFloat("real"_daq, &valueOut.real);
    if (CQDAQ_FAILED(status))
        return status;

    status = serializedObj->readFloat("imaginary"_daq, &valueOut.imaginary);
    if (CQDAQ_FAILED(status))
        return status;

    return status;
}

template <>
inline ErrCode read<ComplexFloat64>(ISerializedObject* serializedObj, const StringPtr& key, ComplexFloat64& valueOut)
{
    SerializedObjectPtr obj;
    ErrCode status = serializedObj->readSerializedObject(key, &obj);

    if (CQDAQ_SUCCEEDED(status))
        status = read<ComplexFloat64>(obj, valueOut);

    return status;
}

template <>
inline ErrCode write<ComplexFloat32>(ISerializer* serializer, const ComplexFloat32& value)
{
    return write(serializer, ComplexFloat64(value.real, value.imaginary));
}

template <>
inline ErrCode read<ComplexFloat32>(ISerializedObject* serializedObj, const StringPtr& key, ComplexFloat32& valueOut)
{
    ComplexFloat64 tmpOut;
    ErrCode status = read<ComplexFloat64>(serializedObj, key, tmpOut);
    valueOut.real = (float) tmpOut.real;
    valueOut.imaginary = (float) tmpOut.imaginary;
    return status;
}

template <>
inline ErrCode write<ConstCharPtr>(ISerializer* serializer, const ConstCharPtr& value)
{
    return serializer->writeString(value, std::strlen(value));
}

template <>
inline ErrCode read<ConstCharPtr>(ISerializedObject* serializedObj, const StringPtr& key, ConstCharPtr& valueOut)
{
    StringPtr str;
    ErrCode status = serializedObj->readString(key, &str);
    if (CQDAQ_SUCCEEDED(status))
        valueOut = str.getCharPtr();
    return status;
}

// Math utils

template <typename T>
Bool isNearRelative(const T& actual, const T& expected, const Float& relativeErr)
{
    return actual == expected;
}

template <>
inline Bool isNearRelative<Float>(const Float& actual, const Float& expected, const Float& relativeErr)
{
    if (std::abs(expected) <= relativeErr || expected == 0)
        return std::abs(actual - expected) <= relativeErr;

    const Float err = std::abs((actual - expected) / expected);
    return err <= relativeErr;
}

template <>
inline Bool isNearRelative<float>(const float& actual, const float& expected, const Float& relativeErr)
{
    return isNearRelative<Float>(actual, expected, relativeErr);
}

template <>
inline Bool isNearRelative<Int>(const Int& actual, const Int& expected, const Float& relativeErr)
{
    return isNearRelative<Float>(actual, expected, relativeErr);
}

template <>
inline Bool isNearRelative<ComplexFloat64>(const ComplexFloat64& actual, const ComplexFloat64& expected, const Float& relativeErr)
{
    return isNearRelative(actual.real, expected.real, relativeErr) && isNearRelative(actual.imaginary, expected.imaginary, relativeErr);
}

template <>
inline Bool isNearRelative<ComplexFloat32>(const ComplexFloat32& actual, const ComplexFloat32& expected, const Float& relativeErr)
{
    return isNearRelative<ComplexFloat64>(actual, expected, relativeErr);
}

};  // namespace coretype_utils

END_NAMESPACE_CQDAQ
