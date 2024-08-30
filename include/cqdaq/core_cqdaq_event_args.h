
#pragma once
#include <coreobjects/core_event_args.h>
#include <cqdaq/component.h>
#include <cqdaq/device_domain.h>
#include <cqdaq/signal.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_core_events
 * @addtogroup cqdaq_core_events_factories Factories
 * @{
 */

/*!
 * @brief Creates Core event args that are passed as argument when a new component is added as a child.
 * @param component The added component.
 *
 * The sender of the event is always the parent component.
 * The ID of the event is 40, and the event name is "ComponentAdded".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsComponentAdded, ICoreEventArgs,
    IComponent*, component
)

/*!
 * @brief Creates Core event args that are passed as argument when a component is removed from the list of children.
 * @param componentId The local ID of the removed component.
 *
 * The sender of the event is always the parent of the removed component.
 *
 * The ID of the event is 50, and the event name is "ComponentRemoved".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsComponentRemoved, ICoreEventArgs,
    IString*, componentId
)

/*!
 * @brief Creates Core event args that are passed as argument when a signal is connected to an input port.
 * @param signal The connected signal.
 *
 * The sender of the event is always the input port into which the signal was connected.
 *
 * The ID of the event is 60, and the event name is "SignalConnected".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsSignalConnected, ICoreEventArgs,
    ISignal*, signal
)

/*!
 * @brief Creates Core event args that are passed as argument when a signal is connected to an input port.
 *
 * The sender of the event is always the input port from which the signal was disconnected. The parameters
 * of this event are empty.
 *
 * The ID of the event is 70, and the event name is "SignalDisconnected".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsSignalDisconnected, ICoreEventArgs
)

/*!
 * @brief Creates Core event args that are passed as argument when the descriptor of a signal changes.
 * @param descriptor The new descriptor.
 *
 * The sender of the event is always the signal of which descriptor was changed.
 *
 * The ID of the event is 80, and the event name is "DataDescriptorChanged".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsDataDescriptorChanged, ICoreEventArgs,
    IDataDescriptor*, descriptor
)

/*!
 * @brief Creates Core event args that are passed as argument when a component is finished updating.
 *
 * A component finished updating at the end of the `update` call.
 * The ID of the event is 90, and the event name is "ComponentUpdateEnd".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsComponentUpdateEnd, ICoreEventArgs
)

/*!
 * @brief Creates Core event args that are passed as argument when a component's internal attribute
 * is modified.
 * @param attributeName The name of the changed attribute.
 * @param attributeValue The new value of the attribute.
 *
 * An example of such attribute are the "active" and "visible" states of a component.
 *
 * The ID of the event is 100, and the event name is "AttributeChanged".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsAttributeChanged, ICoreEventArgs,
    IString*, attributeName, IBaseObject*, attributeValue
)

/*!
 * @brief Creates Core event args that are passed as argument when a tag is added/removed from a component.
 * @param tags The list of tags (as strings).
 *
 * The ID of the event is 110, and the event name is "TagsChanged".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsTagsChanged, ICoreEventArgs,
    IList*, tags
)

/*!
 * @brief Creates Core event args that are passed as argument when the domain of a device changes.
 * @param deviceDomain The new device domain
 *
 * The ID of the event is 150, and the event name is "DeviceDomainChanged".
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, CoreEventArgsDeviceDomainChanged, ICoreEventArgs,
    IDeviceDomain*, deviceDomain
)

/*!@}*/

END_NAMESPACE_CQDAQ
