
#pragma once
#include <cqdaq/packet.h>
#include <coretypes/dictobject.h>
#include <cqdaq/data_descriptor.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IPacket, GenericPacketPtr)]
 */

/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_event_packet Event packet
 * @{
 */

/*!
 * @brief As with Data packets, Event packets travel along the signal paths. They are used to
 * notify recipients of any relevant changes to the signal sending the packet.
 */
DECLARE_CQDAQ_INTERFACE(IEventPacket, IPacket)
{
    /*!
     * @brief Gets the ID of the event as a string. In example "DATA_DESCRIPTOR_CHANGED".
     * @param[out] id The ID of the event.
     */
    virtual ErrCode INTERFACE_FUNC getEventId(IString** id) = 0;

    // [templateType(parameters, IString, IBaseObject)]
    /*!
     * @brief Dictionary containing parameters as <String, BaseObject> pairs relevant to the event
     * signalized by the Event packet.
     * @param[out] parameters The event parameters dictionary.
     */
    virtual ErrCode INTERFACE_FUNC getParameters(IDict** parameters) = 0;
};
/*!@}*/

/*!
 * @brief Creates and Event packet with a given id and parameter dictionary.
 * @param id The ID of the event.
 * @param params The <String, BaseObject> dictionary containing the event parameters.
 */
CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, EventPacket, IString*, id, IDict*, params)

/*!
 * @brief Creates a DataDescriptorChanged Event packet.
 * @param dataDescriptor The data descriptor of the value signal.
 * @param domainDataDescriptor The data descriptor of the domain signal that carries domain data of the value signal.
 *
 * The ID of the packet is "DATA_DESCRIPTOR_CHANGED". Its parameters dictionary contains the keys "DataDescriptor"
 * and "DomainDataDescriptor", carrying their respective Signal descriptor objects as values.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY,
                                        DataDescriptorChangedEventPacket,
                                        IEventPacket,
                                        IDataDescriptor*,
                                        dataDescriptor,
                                        IDataDescriptor*,
                                        domainDataDescriptor)

END_NAMESPACE_CQDAQ
