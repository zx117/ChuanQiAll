
#pragma once
#include <coreobjects/unit_ptr.h>
#include <coretypes/freezable.h>
#include <coretypes/impl.h>
#include <coretypes/intfs.h>
#include <cqdaq/dimension_builder.h>
#include <cqdaq/dimension_ptr.h>
#include <cqdaq/dimension_rule_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class DimensionBuilderImpl : public ImplementationOf<IDimensionBuilder>
{
public:
    explicit DimensionBuilderImpl();
    explicit DimensionBuilderImpl(const DimensionPtr& copy);

    ErrCode INTERFACE_FUNC build(IDimension** dimension) override;

    ErrCode INTERFACE_FUNC setName(IString* name) override;
    ErrCode INTERFACE_FUNC getName(IString** name) override;

    ErrCode INTERFACE_FUNC setUnit(IUnit* unit) override;
    ErrCode INTERFACE_FUNC getUnit(IUnit** unit) override;

    ErrCode INTERFACE_FUNC setRule(IDimensionRule* rule) override;
    ErrCode INTERFACE_FUNC getRule(IDimensionRule** rule) override;

private:
    StringPtr name;
    UnitPtr unit;
    DimensionRulePtr rule;
};

END_NAMESPACE_CQDAQ
