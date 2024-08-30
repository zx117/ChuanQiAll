
#pragma once
#include <cqdaq/scheduler_ptr.h>
#include <cqdaq/logger_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler
 * @addtogroup cqdaq_scheduler_factories Factories
 * @{
 */

/*!
 * @brief Creates an instance of a Scheduler with the specified amount of @p numWorker threads.
 * @param numWorkers The amount of worker threads. If @c 0 then maximum number of concurrent threads supported by the implementation is used.
 * @returns A Scheduler instance with the specified amount of worker threads.
 */
inline SchedulerPtr Scheduler(LoggerPtr logger, SizeT numWorkers = 0)
{
    SchedulerPtr obj(Scheduler_Create(logger, numWorkers));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
