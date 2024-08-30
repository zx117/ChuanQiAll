
#pragma once
#include <cqdaq/function_block_type_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_function_block_type
 * @addtogroup cqdaq_function_block_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a FunctionBlockType pointer, with the id, name, description and
 * optional createDefaultConfigCallback.
 * @param id The unique type ID of the function block.
 * @param name The name of the function block. Eg. FFT.
 * @param description A short description of the function block and its behaviour.
 * @param createDefaultConfigCallback The callback, which is called, when user want to create new
 * default configuration object.
 * Function needs to create and return property object. On each call, we need to create new object,
 * because we want that each instance of the function block has its own configuration object.
 */
inline FunctionBlockTypePtr FunctionBlockType(const StringPtr& id,
                                              const StringPtr& name,
                                              const StringPtr& description,
                                              const FunctionPtr& createDefaultConfigCallback = nullptr)
{
    FunctionBlockTypePtr obj(FunctionBlockType_Create(id, name, description, createDefaultConfigCallback));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Function block type struct.
 */
inline StructTypePtr FunctionBlockTypeStructType()
{
    return StructType("functionBlockType",
                      List<IString>("id", "name", "description"),
                      List<IString>("", "", ""),
                      List<IType>(SimpleType(ctString), SimpleType(ctString), SimpleType(ctString)));
}

/*!@}*/

END_NAMESPACE_CQDAQ
