
#pragma once
#include <cqdaq/channel.h>
#include <cqdaq/function_block_impl.h>
#include <cqdaq/tags_factory.h>
#include <coretypes/validation.h>

BEGIN_NAMESPACE_CQDAQ

template <typename... Interfaces>
class ChannelImpl;

using Channel = ChannelImpl<>;

template <typename... Interfaces>
class ChannelImpl : public FunctionBlockImpl<IChannel, Interfaces...>
{
public:
    using Self = ChannelImpl<Interfaces...>;
    using Super = FunctionBlockImpl<IChannel, Interfaces...>;

    explicit ChannelImpl(const FunctionBlockTypePtr& fbType,
                         const ContextPtr& context,
                         const ComponentPtr& parent,
                         const StringPtr& localId,
                         const StringPtr& className = nullptr);

    // ISerializable
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);
};

template <typename... Interfaces>
ChannelImpl<Interfaces...>::ChannelImpl(const FunctionBlockTypePtr& fbType,
                                        const ContextPtr& context,
                                        const ComponentPtr& parent,
                                        const StringPtr& localId,
                                        const StringPtr& className)
    : FunctionBlockImpl<IChannel, Interfaces...>(fbType, context, parent, localId, className)
{
}

template <typename... Interfaces>
ErrCode INTERFACE_FUNC ChannelImpl<Interfaces...>::getSerializeId(ConstCharPtr* id) const
{
    CQDAQ_PARAM_NOT_NULL(id);

    *id = SerializeId();

    return CQDAQ_SUCCESS;
}

template <typename... Interfaces>
ConstCharPtr ChannelImpl<Interfaces...>::SerializeId()
{
    return "Channel";
}

template <typename... Interfaces>
ErrCode ChannelImpl<Interfaces...>::Deserialize(ISerializedObject* serialized,
                                                IBaseObject* context,
                                                IFunction* factoryCallback,
                                                IBaseObject** obj)
{
    CQDAQ_PARAM_NOT_NULL(obj);

    return daqTry(
        [&obj, &serialized, &context, &factoryCallback]()
        {
            *obj = Super:: template DeserializeFunctionBlock<Channel>(serialized,
                                                            context,
                                                            factoryCallback).detach();
        });
}

CQDAQ_REGISTER_DESERIALIZE_FACTORY(Channel)

END_NAMESPACE_CQDAQ
