
#pragma once
#include <coretypes/complex_number_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

inline ComplexNumberPtr ComplexNumber()
{
    return ComplexNumberPtr(ComplexNumber_Create(0, 0));
}

inline ComplexNumberPtr ComplexNumber(const Float real, const Float imaginary)
{
    return ComplexNumberPtr(ComplexNumber_Create(real, imaginary));
}

inline StructTypePtr ComplexNumberStructType()
{
    return StructType("complexNumber",
                      List<IString>("real", "imaginary"),
                      List<IFloat>(0.0, 0.0),
                      List<IType>(SimpleType(ctFloat), SimpleType(ctFloat)));
}

END_NAMESPACE_CQDAQ
