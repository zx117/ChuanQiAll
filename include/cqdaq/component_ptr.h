//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:19.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/component.h"
#include <cqdaq/removable.h>
#include <coretypes/event_wrapper.h>
#include <coreobjects/property_object_ptr.h>
#include <coretypes/string_ptr.h>
#include <cqdaq/context_ptr.h>
#include <cqdaq/tags_ptr.h>
#include <coretypes/list_ptr.h>
#include <coretypes/event_ptr.h>
#include <coreobjects/core_event_args_ptr.h>
#include <cqdaq/component_status_container_ptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IComponent>
class GenericComponentPtr;

using ComponentPtr = daq::GenericComponentPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IComponent>
{
    using SmartPtr = daq::GenericComponentPtr<daq::IComponent>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component Component
 * @{

 */


/*!
 * @brief Acts as a base interface for components, such as device, function block, channel and signal.

 * The IComponent provides a set of methods that are common to all components:
 * LocalID, GlobalID and Active properties.
 */
template <typename InterfaceType>
class GenericComponentPtr : public GenericPropertyObjectPtr<InterfaceType>
{
public:
    using GenericPropertyObjectPtr<InterfaceType>::GenericPropertyObjectPtr;
    //using GenericPropertyObjectPtr<InterfaceType>::operator=;



    GenericComponentPtr()
        : GenericPropertyObjectPtr<InterfaceType>()

    {
    }

    GenericComponentPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : GenericPropertyObjectPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericComponentPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : GenericPropertyObjectPtr<InterfaceType>(ptr)

    {
    }

    GenericComponentPtr(const ComponentPtr& other)
        : GenericPropertyObjectPtr<InterfaceType>(other)

    {
    }

    GenericComponentPtr(ComponentPtr&& other) noexcept
        : GenericPropertyObjectPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericComponentPtr& operator=(const ComponentPtr& other)
    {
        if (this == &other)
            return *this;

        GenericPropertyObjectPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericComponentPtr& operator=(ComponentPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericPropertyObjectPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the local ID of the component.

     * @returns The local ID of the component.
     * Represents the identifier that is unique in a relation to the
     * parent component. There is no predefined format for local ID. It is a string defined
     * by its parent component.
     */
    daq::StringPtr getLocalId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr localId;
        auto errCode = this->object->getLocalId(&localId);
        daq::checkErrorInfo(errCode);

        return localId;
    }


    /*!
     * @brief Gets the global ID of the component.

     * @returns The global ID of the component.
     * Represents the identifier that is globally unique. Globally unique identifier is composed
     * from local identifiers from the parent components separated by '/' character. Device component
     * must make sure that its ID is globally unique.
     */
    daq::StringPtr getGlobalId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr globalId;
        auto errCode = this->object->getGlobalId(&globalId);
        daq::checkErrorInfo(errCode);

        return globalId;
    }


    /*!
     * @brief Returns true if the component is active; false otherwise.

     * @returns True if the component is active; false otherwise.
     * An active component acquires data, performs calculations and send packets on the signal path.
     */
    daq::Bool getActive() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool active;
        auto errCode = this->object->getActive(&active);
        daq::checkErrorInfo(errCode);

        return active;
    }


    /*!
     * @brief Sets the component to be either active or inactive. Also recursively sets the `active` field
     * of all child components if component is a folder.

     * @param active The new active state of the component.
     * @returns nullptr if "Active" is part of the component's list of locked attributes,     * or if the new active value is equal to the previous.
     * An active component acquires data, performs calculations and send packets on the signal path.
     */
    void setActive(daq::Bool active) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setActive(active);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the context object.

     * @returns The context object.
     */
    daq::ContextPtr getContext() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ContextPtr context;
        auto errCode = this->object->getContext(&context);
        daq::checkErrorInfo(errCode);

        return context;
    }


    /*!
     * @brief Gets the parent of the component.

     * @returns The parent of the component.
     * Every cqDAQ component has a parent, except for instance. Parent should be passed as
     * a parameter to the constructor/factory. Once the component is created, the parent
     * cannot be changed.
     */
    daq::ComponentPtr getParent() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentPtr parent;
        auto errCode = this->object->getParent(&parent);
        daq::checkErrorInfo(errCode);

        return parent;
    }


    /*!
     * @brief Gets the name of the component.

     * @returns The name of the component. Local ID if name is not configured.
     * The object that implements this interface defines how the name is specified.
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
     * @brief Sets the name of the component.

     * @param name The name of the component.
     * @returns nullptr if "Name" is part of the component's list of locked attributes,     * or if the new name value is equal to the previous.
     * The object that implements this interface defines how the name is specified.
     */
    void setName(const daq::StringPtr& name) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setName(name);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the description of the component.

     * @returns The description of the component. Empty if not configured.
     * The object that implements this interface defines how the description is specified.
     */
    daq::StringPtr getDescription() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr description;
        auto errCode = this->object->getDescription(&description);
        daq::checkErrorInfo(errCode);

        return description;
    }


    /*!
     * @brief Sets the description of the component.

     * @param description The description of the component.
     * @returns nullptr if "Description" is part of the component's list of locked attributes,     * or if the new description value is equal to the previous.
     * The object that implements this interface defines how the description is specified.
     */
    void setDescription(const daq::StringPtr& description) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setDescription(description);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the tags of the component.

     * @returns The tags of the component.
     * Tags are user definable labels that can be attached to the component.
     */
    daq::TagsPtr getTags() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::TagsPtr tags;
        auto errCode = this->object->getTags(&tags);
        daq::checkErrorInfo(errCode);

        return tags;
    }


    /*!
     * @brief Gets `visible` metadata state of the component

     * @returns True if the component is visible; False otherwise.
     * Visible determines whether search/getter methods return find the component by default.
     */
    daq::Bool getVisible() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool visible;
        auto errCode = this->object->getVisible(&visible);
        daq::checkErrorInfo(errCode);

        return visible;
    }


    /*!
     * @brief Sets `visible` attribute state of the component

     * @param visible True if the component is visible; False otherwise.
     * @returns nullptr if "Visible" is part of the component's list of locked attributes.
     * Visible determines whether search/getter methods return find the component by default.
     */
    void setVisible(daq::Bool visible) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setVisible(visible);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets a list of the component's locked attributes. The locked attributes cannot be modified via their respective setters.

     * @returns A list of strings containing the names of locked attributes in capital case (eg. "Name", "Description").
     */
    daq::ListPtr<daq::IString> getLockedAttributes() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IString> attributes;
        auto errCode = this->object->getLockedAttributes(&attributes);
        daq::checkErrorInfo(errCode);

        return attributes;
    }


    /*!
     * @brief Gets the Core Event object that triggers whenever a change to this component happens within the cqDAQ core structure.

     * @returns The Core Event object. The event triggers with a Component reference and a CoreEventArgs object as arguments.
     * The Core Event is triggered on various changes to the cqDAQ Components. This includes changes to property values,
     * addition/removal of child components, connecting signals to input ports and others. The event type can be identified
     * via the event ID available within the CoreEventArgs object. Each event type has a set of predetermined parameters
     * available in the `parameters` field of the arguments. These can be used by any cqDAQ server, or other listener to
     * react to changes within the core structure.
     */
    daq::Event<daq::ComponentPtr, daq::CoreEventArgsPtr> getOnComponentCoreEvent() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        EventPtr<> event;
        auto errCode = this->object->getOnComponentCoreEvent(&event);
        daq::checkErrorInfo(errCode);

        return daq::Event<daq::ComponentPtr, daq::CoreEventArgsPtr>(event);
    }


    /*!
     * @brief Gets the container of Component statuses.

     * @returns The container of Component statuses.
     */
    daq::ComponentStatusContainerPtr getStatusContainer() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentStatusContainerPtr statusContainer;
        auto errCode = this->object->getStatusContainer(&statusContainer);
        daq::checkErrorInfo(errCode);

        return statusContainer;
    }


    /*!
     * @brief Finds the component (signal/device/function block) with the specified (global) id.

     * @param id The id of the component to search for.
     * @returns The resulting component.
     * If the component parameter is true, the starting component is the root device.
     * The id provided should be in relative form from the starting component. E.g., to find a signal in
     * the starting component, the id should be in the form of "dev/dev_id/ch/ch_id/sig/sig_id.
     */
    daq::ComponentPtr findComponent(const daq::StringPtr& id) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentPtr outComponent;
        auto errCode = this->object->findComponent(id, &outComponent);
        daq::checkErrorInfo(errCode);

        return outComponent;
    }

#if __has_include(<cqdaq/component_ptr.custom.h>)
    #include <cqdaq/component_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @ingroup cqdaq_component
 * @addtogroup cqdaq_component_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ
