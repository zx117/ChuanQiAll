
#pragma once
#include <coretypes/coretypes.h>
#include <cqdaq/dimension_rule_builder.h>
#include <cqdaq/dimension_rule_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class DimensionRuleBuilderImpl : public ImplementationOf<IDimensionRuleBuilder>
{
public:
    explicit DimensionRuleBuilderImpl();
    explicit DimensionRuleBuilderImpl(const DimensionRulePtr& rule);  // Copy
    
    ErrCode INTERFACE_FUNC build(IDimensionRule** dimensionRule) override;

    ErrCode INTERFACE_FUNC setType(DimensionRuleType type) override;
    ErrCode INTERFACE_FUNC getType(DimensionRuleType* type) override;

    ErrCode INTERFACE_FUNC setParameters(IDict* parameters) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;
    ErrCode INTERFACE_FUNC addParameter(IString* name, IBaseObject* parameter) override;
    ErrCode INTERFACE_FUNC removeParameter(IString* name) override;

private:
    DimensionRuleType ruleType;
    DictPtr<IString, IBaseObject> params;
};

END_NAMESPACE_CQDAQ
