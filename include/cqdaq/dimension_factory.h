
#pragma once
#include <cqdaq/dimension_builder_ptr.h>
#include <cqdaq/dimension_ptr.h>
#include <coreobjects/unit_factory.h>
#include <cqdaq/dimension_rule_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_dimension
 * @addtogroup cqdaq_dimension_factories Factories
 * @{
 */

/*!
 * @brief Creates a Dimension Config object with no configuration parameters.
 */
inline DimensionBuilderPtr DimensionBuilder()
{
    DimensionBuilderPtr obj(DimensionBuilder_Create());
    return obj;
}

/*!
 * @brief Creates a dimension object of which labels and size are defined via rule.
 * @param rule The rule via which labels are defined.
 * @param unit The unit of the dimension's labels.
 * @param name The name the dimension.
 */
inline DimensionPtr Dimension(const DimensionRulePtr& rule,
                              const UnitPtr& unit = nullptr,
                              const StringPtr& name = "")
{
    DimensionPtr obj(Dimension_Create(rule, unit, name));
    return obj;
}

/*!
 * @brief Creates a Dimension using Builder
 * @param builder Dimension Builder
 */
inline DimensionPtr DimensionFromBuilder(const DimensionBuilderPtr& builder)
{
    DimensionPtr obj(DimensionFromBuilder_Create(builder));
    return obj;
}

/*!
 * @brief Creates a builder copy of the dimension object passed as parameter.
 * @param dimension The dimension object to be copied.
 */
inline DimensionBuilderPtr DimensionBuilderCopy(const DimensionPtr& dimension)
{
    DimensionBuilderPtr obj(DimensionBuilderFromExisting_Create(dimension));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Dimension struct.
 */
inline StructTypePtr DimensionStructType()
{
    return StructType("dimension",
                      List<IString>("name", "unit", "rule"),
                      List<IBaseObject>("", "", ""),
                      List<IType>(SimpleType(ctString), UnitStructType(), DimensionRuleStructType()));
}

/*!@}*/

END_NAMESPACE_CQDAQ
