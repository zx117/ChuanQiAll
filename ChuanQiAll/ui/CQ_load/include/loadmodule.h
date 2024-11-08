#pragma once
#include "loadcommon.h"
#include <cqdaq/module_impl.h>

BEGIN_NAMESPACE_LOAD_MODULE

class LoadModule final : public Module
{
public:
    explicit LoadModule(ContextPtr ctx);

    DictPtr<IString, IFunctionBlockType> onGetAvailableFunctionBlockTypes() override;
    FunctionBlockPtr onCreateFunctionBlock(const StringPtr& id, const ComponentPtr& parent, const StringPtr& localId, const PropertyObjectPtr& config) override;

};

END_NAMESPACE_LOAD_MODULE
