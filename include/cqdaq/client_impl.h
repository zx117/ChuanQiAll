
#pragma once
#include <cqdaq/device_impl.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/module_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ClientImpl : public Device
{
public:
    ClientImpl(ContextPtr ctx, const StringPtr& localId, const DeviceInfoPtr& deviceInfo, const ComponentPtr& parent = nullptr);

    // Device

    DeviceInfoPtr onGetInfo() override;
    bool allowAddDevicesFromModules() override;
    bool allowAddFunctionBlocksFromModules() override;

private:
    ModuleManagerPtr manager;
    LoggerPtr logger;
    LoggerComponentPtr loggerComponent;

    std::unordered_map<std::string, size_t> functionBlockCountMap;
};

END_NAMESPACE_CQDAQ
