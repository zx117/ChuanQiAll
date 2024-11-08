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
#include "cqdaq/component_status_container.h"
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/enumeration_ptr.h>
#include <coretypes/dict_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ComponentStatusContainerPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IComponentStatusContainer>
{
    using SmartPtr = daq::ComponentStatusContainerPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component_status_container Component status container
 * @{

 */


/*!
 * @brief A container of Component Statuses and their corresponding values.

 * Each status has a unique name and represents an actual status related to the cqDAQ Component,
 * such as connection status, synchronization status, etc. The statuses' values are represented
 * by Enumeration objects.
 */

class ComponentStatusContainerPtr : public daq::ObjectPtr<IComponentStatusContainer>
{
public:
    using daq::ObjectPtr<IComponentStatusContainer>::ObjectPtr;
    //using daq::ObjectPtr<IComponentStatusContainer>::operator=;



    ComponentStatusContainerPtr()
        : daq::ObjectPtr<IComponentStatusContainer>()

    {
    }

    ComponentStatusContainerPtr(daq::ObjectPtr<IComponentStatusContainer>&& ptr)
        : daq::ObjectPtr<IComponentStatusContainer>(std::move(ptr))

    {
    }

    ComponentStatusContainerPtr(const daq::ObjectPtr<IComponentStatusContainer>& ptr)
        : daq::ObjectPtr<IComponentStatusContainer>(ptr)

    {
    }

    ComponentStatusContainerPtr(const ComponentStatusContainerPtr& other)
        : daq::ObjectPtr<IComponentStatusContainer>(other)

    {
    }

    ComponentStatusContainerPtr(ComponentStatusContainerPtr&& other) noexcept
        : daq::ObjectPtr<IComponentStatusContainer>(std::move(other))

    {
    }
    
    ComponentStatusContainerPtr& operator=(const ComponentStatusContainerPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IComponentStatusContainer>::operator =(other);


        return *this;
    }

    ComponentStatusContainerPtr& operator=(ComponentStatusContainerPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IComponentStatusContainer>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the the current value of Component status with a given name.

     * @param name The name of Component status.
     * @returns The current value of Component status.
     */
    daq::EnumerationPtr getStatus(const daq::StringPtr& name) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::EnumerationPtr value;
        auto errCode = this->object->getStatus(name, &value);
        daq::checkErrorInfo(errCode);

        return value;
    }


    /*!
     * @brief Gets the current values of all Component statuses.

     * @returns The Component statuses as a dictionary.
     * All objects in the statuses dictionary are key value pairs of <IString, IEnumeration>.
     */
    daq::DictPtr<daq::IString, daq::IEnumeration> getStatuses() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DictPtr<daq::IString, daq::IEnumeration> statuses;
        auto errCode = this->object->getStatuses(&statuses);
        daq::checkErrorInfo(errCode);

        return statuses;
    }

#if __has_include(<cqdaq/component_status_container_ptr.custom.h>)
    #include <cqdaq/component_status_container_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
