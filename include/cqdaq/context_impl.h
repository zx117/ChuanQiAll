
#pragma once
#include <cqdaq/context.h>
#include <cqdaq/context_internal.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/scheduler_ptr.h>
#include <cqdaq/module_manager_ptr.h>
#include <coretypes/type_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ContextImpl : public ImplementationOf<IContext, IContextInternal>
{
public:
    explicit ContextImpl(SchedulerPtr scheduler,
                         LoggerPtr logger,
                         TypeManagerPtr typeManager,
                         ModuleManagerPtr moduleManager,
                         DictPtr<IString, IBaseObject> options);
    ~ContextImpl();

    ErrCode INTERFACE_FUNC getScheduler(IScheduler** scheduler) override;
    ErrCode INTERFACE_FUNC getLogger(ILogger** logger) override;
    ErrCode INTERFACE_FUNC getModuleManager(IBaseObject** manager) override;
    ErrCode INTERFACE_FUNC getTypeManager(ITypeManager** manager) override;
    ErrCode INTERFACE_FUNC getOnCoreEvent(IEvent** event) override;
    ErrCode INTERFACE_FUNC moveModuleManager(IModuleManager** manager) override;
    ErrCode INTERFACE_FUNC getOptions(IDict** options) override;
    ErrCode INTERFACE_FUNC getModuleOptions(IString* moduleId, IDict** options) override;

private:
    void componentCoreEventCallback(ComponentPtr& component, CoreEventArgsPtr& eventArgs);

    LoggerPtr logger;
    SchedulerPtr scheduler;
    WeakRefPtr<IModuleManager> moduleManagerWeakRef;
    ModuleManagerPtr moduleManager;
    TypeManagerPtr typeManager;
    EventEmitter<ComponentPtr, CoreEventArgsPtr> coreEvent;
    DictPtr<IString, IBaseObject> options;
};

END_NAMESPACE_CQDAQ
