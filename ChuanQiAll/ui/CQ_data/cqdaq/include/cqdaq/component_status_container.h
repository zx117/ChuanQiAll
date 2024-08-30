
#pragma once

#include <coretypes/coretypes.h>
#include <cqdaq/context.h>
#include <coretypes/event.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IEnumeration, EnumerationPtr, "<coretypes/enumeration_ptr.h>")]
 */

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component_status_container Component status container
 * @{
 */

/*!
 * @brief A container of Component Statuses and their corresponding values.
 *
 * Each status has a unique name and represents an actual status related to the cqDAQ Component,
 * such as connection status, synchronization status, etc. The statuses' values are represented
 * by Enumeration objects.
 */
DECLARE_CQDAQ_INTERFACE(IComponentStatusContainer, IBaseObject)
{
    /*!
     * @brief Gets the the current value of Component status with a given name.
     * @param name The name of Component status.
     * @param[out] value The current value of Component status.
     */
    virtual ErrCode INTERFACE_FUNC getStatus(IString* name, IEnumeration** value) = 0;

    // [templateType(statuses, IString, IEnumeration)]
    /*!
     * @brief Gets the current values of all Component statuses.
     * @param[out] statuses The Component statuses as a dictionary.
     *
     * All objects in the statuses dictionary are key value pairs of <IString, IEnumeration>.
     */
    virtual ErrCode INTERFACE_FUNC getStatuses(IDict** statuses) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, ComponentStatusContainer)

/*!@}*/

END_NAMESPACE_CQDAQ
