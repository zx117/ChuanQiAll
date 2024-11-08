//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:23.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/signal.h"
#include <cqdaq/component_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <coretypes/list_ptr.h>
#include <cqdaq/connection_ptr.h>
#include <coretypes/objectptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::ISignal>
class GenericSignalPtr;

using SignalPtr = daq::GenericSignalPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::ISignal>
{
    using SmartPtr = daq::GenericSignalPtr<daq::ISignal>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_signals
 * @addtogroup cqdaq_signal Signal
 * @{

 */


/*!
 * @brief A signal with an unique ID that sends event/data packets through connections to input ports
 * the signal is connected to.

 * A signal features an unique ID within a given device. It sends data along its signal path to all
 * connected input ports, if its set to be active via its active property.
 * A signal is visible, and its data is streamed to all clients connected to a device only if its public
 * property is set to `True`.
 * Each signal has a domain descriptor, which is set by the owner of the signal - most often a function
 * block or device. The descriptor defines all properties of the signal, such as its name, description
 * and data structure.
 * Signals can have a reference to another signal, which is used for determining the domain data. The domain
 * signal outputs data at the same rate as the signal itself, providing domain (most often time - timestamps)
 * information for each sample sent along the signal path. Each value packet sent by a signal thus contains
 * a reference to another data packet containing domain data (if the signal is associated with another domain signal).
 * Additionally, a list of related signals can be defined, containing any signals relevant to interpreting the
 * signal data.
 * To get the list of connections to input ports of the signal, `getConnections` can be used.
 */
template <typename InterfaceType>
class GenericSignalPtr : public GenericComponentPtr<InterfaceType>
{
public:
    using GenericComponentPtr<InterfaceType>::GenericComponentPtr;
    //using GenericComponentPtr<InterfaceType>::operator=;



    GenericSignalPtr()
        : GenericComponentPtr<InterfaceType>()

    {
    }

    GenericSignalPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : GenericComponentPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericSignalPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : GenericComponentPtr<InterfaceType>(ptr)

    {
    }

    GenericSignalPtr(const SignalPtr& other)
        : GenericComponentPtr<InterfaceType>(other)

    {
    }

    GenericSignalPtr(SignalPtr&& other) noexcept
        : GenericComponentPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericSignalPtr& operator=(const SignalPtr& other)
    {
        if (this == &other)
            return *this;

        GenericComponentPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericSignalPtr& operator=(SignalPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericComponentPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Returns true if the signal is public; false otherwise.

     * @returns True if the signal is public; false otherwise.
     * Public signals are visible to clients connected to the device, and are streamed.
     */
    daq::Bool getPublic() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool isPublic;
        auto errCode = this->object->getPublic(&isPublic);
        daq::checkErrorInfo(errCode);

        return isPublic;
    }


    /*!
     * @brief Sets the signal to be either public or private.

     * @param isPublic If false, the signal is set to private; if true, the signal is set to be public.
     * Public signals are visible to clients connected to the device, and are streamed.
     */
    void setPublic(daq::Bool isPublic) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setPublic(isPublic);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the signal's data descriptor.

     * @returns The signal's data descriptor.
     * The descriptor contains metadata about the signal, providing information about its name, description,...
     * and defines how the data in it's packet's buffers should be interpreted.
     */
    daq::DataDescriptorPtr getDescriptor() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DataDescriptorPtr descriptor;
        auto errCode = this->object->getDescriptor(&descriptor);
        daq::checkErrorInfo(errCode);

        return descriptor;
    }


    /*!
     * @brief Gets the signal that carries its domain data.

     * @returns The domain signal.
     * The domain signal contains domain (most often time) data that is used to interpret a signal's data in
     * a given domain. It has the same sampling rate as the signal.
     */
    daq::SignalPtr getDomainSignal() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SignalPtr signal;
        auto errCode = this->object->getDomainSignal(&signal);
        daq::checkErrorInfo(errCode);

        return signal;
    }


    /*!
     * @brief Gets a list of related signals.

     * @returns The list of related signals.
     * Signals within the related signals list are facilitate the interpretation of a given signal's data, or
     * are otherwise relevant when working with the signal.
     */
    daq::ListPtr<daq::ISignal> getRelatedSignals() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::ISignal> signals;
        auto errCode = this->object->getRelatedSignals(&signals);
        daq::checkErrorInfo(errCode);

        return signals;
    }


    /*!
     * @brief Gets the list of connections to input ports formed by the signal.

     * @returns The list of connections.
     */
    daq::ListPtr<daq::IConnection> getConnections() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IConnection> connections;
        auto errCode = this->object->getConnections(&connections);
        daq::checkErrorInfo(errCode);

        return connections;
    }


    /*!
     * @brief Returns true if the signal is streamed; false otherwise.

     * @returns True if the signal is streamed; false otherwise.
     * A streamed signal receives packets from a streaming server and forwards packets on the signal path.
     * Method always sets `streamed` parameter to False if the signal is local to the current Instance.
     */
    daq::Bool getStreamed() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool streamed;
        auto errCode = this->object->getStreamed(&streamed);
        daq::checkErrorInfo(errCode);

        return streamed;
    }


    /*!
     * @brief Sets the signal to be either streamed or not.

     * @param streamed The new streamed state of the signal.
     * A streamed signal receives packets from a streaming server and forwards packets on the signal path.
     * Setting the "Streamed" flag has no effect if the signal is local to the current Instance.
     * Method returns CQDAQ_IGNORED if that is the case.
     */
    void setStreamed(daq::Bool streamed) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setStreamed(streamed);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the signal last value

     * @returns The IBaseObject value can be a nullptr if there is no value, or if the data type is not supported by the function.
     * If a value is assigned, it can be cast based on the signal description to IFloat if the type is Float32 or Float64,
     * to IInteger if the type is Int8 through Int64 or UInt8 through UInt64, to IComplexNumber if the type is ComplexFloat32 or ComplexFloat64,
     * to IRange if the type is RangeInt64, to IStruct if the type is Struct, and to IList of the forementioned types if there is exactly
     * one dimension.
     */
    daq::BaseObjectPtr getLastValue() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::BaseObjectPtr value;
        auto errCode = this->object->getLastValue(&value);
        daq::checkErrorInfo(errCode);

        return value;
    }

#if __has_include(<cqdaq/signal_ptr.custom.h>)
    #include <cqdaq/signal_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
