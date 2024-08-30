
#pragma once

#include <coretypes/coretypes.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IEnumeration, EnumerationPtr, "<coretypes/enumeration_ptr.h>")]
 */

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component_status_container Component status container private
 * @{
 */

/*!
 * @brief Provides access to private methods of the Component status container.
 *
 * Said methods allow for adding new statuses and setting a value for existing statuses stored in
 * the component status container.
 *
 * Status changed Core events are triggered whenever there is a change in the status of the cqDAQ Component.
 */
DECLARE_CQDAQ_INTERFACE(IComponentStatusContainerPrivate, IBaseObject)
{
    /*!
     * @brief Adds the new status with given name and initial value.
     * @param name The name of the component status.
     * @param initialValue The initial value of the component status.
     */
    virtual ErrCode INTERFACE_FUNC addStatus(IString* name, IEnumeration* initialValue) = 0;

    /*!
     * @brief Sets the value for the existing component status.
     * @param name The name of the component status.
     * @param value The new value of the component status.
     */
    virtual ErrCode INTERFACE_FUNC setStatus(IString* name, IEnumeration* value) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
