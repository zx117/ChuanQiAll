
#pragma once
#include <coretypes/simple_type.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ


/*!
 * @ingroup types_types_simple_type
 * @addtogroup types_types_simple_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a SimpleType from a given CoreType
 * @param coreType The core type that will be wrapped by the SimpleType
 */
inline ObjectPtr<ISimpleType> SimpleType(CoreType coreType)
{
    return {SimpleType_Create(coreType)};
}

/*!@}*/

END_NAMESPACE_CQDAQ
