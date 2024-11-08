#pragma once
#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(IWorker, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC initialize() = 0;
    virtual ErrCode INTERFACE_FUNC reset() = 0;
    virtual ErrCode INTERFACE_FUNC loadFinish() = 0;

    virtual ErrCode INTERFACE_FUNC channelCreate() = 0;
    virtual ErrCode INTERFACE_FUNC channelDelete() = 0;

    virtual ErrCode INTERFACE_FUNC applyConfigChanged() = 0;

    virtual ErrCode INTERFACE_FUNC channelIdChanged() = 0;
    virtual ErrCode INTERFACE_FUNC channelTopologyChanged() = 0;
    virtual ErrCode INTERFACE_FUNC onConfigChanged() = 0;
    virtual ErrCode INTERFACE_FUNC onDataformatChanged() = 0;

    virtual ErrCode INTERFACE_FUNC initializeAcquisition() = 0;
    virtual ErrCode INTERFACE_FUNC startAcquisition() = 0;
    virtual ErrCode INTERFACE_FUNC onAcquisition() = 0;
    virtual ErrCode INTERFACE_FUNC stopAcquisition() = 0;
    virtual ErrCode INTERFACE_FUNC finalizeAcquisition() = 0;    
};


END_NAMESPACE_CQDAQ