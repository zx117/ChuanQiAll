
#pragma once
#include <cqdaq/component_holder.h>
#include <cqdaq/component_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ComponentHolderImpl : public ImplementationOf<IComponentHolder, ISerializable>
{
public:
    ComponentHolderImpl(const StringPtr& localId, const StringPtr& parentGlobalId, const ComponentPtr& component);
    ComponentHolderImpl(const ComponentPtr& component);

    ErrCode INTERFACE_FUNC getLocalId(IString** localId) override;
    ErrCode INTERFACE_FUNC getParentGlobalId(IString** parentId) override;
    ErrCode INTERFACE_FUNC getComponent(IComponent** component) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    static StringPtr getParentIdOrNull(const ComponentPtr& component);
    StringPtr localId;
    StringPtr parentId;
    ComponentPtr component;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ComponentHolderImpl)

END_NAMESPACE_CQDAQ
