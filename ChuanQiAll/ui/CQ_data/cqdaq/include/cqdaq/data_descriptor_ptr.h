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
#include "cqdaq/data_descriptor.h"
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/list_ptr.h>
#include <cqdaq/dimension_ptr.h>
#include <coreobjects/unit_ptr.h>
#include <cqdaq/range_ptr.h>
#include <cqdaq/data_rule_ptr.h>
#include <coretypes/ratio_ptr.h>
#include <cqdaq/scaling_ptr.h>
#include <coretypes/dict_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class DataDescriptorPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IDataDescriptor>
{
    using SmartPtr = daq::DataDescriptorPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_signals
 * @addtogroup cqdaq_data_descriptor Data descriptor
 * @{

 */


/*!
 * @brief Describes the data sent by a signal, defining how they are to be interpreted by anyone receiving the signal's packets.

 * The data descriptor provides all information required on how to process data buffers, and how to interpret the data.
 * It contains the following fields:
 * - `Name`: A descriptive name of the data being described. In example, when the values describe the amplitude of spectrum data, the name
 * would be `Amplitude`.
 * - `Dimensions`: A list of dimensions of the signal. A sample descriptor can have 0 or more dimensions. A signal with 1 dimension
 * has vector data. A signal with 2 dimensions has matrix data, a signal with 0 has a single value for each sample.
 * - `SampleType`: An enum value that specifies the underlying data type (eg. Float64, Int32, String,...)
 * - `Unit`: The unit of the data in the signal's packets.
 * - `ValueRange`: The value range of the data in a signal's packets defining the lowest and highest expected values. The range is not
 * enforced.
 * - `Rule`: The data rule that defines how a signal value is calculated from an implicit initialization value when the rule type is not
 * `Explicit`.
 * - `Origin`: Defines the starting point of the signal. If set, all values are added to the absolute origin when read.
 * - `TickResolution`: Used to scale signal ticks into their physical unit. In example, a resolution of 1/1000 with the unit being `seconds`
 * states that a value of 1 correlates to 1 millisecond.
 * - `PostScaling`: Defines a scaling transformation, which should be applied to data carried by the signal's packets when read. If
 * `PostScaling` is used, the `Rule`, `Resolution`, and `Origin` must not be configured. The `SampleType` must match the
 * `outputDataType` of the `PostScaling`.
 * - `StructFields`: A list of DataDescriptor. The descriptor list is used to define complex data samples. When defined, the sample
 * buffer is laid out so that the data described by the first DataDescriptor is at the start, followed by the data
 * described by the second and so on. If the list is not empty, all descriptor parameters except for `Name` and
 * `Dimensions` should not be configured. See below for a explanation of Structure data descriptors.
 * @subsection data_descriptor_dimensions Dimensions
 * The list of dimensions determines the rank of values described by the descriptor. In example, if the list contains 1 dimension, the data
 * values are vectors. If it contains 2, the data values are matrices, if 0, the descriptor describes a single value.
 * When the data is placed into packet buffers, the values are laid out in packet buffers linearly, where each value fills up
 * `sizeof(sampleType) * (dimensionSize1 * dimensionSize2 *...)` bytes.
 * Data descriptor objects implement the Struct methods internally and are Core type `ctStruct`.
 * @subsection data_descriptor_struct_fields Struct fields
 * A DataDescriptor with the `StructFields` field filled with other descriptors is used to represent signal data in the form of structures.
 * It allows for custom and complex structures to be described and sent by a signal.
 * When evaluating a struct descriptor, their struct field values are laid out in the packet buffers in the order they are placed in
 * the `structFields` list. Eg. a struct with 3 fields, of types [int64_t, float, double] will have a buffer composed of an int64_t value,
 * followed by a float, and lastly a double value.
 * Note that if the Dimensions field of the DataDescriptor is not empty, struct data can also be of a higher rank
 * (eg. a vector/matrix of structs).
 * @subsection data_descriptor_calculation_order Value calculation
 * Besides the struct fields and dimensions, the Value descriptor also provides 4 fields which need to be taken into account and calculated
 * when reading packet buffers: `Rule`, `Resolution`, `Origin`, and `PostScaling`.
 * @subsubsection data_descriptor_calculation_without_scaling Without `PostScaling`
 * 1. Check and apply `Rule`:
 * - If the rule is `explicit`, the values of a packet are present in the packet's data buffer
 * - If not `explicit`, the packet's values need to be calculated. To calculate them, take the PacketOffset and SampleCount of the
 * packet. Use the PacketOffset, as well as the index of the sample in a packet to calculate the rule's output value: `Value = PacketOffset + Rule(Index)`.
 * Eg. `Value = PacketOffset + Delta * Index + Start`
 * 2. Apply `TickResolution`:
 * - If the `TickResolution` is set, multiply the value from 1. with the `Resolution`. This scales the value into the `Unit` of the value
 * descriptor.
 * - If not set, keep the value from 1.
 * 3. Add `Origin`:
 * - If the `Origin` is set, take the value from 2. and add it to the `Origin`.
 * In example, if using the Unix Epoch, a value `1669279690` in seconds would mean Thursday, 24 November 2022 08:48:10 GMT.
 * - If not set, keep the value from 2.
 * @subsubsection data_descriptor_calculation_with_scaling With `PostScaling`
 * If `PostScaling` is set, the `Rule` must be explicit, while `Resolution` and `Origin` must not be configured.
 * To calculate the value with `PostScaling` configured, take the values of the packet's data buffer and apply the post scaling to each
 * value in the buffer: `Value = PostScaling(Value)`, eg. `Value = Value * Scale + Offset`
 */

class DataDescriptorPtr : public daq::ObjectPtr<IDataDescriptor>
{
public:
    using daq::ObjectPtr<IDataDescriptor>::ObjectPtr;
    //using daq::ObjectPtr<IDataDescriptor>::operator=;



    DataDescriptorPtr()
        : daq::ObjectPtr<IDataDescriptor>()

    {
    }

    DataDescriptorPtr(daq::ObjectPtr<IDataDescriptor>&& ptr)
        : daq::ObjectPtr<IDataDescriptor>(std::move(ptr))

    {
    }

    DataDescriptorPtr(const daq::ObjectPtr<IDataDescriptor>& ptr)
        : daq::ObjectPtr<IDataDescriptor>(ptr)

    {
    }

    DataDescriptorPtr(const DataDescriptorPtr& other)
        : daq::ObjectPtr<IDataDescriptor>(other)

    {
    }

    DataDescriptorPtr(DataDescriptorPtr&& other) noexcept
        : daq::ObjectPtr<IDataDescriptor>(std::move(other))

    {
    }
    
    DataDescriptorPtr& operator=(const DataDescriptorPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IDataDescriptor>::operator =(other);


        return *this;
    }

    DataDescriptorPtr& operator=(DataDescriptorPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IDataDescriptor>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets a descriptive name of the signal value.

     * @returns The name of the signal value.
     * When, for example, describing the amplitude values of spectrum data, the name would be `Amplitude`.
     */
    daq::StringPtr getName() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr name;
        auto errCode = this->object->getName(&name);
        daq::checkErrorInfo(errCode);

        return name;
    }


    /*!
     * @brief Gets the list of the descriptor's dimension's.

     * @returns The list of dimensions.
     * The number of dimensions defines the rank of the signal's data (eg. Vector, Matrix).
     */
    daq::ListPtr<daq::IDimension> getDimensions() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IDimension> dimensions;
        auto errCode = this->object->getDimensions(&dimensions);
        daq::checkErrorInfo(errCode);

        return dimensions;
    }


    /*!
     * @brief Gets the descriptor's sample type.

     * @returns The descriptor's sample type.
     */
    daq::SampleType getSampleType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SampleType sampleType;
        auto errCode = this->object->getSampleType(&sampleType);
        daq::checkErrorInfo(errCode);

        return sampleType;
    }


    /*!
     * @brief Gets the unit of the data in a signal's packets.

     * @returns The unit specified by the descriptor.
     */
    daq::UnitPtr getUnit() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::UnitPtr unit;
        auto errCode = this->object->getUnit(&unit);
        daq::checkErrorInfo(errCode);

        return unit;
    }


    /*!
     * @brief Gets the value range of the data in a signal's packets defining the lowest and highest expected values.

     * @returns The value range the signal's data.
     * The range is not enforced by cqDAQ.
     */
    daq::RangePtr getValueRange() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::RangePtr range;
        auto errCode = this->object->getValueRange(&range);
        daq::checkErrorInfo(errCode);

        return range;
    }


    /*!
     * @brief Gets the value Data rule.

     * @returns The value Data rule.
     * If explicit, the values will be contained in the packet buffer. Otherwise they are calculated
     * using the offset packet parameter as the input into the rule.
     */
    daq::DataRulePtr getRule() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DataRulePtr rule;
        auto errCode = this->object->getRule(&rule);
        daq::checkErrorInfo(errCode);

        return rule;
    }


    /*!
     * @brief Gets the absolute origin of a signal value component.

     * @returns The absolute origin.
     * An origin can be an arbitrary string that determines the starting point of the signal data.
     * All explicit or implicit values are multiplied by the resolution and added to the origin to obtain
     * absolute data instead of relative.
     * Most commonly a time reference is used, in which case it should be formatted according to the ISO 8601 standard.
     */
    daq::StringPtr getOrigin() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr origin;
        auto errCode = this->object->getOrigin(&origin);
        daq::checkErrorInfo(errCode);

        return origin;
    }


    /*!
     * @brief Gets the Resolution which scales the explicit or implicit value to the physical unit defined in `unit`.
     * It is defined as domain (usually time) between two consecutive ticks.

     * @returns The Resolution.
     */
    daq::RatioPtr getTickResolution() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::RatioPtr tickResolution;
        auto errCode = this->object->getTickResolution(&tickResolution);
        daq::checkErrorInfo(errCode);

        return tickResolution;
    }


    
    daq::ScalingPtr getPostScaling() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ScalingPtr scaling;
        auto errCode = this->object->getPostScaling(&scaling);
        daq::checkErrorInfo(errCode);

        return scaling;
    }

    /*!
     * @brief Gets the fields of the struct, forming a recursive value descriptor definition.

     * @returns The list of data descriptors forming the struct fields.
     * Contains a list of value descriptors, defining the data layout: the data described by the first DataDescriptor
     * of the list is at the start, followed by the data described by the second and so on.
     */
    daq::ListPtr<daq::IDataDescriptor> getStructFields() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IDataDescriptor> structFields;
        auto errCode = this->object->getStructFields(&structFields);
        daq::checkErrorInfo(errCode);

        return structFields;
    }


    /*!
     * @brief Gets any extra metadata defined by the data descriptor.

     * @returns Additional metadata of the descriptor as a dictionary.
     * All objects in the metadata dictionary must be key value pairs of <String, String>.
     */
    daq::DictPtr<daq::IString, daq::IString> getMetadata() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DictPtr<daq::IString, daq::IString> metadata;
        auto errCode = this->object->getMetadata(&metadata);
        daq::checkErrorInfo(errCode);

        return metadata;
    }


    /*!
     * @brief Gets the size of one sample in bytes.

     * @returns The size of one sample in bytes.
     * The size of one sample is calculated on constructor of the data descriptor object.
     */
    daq::SizeT getSampleSize() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT sampleSize;
        auto errCode = this->object->getSampleSize(&sampleSize);
        daq::checkErrorInfo(errCode);

        return sampleSize;
    }


    /*!
     * @brief Gets the actual sample size in buffer of one sample in bytes.

     * @param[out] sampleSize The actual size of one sample in buffer in bytes.
     * The actual size of one sample is calculated on constructor of the data descriptor object.
     * Actual sample size is the sample size that is used in buffer. If the data descriptor includes
     * implicitly generated samples, the actual sample size is less than sample size.
     */
    daq::SizeT getRawSampleSize() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT rawSampleSize;
        auto errCode = this->object->getRawSampleSize(&rawSampleSize);
        daq::checkErrorInfo(errCode);

        return rawSampleSize;
    }

#if __has_include(<cqdaq/data_descriptor_ptr.custom.h>)
    #include <cqdaq/data_descriptor_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_data_descriptor_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ