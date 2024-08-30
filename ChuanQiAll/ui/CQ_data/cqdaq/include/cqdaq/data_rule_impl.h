
#pragma once
#include <cqdaq/data_rule.h>
#include <cqdaq/rule_private.h>
#include <coretypes/struct_impl.h>
#include <cqdaq/data_rule_ptr.h>
#include <cqdaq/data_rule_builder.h>

BEGIN_NAMESPACE_CQDAQ

class DataRuleImpl final : public GenericStructImpl<IDataRule, IStruct, IRulePrivate>
{
public:
    explicit DataRuleImpl(DataRuleType ruleType, const DictPtr<IString, IBaseObject>& params);
    explicit DataRuleImpl(DataRuleType ruleType, const NumberPtr& param1, const NumberPtr& param2);
    explicit DataRuleImpl(DataRuleType ruleType);
    explicit DataRuleImpl(IDataRuleBuilder* dataRuleBuilder);
    
    ErrCode INTERFACE_FUNC getType(DataRuleType* type) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;

    ErrCode INTERFACE_FUNC verifyParameters() override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    ErrCode verifyParametersInternal();

    DataRuleType ruleType;
    DictPtr<IString, IBaseObject> params;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(DataRuleImpl)

END_NAMESPACE_CQDAQ
