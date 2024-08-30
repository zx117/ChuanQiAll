
#pragma once
#include <cqdaq/context.h>
#include <cqdaq/input_port.h>
#include <cqdaq/task_graph.h>
#include <coretypes/factory.h>

BEGIN_NAMESPACE_CQDAQ

struct IFunctionBlock;
struct IInputPortNotifications;

/*!
 * @brief Represents how the input port should handle the packet-enqueued notification.
 */
enum class PacketReadyNotification
{
    None,       ///< Ignore the notification.
    SameThread, ///< Call the listener in the same thread the notification was received.
    Scheduler,  ///< Call the listener asynchronously or in another thread.
};

 /*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_input_port Input port
 * @{
 */

/*#
 * [interfaceSmartPtr(IInputPort, GenericInputPortPtr)]
 */

/*!
 * @brief The configuration component of input ports. Provides access to Input port owners
 * to internal components of the input port.
 */
DECLARE_CQDAQ_INTERFACE(IInputPortConfig, IInputPort)
{
    /*!
     * @brief Sets the input-ports response to the packet enqueued notification.
     */
    virtual ErrCode INTERFACE_FUNC setNotificationMethod(PacketReadyNotification method) = 0;

    /*!
     * @brief Gets called when a packet was enqueued in a connection.
     */
    virtual ErrCode INTERFACE_FUNC notifyPacketEnqueued() = 0;

    /*!
     * @brief Gets called when a packet was enqueued in a connection.
     *
     * The notification is called on the same thread that enqueued the packet.
     */
    virtual ErrCode INTERFACE_FUNC notifyPacketEnqueuedOnThisThread() = 0;

    /*!
     * @brief Set the object receiving input-port related events and notifications.
     */
    virtual ErrCode INTERFACE_FUNC setListener(IInputPortNotifications* port) = 0;

    /*!
     * @brief Get a custom data attached to the object.
     */
    virtual ErrCode INTERFACE_FUNC getCustomData(IBaseObject** customData) = 0;

    /*!
     * @brief Set a custom data attached to the object.
     */
    virtual ErrCode INTERFACE_FUNC setCustomData(IBaseObject* customData) = 0;

    /*!
     * @brief Sets requires signal flag of the input port.
     * @param requiresSignal True if the input port requires a signal to be connected; false otherwise.
     *
     * If an input port requires a signal, then the input port must have a signal connected otherwise
     * the owner of the input port (function block) should report an error.
     */
    virtual ErrCode INTERFACE_FUNC setRequiresSignal(Bool requiresSignal) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY,
    InputPort,
    IInputPortConfig,
    IContext*, context,
    IComponent*, parent,
    IString*, localId
)

END_NAMESPACE_CQDAQ
