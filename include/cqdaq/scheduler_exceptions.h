
#pragma once
#include <cqdaq/scheduler_errors.h>
#include <coretypes/exceptions.h>

BEGIN_NAMESPACE_CQDAQ

class SchedulerException : public DaqException
{
public:
    using DaqException::DaqException;
};

#define DEFINE_MODULE_MANAGER_EXCEPTION(excName, errCode, excMsg) DEFINE_EXCEPTION_BASE(daq::SchedulerException, excName, errCode, excMsg)

/*
 * Should be in the order of the error's numerical value
 */

DEFINE_MODULE_MANAGER_EXCEPTION(SchedulerUnknown, CQDAQ_ERR_SCHEDULER_UNKNOWN, "Unknown scheduler exception")
DEFINE_MODULE_MANAGER_EXCEPTION(SchedulerStopped, CQDAQ_ERR_SCHEDULER_STOPPED, "Scheduler already stopped")
DEFINE_MODULE_MANAGER_EXCEPTION(NotEnoughTasks, CQDAQ_ERR_NOT_ENOUGH_TASKS, "Not enough tasks provided for this operation")
DEFINE_MODULE_MANAGER_EXCEPTION(EmptyAwaitable, CQDAQ_ERR_EMPTY_AWAITABLE, "Awaitable has no state")

END_NAMESPACE_CQDAQ
