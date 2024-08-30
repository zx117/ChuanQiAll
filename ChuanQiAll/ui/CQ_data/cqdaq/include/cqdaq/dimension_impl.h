
#pragma once
#include <cqdaq/dimension_ptr.h>
#include <coreobjects/unit_ptr.h>
#include <cqdaq/dimension_rule_ptr.h>
#include <coretypes/struct_impl.h>
#include <cqdaq/dimension_builder.h>

BEGIN_NAMESPACE_CQDAQ

class DimensionImpl : public GenericStructImpl<IDimension, IStruct>
{
public:
    explicit DimensionImpl(const DimensionRulePtr& rule,
                           const UnitPtr& unit,
                           const StringPtr& name);

    explicit DimensionImpl(IDimensionBuilder* dimensionBuilder);

    ErrCode INTERFACE_FUNC getName(IString** name) override;
    ErrCode INTERFACE_FUNC getSize(SizeT* size) override;
    ErrCode INTERFACE_FUNC getUnit(IUnit** unit) override;
    ErrCode INTERFACE_FUNC getRule(IDimensionRule** rule) override;
    ErrCode INTERFACE_FUNC getLabels(IList** labels) override;
    
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    ListPtr<IBaseObject> getLinearLabels() const;
    ListPtr<IBaseObject> getLogLabels() const;
    ListPtr<IBaseObject> getListLabels() const;
    static DictPtr<IString, IBaseObject> PackBuilder(IDimensionBuilder* dimensionBuilder);

    StringPtr name;
    UnitPtr unit;
    DimensionRulePtr rule;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(DimensionImpl)

END_NAMESPACE_CQDAQ
