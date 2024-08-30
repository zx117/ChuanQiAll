
#pragma once
#include <coretypes/stringobject.h>
#include <coretypes/procedure.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler_components
 * @addtogroup cqdaq_task Task
 * @{
 */

/*!
 *  @brief A packaged callback with possible continuations and dependencies that can
 *  be arranged in a dependency graph (directed acyclic graph). The task is not executed directly but only
 *  when the graph is scheduled for execution and all dependencies have been satisfied.
 */

/*#
 * [templated(defaultAliasName: TaskPtr)]
 * [interfaceSmartPtr(ITask, GenericTaskPtr)]
 */
DECLARE_CQDAQ_INTERFACE(ITask, IBaseObject)
{
    /*!
     * @brief Gets the task name.
     * @param[out] name The task name.
     */
    virtual ErrCode INTERFACE_FUNC getName(IString** name) = 0;

    /*!
     * @brief Sets the task name that is used in diagnostics.
     * @param name The new task name.
     */
    virtual ErrCode INTERFACE_FUNC setName(IString* name) = 0;

    /*!
     * @brief Sets the continuation to only execute after this task completes.
     * Be careful of forming cycles as tasks whose dependencies cannot be satisfied will never execute.
     * @param continuation The task that should wait for this one to complete.
     * @retval CQDAQ_ERR_NOT_SUPPORTED If the @p continuation implementation was not crated by the scheduler library.
     */
    // [ignore(Wrapper)]
    virtual ErrCode INTERFACE_FUNC then(ITask* continuation) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, Task, IProcedure*, work, IString*, name)

END_NAMESPACE_CQDAQ
