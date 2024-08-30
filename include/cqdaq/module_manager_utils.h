
#pragma once
#include <cqdaq/module.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceLibrary(IPropertyObject, "coreobjects")]
 */

/*!
 * @ingroup cqdaq_modules
 * @addtogroup cqdaq_module_manager Module manager utils
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IModuleManagerUtils, IBaseObject)
{
    
    /*!
     * @brief Returns a list of known devices info.
     * The implementation can start discovery in background and only return the results in this function.
     * @param[out] availableDevices The list of known devices information.
     *
     * Contains information on devices available in all loaded modules.
     */
    // [elementType(availableDevices, IDeviceInfo)]
    virtual ErrCode INTERFACE_FUNC getAvailableDevices(IList** availableDevices) = 0;

    /*!
     * @brief Returns a dictionary of known and available device types this module can create.
     * @param[out] deviceTypes The dictionary of known device types.
     *
     * Contains information on devices available in all loaded modules.
     */
    // [templateType(deviceTypes, IString, IDeviceType)]
    virtual ErrCode INTERFACE_FUNC getAvailableDeviceTypes(IDict** deviceTypes) = 0;

    /*!
     * @brief Creates a device object that can communicate with the device described in the specified connection string.
     * The device object is not automatically added as a sub-device of the caller, but only returned by reference.
     * @param[out] device The device object created to communicate with and control the device.
     * @param connectionString Describes the connection info of the device to connect to.
     * @param parent The parent component/device to which the device attaches.
     * @param config A configuration object that contains parameters used to configure a device in the form of key-value pairs.
     *
     * Iterates through all loaded modules and creates a device with the first module that accepts the provided connection string.
     */
    virtual ErrCode INTERFACE_FUNC createDevice(IDevice** device, IString* connectionString, IComponent* parent, IPropertyObject* config = nullptr) = 0;

    /*!
     * @brief Returns a dictionary of known and available function block types this module can create.
     * @param[out] functionBlockTypes The dictionary of known function block types.
     *
     * Contains information on function blocks available in all loaded modules.
     */
    // [templateType(functionBlockTypes, IString, IFunctionBlockType)]
    virtual ErrCode INTERFACE_FUNC getAvailableFunctionBlockTypes(IDict** functionBlockTypes) = 0;

    /*!
     * @brief Creates and returns a function block with the specified id.
     * The function block is not automatically added to the FB list of the caller.
     * @param id The id of the function block to create. Ids can be retrieved by calling `getAvailableFunctionBlockTypes()`.
     * @param parent The parent component/device to which the device attaches.
     * @param config Function block configuration. In case of a null value, implementation should use default configuration.
     * @param localId Custom local ID for the function block. Overrides the "LocalId" property of the "config" object, if present.
     * @param[out] functionBlock The created function block.
     * 
     * Iterates through all loaded modules and creates a function block with the first module that accepts the provided connection string.
     * The local ID is equal to the name of the function block type with a "_n" suffix, where "n" is an integer, equal to that of the greatest
     * integer suffix amongst the function blocks of the same function block type already added to a given parent. The initial value of "n" is 0.
     * A custom local ID can be provided by adding a "LocalId" string property to the `config` property object input parameter, or by providing the
     * localId string argument.
     */
    virtual ErrCode INTERFACE_FUNC createFunctionBlock(IFunctionBlock** functionBlock, IString* id, IComponent* parent, IPropertyObject* config = nullptr, IString* localId = nullptr) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
