
#pragma once
#include <coretypes/complex_number.h>
#include <coretypes/comparable.h>
#include <coretypes/serializable.h>
#include <coretypes/coretype.h>
#include <coretypes/convertible.h>
#include <coretypes/serialized_object.h>
#include <coretypes/deserializer.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class ComplexNumberImpl : public GenericStructImpl<IComplexNumber, IStruct, IComparable, IConvertible>
{
public:
    explicit ComplexNumberImpl(const Float real, const Float imaginary);

    // IComplexNumber
    ErrCode INTERFACE_FUNC getValue(ComplexFloat64* value) override;
    ErrCode INTERFACE_FUNC equalsValue(const ComplexFloat64 value, Bool* equal) override;
    ErrCode INTERFACE_FUNC getReal(Float* real) override;
    ErrCode INTERFACE_FUNC getImaginary(Float* imaginary) override;

    // IBaseObject
    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // IConvertible
    ErrCode INTERFACE_FUNC toFloat(Float* val) override;
    ErrCode INTERFACE_FUNC toInt(Int* val) override;
    ErrCode INTERFACE_FUNC toBool(Bool* val) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IComparable
    ErrCode INTERFACE_FUNC compareTo(IBaseObject* other) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    static ErrCode Deserialize(ISerializedObject* serializedObj, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;
    static ConstCharPtr SerializeId();

protected:
    ComplexFloat64 value;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ComplexNumberImpl)

END_NAMESPACE_CQDAQ