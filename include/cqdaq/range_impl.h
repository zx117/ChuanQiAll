
#pragma once
#include <cqdaq/range.h>
#include <coretypes/number_ptr.h>
#include <coretypes/serializable.h>
#include <coretypes/serialized_object.h>
#include <coretypes/deserializer.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class RangeImpl : public GenericStructImpl<IRange, IStruct>
{
public:
    explicit RangeImpl(NumberPtr lowValue, NumberPtr highValue);

    ErrCode INTERFACE_FUNC getLowValue(INumber** value) override;
    ErrCode INTERFACE_FUNC getHighValue(INumber** value) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    NumberPtr low;
    NumberPtr high;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(RangeImpl)

END_NAMESPACE_CQDAQ
