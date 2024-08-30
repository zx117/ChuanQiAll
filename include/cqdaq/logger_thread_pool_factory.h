
#pragma once
#include <coretypes/common.h>
#include <cqdaq/logger_thread_pool_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger_thread_pool
 * @addtogroup cqdaq_logger_thread_pool_factories Factories
 * @{
 */

/*!
 * @brief Creates a Logger Thread Pool object.
 */
inline LoggerThreadPoolPtr LoggerThreadPool()
{
    return LoggerThreadPoolPtr(LoggerThreadPool_Create());
}

/*!@}*/

END_NAMESPACE_CQDAQ
