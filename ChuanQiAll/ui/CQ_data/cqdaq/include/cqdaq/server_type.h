
#pragma once
#include <coreobjects/component_type.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IComponentType, GenericComponentTypePtr, "<coreobjects/component_type_ptr.h>")]
 * [interfaceLibrary(IComponentType, "coreobjects")]
 */

/*!
 * @ingroup structure_servers
 * @addtogroup structure_server_type Server type
 * @{
 */

/*!
 * @brief Provides information about the server.
 */

DECLARE_CQDAQ_INTERFACE(IServerType, IComponentType)
{
};
/*!@}*/

/*!
 * @ingroup structure_server_type
 * @addtogroup structure_server_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a Server type object, with the id, name, description and
 * optional createDefaultConfigCallback.
 * @param id The unique type ID of the server.
 * @param name The name of the server type.
 * @param description A short description of the server type.
 * @param createDefaultConfigCallback The callback, which is called, when user want to create new default
 * configuration object.
 * Function needs to create and return property object. On each call, we need to create new object,
 * because we want that each instance of the server has its own configuration object.
 */
CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, ServerType,
    IString*, id,
    IString*, name,
    IString*, description,
    IFunction*, createDefaultConfigCallback
)

/*!@}*/

END_NAMESPACE_CQDAQ
