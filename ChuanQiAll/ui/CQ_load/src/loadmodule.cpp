#include "loadmodule.h"
#include <coretypes/version_info_factory.h>

#include "loadfuncblock.h"

BEGIN_NAMESPACE_LOAD_MODULE

LoadModule::LoadModule(ContextPtr ctx)
    : Module("Reference function block module",
             daq::VersionInfo(1u, 0u, 0u),
             std::move(ctx),
             "ReferenceFunctionBlock")
{
}

DictPtr<IString, IFunctionBlockType> LoadModule::onGetAvailableFunctionBlockTypes()
{
    auto types = Dict<IString, IFunctionBlockType>();

    auto typeRenderer = LoadData::LoadFuncBlock::CreateType();
    types.set(typeRenderer.getId(), typeRenderer);

    return types;
}

FunctionBlockPtr LoadModule::onCreateFunctionBlock(const StringPtr& id,
                                                   const ComponentPtr& parent,
                                                   const StringPtr& localId,
                                                   const PropertyObjectPtr& config)
{

    if (id == LoadData::LoadFuncBlock::CreateType().getId())
    {
        FunctionBlockPtr fb = createWithImplementation<IFunctionBlock, LoadData::LoadFuncBlock>(context, parent, localId);
        return fb;
    }

    LOG_W("Function block \"{}\" not found", id);
    throw NotFoundException("Function block not found");
}



END_NAMESPACE_LOAD_MODULE
