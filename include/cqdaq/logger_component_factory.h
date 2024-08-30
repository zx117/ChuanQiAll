
#pragma once
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/logger_thread_pool_ptr.h>
#include <cqdaq/logger_thread_pool_factory.h>
#include <cqdaq/logger_sink_factory.h>
#include <cqdaq/log.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger_component
 * @addtogroup cqdaq_logger_component_factories Factories
 * @{
 */

/*!
 * @brief Creates a Logger component object with a given name, sinks, thread pool and log severity level.
 * @param name The name of the component.
 * @param sinks The list of Sink objects. List members are of type `ILoggerSink`.
 * @param threadPool The Thread pool object.
 * @param level The minimal severity level of message to log by the component.
 */
inline LoggerComponentPtr LoggerComponent(const StringPtr& name, ListPtr<ILoggerSink> sinks = DefaultSinks(),
                                          const LoggerThreadPoolPtr& threadPool = LoggerThreadPool(),
                                          LogLevel level = LogLevel(CQDAQ_LOG_LEVEL))
{
    return LoggerComponentPtr(LoggerComponent_Create(name, sinks, threadPool, level));
}

/*!@}*/

END_NAMESPACE_CQDAQ
