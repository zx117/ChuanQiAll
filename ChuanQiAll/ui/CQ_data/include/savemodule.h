
#pragma once
#include "common.h"
#include <cqdaq/module_impl.h>

BEGIN_NAMESPACE_SAVE_MODULE

class SaveModule final : public Module
{
public:
    explicit SaveModule(ContextPtr ctx);

    DictPtr<IString, IFunctionBlockType> onGetAvailableFunctionBlockTypes() override;
    FunctionBlockPtr onCreateFunctionBlock(const StringPtr& id, const ComponentPtr& parent, const StringPtr& localId, const PropertyObjectPtr& config) override;

};

END_NAMESPACE_SAVE_MODULE

