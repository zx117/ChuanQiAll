
#pragma once
#include <coretypes/dictobject_factory.h>
#include <coretypes/intfs.h>
#include <cqdaq/data_rule_builder.h>
#include <cqdaq/data_rule_ptr.h>
#include <cqdaq/rule_private.h>

BEGIN_NAMESPACE_CQDAQ

class DataRuleBuilderImpl final : public ImplementationOf<IDataRuleBuilder>
{
public:
    explicit DataRuleBuilderImpl();
    explicit DataRuleBuilderImpl(const DataRulePtr& ruleToCopy);

    ErrCode INTERFACE_FUNC build(IDataRule** scaling) override;

    ErrCode INTERFACE_FUNC setType(DataRuleType type) override;
    ErrCode INTERFACE_FUNC getType(DataRuleType* type) override;

    ErrCode INTERFACE_FUNC setParameters(IDict* parameters) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;
    ErrCode INTERFACE_FUNC addParameter(IString* name, IBaseObject* parameter) override;
    ErrCode INTERFACE_FUNC removeParameter(IString* name) override;

private:
    DataRuleType ruleType;
    DictPtr<IString, IBaseObject> params;
};

END_NAMESPACE_CQDAQ
