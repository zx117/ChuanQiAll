
#pragma once
#include <cqdaq/folder_impl.h>
#include <cqdaq/io_folder_config.h>
#include <cqdaq/channel.h>

BEGIN_NAMESPACE_CQDAQ

template <class... Intfs>
class IoFolderImpl : public FolderImpl<IIoFolderConfig, Intfs ...>
{
public:
    using Super = FolderImpl<IIoFolderConfig, Intfs...>;

    IoFolderImpl(const ContextPtr& context,
                 const ComponentPtr& parent,
                 const StringPtr& localId,
                 const StringPtr& className = nullptr);

    IoFolderImpl(const IntfID& itemId,
                 const ContextPtr& context,
                 const ComponentPtr& parent,
                 const StringPtr& localId,
                 const StringPtr& className = nullptr);

    // ISerializable
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);
protected:
    bool addItemInternal(const ComponentPtr& component) override;

};

template <class... Intfs>
IoFolderImpl<Intfs...>::IoFolderImpl(const ContextPtr& context,
                           const ComponentPtr& parent,
                           const StringPtr& localId,
                           const StringPtr& className)
    : Super(context, parent, localId, className)
{
}

template <class ... Intfs>
IoFolderImpl<Intfs...>::IoFolderImpl(
    const IntfID& itemId,
    const ContextPtr& context,
    const ComponentPtr& parent,
    const StringPtr& localId,
    const StringPtr& className)
    : Super(itemId, context, parent, localId, className)
{
}

template <class... Intfs>
ErrCode IoFolderImpl<Intfs...>::getSerializeId(ConstCharPtr* id) const
{
    CQDAQ_PARAM_NOT_NULL(id);

    *id = SerializeId();

    return CQDAQ_SUCCESS;
}

template <class... Intfs>
ConstCharPtr IoFolderImpl<Intfs...>::SerializeId()
{
    return "IoFolder";
}

template <class... Intfs>
ErrCode IoFolderImpl<Intfs...>::Deserialize(ISerializedObject* serialized,
                                                   IBaseObject* context,
                                                   IFunction* factoryCallback,
                                                   IBaseObject** obj)
{
    CQDAQ_PARAM_NOT_NULL(context);

    return daqTry([&obj, &serialized, &context, &factoryCallback]()
    {
        *obj = Super::template DeserializeFolder<IIoFolderConfig, IoFolderImpl>(serialized, context, factoryCallback).detach();
    });
}

template <class... Intfs>
bool IoFolderImpl<Intfs...>::addItemInternal(const ComponentPtr& component)
{
    if (!component.supportsInterface<IIoFolderConfig>() && !component.supportsInterface<IChannel>())
        throw InvalidParameterException("Type of item not allowed in the folder");

    return Super::addItemInternal(component);
}

END_NAMESPACE_CQDAQ
