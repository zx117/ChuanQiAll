
#pragma once
#include <cqdaq/connection.h>
#include <cqdaq/context.h>
#include <cqdaq/signal.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(ISignal, GenericSignalPtr)]
 * [templated(defaultAliasName: SignalConfigPtr)]
 * [interfaceSmartPtr(ISignalConfig, GenericSignalConfigPtr)]
 */

/*!
 * @ingroup cqdaq_signals
 * @addtogroup cqdaq_signal Signal
 * @{
 */

/*!
 * @brief The configuration component of a Signal. Allows for configuration of its properties,
 * managing its streaming sources, and sending packets through its connections.
 *
 * The Signal config is most often accessible only to the devices or function blocks that own
 * the signal. They react on property, or input signal changes to modify a signal's data descriptor,
 * and send processed/acquired data down its signal path.
 */
DECLARE_CQDAQ_INTERFACE(ISignalConfig, ISignal)
{
    /*!
     * @brief Sets the data descriptor.
     * @param descriptor The data descriptor.
     *
     * Setting the data descriptor triggers a Descriptor changed event packet to be sent to
     * all connections of the signal. If the signal is a domain signal of another, that signal
     * also sends a Descriptor changed event to all its connections.
     */
    virtual ErrCode INTERFACE_FUNC setDescriptor(IDataDescriptor* descriptor) = 0;

    // [templateType(signal, ISignal)]
    /*!
     * @brief Sets the domain signal reference.
     * @param signal The domain signal.
     *
     * Setting a new domain signal triggers a Descriptor changed event packet to be sent to
     * all connections of the signal.
     */
    virtual ErrCode INTERFACE_FUNC setDomainSignal(ISignal* cq_signal) = 0;

    // [elementType(signals, ISignal)]
    /*!
     * @brief Sets the list of related signals.
     * @param signals The list of related signals.
     */
    virtual ErrCode INTERFACE_FUNC setRelatedSignals(IList* cq_signals) = 0;

    // [templateType(signal, ISignal)]
    /*!
     * @brief Adds a related signal to the list of related signals.
     * @param signal The signal to be added.
     * @retval CQDAQ_ERR_DUPLICATEITEM if the signal is already present in the list.
     */
    virtual ErrCode INTERFACE_FUNC addRelatedSignal(ISignal* cq_signals) = 0;

    // [templateType(signal, ISignal)]
    /*!
     * @brief Removes a signal from the list of related signal.
     * @param signal The signal to be removed.
     * @retval CQDAQ_ERR_NOTFOUND if the signal is not part of the list.
     */
    virtual ErrCode INTERFACE_FUNC removeRelatedSignal(ISignal* signal) = 0;

    /*!
     * @brief Clears the list of related signals.
     */
    virtual ErrCode INTERFACE_FUNC clearRelatedSignals() = 0;

    /*!
     * @brief Sends a packet through all connections of the signal.
     * @param packet The packet to be sent.
     */
    virtual ErrCode INTERFACE_FUNC sendPacket(IPacket* packet) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, Signal, ISignalConfig,
    IContext*, context,
    IComponent*, parent,
    IString*, localId,
    IString*, className
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, SignalWithDescriptor, ISignalConfig,
    IContext*, context,
    IDataDescriptor*, descriptor,
    IComponent*, parent,
    IString*, localId,
    IString*, className
)

END_NAMESPACE_CQDAQ
