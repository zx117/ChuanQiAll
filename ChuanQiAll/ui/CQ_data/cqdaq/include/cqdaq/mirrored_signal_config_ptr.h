//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:36.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/mirrored_signal_config.h"
#include <cqdaq/signal_config_ptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/list_ptr.h>
#include <coretypes/event_ptr.h>
#include <cqdaq/subscription_event_args_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class MirroredSignalConfigPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IMirroredSignalConfig>
{
    using SmartPtr = daq::MirroredSignalConfigPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_streamings
 * @addtogroup cqdaq_streaming_signal Mirrored Signal
 * @{

 */


/*!
 * @brief Represents configuration interface for mirrored signals. Allows selecting streaming data sources per signal.

 */

class MirroredSignalConfigPtr : public GenericSignalConfigPtr<IMirroredSignalConfig>
{
public:
    using GenericSignalConfigPtr<IMirroredSignalConfig>::GenericSignalConfigPtr;
    //using GenericSignalConfigPtr<IMirroredSignalConfig>::operator=;



    MirroredSignalConfigPtr()
        : GenericSignalConfigPtr<IMirroredSignalConfig>()

    {
    }

    MirroredSignalConfigPtr(daq::ObjectPtr<IMirroredSignalConfig>&& ptr)
        : GenericSignalConfigPtr<IMirroredSignalConfig>(std::move(ptr))

    {
    }

    MirroredSignalConfigPtr(const daq::ObjectPtr<IMirroredSignalConfig>& ptr)
        : GenericSignalConfigPtr<IMirroredSignalConfig>(ptr)

    {
    }

    MirroredSignalConfigPtr(const MirroredSignalConfigPtr& other)
        : GenericSignalConfigPtr<IMirroredSignalConfig>(other)

    {
    }

    MirroredSignalConfigPtr(MirroredSignalConfigPtr&& other) noexcept
        : GenericSignalConfigPtr<IMirroredSignalConfig>(std::move(other))

    {
    }
    
    MirroredSignalConfigPtr& operator=(const MirroredSignalConfigPtr& other)
    {
        if (this == &other)
            return *this;

        GenericSignalConfigPtr<IMirroredSignalConfig>::operator =(other);


        return *this;
    }

    MirroredSignalConfigPtr& operator=(MirroredSignalConfigPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericSignalConfigPtr<IMirroredSignalConfig>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the global ID of the signal as it appears on the remote device.

     * @returns The signal id.
     */
    daq::StringPtr getRemoteId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr id;
        auto errCode = this->object->getRemoteId(&id);
        daq::checkErrorInfo(errCode);

        return id;
    }


    /*!
     * @brief Gets a list of connection strings of all available streaming sources of the signal.

     * @returns The list of streaming connection strings.
     */
    daq::ListPtr<daq::IString> getStreamingSources() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IString> streamingConnectionStrings;
        auto errCode = this->object->getStreamingSources(&streamingConnectionStrings);
        daq::checkErrorInfo(errCode);

        return streamingConnectionStrings;
    }


    /*!
     * @brief Sets the active streaming source of the signal.

     * @param streamingConnectionString The connection string of streaming source to be set as active.
     * @throws NotFoundException if the streaming source with the corresponding connection string is not     * part of the available streaming sources for the signal.
     */
    void setActiveStreamingSource(const daq::StringPtr& streamingConnectionString) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setActiveStreamingSource(streamingConnectionString);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets a connection strings of the active streaming source of the signal.

     * @returns The connection string of active streaming source.
     */
    daq::StringPtr getActiveStreamingSource() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr streamingConnectionString;
        auto errCode = this->object->getActiveStreamingSource(&streamingConnectionString);
        daq::checkErrorInfo(errCode);

        return streamingConnectionString;
    }


    /*!
     * @brief Stops the streaming and clears the active streaming source of the signal.

     */
    void deactivateStreaming() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->deactivateStreaming();
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the Event that is triggered whenever the acknowledgment for signal subscription
     * completion is received from the streaming server.

     * @returns The Event representing the acknowledgment of signal subscription completion.
     * A handler can be added to the event containing a callback function which is invoked whenever
     * the event is triggered. The callback function requires two parameters - a MirroredSignalConfig
     * object, as well as a "Subscription event args" object.
     * The callback will be invoked with the MirroredSignalConfig object as the first argument,
     * the second argument holds an event args object that contains the connection string of streaming
     * and the event type (Subscribed).
     */
    daq::Event<daq::MirroredSignalConfigPtr, daq::SubscriptionEventArgsPtr> getOnSubscribeComplete() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        EventPtr<> event;
        auto errCode = this->object->getOnSubscribeComplete(&event);
        daq::checkErrorInfo(errCode);

        return daq::Event<daq::MirroredSignalConfigPtr, daq::SubscriptionEventArgsPtr>(event);
    }


    /*!
     * @brief Gets the Event that is triggered whenever the acknowledgment for signal unsubscription
     * completion is received from the streaming server.

     * @returns The Event representing the acknowledgment of signal unsubscription completion.
     * A handler can be added to the event containing a callback function which is invoked whenever
     * the event is triggered. The callback function requires two parameters - a MirroredSignalConfig
     * object, as well as a "Subscription event args" object.
     * The callback will be invoked with the MirroredSignalConfig object as the first argument,
     * the second argument holds an event args object that contains the connection string of streaming
     * and the event type (Unsubscribed).
     */
    daq::Event<daq::MirroredSignalConfigPtr, daq::SubscriptionEventArgsPtr> getOnUnsubscribeComplete() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        EventPtr<> event;
        auto errCode = this->object->getOnUnsubscribeComplete(&event);
        daq::checkErrorInfo(errCode);

        return daq::Event<daq::MirroredSignalConfigPtr, daq::SubscriptionEventArgsPtr>(event);
    }

#if __has_include(<cqdaq/mirrored_signal_config_ptr.custom.h>)
    #include <cqdaq/mirrored_signal_config_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ