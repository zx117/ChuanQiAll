#pragma once
#include <coretypes/type_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_types_type_manager
 * @defgroup types_types_type_manager_factories Factories
 * @{
 */

/*!
 * @brief Creates a new Type manager.
 * The Type manager should usually be created only as part of the Context creation.
 */
inline TypeManagerPtr TypeManager()
{
    TypeManagerPtr obj(TypeManager_Create());
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
