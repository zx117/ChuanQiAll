
#pragma once
#include <cqdaq/packet.h>
#include <coretypes/intfs.h>
#include <coretypes/validation.h>
#include <cqdaq/packet_ptr.h>
#include <cqdaq/packet_destruct_callback_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TInterface = IPacket, typename ... TInterfaces>
class PacketImpl : public ImplementationOf<TInterface, TInterfaces ...>
{
public:
    PacketImpl();
    ~PacketImpl();

    ErrCode INTERFACE_FUNC getType(PacketType* type) override;
    ErrCode INTERFACE_FUNC subscribeForDestructNotification(IPacketDestructCallback* packetDestructCallback) override;
    ErrCode INTERFACE_FUNC getRefCount(SizeT* refCount) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

protected:
    PacketType type;
    std::mutex sync;
    std::vector<PacketDestructCallbackPtr> packetDestructCallbackList;
};

template <typename TInterface, typename ... TInterfaces>
PacketImpl<TInterface, TInterfaces ...>::PacketImpl()
    : type(PacketType::None)
{
}

template <typename TInterface, typename ... TInterfaces>
PacketImpl<TInterface, TInterfaces...>::~PacketImpl()
{
    for (const auto& packetDestructCallback : packetDestructCallbackList)
        packetDestructCallback->onPacketDestroyed();
}

template <typename TInterface, typename... TInterfaces>
ErrCode PacketImpl<TInterface, TInterfaces...>::getType(PacketType* type)
{
    CQDAQ_PARAM_NOT_NULL(type);

    *type = this->type;
    return CQDAQ_SUCCESS;
}

template <typename TInterface, typename ... TInterfaces>
ErrCode PacketImpl<TInterface, TInterfaces...>::subscribeForDestructNotification(IPacketDestructCallback* packetDestructCallback)
{
    CQDAQ_PARAM_NOT_NULL(packetDestructCallback);

    std::scoped_lock lock(sync);
    packetDestructCallbackList.push_back(packetDestructCallback);

    return CQDAQ_SUCCESS;
}

template <typename TInterface, typename ... TInterfaces>
ErrCode PacketImpl<TInterface, TInterfaces...>::getRefCount(SizeT* refCount)
{
    CQDAQ_PARAM_NOT_NULL(refCount);

    *refCount = this->getReferenceCount();
    return CQDAQ_SUCCESS;
}

template <typename TInterface, typename... TInterfaces>
inline ErrCode INTERFACE_FUNC PacketImpl<TInterface, TInterfaces...>::equals(IBaseObject* other, Bool* equals) const
{
    if (equals == nullptr)
        return this->makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equals out-parameter must not be null");

    *equals = false;
    if (other == nullptr)
        return CQDAQ_SUCCESS;

    const PacketPtr packetOther = BaseObjectPtr::Borrow(other).asPtrOrNull<IPacket>();
    if (packetOther == nullptr)
        return CQDAQ_SUCCESS;

    if (this->type != packetOther.getType())
        return CQDAQ_SUCCESS;

    *equals = true;
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
