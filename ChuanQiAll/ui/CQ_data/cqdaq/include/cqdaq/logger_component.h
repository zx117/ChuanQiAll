

#pragma once
#include <cqdaq/logger_sink.h>
#include <cqdaq/logger_thread_pool.h>
#include <cqdaq/source_location.h>
#include <coretypes/baseobject.h>
#include <coretypes/common.h>
#include <coretypes/listobject.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger
 * @addtogroup cqdaq_logger_component Logger component
 * @{
 */

/*#
 * [include(ILoggerSink)]
 * [include(ISourceLocation)]
 */
/*!
 * @brief Logs messages produced by a specific part of cqDAC SDK. The messages are written
 * into the @ref ILoggerSink "Logger Sinks" associated with the Logger Component object.
 *
 * The set of associated sinks is initialized on the Logger Component object creation and cannot be
 * changed after.
 *
 * Logger Component allows to set up a threshold log severity level, so the messages with lower level
 * will not be registered.
 * Additionally, it provides the ability to trigger writing out messages stored in temporary buffers or
 * set up the minimum severity level of messages to be written out automatically,
 * see `flushOnLevel` method.
 */
DECLARE_CQDAQ_INTERFACE(ILoggerComponent, IBaseObject)
{
    /*!
     * @brief Gets the name of the component.
     * @param[out] name The name of the component.
     */
    virtual ErrCode INTERFACE_FUNC getName(IString** name) = 0;

    /*!
     * @brief Sets the minimal severity level of messages to be logged by the component.
     * @param level The log severity level of the component.
     */
    virtual ErrCode INTERFACE_FUNC setLevel(LogLevel level) = 0;

    /*!
     * @brief Gets the minimal severity level of messages to be logged by the component.
     * @param[out] level The log severity level of the component.
     */
    virtual ErrCode INTERFACE_FUNC getLevel(LogLevel* level) = 0;

    /*!
     * @brief Logs a message with the provided source location and severity level.
     * @param location The source location.
     * @param msg The message.
     * @param level The severity level of the message.
     */
    virtual ErrCode INTERFACE_FUNC logMessage(SourceLocation location, ConstCharPtr msg, LogLevel level) = 0;

    /*!
     * @brief Sets the custom formatter pattern for the component.
     * @param pattern The format pattern string.
     */
    virtual ErrCode INTERFACE_FUNC setPattern(IString* pattern) = 0;

    /*!
     * @brief Checks whether the messages with given log severity level will be logged or not.
     * @param level The severity level of messages.
     * @param[out] willLog True if the messages with @p level will be logged within the component; false otherwise.
     */
    virtual ErrCode INTERFACE_FUNC shouldLog(LogLevel level, Bool* willLog) = 0;

    /*!
     * @brief Triggers writing out the messages stored in temporary buffers.
     */
    virtual ErrCode INTERFACE_FUNC flush() = 0;

    /*!
     * @brief Sets the minimum severity level of messages to be automatically written to the associated
     * sinks bypassing the temporary buffers.
     * @param level The severity level of messages.
     */
    virtual ErrCode INTERFACE_FUNC flushOnLevel(LogLevel level) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, LoggerComponent,
    IString*, name,
    IList*, sinks,
    ILoggerThreadPool*, threadPool,
    LogLevel, level)

END_NAMESPACE_CQDAQ
