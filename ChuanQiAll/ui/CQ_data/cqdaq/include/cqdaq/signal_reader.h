
#pragma once
#include <cqdaq/event_packet_ptr.h>
#include <cqdaq/input_port_config_ptr.h>
#include <cqdaq/multi_typed_reader.h>
#include <cqdaq/read_info.h>
#include <cqdaq/reader_domain_info.h>

#include <chrono>

BEGIN_NAMESPACE_CQDAQ

enum class SyncStatus
{
    Unsynchronized,
    Synchronizing,
    Synchronized
};

struct SignalInfo
{
    InputPortConfigPtr port;
    FunctionPtr changeCallback;
    FunctionPtr valueTransformFunction;
    FunctionPtr domainTransformFunction;
    ReadMode readMode;
    LoggerComponentPtr loggerComponent;
};

struct SignalReader
{
    SignalReader(const InputPortConfigPtr& port,
                 SampleType valueReadType,
                 SampleType domainReadType,
                 ReadMode mode,
                 const LoggerComponentPtr& logger);

    SignalReader(const SignalReader& old,
                 const InputPortNotificationsPtr& listener,
                 SampleType valueReadType,
                 SampleType domainReadType);

    SignalReader(const SignalInfo& old,
                 const InputPortNotificationsPtr& listener,
                 SampleType valueReadType,
                 SampleType domainReadType);

    void readDescriptorFromPort();

    SizeT getAvailable(bool acrossDescriptorChanges) const;
    void handleDescriptorChanged(const EventPacketPtr& eventPacket);
    bool trySetDomainSampleType(const daq::DataPacketPtr& domainPacket) const;
    void setCommonSampleRate(const std::int64_t commonSampleRate);

    void prepare(void* outValues, SizeT count, std::chrono::milliseconds timeoutTime);
    void prepareWithDomain(void* outValues, void* domain, SizeT count, std::chrono::milliseconds timeoutTime);

    void setStartInfo(std::chrono::system_clock::time_point minEpoch, const RatioPtr& maxResolution);

    std::unique_ptr<Comparable> readStartDomain();
    void readUntilNextDataPacket();
    bool sync(const Comparable& commonStart);

    ErrCode readPackets();
    ErrCode readPacketData();
    ErrCode handlePacket(const PacketPtr& packet, bool& firstData);

    void* getValuePacketData(const DataPacketPtr& packet) const;

    LoggerComponentPtr loggerComponent;

    std::unique_ptr<Reader> valueReader;
    std::unique_ptr<Reader> domainReader;

    InputPortConfigPtr port;
    ConnectionPtr connection;
    FunctionPtr changeCallback;

    ReadInfo info{};
    ReadMode readMode;
    ReaderDomainInfo domainInfo;

    std::int64_t sampleRate;
    std::int64_t commonSampleRate;
    std::int32_t sampleRateDivider;
    
    bool invalid{false};
    SyncStatus synced{SyncStatus::Unsynchronized};
};

END_NAMESPACE_CQDAQ
