

#pragma once
#include <cqdaq/logger.h>
#include <coretypes/common.h>
#include <cqdaq/log_level.h>
#include <cqdaq/source_location.h>

#include <fmt/format.h>

#if !defined(CQDAQ_LOG_LEVEL)
    #ifdef NDEBUG
        #define CQDAQ_LOG_LEVEL CQDAQ_LOG_LEVEL_INFO
    #else
        #define CQDAQ_LOG_LEVEL CQDAQ_LOG_LEVEL_DEBUG
    #endif
#endif

/// Plain

#define DAQLOG_PLAIN(loggerComponent, message, level) loggerComponent.logMessage(\
    daq::SourceLocation{__FILE__, __LINE__, CQDAQ_CURRENT_FUNCTION}, message, level);

#if (CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_TRACE)
    #define DAQLOG_T(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Trace);
#else
    #define DAQLOG_T(loggerComponent, message)
#endif

#if (CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_DEBUG)
    #define DAQLOG_D(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Debug);
#else
    #define DAQLOG_D(loggerComponent, message)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_INFO
    #define DAQLOG_I(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Info);
#else
    #define DAQLOG_I(loggerComponent, message)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_WARN
    #define DAQLOG_W(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Warn);
#else
    #define DAQLOG_W(loggerComponent, message)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_ERROR
    #define DAQLOG_E(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Error);
#else
    #define DAQLOG_E(loggerComponent, message)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_CRITICAL
    #define DAQLOG_C(loggerComponent, message) DAQLOG_PLAIN(loggerComponent, message, daq::LogLevel::Critical);
#else
    #define DAQLOG_C(loggerComponent, message)
#endif

/// Format

#define DAQLOG_FORMATTED(loggerComponent, message, logLevel, ...)                                    \
    loggerComponent.logMessage(daq::SourceLocation{__FILE__, __LINE__, CQDAQ_CURRENT_FUNCTION},    \
                               fmt::format(FMT_STRING(message), ##__VA_ARGS__).data(),               \
                               logLevel);

#if (CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_TRACE)
    #define DAQLOGF_T(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                    \
                        daq::LogLevel::Trace,        \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_T(logger, message, ...)
#endif

#if (CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_DEBUG)
    #define DAQLOGF_D(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                     \
                        daq::LogLevel::Debug,        \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_D(logger, message, ...)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_INFO
    #define DAQLOGF_I(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                     \
                        daq::LogLevel::Info,         \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_I(logger, message, ...)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_WARN
    #define DAQLOGF_W(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                     \
                        daq::LogLevel::Warn,         \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_W(logger, message, ...)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_ERROR
    #define DAQLOGF_E(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                     \
                        daq::LogLevel::Error,        \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_E(logger, message, ...)
#endif

#if CQDAQ_LOG_LEVEL <= CQDAQ_LOG_LEVEL_CRITICAL
    #define DAQLOGF_C(loggerComponent, message, ...) \
        DAQLOG_FORMATTED(loggerComponent,            \
                        message,                     \
                        daq::LogLevel::Critical,     \
                        ##__VA_ARGS__);
#else
    #define DAQLOGF_C(logger, message, ...)
#endif
