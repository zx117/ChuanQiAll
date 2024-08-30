

#pragma once
#include <cqdaq/log.h>

#if !defined(LOG_T)
    #define LOG_T(message, ...) DAQLOGF_T(loggerComponent, message, ##__VA_ARGS__)
    #define LOG_D(message, ...) DAQLOGF_D(loggerComponent, message, ##__VA_ARGS__)
    #define LOG_I(message, ...) DAQLOGF_I(loggerComponent, message, ##__VA_ARGS__)
    #define LOG_W(message, ...) DAQLOGF_W(loggerComponent, message, ##__VA_ARGS__)
    #define LOG_E(message, ...) DAQLOGF_E(loggerComponent, message, ##__VA_ARGS__)
    #define LOG_C(message, ...) DAQLOGF_C(loggerComponent, message, ##__VA_ARGS__)

    #define LOGP_T(message) DAQLOG_T(loggerComponent, message)
    #define LOGP_D(message) DAQLOG_D(loggerComponent, message)
    #define LOGP_I(message) DAQLOG_I(loggerComponent, message)
    #define LOGP_W(message) DAQLOG_W(loggerComponent, message)
    #define LOGP_E(message) DAQLOG_E(loggerComponent, message)
    #define LOGP_C(message) DAQLOG_C(loggerComponent, message)
#endif
