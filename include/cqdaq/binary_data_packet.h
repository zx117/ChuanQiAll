
#pragma once
#include <cqdaq/data_packet.h>
#include <cqdaq/data_descriptor.h>
#include <cqdaq/deleter.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @brief Creates a binary value packet that contains exactly one sample.
 * @param descriptor The descriptor of the signal sending the data.
 * @param sampleMemSize The memory size of a sample.
 *
 * Binary value packet should contain exactly one sample of `SampleType::Binary`
 * sample type.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(
    LIBRARY_FACTORY, BinaryDataPacket,
    IDataPacket, createBinaryDataPacket,
    IDataPacket*, domainPacket,
    IDataDescriptor*, descriptor,
    SizeT, sampleMemSize
)

/*!
 * @brief Creates a binary value packet with external memory and a deleter that contains exactly one sample.
 * @param descriptor The descriptor of the signal sending the data.
 * @param sampleMemSize The memory size of a sample.
 *
 * Binary value packet should contain exactly one sample of `SampleType::Binary`
 * sample type. Memory should be allocated by the caller and a custom deleter callback
 * should be provided.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(
    LIBRARY_FACTORY, BinaryDataPacketWithExternalMemory,
    IDataPacket, createBinaryDataPacketWithExternalMemory,
    IDataPacket*, domainPacket,
    IDataDescriptor*, descriptor,
    SizeT, sampleMemSize,
    void*, data,
    IDeleter*, deleter
)

END_NAMESPACE_CQDAQ
