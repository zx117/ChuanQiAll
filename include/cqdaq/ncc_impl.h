
#pragma once
#include <cqdaq/ncc.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/logger_ptr.h>
#include <coreobjects/core_event_args_ptr.h>
#include <cqdaq/io_folder_config_ptr.h>
#include <cqdaq/channel_ptr.h>
#include <cqdaq/device_ptr.h>
#include <cqdaq/ncc_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class NccImpl : public ImplementationOf<INcc>
{
public:
    explicit NccImpl(const DevicePtr& dc, const LoggerPtr& log);
    ~NccImpl();

 //   virtual ErrCode INTERFACE_FUNC getModules(IList** value) override;
    virtual ErrCode getStartAbsTime(Int* value) override;
 //   virtual ErrCode INTERFACE_FUNC getClockProvider(IClockProviderHelper** value) = 0;
 //   virtual ErrCode INTERFACE_FUNC getAbsTimeProvider(IAbsTime** value) = 0;

    // virtual ErrCode getActiveChannels(IList** channels) override;
    // virtual ErrCode getUsedChannels(IList** channels) override;
    // virtual ErrCode getAllChannels(IList** channels) override;
    virtual ErrCode applyConfigChanged() override;

    virtual ErrCode initialize() override;
    virtual ErrCode reset() override;
    virtual ErrCode loadFinish() override;

    virtual ErrCode channelCreate() override;
    virtual ErrCode channelDelete() override;
    virtual ErrCode channelIdChanged() override;
    virtual ErrCode channelTopologyChanged() override;

    virtual ErrCode initializeAcquisition() override;
    virtual ErrCode startAcquisition() override;
    virtual ErrCode onAcquisition() override;
    virtual ErrCode stopAcquisition() override;
    virtual ErrCode finalizeAcquisition() override;
    virtual ErrCode onConfigChanged() override;
    virtual ErrCode onDataformatChanged() override;

//    virtual ErrCode INTERFACE_FUNC getAcquisitionInfo(IAcquisitionInfo** value) = 0;
protected:
    IoFolderConfigPtr topo;
    ListPtr<IChannel> allChannels;
    ListPtr<IChannel> activeChannels;
private:
    void initTopology();

    DevicePtr dataCenter;
    //void componentCoreEventCallback(ComponentPtr& component, CoreEventArgsPtr& eventArgs);
    LoggerPtr logger;
    //EventEmitter<ComponentPtr, CoreEventArgsPtr> coreEvent;
};

END_NAMESPACE_CQDAQ