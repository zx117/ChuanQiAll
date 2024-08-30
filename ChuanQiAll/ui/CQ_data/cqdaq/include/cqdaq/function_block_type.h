

#pragma once
#include <coreobjects/component_type.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IComponentType, GenericComponentTypePtr, "<coreobjects/component_type_ptr.h>")]
 * [interfaceLibrary(IComponentType, "coreobjects")]
 */

/*!
 * @ingroup cqdaq_function_blocks
 * @addtogroup cqdaq_function_block_type Function block type
 * @{
 */

/*!
 * @brief Provides information about the function block.
 */
DECLARE_CQDAQ_INTERFACE(IFunctionBlockType, IComponentType)
{
};
/*!@}*/

/*!
 * @ingroup cqdaq_function_block_type
 * @addtogroup cqdaq_function_block_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a Function block type object, with the id, name, description and
 * optional createDefaultConfigCallback.
 * @param id The unique type ID of the function block.
 * @param name The name of the function block. Eg. FFT.
 * @param description A short description of the function block and its behaviour.
 * @param createDefaultConfigCallback The callback, which is called, when user want to create new
 * default configuration object.
 * Function needs to create and return property object. On each call, we need to create new object,
 * because we want that each instance of the function block has its own configuration object.
 */
CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, FunctionBlockType,
    IString*, id,
    IString*, name,
    IString*, description,
    IFunction*, createDefaultConfigCallback
)

/*!@}*/

END_NAMESPACE_CQDAQ
