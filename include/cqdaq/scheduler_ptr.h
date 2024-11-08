//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:05.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/scheduler.h"
#include <coretypes/objectptr.h>
#include <coretypes/function_ptr.h>
#include <cqdaq/awaitable_ptr.h>
#include <cqdaq/task_graph_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class SchedulerPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IScheduler>
{
    using SmartPtr = daq::SchedulerPtr;
};


END_NAMESPACE_CQDAQ

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

class SchedulerPtr : public daq::ObjectPtr<IScheduler>
{
public:
    using daq::ObjectPtr<IScheduler>::ObjectPtr;
    //using daq::ObjectPtr<IScheduler>::operator=;



    SchedulerPtr()
        : daq::ObjectPtr<IScheduler>()

    {
    }

    SchedulerPtr(daq::ObjectPtr<IScheduler>&& ptr)
        : daq::ObjectPtr<IScheduler>(std::move(ptr))

    {
    }

    SchedulerPtr(const daq::ObjectPtr<IScheduler>& ptr)
        : daq::ObjectPtr<IScheduler>(ptr)

    {
    }

    SchedulerPtr(const SchedulerPtr& other)
        : daq::ObjectPtr<IScheduler>(other)

    {
    }

    SchedulerPtr(SchedulerPtr&& other) noexcept
        : daq::ObjectPtr<IScheduler>(std::move(other))

    {
    }
    
    SchedulerPtr& operator=(const SchedulerPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IScheduler>::operator =(other);


        return *this;
    }

    SchedulerPtr& operator=(SchedulerPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IScheduler>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Schedules the specified @p work function to run on the thread-pool.
     * The call does not block but immediately returns an @p awaitable that represents
     * the asynchronous execution. It can be waited upon and queried for status and result.

     * @param work The function to schedule for execution.
     * @returns The object representing the state and result of the execution.
     * @throws CqdaqErrException when the scheduler already stopped and is not accepting any more work.
     */
    daq::AwaitablePtr scheduleWork(const daq::FunctionPtr& work) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::AwaitablePtr awaitable;
        auto errCode = this->object->scheduleWork(work, &awaitable);
        daq::checkErrorInfo(errCode);

        return awaitable;
    }


    /*!
     * @brief Schedules the specified dependency @p graph to run on the thread-pool.
     * The call does not block but immediately returns an @p awaitable that represents
     * the asynchronous execution. It can be waited upon and queried for status and result.
     * <b>Any exceptions that occur during the graph execution are silently ignored.</b>

     * @param graph The dependency graph (acyclic directed graph) to schedule.
     * @returns The object representing the state and result of the execution.
     * @throws CqdaqErrException when the scheduler already stopped and is not accepting any more work.
     */
    daq::AwaitablePtr scheduleGraph(const daq::TaskGraphPtr& graph) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::AwaitablePtr awaitable;
        auto errCode = this->object->scheduleGraph(graph, &awaitable);
        daq::checkErrorInfo(errCode);

        return awaitable;
    }


    /*!
     * @brief Cancels all outstanding work and waits for the remaining to complete.
     * After this point the scheduler does not allow any new work or graphs for scheduling.

     */
    void stop() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->stop();
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Waits fo all current scheduled work and tasks to complete.

     */
    void waitAll() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->waitAll();
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Returns whether more than one worker thread is used.

     * @returns Returns @c true if more that one worker thread is used by the scheduler.
     */
    daq::Bool isMultiThreaded() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool multiThreaded;
        auto errCode = this->object->isMultiThreaded(&multiThreaded);
        daq::checkErrorInfo(errCode);

        return multiThreaded;
    }

#if __has_include(<cqdaq/scheduler_ptr.custom.h>)
    #include <cqdaq/scheduler_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ
