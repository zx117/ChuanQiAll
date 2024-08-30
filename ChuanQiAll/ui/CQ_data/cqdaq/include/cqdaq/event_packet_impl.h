
#pragma once
#include <coretypes/dictobject_factory.h>
#include <cqdaq/event_packet.h>
#include <cqdaq/packet_impl.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class EventPacketImpl : public PacketImpl<IEventPacket, ISerializable>
{
public:
    using Super = PacketImpl<IEventPacket, ISerializable>;

    explicit EventPacketImpl(StringPtr eventId, DictPtr<IString, IBaseObject> parameters);

    ErrCode INTERFACE_FUNC getEventId(IString** id) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    StringPtr eventId;
    DictPtr<IString, IBaseObject> parameters;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(EventPacketImpl)

END_NAMESPACE_CQDAQ
