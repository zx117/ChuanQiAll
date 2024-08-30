
#pragma once
#include <coretypes/type.h>
#include <coretypes/listobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_types
 * @defgroup types_types_type_manager Type manager
 * @{
 */

/*!
 * @brief Container for Type objects. The Type manager is used when creating certain types of objects
 * (eg. Structs and Property object classes). The Types stored within the manager contain pre-defined fields,
 * as well as constraints specifying how objects should look.
 *
 * The currently available types in cqDAQ that should be added to the Type manager are the Struct type
 * and the Property object class. The former is used to validate Structs when they are created, while the latter
 * contains pre-defined properties that are added to Property objects on construction.
 *
 * When adding a Property object class to the manager, they can form inheritance chains with one-another.
 * Thus, a parent of a given class must be added to the manager before any of its children. Likewise, a class
 * cannot be removed before its children are removed.
 */
DECLARE_CQDAQ_INTERFACE(ITypeManager, IBaseObject)
{
    /*!
     * @brief Adds a type to the manager.
     * @param type The Type to be added.
     * @retval CQDAQ_ERR_ALREADYEXISTS if a type with the same name is already added.
     * @retval CQDAQ_ERR_INVALIDPARAMETER if either the type name is an empty string.
     *
     * The type name must be unique and. If a Property object class specifies a parent class,
     * then the parent class must be added before it.
     */
    virtual ErrCode INTERFACE_FUNC addType(IType* type) = 0;
    
    /*!
     * @brief Removes the type from the manager.
     * @param typeName The type's name.
     * @retval CQDAQ_ERR_NOTFOUND if the class is not registered.
     *
     * The removed class must not be a parent of another added class. If it is, those classes must be removed
     * before it.
     */
    virtual ErrCode INTERFACE_FUNC removeType(IString* typeName) = 0;

    /*!
     * @brief Gets an added Type by name.
     * @param typeName The Type's name.
     * @param[out] type The Type with name equal to `name`.
     * @retval CQDAQ_ERR_NOTFOUND if a Type with the specified name is not added.
     */
    virtual ErrCode INTERFACE_FUNC getType(IString* typeName, IType** type) = 0;

    // [elementType(types, IString)]
    /*!
     * @brief Gets a list of all added Types.
     * @param[out] types The list of all added Types.
     */
    virtual ErrCode INTERFACE_FUNC getTypes(IList** types) = 0;

    /*!
     * @brief Checks if a type with the specified name is already added.
     * @param typeName The name of the checked type.
     * @param[out] hasType True if the type is aready added to the manager; False otherwise.
     */
    virtual ErrCode INTERFACE_FUNC hasType(IString* typeName, Bool* hasType) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, TypeManager)


END_NAMESPACE_CQDAQ
