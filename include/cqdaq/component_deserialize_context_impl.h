
#pragma once
#include <cqdaq/component_deserialize_context.h>
#include <cqdaq/component_ptr.h>
#include <coretypes/validation.h>

namespace daq
{

template <class MainInterface, class ... Interfaces>
class GenericComponentDeserializeContextImpl : public ImplementationOf<MainInterface, Interfaces...>
{
public:
    using Super = ImplementationOf<MainInterface, Interfaces...>;

    GenericComponentDeserializeContextImpl(const ContextPtr& context,
                                           const ComponentPtr& root,
                                           const ComponentPtr& parent,
                                           const StringPtr& localId,
                                           const IntfID* inftID);


    ErrCode INTERFACE_FUNC getParent(IComponent** parent) override;
    ErrCode INTERFACE_FUNC getRoot(IComponent** root) override;
    ErrCode INTERFACE_FUNC getLocalId(IString** localId) override;
    ErrCode INTERFACE_FUNC getContext(IContext** context) override;
    ErrCode INTERFACE_FUNC getIntfID(IntfID* id) override;

    ErrCode INTERFACE_FUNC clone(IComponent* newParent,
                                 IString* newLocalId,
                                 IComponentDeserializeContext** newComponentDeserializeContext,
                                 IntfID* newIntfID) override;

    ErrCode INTERFACE_FUNC queryInterface(const IntfID& intfID, void** obj) override;
    ErrCode INTERFACE_FUNC borrowInterface(const IntfID& intfID, void** obj) const override;

protected:
    ContextPtr context;
    ComponentPtr root;
    ComponentPtr parent;
    StringPtr localId;
    TypeManagerPtr typeManager;
    std::unique_ptr<IntfID> intfID;
};

using ComponentDeserializeContextImpl = GenericComponentDeserializeContextImpl<IComponentDeserializeContext>;

template <class MainInterface, class ... Interfaces>
GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::GenericComponentDeserializeContextImpl(
    const ContextPtr& context,
    const ComponentPtr& root,
    const ComponentPtr& parent,
    const StringPtr& localId,
    const IntfID* intfID)
    : context(context)
    , root(root)
    , parent(parent)
    , localId(localId)
    , typeManager(context.assigned() ? context.getTypeManager() : nullptr)
{
    if (intfID != nullptr)
        this->intfID = std::make_unique<IntfID>(*intfID);
}

template <class MainInterface, class... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::getParent(IComponent** parent)
{
    CQDAQ_PARAM_NOT_NULL(parent);

    *parent = this->parent.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

template <class MainInterface, class ... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::getRoot(IComponent** root)
{
    CQDAQ_PARAM_NOT_NULL(root);

    *root = this->root.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

template <class MainInterface, class... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::getLocalId(IString** localId)
{
    CQDAQ_PARAM_NOT_NULL(localId);

    *localId = this->localId.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

template <class MainInterface, class... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::getContext(IContext** context)
{
    CQDAQ_PARAM_NOT_NULL(context);

    *context = this->context.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

template <class MainInterface, class ... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::getIntfID(IntfID* intfID)
{
    if (this->intfID)
    {
        *intfID = *(this->intfID.get());
        return CQDAQ_SUCCESS;
    }

    return CQDAQ_NOTFOUND;
}

template <class MainInterface, class ... Interfaces>
ErrCode GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::clone(
    IComponent* newParent,
    IString* newLocalId,
    IComponentDeserializeContext** newComponentDeserializeContext,
    IntfID* newIntfID)
{
    CQDAQ_PARAM_NOT_NULL(newLocalId);
    CQDAQ_PARAM_NOT_NULL(newComponentDeserializeContext);

    return createComponentDeserializeContext(newComponentDeserializeContext, context, root, newParent, newLocalId, newIntfID);
}

template <class MainInterface, class... Interfaces>
ErrCode INTERFACE_FUNC GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::queryInterface(
    const IntfID& intfID,
    void** obj)
{
    CQDAQ_PARAM_NOT_NULL(obj);

    if (intfID == ITypeManager::Id && typeManager.assigned())
    {
        *obj = reinterpret_cast<void**>(typeManager.addRefAndReturn());
        return CQDAQ_SUCCESS;
    }

    return Super::queryInterface(intfID, obj);
}

template <class MainInterface, class... Interfaces>
ErrCode INTERFACE_FUNC GenericComponentDeserializeContextImpl<MainInterface, Interfaces...>::borrowInterface(
    const IntfID& intfID,
    void** obj) const
{
    CQDAQ_PARAM_NOT_NULL(obj);

    if (intfID == ITypeManager::Id && typeManager.assigned())
    {
        *obj = reinterpret_cast<void**>(typeManager.getObject());
        return CQDAQ_SUCCESS;
    }

    return Super::borrowInterface(intfID, obj);
}

}
