
#pragma once
#include <cqdaq/signal.h>
#include <cqdaq/component.h>

BEGIN_NAMESPACE_CQDAQ

struct IConnection;

/*#
 * [interfaceSmartPtr(IComponent, GenericComponentPtr, "<cqdaq/component_ptr.h>")]
 * [templated(defaultAliasName: InputPortPtr)]
 * [interfaceSmartPtr(IInputPort, GenericInputPortPtr)]
 */

/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_input_port Input port
 * @{
 */

/*!
 * @brief Signals accepted by input ports can be connected, forming a connection between the input port
 * and signal, through which Packets can be sent.
 *
 * Any cqDAQ object which wishes to receive signal data must create an input port and connect it to said
 * signals. Such objects are for example function blocks, and readers.
 *
 * An input port can filter out incompatible signals by returning false when such a signal is passed as argument
 * to `acceptsSignal`, and also rejects the signals when they are passed as argument to `connect`.
 *
 * Depending on the configuration, an input port might not require a signal to be connected, returning false
 * when `requiresSignal` is called. Such input ports are usually a part of function blocks that do not require
 * a given signal to perform calculations.
 */
DECLARE_CQDAQ_INTERFACE(IInputPort, IComponent)
{
    /*!
     * @brief Returns true if the signal can be connected to the input port; false otherwise.
     * @param signal The signal being evaluated for compatibility.
     * @param[out] accepts True if the signal can be connected; false otherwise.
     * @retval CQDAQ_ERR_NOTASSIGNED if the accepted signal criteria is not defined by the input port.
     */
    virtual ErrCode INTERFACE_FUNC acceptsSignal(ISignal* signal, Bool* accepts) = 0;

    /*!
     * @brief Connects the signal to the input port, forming a Connection.
     * @param signal The signal to be connected to the input port.
     * @retval CQDAQ_ERR_SIGNAL_NOT_ACCEPTED if the signal is not accepted.
     * @retval CQDAQ_ERR_NOTASSIGNED if the accepted signal criteria is not defined by the input port.
     *
     * The signal is notified of the connection formed between it and the input port.
     */
    virtual ErrCode INTERFACE_FUNC connect(ISignal* signal) = 0;

    /*!
     * @brief Disconnects the signal from the input port.
     */
    virtual ErrCode INTERFACE_FUNC disconnect() = 0;

    /*!
     * @brief Gets the signal connected to the input port.
     * @param[out] signal The signal connected to the input port.
     */
    virtual ErrCode INTERFACE_FUNC getSignal(ISignal** signal) = 0;

    /*!
     * @brief Returns true if the input port requires a signal to be connected; false otherwise.
     * @param[out] requiresSignal True if the input port requires a signal to be connected; false otherwise.
     */
    virtual ErrCode INTERFACE_FUNC getRequiresSignal(Bool* requiresSignal) = 0;

    /*!
     * @brief Gets the Connection object formed between the Signal and Input port.
     * @param[out] connection The Connection object.
     */
    virtual ErrCode INTERFACE_FUNC getConnection(IConnection** connection) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
