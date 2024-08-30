
#pragma once
#include <cqdaq/module_manager.h>
#include <cqdaq/module_manager_utils.h>
#include <cqdaq/context_ptr.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/device_info_ptr.h>
#include <coretypes/string_ptr.h>
#include <vector>

BEGIN_NAMESPACE_CQDAQ

struct ModuleLibrary;

class ModuleManagerImpl : public ImplementationOfWeak<IModuleManager, IModuleManagerUtils>
{
public:
    explicit ModuleManagerImpl(const BaseObjectPtr& path);
    ~ModuleManagerImpl() override;

    ErrCode INTERFACE_FUNC getModules(IList** availableModules) override;
    ErrCode INTERFACE_FUNC addModule(IModule* module) override;
    ErrCode INTERFACE_FUNC loadModules(IContext* context) override;

    ErrCode INTERFACE_FUNC getAvailableDevices(IList** availableDevices) override;
    ErrCode INTERFACE_FUNC getAvailableDeviceTypes(IDict** deviceTypes) override;
    ErrCode INTERFACE_FUNC createDevice(IDevice** device, IString* connectionString, IComponent* parent, IPropertyObject* config = nullptr) override;
    ErrCode INTERFACE_FUNC getAvailableFunctionBlockTypes(IDict** functionBlockTypes) override;
    ErrCode INTERFACE_FUNC createFunctionBlock(IFunctionBlock** functionBlock, IString* id, IComponent* parent, IPropertyObject* config = nullptr, IString* localId = nullptr) override;

private:
    static uint16_t getServerCapabilityPriority(const ServerCapabilityPtr& cap);
    bool modulesLoaded;
    std::vector<std::string> paths;
    std::vector<ModuleLibrary> libraries;
    LoggerPtr logger;
    LoggerComponentPtr loggerComponent;
    DictPtr<IString, IDeviceInfo> availableDevicesGroup;
    std::unordered_map<std::string, size_t> functionBlockCountMap;
};

END_NAMESPACE_CQDAQ
