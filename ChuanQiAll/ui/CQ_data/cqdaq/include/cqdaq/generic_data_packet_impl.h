
#pragma once
#include <cqdaq/data_packet_ptr.h>
#include <cqdaq/packet_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TInterface = IDataPacket>
class GenericDataPacketImpl : public PacketImpl<TInterface>
{
public:
    explicit GenericDataPacketImpl(const DataPacketPtr& domainPacket);

    ErrCode INTERFACE_FUNC getDomainPacket(IDataPacket** packet) override;
    ErrCode INTERFACE_FUNC getPacketId(Int* packetId) override;

protected:
    DataPacketPtr domainPacket;
    Int packetId;
};

Int generatePacketId();

template <typename TInterface>
GenericDataPacketImpl<TInterface>::GenericDataPacketImpl(const DataPacketPtr& domainPacket)
    : domainPacket(domainPacket)
    , packetId(generatePacketId())
{
    this->type = PacketType::Data;
}

template <typename TInterface>
ErrCode GenericDataPacketImpl<TInterface>::getDomainPacket(IDataPacket** packet)
{
    CQDAQ_PARAM_NOT_NULL(packet);

    *packet = domainPacket.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode GenericDataPacketImpl<TInterface>::getPacketId(Int* packetId)
{
    CQDAQ_PARAM_NOT_NULL(packetId);

    *packetId = this->packetId;
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
