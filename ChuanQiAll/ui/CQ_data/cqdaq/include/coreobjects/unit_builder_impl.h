#pragma once
#include <coreobjects/unit_builder.h>
#include <coreobjects/unit_factory.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class UnitBuilderImpl : public ImplementationOf<IUnitBuilder>
{
public:
    explicit UnitBuilderImpl();
    explicit UnitBuilderImpl(const UnitPtr& unitToCopy);
    explicit UnitBuilderImpl(Int id, StringPtr symbol, StringPtr name, StringPtr quantity);

    ErrCode INTERFACE_FUNC build(IUnit** unit) override;

    ErrCode INTERFACE_FUNC setId(Int id) override;
    ErrCode INTERFACE_FUNC getId(Int* id) override;

    ErrCode INTERFACE_FUNC setSymbol(IString* symbol) override;
    ErrCode INTERFACE_FUNC getSymbol(IString** symbol) override;

    ErrCode INTERFACE_FUNC setName(IString* name) override;
    ErrCode INTERFACE_FUNC getName(IString** name) override;

    ErrCode INTERFACE_FUNC setQuantity(IString* quantity) override;
    ErrCode INTERFACE_FUNC getQuantity(IString** quantity) override;

private:
    Int id;
    StringPtr symbol;
    StringPtr name;
    StringPtr quantity;
};

END_NAMESPACE_CQDAQ
