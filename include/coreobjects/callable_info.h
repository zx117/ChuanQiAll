#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/listobject.h>
#include <coretypes/coretype.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_utility
 * @addtogroup objects_callable_info CallableInfo
 * @{
 */

/*!
 * @brief Provides information about the argument count and types, as well as the return type of
 * Function/Procedure-type properties.
 *
 * A callable should be invoked with the parameter types specified in the `arguments` field, in the
 * order listed.
 *
 * A Procedure-type Property will not have a return type configured in its Callable info field.
 * 
 * Argument info objects implement the Struct methods internally and are Core type `ctStruct`.
 */
DECLARE_CQDAQ_INTERFACE(ICallableInfo, IBaseObject)
{
    /*!
     * @brief Gets the return type of the callable function.
     * @param[out] type The return type of the callable.
     */
    virtual ErrCode INTERFACE_FUNC getReturnType(CoreType* type) = 0;
    // [elementType(argumentInfo, IArgumentInfo)]
    /*!
     * @brief Gets the list of arguments the callable function/procedure expects.
     * @param[out] argumentInfo the list of arguments of type `ArgumentInfo`.
     */
    virtual ErrCode INTERFACE_FUNC getArguments(IList** argumentInfo) = 0;
};

/*!@}*/

/*!
 * @addtogroup objects_callable_info_factories Factories
 * @{
 */

/*!
 * @brief Creates a CallableInfo object with the specified arguments and return type.
 * @param argumentInfo The list of `ArgumentInfo` type argument information.
 * @param returnType The return type of the described callable object.
 */
CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, CallableInfo,
    IList*, argumentInfo,
    CoreType, returnType
);

/*!@}*/

END_NAMESPACE_CQDAQ
