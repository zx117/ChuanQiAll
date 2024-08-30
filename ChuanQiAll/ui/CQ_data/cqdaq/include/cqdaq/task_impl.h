

#pragma once
#include <cqdaq/graph_visualization.h>
#include <cqdaq/task_flow.h>
#include <cqdaq/task_graph.h>
#include <cqdaq/task_internal.h>
#include <cqdaq/task_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/procedure_ptr.h>
#include <coretypes/string_ptr.h>

#include <unordered_set>

BEGIN_NAMESPACE_CQDAQ

class TaskGraph;

class SubTask : public ImplementationOf<ITask, ITaskInternal>
{
public:
    SubTask();
    explicit SubTask(ProcedurePtr callable, StringPtr name = "");
    explicit SubTask(const tf::Task& task, TaskGraph* graph);

    ErrCode INTERFACE_FUNC setName(IString* taskName) override;
    ErrCode INTERFACE_FUNC getName(IString** taskName) override;
    ErrCode INTERFACE_FUNC then(ITask* continuation) override;

    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override;

    //
    // Implementation specific
    //

    tf::Task& INTERFACE_FUNC getTask() noexcept override;
    tf::Taskflow* INTERFACE_FUNC getFlow() noexcept override;
    void* INTERFACE_FUNC getGraph() noexcept override;

    void initialize(TaskGraph& graph);

private:
    SizeT id;
    tf::Task task;
    TaskGraph* graph;
    StringPtr name;
    ProcedurePtr callable;
};

END_NAMESPACE_CQDAQ

template <>
struct std::hash<daq::TaskPtr>
{
    using argument_type = daq::TaskPtr;
    using result_type = daq::SizeT;

    result_type operator()(const daq::TaskPtr& task) const noexcept
    {
        return task.getHashCode();
    }
};

BEGIN_NAMESPACE_CQDAQ

class TaskGraph : public ImplementationOf<ITaskGraph, ITaskInternal, IGraphVisualization>
{
public:
    TaskGraph();
    explicit TaskGraph(ProcedurePtr callable, const StringPtr& name);

    ErrCode INTERFACE_FUNC getName(IString** name) override;
    ErrCode INTERFACE_FUNC setName(IString* name) override;

    ErrCode INTERFACE_FUNC then(ITask* continuation) override;
    ErrCode INTERFACE_FUNC dump(IString** dot) override;

    tf::Task& INTERFACE_FUNC getTask() noexcept override;
    tf::Taskflow* INTERFACE_FUNC getFlow() noexcept override;
    void* INTERFACE_FUNC getGraph() noexcept override;

    void addTask(TaskPtr newTask);

private:
    ProcedurePtr callable;

    tf::Taskflow flow;
    tf::Task task;
    std::unordered_set<TaskPtr> tasks;
};

using RootTaskImpl = daq::TaskGraph;

END_NAMESPACE_CQDAQ
