
#pragma once
#include <cqdaq/block_reader.h>
#include <cqdaq/reader_impl.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/data_packet_ptr.h>

#include <condition_variable>
#include <deque>

BEGIN_NAMESPACE_CQDAQ

struct BlockReadInfo
{
    using Clock = std::chrono::steady_clock;
    using Duration = Clock::duration;

    DataPacketPtr dataPacket;
    SizeT prevSampleIndex{};

    SizeT remainingSamplesToRead{};

    void* values{};
    void* domainValues{};

    Clock::duration timeout;
    Clock::time_point startTime;

    void prepare(void* outValues, SizeT sampleCount, std::chrono::milliseconds timeoutTime)
    {
        remainingSamplesToRead = sampleCount;
        values = outValues;

        domainValues = nullptr;

        timeout = std::chrono::duration_cast<Duration>(timeoutTime);
        startTime = std::chrono::steady_clock::now();
    }

    void prepareWithDomain(void* outValues, void* domain, SizeT sampleCount, std::chrono::milliseconds timeoutTime)
    {
        remainingSamplesToRead = sampleCount;
        values = outValues;

        domainValues = domain;

        timeout = std::chrono::duration_cast<Duration>(timeoutTime);
        startTime = std::chrono::steady_clock::now();
    }

    void reset()
    {
        dataPacket = nullptr;
        prevSampleIndex = 0;
    }

    [[nodiscard]] Duration durationFromStart() const { return std::chrono::duration_cast<Duration>(Clock::now() - startTime); }
};

struct BlockNotifyInfo
{
    std::mutex mutex;
    std::condition_variable condition;

    bool dataReady{};
};

extern template class ReaderImpl<IBlockReader>;

class BlockReaderImpl final : public ReaderImpl<IBlockReader>
{
public:
    using Super = ReaderImpl<IBlockReader>;

    explicit BlockReaderImpl(const SignalPtr& signal,
                             SizeT blockSize,
                             SampleType valueReadType,
                             SampleType domainReadType,
                             ReadMode readMode);

    explicit BlockReaderImpl(IInputPortConfig* port,
                             SizeT blockSize,
                             SampleType valueReadType,
                             SampleType domainReadType,
                             ReadMode readMode);

    BlockReaderImpl(const ReaderConfigPtr& readerConfig,
                    SampleType valueReadType,
                    SampleType domainReadType,
                    SizeT blockSize,
                    ReadMode mode);

    BlockReaderImpl(BlockReaderImpl* old,
                    SampleType valueReadType,
                    SampleType domainReadType,
                    SizeT blockSize);

    ErrCode INTERFACE_FUNC getAvailableCount(SizeT* count) override;

    ErrCode INTERFACE_FUNC packetReceived(IInputPort* port) override;

    ErrCode INTERFACE_FUNC read(void* blocks, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) override;
    ErrCode INTERFACE_FUNC readWithDomain(void* dataBlocks, void* domainBlocks, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) override;

    ErrCode INTERFACE_FUNC getBlockSize(SizeT* size) override;

private:
    ErrCode readPackets(IReaderStatus** status, SizeT* count);
    ErrCode readPacketData();

    SizeT getAvailable() const;
    SizeT getAvailableSamples() const;

    SizeT blockSize;
    BlockReadInfo info{};
    BlockNotifyInfo notify{};
};

END_NAMESPACE_CQDAQ
