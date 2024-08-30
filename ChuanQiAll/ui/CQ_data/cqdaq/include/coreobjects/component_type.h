#pragma once
#include <coreobjects/property_object.h>
#include <coretypes/stringobject.h>
#include <coretypes/function.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [templated(defaultAliasName: ComponentTypePtr)]
 * [interfaceSmartPtr(IComponentType, GenericComponentTypePtr)]
 */

/*!
 * @ingroup objects_utility
 * @addtogroup objects_component_type Component type
 * @{
 */

/*!
 * @brief Provides information about the component types.
 *
 * Is a Struct core type, and has access to Struct methods internally. Note that the Default config is not part of
 * the Struct fields.
 */

DECLARE_CQDAQ_INTERFACE(IComponentType, IBaseObject)
{
    /*!
     * @brief Gets the unique component type id.
     * @param[out] id The unique id of a component type.
     *
     * Unique id should not be presented on the UI.
     */
    virtual ErrCode INTERFACE_FUNC getId(IString** id) = 0;

    /*!
     * @brief Gets the user-friendly name of a component.
     * @param[out] name The user-friendly name of a component.
     *
     * Name is usually presented on the UI. Does not have to be unique.
     */
    virtual ErrCode INTERFACE_FUNC getName(IString** name) = 0;

    /*!
     * @brief Gets the description of a component.
     * @param[out] description The description of a component.
     *
     * A short description of a component and it's parameters.
     */
    virtual ErrCode INTERFACE_FUNC getDescription(IString** description) = 0;

    /*!
     * @brief The function creates and returns default configuration. On each call, we need to create new object,
     * because we want that each instance of the component has its own configuration object.
     * @param[out] defaultConfig Newly created configuration object.
     *
     * Configuration objects are property object with user-defined key-value pairs.
     * For example: DefaultPort=1000, OutputRate=5000, ...
     */
    virtual ErrCode INTERFACE_FUNC createDefaultConfig(IPropertyObject** defaultConfig) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
