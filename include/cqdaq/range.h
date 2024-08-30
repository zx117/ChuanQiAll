
#pragma once
#include <coretypes/number.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceLibrary(INumber, CoreTypes)]
 */

/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_range Range
 * @{
 */

/*!
 * @brief Describes a range of values between the `lowValue` and `highValue` boundaries.
 * 
 * Range objects implement the Struct methods internally and are Core type `ctStruct`.
 */
DECLARE_CQDAQ_INTERFACE(IRange, IBaseObject)
{
    /*!
     * @brief Gets the lower boundary value of the range.
     */
    virtual ErrCode INTERFACE_FUNC getLowValue(INumber** value) = 0;
    /*!
     * @brief Gets the upper boundary value of the range.
     */
    virtual ErrCode INTERFACE_FUNC getHighValue(INumber** value) = 0;
};
/*!@}*/

/*!
 * @ingroup cqdaq_range
 * @addtogroup cqdaq_range_factories Factories
 * @{
 */

/*!
 * @brief Creates a range object with specified low and high boundary values.
 * @param lowValue The lower boundary of the range.
 * @param highValue The upper boundary of the range.
 * @retval CQDAQ_ERR_RANGE_BOUNDARIES_INVALID if lowValue > highValue.
 */
CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, Range, INumber*, lowValue, INumber*, highValue)

/*!@}*/

END_NAMESPACE_CQDAQ
