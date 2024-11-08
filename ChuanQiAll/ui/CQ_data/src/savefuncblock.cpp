#include "savefuncblock.h"

#include <cqdaq/event_packet_ids.h>
#include <cqdaq/event_packet_params.h>
#include <cqdaq/event_packet_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <coreobjects/eval_value_factory.h>

// #include "dispatch.h"

#include "savesqldata.h"
#include "connectionpool.h"
#include "threadpool.hpp"
#include "recorddao.h"
#include "configrationdao.h"

#include <iostream>
#include <QDateTime>


BEGIN_NAMESPACE_SAVE_MODULE


namespace SaveData
{

SaveFuncBlock::SaveFuncBlock(const ContextPtr& ctx, const ComponentPtr& parent, const StringPtr& localId)
    : FunctionBlockImpl<IFunctionBlock, ICommunication>(CreateType(), ctx, parent, localId),
    inputPortCount(0),
    startMesure(true),
    startSave(true),
    dbBaseName("test111"),
    dbName("test111.db"),
    pieceMinutes(10),
    multiFileIndex(0)
{
    updateInputPorts();
    saveMinutes = pieceMinutes;
}

SaveFuncBlock::~SaveFuncBlock()
{
    if (startMesure){
        startMesure = false;
        cv.notify_one();
    }
    saveThread.join();
    LOGP_D("Save thread stopped")
}

FunctionBlockTypePtr SaveFuncBlock::CreateType()
{
    return FunctionBlockType(
        "ref_fb_module_saver",
        "Saverer",
        "Signal visualization"
        );
}

void SaveFuncBlock::updateInputPorts()
{
    for (auto it = saveContexts.begin(); it != saveContexts.end();)
    {
        if (!it->inputPort.getSignal().assigned())
        {
            removeInputPort(it->inputPort);
            it = saveContexts.erase(it);
        }
        else
            ++it;
    }

    const auto inputPort = createAndAddInputPort(fmt::format("Input{}", inputPortCount++), PacketReadyNotification::SameThread);
    saveContexts.emplace_back(SignalContext{ 0, inputPort });
    for (size_t i = 0; i < saveContexts.size(); i++)
        saveContexts[i].index = i;
}

void SaveFuncBlock::onConnected(const InputPortPtr &inputPort)
{
    std::scoped_lock lock(sync);
    // subscribeToSignalCoreEvent(inputPort.getSignal());
    updateInputPorts();
    auto sig = inputPort.getSignal();
    auto sigDes = sig.getDescriptor();
    auto sigName = sigDes.getName().toStdString();
    auto nameSig = sigName + "_scaled";
    auto nameReduced = sigName + "_reduced";
    std::replace(nameSig.begin(), nameSig.end(), ' ', '_');
    std::replace(nameReduced.begin(), nameReduced.end(), ' ', '_');
    std::cout << "+========= onConnected " << nameSig << std::endl << std::flush;

    threadPool->enqueue([this](std::string tableName) ->void {
        dbManager->createTable(tableName);
    }, nameSig);

    threadPool->enqueue([this](std::string tableName) ->void {
        dbManager->createTable(tableName);
    }, nameReduced);

    for (size_t i = 0; i < saveContexts.size(); i++)
    {
        if(saveContexts[i].inputPort.getLocalId() == inputPort.getLocalId())
        {
            saveContexts[i].tableName = nameSig;
        }
    }

    LOG_T("Connected to port {}", inputPort.getLocalId());
}

void SaveFuncBlock::onDisconnected(const InputPortPtr &inputPort)
{
    std::scoped_lock lock(sync);
    updateInputPorts(); // todo zxx

    LOG_T("Disconnected from port {}", inputPort.getLocalId());
}

void SaveFuncBlock::subscribeToSignalCoreEvent(const SignalPtr& signal)
{
    // signal.getOnComponentCoreEvent() += event(&SaveFuncBlock::processCoreEvent);
}

void SaveFuncBlock::renderLoop()
{
    std::unique_lock<std::mutex> lock(sync);
    const auto defaultWaitTime = std::chrono::milliseconds(20);
    auto waitTime = defaultWaitTime;

    while (startMesure) {
        cv.wait_for(lock, waitTime);
        auto t1 = std::chrono::steady_clock::now();
        if(startMesure && startSave)
        {
            if (saveClock.elapsed() >= saveMinutes * 60000L) // min -> ms
            {
                createNextSaveFile();
            }
            prepareSignalContexts();
            processSaveContexts();
        }
        auto t2 = std::chrono::steady_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        waitTime = defaultWaitTime - duration;
        if (waitTime < std::chrono::milliseconds(1))
            waitTime = std::chrono::milliseconds(1);
    }
}

void SaveFuncBlock::prepareSignalContexts()
{
    for (auto& sigCtx: saveContexts){
        prepareSignalContext(sigCtx);
    }
}

void SaveFuncBlock::prepareSignalContext(SignalContext& signalContext)
{
    const auto conn = signalContext.inputPort.getConnection();
    if (!conn.assigned())
        return;

    PacketPtr packet = conn.dequeue();
    if (packet.assigned())
    {
        if (packet.getType() == PacketType::Event)
        {
            auto eventPacket = packet.asPtr<IEventPacket>(true);
            if (eventPacket.getEventId() == event_packet_id::DATA_DESCRIPTOR_CHANGED)
            {
                DataDescriptorPtr valueSignalDescriptor = eventPacket.getParameters().get(event_packet_param::DATA_DESCRIPTOR);
                DataDescriptorPtr domainSignalDescriptor = eventPacket.getParameters().get(event_packet_param::DOMAIN_DATA_DESCRIPTOR);
                processSignalDescriptorChanged(signalContext, valueSignalDescriptor, domainSignalDescriptor);
            }
        }
        else if (packet.getType() == PacketType::Data)
        {
            auto dataPacket = packet.asPtr<IDataPacket>();
            // processDataPacket(signalContext, dataPacket);
            if(signalContext.tableName == "AI_16"){
                ++signalContext.testID;
                if (signalContext.testID == 300)
                    startSave = false;
            }

            signalContext.dataPackets.push_front(dataPacket);
            // SAMPLE_TYPE_DISPATCH(signalContext.domainSampleType, processSaveData, signalContext, dataPacket)
        }
    }
}

void SaveFuncBlock::processDataPacket(SignalContext &signalContext, const DataPacketPtr &dataPacket)
{
    if (!signalContext.valid)
        return;

    auto domainPacket = dataPacket.getDomainPacket();
    // auto valuePacket = dataPacket.();

    if (!domainPacket.assigned())
    {
        LOGP_W("Packet recieved, but no domain packet assigned. Packet ignored")
        return;
    }

    signalContext.dataPackets.push_back(dataPacket);
    // SAMPLE_TYPE_DISPATCH(signalContext.domainSampleType, processSaveData, signalContext, dataPacket)
}

void SaveFuncBlock::processSaveContexts()
{
    for(int i = 0; i < saveContexts.size(); ++i){
        SignalContext &sigCtx = saveContexts[i];
        if (sigCtx.dataPackets.empty())
            return;

        for (auto packetIt = sigCtx.dataPackets.begin(); packetIt != sigCtx.dataPackets.end();)
        {
            auto data = (*packetIt).getData();
            auto timeData = (*packetIt).getDomainPacket().getData();
            auto test_s = (*packetIt).getDomainPacket().getDataSize();
            size_t count = (*packetIt).getDataSize();
            std::cout << "=====test_s:" << test_s << count << "\n";
            std::vector<char> charVector(count);
            std::memcpy(charVector.data(), data, count);
            std::vector<char> timeVector(count);
            std::memcpy(timeVector.data(), timeData, count);
            Data paraData(count, 0, charVector, timeVector, sigCtx.sampTypeStr, sigCtx.level, 0, 0);
            // threadPool->enqueue([this](std::string tableName, Data data) -> void{
            //     dbManager->insertData(tableName, data);
            // }, sigCtx.tableName, paraData);

            dbManager->execute_in_thread([](){},
                                         &SaveSqlData::insertData, dbManager,
                                         sigCtx.tableName, paraData);

            packetIt = sigCtx.dataPackets.erase(packetIt);
        }
    }
}

void SaveFuncBlock::processSignalDescriptorChanged(SignalContext &signalContext, const DataDescriptorPtr &valueSignalDescriptor, const DataDescriptorPtr &domainSignalDescriptor)
{
    if (domainSignalDescriptor.assigned())
        signalContext.inputDomainDataDescriptor = domainSignalDescriptor;

    if (valueSignalDescriptor.assigned())
        signalContext.inputDataSignalDescriptor = valueSignalDescriptor;

    configureSignalContext(signalContext);
}

void SaveFuncBlock::configureSignalContext(SignalContext &signalContext)
{
    signalContext.valid = false;
    if (!signalContext.inputDataSignalDescriptor.assigned() || !signalContext.inputDomainDataDescriptor.assigned())
    {
        LOG_D("Incomplete input signal descriptors")
        return;
    }
    if (!signalContext.inputDataSignalDescriptor.assigned() || !signalContext.inputDomainDataDescriptor.assigned())
    {
        LOG_D("Incomplete input signal descriptors")
        return;
    }

    try{
        const auto domainDataDescriptor = signalContext.inputDomainDataDescriptor;
        if (!domainDataDescriptor.getTickResolution().assigned())
        {
            LOGP_W("Domain resolution not assigned")
            return;
        }

        signalContext.domainSampleType = domainDataDescriptor.getSampleType();
        const auto dataDescriptor = signalContext.inputDataSignalDescriptor;

        if (dataDescriptor.getDimensions().getCount() > 1)  // matrix not supported on the input
        {
            LOG_W("Matrix signals not supported")
            return;
        }
        signalContext.sampleType = dataDescriptor.getSampleType();

        switch (signalContext.sampleType)
        {
        case (SampleType::Float32):
            signalContext.sampTypeStr = "float";
            break;
        case (SampleType::Float64):
            signalContext.sampTypeStr = "double";
            break;
        case (SampleType::UInt8):
            signalContext.sampTypeStr = "uint8_t";
            break;
        case (SampleType::Int8):
            signalContext.sampTypeStr = "int8_t";
            break;
        case (SampleType::UInt16):
            signalContext.sampTypeStr = "uint16_t";
            break;
        case (SampleType::Int16):
            signalContext.sampTypeStr = "int16_t";
            break;
        case (SampleType::UInt32):
            signalContext.sampTypeStr = "uint32_t";
            break;
        case (SampleType::Int32):
            signalContext.sampTypeStr = "int32_t";
            break;
        case (SampleType::UInt64):
            signalContext.sampTypeStr = "uint64_t";
            break;
        case (SampleType::Int64):
            signalContext.sampTypeStr = "int64_t";
            break;
        default:
            signalContext.sampTypeStr = "invalid";
        }
        // todo zxx
        signalContext.valid = true;
    }
    catch (const std::exception& e)
    {
        LOG_E("Signal descriptor changed error: {}", e.what())
    }
}

void SaveFuncBlock::createNextSaveFile()
{
    dbName = dbBaseName + "_Ind" + QString::number( ++multiFileIndex ).toStdString() + ".db";
    std::cout << "=============createNextSaveFile " << dbName << std::endl;

    ConnectionPool::get_instance().resetPool(dbName);
    for (size_t i = 0; i < saveContexts.size(); i++)
    {
        threadPool->enqueue([this](std::string tableName) ->void {
            dbManager->createTable(tableName);
        }, saveContexts[i].tableName);
    }

    saveClock.restart();
}

void SaveFuncBlock::createConfigrationDB()
{
}

void SaveFuncBlock::processStopSaveData()
{
    saveClock.invalidate();

    // test record data
    recordDB = new RecordDao();
    std::string recordName = dbBaseName + ".db";

    bool fromPool = (recordName == dbName);
    if(!fromPool)
        recordDB->openRecordDB(recordName);
    recordDB->createTable(fromPool);
    recordDB->update_conf(oprationTtimeStr, fromPool);
    if (recordDB){
        delete recordDB;
        recordDB = nullptr;
    }

    // configration
    confDB = new ConfigrationDao();
}

void SaveFuncBlock::startSaving()
{
    startSave = true;
    ConnectionPool::get_instance().initConnection(dbName, 8);
    threadPool = new ThreadPool(8);
    dbManager = new SaveSqlData();

    saveClock.restart();
    saveThread = std::thread{ &SaveFuncBlock::renderLoop, this };
    std::cout << "=======startSaving";
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
    oprationTtimeStr = "start:" + QString::number(timestamp).toStdString();
}

void SaveFuncBlock::pauseSaving()
{
    startSave = false;
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
    std::string str = " pause:" + QString::number(timestamp).toStdString();
    oprationTtimeStr += str;
}

void SaveFuncBlock::continueSaving()
{
    startSave = true;
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
    std::string str = " continue:" + QString::number(timestamp).toStdString();
    oprationTtimeStr += str;
}

void SaveFuncBlock::stopSaving()
{
    startSave = false;
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
    std::string str = " stop:" + QString::number(timestamp).toStdString();
    oprationTtimeStr += str;

    processStopSaveData();
}

template <SampleType DST>
void SaveFuncBlock::processSaveData(SignalContext &signalContext, const DataPacketPtr &dataPacket)
{}


}
END_NAMESPACE_SAVE_MODULE
