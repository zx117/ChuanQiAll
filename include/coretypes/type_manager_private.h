
#pragma once
#include <coretypes/procedure.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_types
 * @defgroup types_types_type_manager Type manager private
 * @{
 */
DECLARE_CQDAQ_INTERFACE(ITypeManagerPrivate, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC setCoreEventCallback(IProcedure* callback) = 0;
};

/*!@}*/



END_NAMESPACE_CQDAQ
