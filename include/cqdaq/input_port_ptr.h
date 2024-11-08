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
#include "cqdaq/input_port.h"
#include <cqdaq/component_ptr.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/connection_ptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IInputPort>
class GenericInputPortPtr;

using InputPortPtr = daq::GenericInputPortPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IInputPort>
{
    using SmartPtr = daq::GenericInputPortPtr<daq::IInputPort>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_input_port Input port
 * @{

 */


/*!
 * @brief Signals accepted by input ports can be connected, forming a connection between the input port
 * and signal, through which Packets can be sent.

 * Any cqDAQ object which wishes to receive signal data must create an input port and connect it to said
 * signals. Such objects are for example function blocks, and readers.
 * An input port can filter out incompatible signals by returning false when such a signal is passed as argument
 * to `acceptsSignal`, and also rejects the signals when they are passed as argument to `connect`.
 * Depending on the configuration, an input port might not require a signal to be connected, returning false
 * when `requiresSignal` is called. Such input ports are usually a part of function blocks that do not require
 * a given signal to perform calculations.
 */
template <typename InterfaceType>
class GenericInputPortPtr : public GenericComponentPtr<InterfaceType>
{
public:
    using GenericComponentPtr<InterfaceType>::GenericComponentPtr;
    //using GenericComponentPtr<InterfaceType>::operator=;



    GenericInputPortPtr()
        : GenericComponentPtr<InterfaceType>()

    {
    }

    GenericInputPortPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : GenericComponentPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericInputPortPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : GenericComponentPtr<InterfaceType>(ptr)

    {
    }

    GenericInputPortPtr(const InputPortPtr& other)
        : GenericComponentPtr<InterfaceType>(other)

    {
    }

    GenericInputPortPtr(InputPortPtr&& other) noexcept
        : GenericComponentPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericInputPortPtr& operator=(const InputPortPtr& other)
    {
        if (this == &other)
            return *this;

        GenericComponentPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericInputPortPtr& operator=(InputPortPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericComponentPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Returns true if the signal can be connected to the input port; false otherwise.

     * @param signal The signal being evaluated for compatibility.
     * @returns True if the signal can be connected; false otherwise.
     * @throws NotAssignedException if the accepted signal criteria is not defined by the input port.
     */
    daq::Bool acceptsSignal(const daq::SignalPtr& signal) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool accepts;
        auto errCode = this->object->acceptsSignal(signal, &accepts);
        daq::checkErrorInfo(errCode);

        return accepts;
    }


    /*!
     * @brief Connects the signal to the input port, forming a Connection.

     * @param signal The signal to be connected to the input port.
     * @throws CqdaqErrException if the signal is not accepted.
     * @throws NotAssignedException if the accepted signal criteria is not defined by the input port.
     * The signal is notified of the connection formed between it and the input port.
     */
    void connect(const daq::SignalPtr& signal) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->connect(signal);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Disconnects the signal from the input port.

     */
    void disconnect() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->disconnect();
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the signal connected to the input port.

     * @returns The signal connected to the input port.
     */
    daq::SignalPtr getSignal() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SignalPtr signal;
        auto errCode = this->object->getSignal(&signal);
        daq::checkErrorInfo(errCode);

        return signal;
    }


    /*!
     * @brief Returns true if the input port requires a signal to be connected; false otherwise.

     * @returns True if the input port requires a signal to be connected; false otherwise.
     */
    daq::Bool getRequiresSignal() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool requiresSignal;
        auto errCode = this->object->getRequiresSignal(&requiresSignal);
        daq::checkErrorInfo(errCode);

        return requiresSignal;
    }


    /*!
     * @brief Gets the Connection object formed between the Signal and Input port.

     * @returns The Connection object.
     */
    daq::ConnectionPtr getConnection() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ConnectionPtr connection;
        auto errCode = this->object->getConnection(&connection);
        daq::checkErrorInfo(errCode);

        return connection;
    }

#if __has_include(<cqdaq/input_port_ptr.custom.h>)
    #include <cqdaq/input_port_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
