
#pragma once
#include <cqdaq/awaitable.h>
#include <cqdaq/task_graph.h>
#include <cqdaq/logger.h>
#include <coretypes/listobject.h>
#include <coretypes/procedure.h>
#include <coretypes/function.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler_components
 * @addtogroup cqdaq_scheduler Scheduler
 * @{
 */

/*!
 * @brief A thread-pool scheduler that supports scheduling one-off functions as well as
 * dependency graphs.
 */
DECLARE_CQDAQ_INTERFACE(IScheduler, IBaseObject)
{
    /*!
     * @brief Schedules the specified @p work function to run on the thread-pool.
     * The call does not block but immediately returns an @p awaitable that represents
     * the asynchronous execution. It can be waited upon and queried for status and result.
     * @param work The function to schedule for execution.
     * @param[out] awaitable The object representing the state and result of the execution.
     * @retval CQDAQ_ERR_SCHEDULER_STOPPED when the scheduler already stopped and is not accepting any more work.
     */
    virtual ErrCode INTERFACE_FUNC scheduleWork(IFunction* work, IAwaitable** awaitable) = 0;

    /*!
     * @brief Schedules the specified dependency @p graph to run on the thread-pool.
     * The call does not block but immediately returns an @p awaitable that represents
     * the asynchronous execution. It can be waited upon and queried for status and result.
     * <b>Any exceptions that occur during the graph execution are silently ignored.</b>
     * @param graph The dependency graph (acyclic directed graph) to schedule.
     * @param[out] awaitable The object representing the state and result of the execution.
     * @retval CQDAQ_ERR_SCHEDULER_STOPPED when the scheduler already stopped and is not accepting any more work.
     */
    virtual ErrCode INTERFACE_FUNC scheduleGraph(ITaskGraph* graph, IAwaitable** awaitable) = 0;

    /*!
     * @brief Cancels all outstanding work and waits for the remaining to complete.
     * After this point the scheduler does not allow any new work or graphs for scheduling.
     */
    virtual ErrCode INTERFACE_FUNC stop() = 0;

    /*!
     * @brief Waits fo all current scheduled work and tasks to complete.
     */
    virtual ErrCode INTERFACE_FUNC waitAll() = 0;

    /*!
     * @brief Returns whether more than one worker thread is used.
     * @param[out] multiThreaded Returns @c true if more that one worker thread is used by the scheduler.
     */
    virtual ErrCode INTERFACE_FUNC isMultiThreaded(Bool* multiThreaded) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, Scheduler,
    ILogger*, logger,
    SizeT, numWorkers
)

END_NAMESPACE_CQDAQ
