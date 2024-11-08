#pragma once
#include <coretypes/common.h>
#include <cqdaq/folder.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(IDataCenter, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC getChannelTopology(IFolder** ioFolder) = 0;

    virtual ErrCode INTERFACE_FUNC getStartAbsTime(Int* value) = 0;

    // [elementType(channels, IChannel)]
    /*!
     * @brief Gets a flat list of all actived channels.
     * @param[out] channels The flat list of channels.
     */
    virtual ErrCode INTERFACE_FUNC getActiveChannels(IList** channels) = 0;

    // [elementType(channels, IChannel)]
    /*!
     * @brief Gets a flat list of all used channels.
     * @param[out] channels The flat list of channels.
     */
    virtual ErrCode INTERFACE_FUNC getUsedChannels(IList** channels) = 0;

    // [elementType(channels, IChannel)]
    /*!
     * @brief Gets a flat list of all channels.
     * @param[out] channels The flat list of channels.
     */
    virtual ErrCode INTERFACE_FUNC getAllChannels(IList** channels) = 0;
};

END_NAMESPACE_CQDAQ