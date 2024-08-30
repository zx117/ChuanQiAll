
#pragma once
#include <cqdaq/reader_status.h>
#include <cqdaq/block_reader_status.h>
#include <cqdaq/event_packet_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <class MainInterface, class ... Interfaces>
class GenericReaderStatusImpl : public ImplementationOf<MainInterface, Interfaces...>
{
public:
    explicit GenericReaderStatusImpl(const EventPacketPtr& eventPacket, Bool valid);

    ErrCode INTERFACE_FUNC getReadStatus(ReadStatus* status) override;

    ErrCode INTERFACE_FUNC getEventPacket(IEventPacket** packet) override;

    ErrCode INTERFACE_FUNC getValid(Bool* valid) override;

private:
    EventPacketPtr eventPacket;
    Bool valid;
};

using ReaderStatusImpl = GenericReaderStatusImpl<IReaderStatus>;

class BlockReaderStatusImpl final : public GenericReaderStatusImpl<IBlockReaderStatus>
{
public:
    using Super = GenericReaderStatusImpl<IBlockReaderStatus>;
    explicit BlockReaderStatusImpl(const EventPacketPtr& eventPacket, Bool valid, SizeT readSamples);

    ErrCode INTERFACE_FUNC getReadSamples(SizeT* readSamples) override;

private:
    SizeT readSamples;
};

END_NAMESPACE_CQDAQ
