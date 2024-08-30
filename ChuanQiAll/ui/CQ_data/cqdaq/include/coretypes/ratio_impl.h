
#pragma once
#include <coretypes/common.h>
#include <coretypes/ratio.h>
#include <coretypes/convertible.h>
#include <coretypes/serializable.h>
#include <coretypes/deserializer.h>
#include <coretypes/coretype.h>
#include <coretypes/comparable.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class RatioImpl : public GenericStructImpl<IRatio, IStruct, IConvertible, IComparable>
{
public:
    RatioImpl(Int numerator, Int denominator);

    // IBaseObject
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // IRatio
    ErrCode INTERFACE_FUNC getNumerator(Int* numerator) override;
    ErrCode INTERFACE_FUNC getDenominator(Int* denominator) override;
    ErrCode INTERFACE_FUNC simplify(IRatio** simplifiedRatio) override;

    // IConvertible
    ErrCode INTERFACE_FUNC toFloat(Float* val) override;
    ErrCode INTERFACE_FUNC toInt(Int* val) override;
    ErrCode INTERFACE_FUNC toBool(Bool* val) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IComparable
    ErrCode INTERFACE_FUNC compareTo(IBaseObject* obj) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

private:
    Int numerator;
    Int denominator;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(RatioImpl)

END_NAMESPACE_CQDAQ
