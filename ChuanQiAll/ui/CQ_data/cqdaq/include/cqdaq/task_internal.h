
#pragma once
#include <coretypes/baseobject.h>
#include <cqdaq/task_flow.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler_components
 * @addtogroup cqdaq_task TaskInternal
 * @{
 */

/*!
 * @brief Interface for accessing task and graph internals used to schedule them.
 * It should only be used internally inside the scheduler library.
 */
DECLARE_CQDAQ_INTERFACE(ITaskInternal, IBaseObject)
{
    virtual tf::Task& INTERFACE_FUNC getTask() = 0;
    virtual tf::Taskflow* INTERFACE_FUNC getFlow() = 0;
    //
    virtual void* INTERFACE_FUNC getGraph() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
