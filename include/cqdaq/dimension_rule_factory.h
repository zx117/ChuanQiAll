
#pragma once
#include <cqdaq/dimension_rule_builder_ptr.h>
#include <cqdaq/dimension_rule_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

// TODO: Allow linear and log rule start to be defined as range.

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_dimension_rule
 * @addtogroup cqdaq_dimension_rule_factories Factories
 * @{
 */

/*!
 * @brief Creates a Rule with a Linear rule type configuration.
 *
 * @param delta Coefficient by which the input data is to be multiplied.
 * @param start Constant that is added to the <em>scale * value</em> multiplication result.
 * @param size The size of the dimension described by the rule
 *
 * The scale and offset are stored within the `parameters` member of the Rule object
 * with the scale being at the first position of the list, and the offset at the second.
 */
inline DimensionRulePtr LinearDimensionRule(const NumberPtr& delta,
                                            const NumberPtr& start,
                                            const SizeT& size)
{
    DimensionRulePtr obj(LinearDimensionRule_Create(delta, start, size));

    return obj;
}

/*!
 * @brief Creates a Rule with a List rule type configuration.
 *
 * @param list The list of dimension labels.
 *
 * The list is stored within the `parameters` member of the Rule object.
 */
inline DimensionRulePtr ListDimensionRule(const ListPtr<INumber>& list)
{
    DimensionRulePtr obj(ListDimensionRule_Create(list));
    return obj;
}

/*!
 * @brief Creates a Rule with a Logarithmic rule type configuration.
 *
 * @param delta Coefficient by which the input data is to be multiplied.
 * @param start Constant that is added to the <em>scale * value</em> multiplication result.
 * @param base The base of the logarithm.
 * @param size The size of the dimension described by the rule.
 */
inline DimensionRulePtr LogarithmicDimensionRule(const NumberPtr& delta,
                                                 const NumberPtr& start,
                                                 const NumberPtr& base,
                                                 const SizeT& size)
{
    DimensionRulePtr obj(LogarithmicDimensionRule_Create(delta, start, base, size));
    return obj;
}

/*!
 * @brief Creates a Rule with a given type and parameters.
 *
 * @param type The type of the Dimension rule
 * @param parameters Tha parameters of the Dimension rule
 */
inline DimensionRulePtr DimensionRule(DimensionRuleType type, const DictPtr<IString, IBaseObject> parameters)
{
    DimensionRulePtr obj(DimensionRule_Create(type, parameters));
    return obj;
}

/*!
 * @brief Creates a Data rule builder with no parameters.
 */
inline DimensionRuleBuilderPtr DimensionRuleBuilder()
{
    DimensionRuleBuilderPtr obj(DimensionRuleBuilder_Create());
    return obj;
}


/*!
 * @brief Dimension rule copy factory that creates a builder Rule object from a possibly non-configurable Rule.
 * @param ruleToCopy The rule of which configuration should be copied.
 */
inline DimensionRuleBuilderPtr DimensionRuleBuilderCopy(const DimensionRulePtr& rule)
{
    DimensionRuleBuilderPtr obj(DimensionRuleBuilderFromExisting_Create(rule));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Dimension rule struct.
 */
inline StructTypePtr DimensionRuleStructType()
{
    return StructType("dimensionRule",
                      List<IString>("ruleType", "parameters"),
                      List<IBaseObject>(0, Dict<IString, IBaseObject>()),
                      List<IType>(SimpleType(ctInt), SimpleType(ctDict)));
}

/*!
 * @brief Creates a DimensionRule using Builder
 * @param builder DimensionRule Builder
 */
inline DimensionRulePtr DimensionRuleFromBuilder(const DimensionRuleBuilderPtr& builder)
{
    DimensionRulePtr obj(DimensionRuleFromBuilder_Create(builder));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
