#pragma once
#include <coretypes/common.h>
#include <coretypes/function.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_property
 * @addtogroup objects_coercer Coercer
 * @{
 */

/*!
 * @brief Used by cqDAQ properties to coerce a value to match the restrictions imposed by the Property.
 *
 * Whenever a value is set to on a Property object, if the corresponding Property has a coercer configured, the value will
 * be evaluated and modified to fit the restrictions imposed by the coercer. For example, a coercer can enforce lower-than,
 * greater-than, equality, or other number relations on written values.
 *
 * The coercion conditions are configured with an evaluation string when the coercer is constructed. The string constructs an
 * Eval value that replaces any instance of the keyword "value" or "val" with the value being set. The result of the Eval
 * value evaluation is the output of the `coerce` function call. For example, coercers created with the string
 * "if(value > 5, 5, value)" would enforce that the property value is always equal to or lower than 5.
 */

DECLARE_CQDAQ_INTERFACE(ICoercer, IBaseObject)
{
    /*!
     * @brief Coerces `value` to match the coercion restrictions and outputs the result.
     * @param propObj Optional property object parameter required if the coercion depends on other properties of the Property object.
     * @param value The value to be coerced to fit the restrictions.
     * @param[out] result The coercer output containing the modified `value`.
     * @retval CQDAQ_ERR_COERCE_FAILED if `value` cannot be coerced to fit the restrictions.
     * @retval CQDAQ_SUCCESS If the value either already fits the restrictions, or was successfully modified to do so.
     */
    virtual ErrCode INTERFACE_FUNC coerce(IBaseObject* propObj, IBaseObject* value, IBaseObject** result) = 0;

    /*!
     * @brief Gets the string expression used when creating the coercer.
     * @param[out] eval The coercion expression.
     */
    virtual ErrCode INTERFACE_FUNC getEval(IString** eval) = 0;
};

/*!@}*/

/*!
 * @addtogroup objects_coercer_factories Factories
 * @{
 */

/*!
 * @brief Creates a Coercer with the given evaluation expression.
 * @param eval The evaluation expression used for coercion.
 */
CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, Coercer, IString*, eval)

/*!@}*/

END_NAMESPACE_CQDAQ
