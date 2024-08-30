
#pragma once
#include <coretypes/baseobject.h>
#include <cqdaq/mirrored_signal_config_ptr.h>
#include <cqdaq/event_packet_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_streamings
 * @addtogroup cqdaq_streaming_streaming Streaming
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(IStreamingPrivate, IBaseObject)
{
    /*!
     * @brief Enables delivering packets from server to client for signal via the streaming
     * @param signalRemoteId The global remote ID of the signal to be subscribed.
     * @param domainSignalRemoteId The global remote ID of the domain signal of the signal to be subscribed.
     */
    virtual ErrCode INTERFACE_FUNC subscribeSignal(const StringPtr& signalRemoteId, const StringPtr& domainSignalRemoteId) = 0;

    /*!
     * @brief Disables delivering packets from server to client for signal via the streaming
     * @param signalRemoteId The global remote ID of the signal to be unsubscribed.
     * @param domainSignalRemoteId The remote global ID of the domain signal of the signal to be unsubscribed.
     */
    virtual ErrCode INTERFACE_FUNC unsubscribeSignal(const StringPtr& signalRemoteId, const StringPtr& domainSignalRemoteId) = 0;

    /*!
     * @brief Removes added signal without removing the streaming source from it.
     * @param signalRemoteId The global remote ID of the removed signal.
     * @retval CQDAQ_ERR_NOTFOUND if a signal with corresponding remote Id was not added to the Streaming.
     */
    virtual ErrCode INTERFACE_FUNC detachRemovedSignal(const StringPtr& signalRemoteId) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
