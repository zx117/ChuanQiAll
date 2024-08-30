
#pragma once
#include <coretypes/dictobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_instance IConfigProvider
 * @{
 */

/*!
 * @brief Config provider is an interface that was made for populating an options dictionary of an instance builder from external sources
 * like a config file, environment variables, or command line arguments.
 * The process of population of the dictionary have to be alligned with rules:
 * - all keys are set in lowercase. Values are set without case changes.
 * - if a provider is trying to override an existing value, it has to have the same type. For example provider can not replace integer value with string or object with list
 * - if a provider is overriding a list, it replaces old list items with a new one. 
 */
DECLARE_CQDAQ_INTERFACE(IConfigProvider, IBaseObject)
{
    // [returnSelf]
    // [templateType(options, IString, IBaseObject)]
    /*!
     * @brief Populate the existing options dictionary with variables from config provider
     * @param options The options dictionary
     */
    virtual ErrCode INTERFACE_FUNC populateOptions(IDict* options) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, JsonConfigProvider, IConfigProvider, IString*, filename)
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, EnvConfigProvider, IConfigProvider)
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, CmdLineArgsConfigProvider, IConfigProvider, IList*, cmdLineArgs)

END_NAMESPACE_CQDAQ
