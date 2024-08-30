
#pragma once
#include <cqdaq/range_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_range
 * @addtogroup cqdaq_range_factories Factories
 * @{
 */

/*!
 * @brief Creates a range object with specified low and high boundary values.
 * @param lowValue The lower boundary of the range.
 * @param highValue The upper boundary of the range.
 * @throws RangeBoundariesInvalidException if lowValue > highValue.
 */
inline RangePtr Range(const NumberPtr& lowValue, const NumberPtr& highValue)
{
    RangePtr obj(Range_Create(lowValue, highValue));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Range struct.
 */
inline StructTypePtr RangeStructType()
{
    return StructType("range",
                      List<IString>("lowValue", "highValue"),
                      List<INumber>(0, 1),
                      List<IType>(SimpleType(ctFloat), SimpleType(ctFloat)));
}
/*!@}*/

END_NAMESPACE_CQDAQ
