#pragma once
#include <common.h>
#include <cqdaq/function_block_impl.h>
#include <cqdaq/function_block_type_factory.h>
#include <cqdaq/sample_type.h>
#include <cqdaq/data_packet_ptr.h>
#include <cqdaq/sample_type_traits.h>

#include <QElapsedTimer>

#include "icommunication.h"


class SaveSqlData;
class ThreadPool;
class RecordDao;
class ConfigrationDao;


BEGIN_NAMESPACE_SAVE_MODULE

namespace SaveData
{


struct SignalContext
{
    size_t index;
    InputPortConfigPtr inputPort;
    std::string tableName;

    std::deque<DataPacketPtr> dataPackets;
    std::deque<DataPacketPtr> dataPacketsInFreezeMode;

    DataDescriptorPtr inputDataSignalDescriptor;
    DataDescriptorPtr inputDomainDataDescriptor;

    bool valid{ false };

    SampleType sampleType;
    SampleType domainSampleType;
    std::string sampTypeStr;
    int level { 1 };

    qint64 testID{ 0 };
};


class SaveFuncBlock final : public FunctionBlockImpl<IFunctionBlock, ICommunication>
{
public:
    explicit SaveFuncBlock(const ContextPtr& ctx, const ComponentPtr& parent, const StringPtr& localId);
    ~SaveFuncBlock() override;

    void onConnected(const InputPortPtr& port) override;
    void onDisconnected(const InputPortPtr& port) override;

    static FunctionBlockTypePtr CreateType();

    void startSaving() override;
    void pauseSaving() override;
    void continueSaving() override;
    void stopSaving() override;

private:
    void updateInputPorts();
    void subscribeToSignalCoreEvent(const SignalPtr& signal);
    void renderLoop();
    void prepareSignalContexts();
    void processSaveContexts();
    void prepareSignalContext(SignalContext &cont);
    void processDataPacket(SignalContext& signalContext, const DataPacketPtr& dataPacket);

    template <SampleType DST>
    void processSaveData(SignalContext &signalContext, const DataPacketPtr &dataPacket);

    void processSignalDescriptorChanged(SignalContext& signalContext,
                                        const DataDescriptorPtr& valueSignalDescriptor,
                                        const DataDescriptorPtr& domainSignalDescriptor);
    void configureSignalContext(SignalContext& signalContext);

    void createNextSaveFile();
    void createConfigrationDB();

    void processStopSaveData();


private:
    std::vector<SignalContext> saveContexts;
    int inputPortCount;
    std::thread saveThread;
    std::condition_variable cv;

    SaveSqlData* dbManager;
    RecordDao* recordDB;
    ConfigrationDao* confDB;

    int testIndex = 0;
    int testSId = 0;

    QElapsedTimer saveClock;

    // for test
    bool startMesure;
    bool startSave;
    std::string dbBaseName;
    std::string dbName;
    int pieceMinutes;
    int saveMinutes;
    int multiFileIndex;

    ThreadPool *threadPool;
    std::mutex mtx;

    std::string oprationTtimeStr;

};

}
END_NAMESPACE_SAVE_MODULE
