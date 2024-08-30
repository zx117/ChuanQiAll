#pragma once

#include <coreobjects/argument_info_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_argument_info
 * @addtogroup objects_argument_info_factories Factories
 * @{
 */

/*!
 * @brief Creates an Argument info object with the specified name and type.
 * @param name The name of the argument.
 * @param type The type expected of the argument.
 */
inline ArgumentInfoPtr ArgumentInfo(StringPtr name, CoreType type)
{
    return ArgumentInfoPtr::Adopt(ArgumentInfo_Create(name, type));
}

/*!
 * @brief Creates the Struct type object that defines the Argument info struct.
 */
inline StructTypePtr ArgumentInfoStructType()
{
    return StructType("argumentInfo",
                      List<IString>("name", "type"),
                      List<IBaseObject>("", static_cast<Int>(ctUndefined)),
                      List<IType>(SimpleType(ctString), SimpleType(ctInt)));
}

/*!@}*/

END_NAMESPACE_CQDAQ
