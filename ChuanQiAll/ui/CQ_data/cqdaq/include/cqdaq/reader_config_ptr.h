//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:56:05.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/reader_config.h"
#include <coretypes/objectptr.h>
#include <coretypes/function_ptr.h>
#include <coretypes/list_ptr.h>
#include <cqdaq/input_port_config_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ReaderConfigPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IReaderConfig>
{
    using SmartPtr = daq::ReaderConfigPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_reader_config Reader config
 * @{

 */


/*!
 * @brief An interface providing access to a new reader in order to reuse the invalidated reader's settings and configuration.

 */

class ReaderConfigPtr : public daq::ObjectPtr<IReaderConfig>
{
public:
    using daq::ObjectPtr<IReaderConfig>::ObjectPtr;
    //using daq::ObjectPtr<IReaderConfig>::operator=;



    ReaderConfigPtr()
        : daq::ObjectPtr<IReaderConfig>()

    {
    }

    ReaderConfigPtr(daq::ObjectPtr<IReaderConfig>&& ptr)
        : daq::ObjectPtr<IReaderConfig>(std::move(ptr))

    {
    }

    ReaderConfigPtr(const daq::ObjectPtr<IReaderConfig>& ptr)
        : daq::ObjectPtr<IReaderConfig>(ptr)

    {
    }

    ReaderConfigPtr(const ReaderConfigPtr& other)
        : daq::ObjectPtr<IReaderConfig>(other)

    {
    }

    ReaderConfigPtr(ReaderConfigPtr&& other) noexcept
        : daq::ObjectPtr<IReaderConfig>(std::move(other))

    {
    }
    
    ReaderConfigPtr& operator=(const ReaderConfigPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IReaderConfig>::operator =(other);


        return *this;
    }

    ReaderConfigPtr& operator=(ReaderConfigPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IReaderConfig>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the transform function that will be called with the read value-data and currently valid Signal-Descriptor
     * giving the user the chance add a custom post-processing step.

     * @returns The function performing the post-processing or @c nullptr if not assigned.
     */
    daq::FunctionPtr getValueTransformFunction() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::FunctionPtr transform;
        auto errCode = this->object->getValueTransformFunction(&transform);
        daq::checkErrorInfo(errCode);

        return transform;
    }


    /*!
     * @brief Gets the transform function that will be called with the read domain-data and currently valid Signal-Descriptor
     * giving the user the chance add a custom post-processing step.

     * @returns The function performing the post-processing or @c nullptr if not assigned.
     */
    daq::FunctionPtr getDomainTransformFunction() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::FunctionPtr transform;
        auto errCode = this->object->getDomainTransformFunction(&transform);
        daq::checkErrorInfo(errCode);

        return transform;
    }


    /*!
     * @brief Gets the internally created input-ports if used.

     * @returns The internal Input-Ports if used by the reader otherwise @c nullptr.
     */
    daq::ListPtr<daq::IInputPortConfig> getInputPorts() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IInputPortConfig> ports;
        auto errCode = this->object->getInputPorts(&ports);
        daq::checkErrorInfo(errCode);

        return ports;
    }


    /*!
     * @brief Gets the type of time-out handling used by the reader.

     * @returns How the reader handles time-outs.
     */
    daq::ReadTimeoutType getReadTimeoutType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ReadTimeoutType timeoutType;
        auto errCode = this->object->getReadTimeoutType(&timeoutType);
        daq::checkErrorInfo(errCode);

        return timeoutType;
    }


    /*!
     * @brief Marks the current reader as invalid preventing any additional operations to be performed on the reader
     * except reusing its info and configuration in a new reader.

     */
    void markAsInvalid() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->markAsInvalid();
        daq::checkErrorInfo(errCode);
    }

#if __has_include(<cqdaq/reader_config_ptr.custom.h>)
    #include <cqdaq/reader_config_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ