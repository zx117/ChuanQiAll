
#pragma once
#include <coretypes/struct_impl.h>
#include <cqdaq/dimension_rule_ptr.h>
#include <cqdaq/rule_private.h>
#include <cqdaq/dimension_rule.h>

BEGIN_NAMESPACE_CQDAQ

class DimensionRuleImpl : public GenericStructImpl<IDimensionRule, IStruct, IRulePrivate>
{
public:
    explicit DimensionRuleImpl(DimensionRuleType ruleType, const DictPtr<IString, IBaseObject>& params);
    explicit DimensionRuleImpl(const ListPtr<INumber>& list);
    explicit DimensionRuleImpl(const NumberPtr& delta, const NumberPtr& start, const SizeT& size);   
    explicit DimensionRuleImpl(const NumberPtr& delta, const NumberPtr& start, const NumberPtr& base, const SizeT& size);
    explicit DimensionRuleImpl(IDimensionRuleBuilder* dimensionRuleBuilder);

    ErrCode INTERFACE_FUNC getType(DimensionRuleType* type) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;

    ErrCode INTERFACE_FUNC verifyParameters() override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    enum class LabelType
    {
        None = 0,
        Number,
        Range,
        String
    };

    ErrCode verifyParametersInternal() const;
    ErrCode checkLinearRuleValidity() const;
    ErrCode checkListRuleValidity() const;
    ErrCode checkLogRuleValidity() const;
    static LabelType getLabelType(const ObjectPtr<IBaseObject>& label);
    static bool listLabelsValid(const ListPtr<IBaseObject>& list);

    DimensionRuleType ruleType;
    DictPtr<IString, IBaseObject> params;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(DimensionRuleImpl)

END_NAMESPACE_CQDAQ
