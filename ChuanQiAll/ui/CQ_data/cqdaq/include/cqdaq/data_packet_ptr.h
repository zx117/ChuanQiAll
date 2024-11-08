//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:22.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/data_packet.h"
#include "packet_ptr.h"
#include <cqdaq/packet_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <coretypes/number_ptr.h>
#include <coretypes/objectptr.h>
#include <coretypes/type_manager_ptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IDataPacket>
class GenericDataPacketPtr;

using DataPacketPtr = daq::GenericDataPacketPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IDataPacket>
{
    using SmartPtr = daq::GenericDataPacketPtr<daq::IDataPacket>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_data_packet Data packet
 * @{

 */


/*!
 * @brief Packet that contains data sent by a signal. The data can be either explicit, or implicit.

 * Explicit data is contained within a signal's buffer, accessible through `getRawData`, while implicit
 * packets do not carry any data. Their values are calculated given a rule, packet offset, and the index of
 * a sample within the data buffer.
 * To obtain implicitly calculated, or scaled values, `getData` should be used. The data descriptor and sample
 * count provide information about the type and amount of data available at the obtained address.
 */
template <typename InterfaceType>
class GenericDataPacketPtr : public GenericPacketPtr<InterfaceType>
{
public:
    using GenericPacketPtr<InterfaceType>::GenericPacketPtr;
    //using GenericPacketPtr<InterfaceType>::operator=;



    GenericDataPacketPtr()
        : GenericPacketPtr<InterfaceType>()

    {
    }

    GenericDataPacketPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : GenericPacketPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericDataPacketPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : GenericPacketPtr<InterfaceType>(ptr)

    {
    }

    GenericDataPacketPtr(const DataPacketPtr& other)
        : GenericPacketPtr<InterfaceType>(other)

    {
    }

    GenericDataPacketPtr(DataPacketPtr&& other) noexcept
        : GenericPacketPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericDataPacketPtr& operator=(const DataPacketPtr& other)
    {
        if (this == &other)
            return *this;

        GenericPacketPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericDataPacketPtr& operator=(DataPacketPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericPacketPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the signal descriptor of the signal that sent the packet at the time of sending.

     * @returns The signal descriptor.
     */
    daq::DataDescriptorPtr getDataDescriptor() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DataDescriptorPtr descriptor;
        auto errCode = this->object->getDataDescriptor(&descriptor);
        daq::checkErrorInfo(errCode);

        return descriptor;
    }


    /*!
     * @brief Gets the number of samples in the packet.

     * @returns the number of samples.
     */
    daq::SizeT getSampleCount() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT sampleCount;
        auto errCode = this->object->getSampleCount(&sampleCount);
        daq::checkErrorInfo(errCode);

        return sampleCount;
    }


    /*!
     * @brief Gets current packet offset. This offset is later applied to the data rule used by a signal to calculate
     * actual data value. This value is usually a time or other domain value. Packet offset is particularly useful when
     * one wants to transfer a gap in otherwise equidistant samples.
     * If we have a linear data rule, defined by equation f(x) = k*x + n, then the data value will be calculated
     * by the equation g(x) = offset + f(x).

     * @returns The packet offset
     */
    daq::NumberPtr getOffset() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::NumberPtr offset;
        auto errCode = this->object->getOffset(&offset);
        daq::checkErrorInfo(errCode);

        return offset;
    }


    /*!
     * @brief Gets the calculated/scaled data address of the packet.

     * @returns The address of the data.
     * `getData` uses the packet's data descriptor to calculate the values as follows:
     * 1. If the data rule is implicit, it uses the packet offset and sample count to calculate the data according to the rule.
     * 2. If the data rule is explicit:
     * - If the data is a Struct, it returns a pointer to the raw data.
     * - If no Post scaling is defined, it simply returns a pointer to the raw data.
     * - If the Post scaling is defined, it scales the data and returns a pointer to the scaled data.
     * The data should be cast to the appropriate type, as defined by the data descriptor, and read while keeping the
     * data dimensions in mind.
     */
    void* getData() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        void* address;
        auto errCode = this->object->getData(&address);
        daq::checkErrorInfo(errCode);

        return address;
    }


    /*!
     * @brief Gets a pointer to the raw packet data. `nullptr` if the signal's data rule is implicit.

     * @returns Pointer to the raw packet data.
     */
    void* getRawData() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        void* address;
        auto errCode = this->object->getRawData(&address);
        daq::checkErrorInfo(errCode);

        return address;
    }


    /*!
     * @brief Gets size of data buffer in bytes.

     * @returns the size of data buffer in bytes.
     */
    daq::SizeT getDataSize() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT dataSize;
        auto errCode = this->object->getDataSize(&dataSize);
        daq::checkErrorInfo(errCode);

        return dataSize;
    }


    /*!
     * @brief Gets size of raw data buffer in bytes.

     * @param[out] dataSize the size of raw data buffer in bytes.
     * Raw data size is 0 if signal's data rule is implicit.
     */
    daq::SizeT getRawDataSize() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT rawDataSize;
        auto errCode = this->object->getRawDataSize(&rawDataSize);
        daq::checkErrorInfo(errCode);

        return rawDataSize;
    }


    /*!
     * @brief Gets the associated domain Data packet.

     * @returns The domain data packet.
     */
    daq::GenericDataPacketPtr<daq::IDataPacket> getDomainPacket() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::GenericDataPacketPtr<daq::IDataPacket> packet;
        auto errCode = this->object->getDomainPacket(&packet);
        daq::checkErrorInfo(errCode);

        return packet;
    }


    /*!
     * @brief Gets the unique packet id.

     * @returns The packet unique id.
     * The packet id is automatically created on packet construction.
     */
    daq::Int getPacketId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Int packetId;
        auto errCode = this->object->getPacketId(&packetId);
        daq::checkErrorInfo(errCode);

        return packetId;
    }


    /*!
     * @brief Gets the data packet last value

     * @returns The IBaseObject value can be a nullptr if there is no value, or if the data type is not supported by the function.
     * @param typeManager Optional ITypeManager value can be provided to enable getLastValue for IStruct.
     * If a value is assigned, it can be cast based on the signal description to IFloat if the type is Float32 or Float64,
     * to IInteger if the type is Int8 through Int64 or UInt8 through UInt64, to IComplexNumber if the type is ComplexFloat32 or ComplexFloat64,
     * to IRange if the type is RangeInt64, to IStruct if the type is Struct, and to IList of the forementioned types if there is exactly
     * one dimension.
     */
    daq::BaseObjectPtr getLastValue(const daq::TypeManagerPtr& typeManager = nullptr) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::BaseObjectPtr value;
        auto errCode = this->object->getLastValue(&value, typeManager);
        daq::checkErrorInfo(errCode);

        return value;
    }

#if __has_include(<cqdaq/data_packet_ptr.custom.h>)
    #include <cqdaq/data_packet_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
