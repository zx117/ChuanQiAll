
#pragma once
#include <cqdaq/sample_type.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/stream_reader.h>
#include <cqdaq/reader_config_ptr.h>
#include <cqdaq/event_packet_ptr.h>
#include <cqdaq/input_port_factory.h>
#include <cqdaq/typed_reader.h>
#include <cqdaq/data_packet_ptr.h>
#include <cqdaq/read_info.h>
#include <coreobjects/property_object_factory.h>

#include <condition_variable>

BEGIN_NAMESPACE_CQDAQ


class StreamReaderImpl final : public ImplementationOfWeak<IStreamReader, IReaderConfig, IInputPortNotifications>
{
public:
    explicit StreamReaderImpl(const SignalPtr& signal,
                              SampleType valueReadType,
                              SampleType domainReadType,
                              ReadMode mode,
                              ReadTimeoutType timeoutType);
    
    explicit StreamReaderImpl(IInputPortConfig* port,
                              SampleType valueReadType,
                              SampleType domainReadType,
                              ReadMode mode,
                              ReadTimeoutType timeoutType);

    explicit StreamReaderImpl(const ReaderConfigPtr& readerConfig,
                              SampleType valueReadType,
                              SampleType domainReadType,
                              ReadMode readMode);

    explicit StreamReaderImpl(StreamReaderImpl* old,
                              SampleType valueReadType,
                              SampleType domainReadType);
    
    ~StreamReaderImpl() override;

    // IReader
    ErrCode INTERFACE_FUNC getAvailableCount(SizeT* count) override;
    ErrCode INTERFACE_FUNC setOnDataAvailable(IProcedure* callback) override;

    // ISampleReader
    ErrCode INTERFACE_FUNC getValueReadType(SampleType* sampleType) override;
    ErrCode INTERFACE_FUNC getDomainReadType(SampleType* sampleType) override;

    ErrCode INTERFACE_FUNC setValueTransformFunction(IFunction* transform) override;
    ErrCode INTERFACE_FUNC setDomainTransformFunction(IFunction* transform) override;

    ErrCode INTERFACE_FUNC getReadMode(ReadMode* mode) override;

    // StreamReader
    ErrCode INTERFACE_FUNC read(void* samples, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) override;

    ErrCode INTERFACE_FUNC readWithDomain(void* samples,
                                          void* domain,
                                          SizeT* count,
                                          SizeT timeoutMs = 0,
                                          IReaderStatus** status = nullptr) override;

    // IReaderConfig
    ErrCode INTERFACE_FUNC getValueTransformFunction(IFunction** transform) override;
    ErrCode INTERFACE_FUNC getDomainTransformFunction(IFunction** transform) override;
    ErrCode INTERFACE_FUNC getInputPorts(IList** ports) override;

    ErrCode INTERFACE_FUNC getReadTimeoutType(ReadTimeoutType* timeout) override;
    ErrCode INTERFACE_FUNC markAsInvalid() override;

    // IInputPortNotifications
    ErrCode INTERFACE_FUNC acceptsSignal(IInputPort* port, ISignal* signal, Bool* accept) override;
    ErrCode INTERFACE_FUNC connected(IInputPort* port) override;
    ErrCode INTERFACE_FUNC disconnected(IInputPort* port) override;
    ErrCode INTERFACE_FUNC packetReceived(IInputPort* port) override;

private:
    void readDescriptorFromPort();
    void connectSignal(const SignalPtr& signal);
    void inferReaderReadType(const DataDescriptorPtr& newDescriptor, std::unique_ptr<Reader>& reader) const;

    ErrCode onPacketReady();

    void handleDescriptorChanged(const EventPacketPtr& eventPacket);

    [[nodiscard]]
    bool trySetDomainSampleType(const daq::DataPacketPtr& domainPacket);

    ErrCode readPackets(IReaderStatus** status);
    ErrCode readPacketData();

    ReadInfo info{};
    NotifyInfo notify{};
    std::unique_ptr<Reader> valueReader;
    std::unique_ptr<Reader> domainReader;

    DataDescriptorPtr dataDescriptor;
    DataDescriptorPtr domainDescriptor;

    ReadMode readMode;
    ReadTimeoutType timeoutType;
    InputPortConfigPtr inputPort;
    PropertyObjectPtr portBinder;
    ConnectionPtr connection;

    bool invalid{};

    std::mutex mutex;
    ProcedurePtr readCallback;
};

END_NAMESPACE_CQDAQ
