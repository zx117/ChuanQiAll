
#pragma once
#include <cqdaq/task_ptr.h>
#include <cqdaq/task_graph_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_task
 * @addtogroup cqdaq_task_factories Factories
 * @{
 */

/*!
 * @brief Creates a dependency graph (directed acyclic graph) of tasks that can be scheduled for execution on a Scheduler
 * with the specified @p work that is always executed before any other task on the graph.
 * @param work The root callable that is always executed before any other tasks on the graph.
 * @param name The graph name used in diagnostics.
 * @return An instance of a dependency graph used for scheduling.
 */
inline TaskPtr TaskGraph(ProcedurePtr work, StringPtr name)
{
    TaskPtr obj(TaskGraph_Create(work, name));
    return obj;
}
/*!
 * @brief Creates a dependency graph (directed acyclic graph) of tasks that can be scheduled for execution on a Scheduler.
 * @param name The graph name used in diagnostics.
 * @return An instance of a dependency graph used for scheduling.
 */
inline TaskPtr TaskGraph(StringPtr name)
{
    TaskPtr obj(TaskGraph_Create(nullptr, name));
    return obj;
}

/*!
 * @brief A packaged callback with possible continuations and dependencies that can
 * be arranged in a dependency graph (directed acyclic graph).
 * @param work The callback to execute when the dependencies complete.
 * @param name The name used for diagnostics.
 * @return An instance of a task on a dependency graph.
 */
inline TaskPtr Task(ProcedurePtr work, StringPtr name = "")
{
    TaskPtr obj(Task_Create(work, name));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
