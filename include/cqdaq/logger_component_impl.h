
#pragma once
#include <cqdaq/logger_component.h>
#include <cqdaq/logger_thread_pool_ptr.h>

#include <coretypes/intfs.h>
#include <coretypes/listobject_factory.h>
#include <coretypes/string_ptr.h>

#include <memory>

#include <spdlog/async_logger.h>

BEGIN_NAMESPACE_CQDAQ

class LoggerComponentImpl final : public ImplementationOf<ILoggerComponent>
{
public:
#ifdef CQDAQ_LOGGER_SYNC
    using LoggerComponentType = spdlog::logger;
#else
    using LoggerComponentType = spdlog::async_logger;
#endif
    using LoggerComponentTypePtr = std::shared_ptr<LoggerComponentType>;

    LoggerComponentImpl(const StringPtr& name, const ListPtr<ILoggerSink>& sinks, const LoggerThreadPoolPtr& threadPool, LogLevel level = LogLevel::Info);

    ErrCode INTERFACE_FUNC getName(IString** name) override;

    ErrCode INTERFACE_FUNC setLevel(LogLevel level) override;
    ErrCode INTERFACE_FUNC getLevel(LogLevel* level) override;

    ErrCode INTERFACE_FUNC logMessage(SourceLocation location, ConstCharPtr msg, LogLevel level) override;

    ErrCode INTERFACE_FUNC setPattern(IString* pattern) override;
    ErrCode INTERFACE_FUNC shouldLog(LogLevel level, Bool* willLog) override;

    ErrCode INTERFACE_FUNC flush() override;
    ErrCode INTERFACE_FUNC flushOnLevel(LogLevel level) override;

    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

private:
    LoggerComponentTypePtr spdlogLogger;
    LoggerThreadPoolPtr threadPool;

    LogLevel getDefaultLogLevel();
    LogLevel getLogLevelFromParam(LogLevel logLevel);
};

END_NAMESPACE_CQDAQ
