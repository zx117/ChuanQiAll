#pragma once
#include <coreobjects/property.h>
#include <coreobjects/property_object.h>

BEGIN_NAMESPACE_CQDAQ


/*!
 * @ingroup objects_property_object
 * @addtogroup objects_property_object_obj PropertyObjectInternal
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IPropertyObjectInternal, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC checkForReferences(IProperty* property, Bool* isReferenced) = 0;
    virtual ErrCode INTERFACE_FUNC enableCoreEventTrigger() = 0;
    virtual ErrCode INTERFACE_FUNC disableCoreEventTrigger() = 0;
    virtual ErrCode INTERFACE_FUNC getCoreEventTrigger(IProcedure** trigger) = 0;
    virtual ErrCode INTERFACE_FUNC setCoreEventTrigger(IProcedure* trigger) = 0;
    virtual ErrCode INTERFACE_FUNC clone(IPropertyObject** cloned) = 0;
    virtual ErrCode INTERFACE_FUNC setPath(IString* path) = 0;
    virtual ErrCode INTERFACE_FUNC isUpdating(Bool* updating) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
