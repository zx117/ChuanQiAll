
#pragma once
#include <cqdaq/server_type_ptr.h>
#include <coretypes/function_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup structure_server_type
 * @addtogroup structure_server_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a ServerTypeConfigPtr pointer, with the id, name, description and
 * optional createDefaultConfigCallback.
 * @param id The unique type ID of the server.
 * @param name The name of the server type.
 * @param description A short description of the server type.
 * @param createDefaultConfigCallback The callback, which is called, when user want to create new default
 * configuration object.
 * Function needs to create and return property object. On each call, we need to create new object,
 * because we want that each instance of the server has its own configuration object.
 */
inline ServerTypePtr ServerType(const StringPtr& id,
                                      const StringPtr& name,
                                      const StringPtr& description,
                                      const FunctionPtr& createDefaultConfigCallback = nullptr)
{
    ServerTypePtr obj(ServerType_Create(id, name, description, createDefaultConfigCallback));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Server type struct.
 */
inline StructTypePtr ServerTypeStructType()
{
    return StructType("serverType",
                      List<IString>("id", "name", "description"),
                      List<IString>("", "", ""),
                      List<IType>(SimpleType(ctString), SimpleType(ctString), SimpleType(ctString)));
}

/*!@}*/
        
END_NAMESPACE_CQDAQ
