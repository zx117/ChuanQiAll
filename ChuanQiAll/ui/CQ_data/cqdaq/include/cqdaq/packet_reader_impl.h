
#pragma once
#include <cqdaq/packet_reader.h>
#include <cqdaq/reader_impl.h>

BEGIN_NAMESPACE_CQDAQ

class PacketReaderImpl : public ImplementationOfWeak<IPacketReader, IInputPortNotifications>
{
public:
    explicit PacketReaderImpl(const SignalPtr& signal);
    explicit PacketReaderImpl(IInputPortConfig* port);
    ~PacketReaderImpl() override;

    ErrCode INTERFACE_FUNC getAvailableCount(SizeT* count) override;
    ErrCode INTERFACE_FUNC setOnDataAvailable(IProcedure* callback) override;

    ErrCode INTERFACE_FUNC read(IPacket** packet) override;
    ErrCode INTERFACE_FUNC readAll(IList** allPackets) override;

    // IInputPortNotifications
    ErrCode INTERFACE_FUNC acceptsSignal(IInputPort* port, ISignal* signal, Bool* accept) override;
    ErrCode INTERFACE_FUNC connected(IInputPort* port) override;
    ErrCode INTERFACE_FUNC disconnected(IInputPort* port) override;
    ErrCode INTERFACE_FUNC packetReceived(IInputPort* port) override;
private:
    std::mutex mutex;
    InputPortConfigPtr port;
    PropertyObjectPtr portBinder;
    ConnectionPtr connection;
    ProcedurePtr readCallback;
};

END_NAMESPACE_CQDAQ
