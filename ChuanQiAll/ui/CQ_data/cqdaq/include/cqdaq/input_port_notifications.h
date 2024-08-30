
#pragma once
#include <cqdaq/signal.h>
#include <cqdaq/input_port.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_input_port Input port notifications
 * @{
 */

/*!
 * @brief Notifications object passed to the input port on construction by its owner (listener).
 *
 * Input ports invoke the notification functions within the Input port notifications object when corresponding
 * events occur. The listener can then react on those events.
 */
DECLARE_CQDAQ_INTERFACE(IInputPortNotifications, IBaseObject)
{
    /*!
     * @brief Called when the Input port method `acceptsSignal` is called. Should return true if the signal is
     * accepted; false otherwise.
     * @param port The input port on which the method was called.
     * @param signal The signal which is being checked for acceptance.
     * @param[out] accept True if the signal is accepted; false otherwise.
     */
    virtual ErrCode INTERFACE_FUNC acceptsSignal(IInputPort* port, ISignal* signal, Bool* accept) = 0;

    /*!
     * @brief Called when a signal is connected to the input port.
     * @param port The port to which the signal was connected.
     */
    virtual ErrCode INTERFACE_FUNC connected(IInputPort* port) = 0;

    /*!
     * @brief Called when a signal is disconnected from the input port.
     * @param port The port from which a signal was disconnected.
     */
    virtual ErrCode INTERFACE_FUNC disconnected(IInputPort* port) = 0;

    /*!
     * @brief Notifies the listener of the newly received packet on the specified input-port.
     * @param port The port on which the new packet was received.
     */
    virtual ErrCode INTERFACE_FUNC packetReceived(IInputPort* port) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
