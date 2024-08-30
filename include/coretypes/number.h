
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_numerics
 * @{
 */

/*!
 * @brief Represents either a float or an int number.
 *
 * Number is used if data type of the number is not strictly defined, i.e.
 * it can accept a float or an int.
 */
DECLARE_CQDAQ_INTERFACE(INumber, IBaseObject)
{
    /*!
     * @brief Gets a value stored in the object as a floating point value.
     * @param[out] value Stored value as a floating point.
     * @return CQDAQ_SUCCESS if succeeded, error code otherwise.
     */    
    virtual ErrCode INTERFACE_FUNC getFloatValue(Float* value) = 0;

    /*!
     * @brief Gets a value stored in the object as an integer value.
     * @param[out] value Stored value as an integer.
     * @return CQDAQ_SUCCESS if succeeded, error code otherwise.
     */
    virtual ErrCode INTERFACE_FUNC getIntValue(Int* value) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
