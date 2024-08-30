
#pragma once
#include <cqdaq/logger.h>
#include <cqdaq/logger_sink_ptr.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/logger_thread_pool_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/listobject_factory.h>
#include <coretypes/string_ptr.h>

#include <memory>
#include <unordered_map>
#include <vector>

#include <spdlog/spdlog.h>
#include <spdlog/details/periodic_worker.h>

BEGIN_NAMESPACE_CQDAQ

class LoggerImpl final : public ImplementationOf<ILogger>
{
public:
    using LoggerFlushWorker = spdlog::details::periodic_worker;
    using LoggerFlushWorkerPtr = std::unique_ptr<LoggerFlushWorker>;

    explicit LoggerImpl(const ListPtr<ILoggerSink>& sinksList, LogLevel level = LogLevel::Default);

    ErrCode INTERFACE_FUNC setLevel(LogLevel level) override;
    ErrCode INTERFACE_FUNC getLevel(LogLevel* level) override;

    ErrCode INTERFACE_FUNC getOrAddComponent(IString* name, ILoggerComponent** component) override;
    ErrCode INTERFACE_FUNC addComponent(IString* name, ILoggerComponent** component) override;
    ErrCode INTERFACE_FUNC removeComponent(IString* name) override;

    ErrCode INTERFACE_FUNC getComponents(IList** components) override;
    ErrCode INTERFACE_FUNC getComponent(IString* name, ILoggerComponent** component) override;

    ErrCode INTERFACE_FUNC flush() override;
    ErrCode INTERFACE_FUNC flushOnLevel(LogLevel level) override;

private:
    void flushComponents();
    void flushSinks();
private:
    std::mutex addComponentMutex;
    std::vector<LoggerSinkPtr> sinks;
    std::unordered_map<std::string, LoggerComponentPtr> components;
    LoggerThreadPoolPtr threadPool;
    LogLevel level;
    LoggerFlushWorkerPtr periodicFlushWorker;
    LogLevel flushLevel;
};

END_NAMESPACE_CQDAQ
