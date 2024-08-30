
#pragma once
#include <cqdaq/logger_ptr.h>
#include <cqdaq/log.h>
#include <cqdaq/logger_sink_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger_logger
 * @addtogroup cqdaq_logger_logger_factories Factories
 * @{
 */

/*!
 * @brief Creates a Logger object with a given log severity level and default set of sinks.
 * @param fileName The name used for the rotating files Sink. @see RotatingFileLoggerSink.
 * @param level The default minimal severity level of the messages to be logged.
 */
inline LoggerPtr Logger(const StringPtr& fileName = nullptr, LogLevel level = LogLevel(CQDAQ_LOG_LEVEL))
{
    return LoggerPtr(Logger_Create(DefaultSinks(fileName), level));
}

/*!
 * @brief Creates a Logger object with given sinks, and log severity level.
 * @param sinks The list of Sink objects. List members are of type `ILoggerSink`.
 * @param level The default minimal severity level of the messages to be logged.
 */
inline LoggerPtr LoggerWithSinks(ListPtr<ILoggerSink> sinks, LogLevel level = LogLevel(CQDAQ_LOG_LEVEL))
{
    return LoggerPtr(Logger_Create(sinks, level));
}

/*!@}*/

END_NAMESPACE_CQDAQ
