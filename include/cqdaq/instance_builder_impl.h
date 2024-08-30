
#pragma once
#include <cqdaq/instance_builder.h>
#include <cqdaq/instance_factory.h>
#include <cqdaq/config_provider_ptr.h>
#include <set>

BEGIN_NAMESPACE_CQDAQ

class InstanceBuilderImpl : public ImplementationOf<IInstanceBuilder>
{
public:
    explicit InstanceBuilderImpl();

    ErrCode INTERFACE_FUNC build(IInstance** instance) override;

    ErrCode INTERFACE_FUNC addConfigProvider(IConfigProvider* configProvider) override;

    ErrCode INTERFACE_FUNC setContext(IContext* context) override;
    ErrCode INTERFACE_FUNC getContext(IContext** context) override;

    ErrCode INTERFACE_FUNC setLogger(ILogger* logger) override;
    ErrCode INTERFACE_FUNC getLogger(ILogger** logger) override;
    
    ErrCode INTERFACE_FUNC setGlobalLogLevel(LogLevel logLevel) override;
    ErrCode INTERFACE_FUNC getGlobalLogLevel(LogLevel* logLevel) override;

    ErrCode INTERFACE_FUNC setComponentLogLevel(IString* component, LogLevel logLevel) override;
    ErrCode INTERFACE_FUNC getComponentsLogLevel(IDict** components) override;

    ErrCode INTERFACE_FUNC addLoggerSink(ILoggerSink* sink) override;
    ErrCode INTERFACE_FUNC setSinkLogLevel(ILoggerSink* sink, LogLevel logLevel) override;
    ErrCode INTERFACE_FUNC getLoggerSinks(IList** sinks) override;

    ErrCode INTERFACE_FUNC setModulePath(IString* path) override;
    ErrCode INTERFACE_FUNC getModulePath(IString** path) override;
    ErrCode INTERFACE_FUNC addModulePath(IString* path) override;
    ErrCode INTERFACE_FUNC getModulePathsList(IList** paths) override;

    ErrCode INTERFACE_FUNC setModuleManager(IModuleManager* moduleManager) override;
    ErrCode INTERFACE_FUNC getModuleManager(IModuleManager** moduleManager) override;

    ErrCode INTERFACE_FUNC setSchedulerWorkerNum(SizeT numWorkers) override;
    ErrCode INTERFACE_FUNC getSchedulerWorkerNum(SizeT* numWorkers) override;

    ErrCode INTERFACE_FUNC setScheduler(IScheduler* scheduler) override;
    ErrCode INTERFACE_FUNC getScheduler(IScheduler** scheduler) override;

    ErrCode INTERFACE_FUNC setDefaultRootDeviceLocalId(IString* localId) override;
    ErrCode INTERFACE_FUNC getDefaultRootDeviceLocalId(IString** localId) override;

    ErrCode INTERFACE_FUNC setRootDevice(IString* connectionString, IPropertyObject* config) override;
    ErrCode INTERFACE_FUNC getRootDevice(IString** connectionString) override;
    ErrCode INTERFACE_FUNC getRootDeviceConfig(IPropertyObject** config) override;

    ErrCode INTERFACE_FUNC setDefaultRootDeviceInfo(IDeviceInfo* deviceInfo) override;
    ErrCode INTERFACE_FUNC getDefaultRootDeviceInfo(IDeviceInfo** deviceInfo) override;

    ErrCode INTERFACE_FUNC getOptions(IDict** options) override;

    ErrCode INTERFACE_FUNC enableStandardProviders(Bool flag) override;

private:
    static DictPtr<IString, IBaseObject> GetDefaultOptions();

    DictPtr<IString, IBaseObject> getModuleManagerOptions();
    DictPtr<IString, IBaseObject> getSchedulerOptions();
    DictPtr<IString, IBaseObject> getLoggingOptions();
    DictPtr<IString, IBaseObject> getRootDevice();
    DictPtr<IString, IBaseObject> getModules();

    DeviceInfoPtr defaultRootDeviceInfo;

    DictPtr<IString, LogLevel> componentsLogLevel;
    std::set<LoggerSinkPtr> sinks;
    LoggerPtr logger;

    SchedulerPtr scheduler;
    ModuleManagerPtr moduleManager;
    ContextPtr context{nullptr};

    Bool useStandardProviders{false};
    ListPtr<IConfigProvider> providers;
    DictPtr<IString, IBaseObject> options;
    PropertyObjectPtr rootDeviceConfig{nullptr};
};

END_NAMESPACE_CQDAQ
