
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_functions
 * @defgroup types_procedure Procedure
 * @{
 */

/// Function pointer to callback without return value.
typedef ErrCode (*ProcCall)(IBaseObject*);

/*!
 * @brief Holds a callback function without return value.
 *
 * Represents a callable object without return value. The cqDAQ SDK uses this interface when
 * it needs to make a call back to the client.
 *
 * Although the implementation of this interface is provided by cqDAQ, C++ and other
 * bindings provide their implementation which allows passing function as a lambda
 * functions and other constructs.
 *
 * Available factories:
 * @code
 * // Creates a new Procedure object. Throws exception if not successful.
 * IFunction* Procedure_Create(ProcCall value)
 *
 * // Creates a new Procedure object. Returns error code if not successful.
 * ErrCode createProcedure(IFuncObject** obj, ProcCall value)
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(IProcedure, IBaseObject)
{
    /*!
     * @brief Calls the stored callback.
     * @param params Parameters passed to the callback.
     *
     * If the callback expects no parameters, the `params` parameter has to be `nullptr`. If it
     * expects a single parameter, pass any cqDAQ object as the `params` parameter.
     * If it expects multiple parameters, pass an IList<IBaseObject> as the `params` parameter.
     *
     */
    virtual ErrCode INTERFACE_FUNC dispatch(IBaseObject* params) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(LIBRARY_FACTORY, Procedure, IProcedure, createProcedure, ProcCall, value)

END_NAMESPACE_CQDAQ
