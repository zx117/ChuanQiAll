#include "savemodule.h"
#include <coretypes/version_info_factory.h>

#include "savefuncblock.h"

BEGIN_NAMESPACE_SAVE_MODULE

SaveModule::SaveModule(ContextPtr ctx)
    : Module("Reference function block module",
             daq::VersionInfo(1u, 0u, 0u),
             std::move(ctx),
             "ReferenceFunctionBlock")
{
}

DictPtr<IString, IFunctionBlockType> SaveModule::onGetAvailableFunctionBlockTypes()
{
    auto types = Dict<IString, IFunctionBlockType>();

    auto typeRenderer = SaveData::SaveFuncBlock::CreateType();
    types.set(typeRenderer.getId(), typeRenderer);

    return types;
}

FunctionBlockPtr SaveModule::onCreateFunctionBlock(const StringPtr& id,
                                                    const ComponentPtr& parent,
                                                    const StringPtr& localId,
                                                    const PropertyObjectPtr& config)
{

    if (id == SaveData::SaveFuncBlock::CreateType().getId())
    {
        FunctionBlockPtr fb = createWithImplementation<IFunctionBlock, SaveData::SaveFuncBlock>(context, parent, localId);
        return fb;
    }

    LOG_W("Function block \"{}\" not found", id);
    throw NotFoundException("Function block not found");
}


END_NAMESPACE_SAVE_MODULE

