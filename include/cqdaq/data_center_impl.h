
#pragma once
#include <cqdaq/device_impl.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/module_manager_ptr.h>
#include <cqdaq/data_center_config.h>

BEGIN_NAMESPACE_CQDAQ

class DataCenterImpl : public DeviceBase<IDataCenterConfig>
{
public:
    DataCenterImpl(ContextPtr ctx, const StringPtr& localId, const DeviceInfoPtr& deviceInfo, const ComponentPtr& parent = nullptr);

    // Device

    DeviceInfoPtr onGetInfo() override;
    bool allowAddDevicesFromModules() override;
    bool allowAddFunctionBlocksFromModules() override;

    //IDataCenterConfig
    ErrCode addIoSubFolder(IIoFolderConfig** ioFolderConfig, IString* localId, IIoFolderConfig* parent) override;

    //IDataCenter
    ErrCode getChannelTopology(IFolder** ioFolder) override;
    ErrCode getStartAbsTime(Int* value) override;
    ErrCode getActiveChannels(IList** channels) override;
    ErrCode getUsedChannels(IList** channels) override;
    ErrCode getAllChannels(IList** channels) override;

private:
    ModuleManagerPtr manager;
    LoggerPtr logger;
    LoggerComponentPtr loggerComponent;

    std::unordered_map<std::string, size_t> functionBlockCountMap;
};

END_NAMESPACE_CQDAQ
