

#pragma once
#include <cqdaq/task.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler_components
 * @addtogroup cqdaq_task TaskGraph
 * @{
 */

/*!
 * @brief A dependency graph (directed acyclic graph) of tasks that can be scheduled for execution on a Scheduler.
 */
/*#
 * [interfaceSmartPtr(ITask, GenericTaskPtr)]
 */
DECLARE_CQDAQ_INTERFACE(ITaskGraph, ITask)
{
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, TaskGraph, IProcedure*, work, IString*, name)

END_NAMESPACE_CQDAQ
