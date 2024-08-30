
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_functions
 * @defgroup types_function Function
 * @{
 */

/// Function pointer to callback.
typedef ErrCode (*FuncCall)(IBaseObject*, IBaseObject**);

/*!
 * @brief Holds a callback function.
 *
 * Represents a callable object. The cqDAQ SDK uses this interface when it needs to make
 * a call back to the client.
 *
 * Although the implementation of this interface is provided by cqDAQ, C++ and other
 * bindings provide their implementation which allows passing function as a lambda
 * functions and other constructs.
 *  
 * Available factories:
 * @code
 * // Creates a new Function object. Throws exception if not successful.
 * IFunction* Function_Create(FuncCall value)
 *
 * // Creates a new Function object. Returns error code if not successful.
 * ErrCode createFunction(IFuncObject** obj, FuncCall value)
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(IFunction, IBaseObject)
{
    /*!
     * @brief Calls the stored callback.
     * @param params Parameters passed to the callback.
     * @param[out] result Return value of the callback.
     *
     * If the callback expects no parameters, the `params` parameter has to be `null`. If it
     * expects a single parameter, pass any cqDAQ object as the `params` parameter.
     * If it expects multiple parameters, pass an IList<IBaseObject> as the `params` parameter.
     *
     */
    virtual ErrCode INTERFACE_FUNC call(IBaseObject* params, IBaseObject** result) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(LIBRARY_FACTORY, Function, IFunction, createFunction, FuncCall, value)

END_NAMESPACE_CQDAQ
