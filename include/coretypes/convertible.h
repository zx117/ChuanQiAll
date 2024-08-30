
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_utility
 * @{
 */

/*!
 * @brief Enables conversion of the object to either Int, Float, or Bool type.
 *
 * An object which implements `IIntObject` will typically also implement IConvertible,
 * which allows conversion to other types.
 *
 * Example:
 * @code
 * IIntObject* intObj = ...;
 * IConvertible* conv;
 * auto errCode = intObj.queryInterface(IConvertible::Id, reinterpret_cast<void**>(&conv));
 * if (CQDAQ_FAILED(errCode))
 *   return;
 *
 * Float val;
 * errCode = conv->toFloat(&val);
 * if (CQDAQ_FAILED(errCode))
 *   return;
 *
 * // print val
 * @endcode 
 */

DECLARE_CQDAQ_INTERFACE(IConvertible, IBaseObject)
{
    /*!
     * @brief Converts the object to Float type.
     * @param[out] val Float value.
     * @retval CQDAQ_ERR_CONVERSIONFAILED Conversion has failed
     */
    virtual ErrCode INTERFACE_FUNC toFloat(Float* val) = 0;
    /*!
     * @brief Converts the object to Int type.
     * @param[out] val Int value.
     * @retval CQDAQ_ERR_CONVERSIONFAILED Conversion has failed
     */
    virtual ErrCode INTERFACE_FUNC toInt(Int* val) = 0;
    /*!
     * @brief Converts the object to Bool type.
     * @param[out] val Bool value
     * @retval CQDAQ_ERR_CONVERSIONFAILED Conversion has failed
     */
    virtual ErrCode INTERFACE_FUNC toBool(Bool * val) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
