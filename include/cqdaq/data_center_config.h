#pragma once
#include <coretypes/common.h>
#include <cqdaq/io_folder_config.h>
#include <cqdaq/data_center.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(IDataCenterConfig, IDataCenter)
{
    virtual ErrCode INTERFACE_FUNC addIoSubFolder(IIoFolderConfig** ioFolderConfig, IString* localId, IIoFolderConfig* parent) = 0;
};





END_NAMESPACE_CQDAQ