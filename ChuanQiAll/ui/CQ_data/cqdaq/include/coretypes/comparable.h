
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_utility
 * @{
 */

/*!
 * @brief Enables comparison to another object.
 *
 * Use this interface to compare the object to another object. his interface is implemented by types
 * whose values can be ordered or sorted. It requires that implementing types define a single method,
 * `compareTo`, that indicates whether the position of the current instance in the sort order is before,
 * after, or the same as a second object of the same type.
 */

DECLARE_CQDAQ_INTERFACE(IComparable, IBaseObject)
{
    /*!
     * @brief Compares the object to another object.
     * @param obj Object for comparison.
     * @retval CQDAQ_LOWER The object's value is lower than the value of the compared object.
     * @retval CQDAQ_HIGHER The object's value is higher than the value of the compared object.
     * @retval CQDAQ_EQUAL The object's value is equal to the value of the compared object.
     *
     * Compares the current instance with another object of the same type and returns an integer that
     * indicates whether the current instance precedes, follows, or occurs in the same position in the
     * sort order as the other object. 
     */
    virtual ErrCode INTERFACE_FUNC compareTo(IBaseObject* obj) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
