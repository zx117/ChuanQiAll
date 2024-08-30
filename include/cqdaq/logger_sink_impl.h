
#pragma once
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <memory>
#include <cqdaq/logger_sink.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <cqdaq/logger_sink_base_private.h>
#include <cqdaq/logger_sink_last_message_private.h>
#include <cqdaq/logger_sink_last_message_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <typename... Interfaces>
class LoggerSinkBase : public ImplementationOf<ILoggerSink, ILoggerSinkBasePrivate, Interfaces...>
{
public:
    using Sink = spdlog::sinks::sink;
    using SinkPtr = std::shared_ptr<Sink>;

    LoggerSinkBase(SinkPtr&& sink);

    ErrCode INTERFACE_FUNC setLevel(LogLevel level) override;
    ErrCode INTERFACE_FUNC getLevel(LogLevel* level) override;

    ErrCode INTERFACE_FUNC shouldLog(LogLevel level, Bool* willLog) override;

    ErrCode INTERFACE_FUNC setPattern(IString* pattern) override;
    ErrCode INTERFACE_FUNC flush() override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    ErrCode INTERFACE_FUNC getSinkImpl(SinkPtr* sinkImp) override;

protected:
    SinkPtr sink;
};

template <typename TSinkType, typename... Interfaces>
class LoggerSinkImpl : public LoggerSinkBase<Interfaces...>
{
public:
    using Super = LoggerSinkBase<Interfaces...>;
    using SinkType = TSinkType;

    LoggerSinkImpl();
    explicit LoggerSinkImpl(typename Super::SinkPtr&& sink);
};

template <>
class LoggerSinkImpl<spdlog::sinks::rotating_file_sink_mt>
    : public LoggerSinkImpl<void>
{
public:
    LoggerSinkImpl(IString* fileName, SizeT maxFileSize, SizeT maxFiles);
};

template <>
class LoggerSinkImpl<spdlog::sinks::basic_file_sink_mt>
    : public LoggerSinkImpl<void>
{
public:
    explicit LoggerSinkImpl(IString* fileName);
};

class LoggerSinkLastMessageImpl
    : public LoggerSinkImpl<spdlog::sinks::LoggerSinkLastMessageMt, ILastMessageLoggerSinkPrivate>
{
public:
    ErrCode INTERFACE_FUNC getLastMessage(IString** lastMessage) override;
    ErrCode INTERFACE_FUNC waitForMessage(SizeT timeoutMs, Bool* success) override;
};


END_NAMESPACE_CQDAQ
