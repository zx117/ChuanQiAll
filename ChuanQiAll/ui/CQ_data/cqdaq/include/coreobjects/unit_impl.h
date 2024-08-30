#pragma once
#include <coreobjects/unit_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/struct_impl.h>
#include <coreobjects/unit_builder_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class UnitImpl : public GenericStructImpl<IUnit, IStruct>
{
public:
    explicit UnitImpl(Int id, StringPtr symbol, StringPtr name, StringPtr quantity);
    explicit UnitImpl(IUnitBuilder* unitBuilder);

    ErrCode INTERFACE_FUNC getId(Int* id) override;
    ErrCode INTERFACE_FUNC getSymbol(IString** symbol) override;
    ErrCode INTERFACE_FUNC getName(IString** name) override;
    ErrCode INTERFACE_FUNC getQuantity(IString** quantity) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    static DictPtr<IString, IBaseObject> PackBuilder(IUnitBuilder* unitBuilder);
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(UnitImpl)

END_NAMESPACE_CQDAQ
