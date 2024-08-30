
#pragma once
#include <cqdaq/scheduler.h>
#include <coretypes/intfs.h>
#include <coretypes/impl.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/awaitable_ptr.h>

#include <cqdaq/task_flow.h>

BEGIN_NAMESPACE_CQDAQ

class SchedulerImpl final : public ImplementationOf<IScheduler>
{
public:
    explicit SchedulerImpl(LoggerPtr logger, SizeT numWorkers);
    ~SchedulerImpl() override;

    ErrCode INTERFACE_FUNC scheduleWork(IFunction* task, IAwaitable** awaitable) override;
    ErrCode INTERFACE_FUNC scheduleGraph(ITaskGraph* graph, IAwaitable** awaitable) override;
    ErrCode INTERFACE_FUNC isMultiThreaded(Bool* multiThreaded) override;

    ErrCode INTERFACE_FUNC stop() override;
    ErrCode INTERFACE_FUNC waitAll() override;

    [[nodiscard]] std::size_t getWorkerCount() const;

private:
    ErrCode checkAndPrepare(const IBaseObject* work, IAwaitable** awaitable);

    bool stopped;
    LoggerPtr logger;
    LoggerComponentPtr loggerComponent;

    std::unique_ptr<tf::Executor> executor;
};

END_NAMESPACE_CQDAQ
