
#pragma once
#include <coretypes/common.h>
#include <coretypes/ratio_ptr.h>
#include <coretypes/simplified_ratio_ptr.h>
#include <coretypes/ctutils.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

inline RatioPtr Ratio(Int num, Int den)
{
    return RatioPtr(Ratio_Create(num, den));
}

inline SimplifiedRatioPtr SimplifiedRatio(Int num, Int den)
{
    simplify(num, den);
    return SimplifiedRatioPtr(Ratio_Create(num, den));
}

inline StructTypePtr RatioStructType()
{
    return StructType("ratio",
                      List<IString>("numerator", "denominator"),
                      List<Int>(0, 1),
                      List<IType>(SimpleType(ctInt), SimpleType(ctInt)));
}

END_NAMESPACE_CQDAQ
