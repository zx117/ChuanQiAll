
#pragma once
#include <coretypes/stringobject.h>
#include <coretypes/type.h>
#include <coretypes/coretype.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_types
 * @defgroup types_types_simple_type SimpleType
 * @{
 */

/*#
 * [templated(IType)]
 * [interfaceSmartPtr(IType, TypePtr)]
 */
/*!
 * @brief Simple type created from a CoreType. The name of the type matches that of the CoreType
 * used for its construction (eg. ctInt == "int"
 */
DECLARE_CQDAQ_INTERFACE(ISimpleType, IType)
{
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, SimpleType, ISimpleType,
    CoreType, coreType
)

END_NAMESPACE_CQDAQ
