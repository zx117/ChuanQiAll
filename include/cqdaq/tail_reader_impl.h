
#pragma once
#include <cqdaq/reader_impl.h>
#include <cqdaq/tail_reader.h>
#include <cqdaq/reader_config_ptr.h>
#include <cqdaq/data_packet_ptr.h>

#include <deque>

BEGIN_NAMESPACE_CQDAQ

struct TailReaderInfo;

extern template class ReaderImpl<ITailReader>;

class TailReaderImpl final : public ReaderImpl<ITailReader>
{
public:
    using Super = ReaderImpl<ITailReader>;

    TailReaderImpl(ISignal* signal,
                   SizeT historySize,
                   SampleType valueReadType,
                   SampleType domainReadType,
                   ReadMode mode);

    TailReaderImpl(IInputPortConfig* port,
                   SizeT historySize,
                   SampleType valueReadType,
                   SampleType domainReadType,
                   ReadMode mode);

    TailReaderImpl(const ReaderConfigPtr& readerConfig,
                   SampleType valueReadType,
                   SampleType domainReadType,
                   SizeT historySize,
                   ReadMode mode);

    TailReaderImpl(TailReaderImpl* old,
                   SampleType valueReadType,
                   SampleType domainReadType,
                   SizeT historySize);

    ErrCode INTERFACE_FUNC getAvailableCount(SizeT* count) override;
    ErrCode INTERFACE_FUNC getHistorySize(SizeT* size) override;

    ErrCode INTERFACE_FUNC read(void* values, SizeT* count, IReaderStatus** status) override;
    ErrCode INTERFACE_FUNC readWithDomain(void* values, void* domain, SizeT* count, IReaderStatus** status) override;

    ErrCode INTERFACE_FUNC packetReceived(IInputPort* port) override;

private:
    ErrCode readPacket(TailReaderInfo& info, const DataPacketPtr& packet);
    ErrCode readData(TailReaderInfo& info, IReaderStatus** status);

private:
    SizeT historySize;

    SizeT cachedSamples;
    std::deque<PacketPtr> packets;
};

END_NAMESPACE_CQDAQ
