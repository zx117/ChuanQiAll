
#pragma once
#include <cqdaq/data_packet_ptr.h>
#include <cqdaq/binary_data_packet.h>
#include <cqdaq/deleter_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_packet_factories Factories
 * @{
 */

/*!
 * @brief Creates a data packet with binary sample type with a given descriptor and memory size of a sample.
 * @param descriptor The descriptor of the signal sending the data.
 * @param sampleSize the memory size of the binary sample.
 *
 * Binary value packet contains exactly one sample of binary type. The size of the sample is provided with
 * `sampleSize` argument.
 */
inline DataPacketPtr BinaryDataPacket(
    const DataPacketPtr& domainPacket,
    const DataDescriptorPtr& descriptor,
    uint64_t sampleSize)
{
    DataPacketPtr obj(BinaryDataPacket_Create(domainPacket, descriptor, sampleSize));
    return obj;
}

/*!
 * @brief Creates a data packet with binary sample type with a given descriptor, memory size of a sample,
 * pointer to an existing memory location and a deleter.
 * @param descriptor The descriptor of the signal sending the data.
 * @param sampleSize the memory size of the binary sample.
 * @param data Pointer to a custom memory location
 * @param delter Deleter callback to free the memory
 *
 * Binary data packet contains exactly one sample of binary type. The size of the sample is provided with
 * `sampleSize` argument. This factory does not allocate any memory for the data. Instead the memory is
 * provided through `data` parameter. Deleter callback is called when the packet is destroyed. The callback
 * should free the memory.
 */
inline DataPacketPtr BinaryDataPacketWithExternalMemory(
    const DataPacketPtr& domainPacket,
    const DataDescriptorPtr& descriptor, uint64_t sampleSize,
    void* data,
    const DeleterPtr& deleter)
{
    DataPacketPtr obj(BinaryDataPacketWithExternalMemory_Create(domainPacket, descriptor, sampleSize, data, deleter));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
