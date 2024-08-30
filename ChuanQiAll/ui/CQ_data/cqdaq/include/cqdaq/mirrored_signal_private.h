
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>
#include <cqdaq/event_packet_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/mirrored_signal_config_ptr.h>
#include <cqdaq/streaming_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_streamings
 * @addtogroup cqdaq_streaming_signal Mirrored Signal private
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(IMirroredSignalPrivate, IBaseObject)
{
    /*!
     * @brief Handles event packet e.g. packet with changes of the signals descriptors or
     * signal properties
     * @param eventPacket The event packet to be handled.
     * @returns True if the eventPacket should be sent along the signal path; False otherwise.
     */
    virtual ErrCode INTERFACE_FUNC triggerEvent(IEventPacket* eventPacket, Bool* forward) = 0;

    /*!
     * @brief Adds streaming source for signal.
     * @param streaming The Streaming object representing the data source.
     */
    virtual ErrCode INTERFACE_FUNC addStreamingSource(IStreaming* streaming) = 0;

    /*!
     * @brief Removes streaming source for signal.
     * @param streamingConnectionString The connection string of streaming source to be removed.
     */
    virtual ErrCode INTERFACE_FUNC removeStreamingSource(IString* streamingConnectionString) = 0;

    /*!
     * @brief Handles the completion of subscription acknowledged by the specified streaming source.
     * @param streamingConnectionString The connection string of the streaming source that completed
     * the subscription for the signal.
     */
    virtual ErrCode INTERFACE_FUNC subscribeCompleted(IString* streamingConnectionString) = 0;

    /*!
     * @brief Handles the completion of unsubscription acknowledged by the specified streaming source.
     * @param streamingConnectionString The connection string of the streaming source that completed
     * the unsubscription for the signal.
     */
    virtual ErrCode INTERFACE_FUNC unsubscribeCompleted(IString * streamingConnectionString) = 0;

    /*!
     * @brief Acts the same as unsubscribeCompleted() but does not enter a critical section.
     * @param streamingConnectionString The connection string of the streaming source that completed
     * the unsubscription for the signal.
     */
    virtual ErrCode INTERFACE_FUNC unsubscribeCompletedNoLock(IString * streamingConnectionString) = 0;

    virtual ErrCode INTERFACE_FUNC getMirroredDataDescriptor(IDataDescriptor** descriptor) = 0;
    virtual ErrCode INTERFACE_FUNC setMirroredDataDescriptor(IDataDescriptor* descriptor) = 0;

    virtual ErrCode INTERFACE_FUNC getMirroredDomainSignal(IMirroredSignalConfig** domainSignals) = 0;
    virtual ErrCode INTERFACE_FUNC setMirroredDomainSignal(IMirroredSignalConfig* domainSignal) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
