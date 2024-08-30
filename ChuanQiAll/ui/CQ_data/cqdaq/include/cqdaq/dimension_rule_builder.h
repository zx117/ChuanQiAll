
#pragma once
#include <cqdaq/dimension_rule.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_dimension
 * @addtogroup cqdaq_dimension_rule Dimension rule
 * @{
 */
    
/*!
 * @brief Configuration component of Dimension rule objects. Contains setter methods that allow for Dimension rule
 * parameter configuration, and a `build` method that builds the Dimension rule.
 */
DECLARE_CQDAQ_INTERFACE(IDimensionRuleBuilder, IBaseObject)
{
    /*!
     * @brief Builds and returns a Dimension rule object using the currently set values of the Builder.
     * @param[out] dataRule The built Dimension rule.
     */
    virtual ErrCode INTERFACE_FUNC build(IDimensionRule** dimensionRule) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the type of the dimension rule. Rule parameters must be configured to match the requirements of the rule type.
     * @param type The type of the dimension rule.
     *
     * The required rule parameters are as follows:
     *   - Linear: `delta`, `start`, and `size` number parameters. Calculated as: <em>index * delta + start</em> for `size` number of elements.
     *   - Logarithmic: `delta`, `start`, `base`, and `size` number parameters. Calculated as: <em>base ^ (index * delta + start)</em> for `size` number of elements.
     *   - List: `list` parameter. The list contains all dimension labels.
     */
    virtual ErrCode INTERFACE_FUNC setType(DimensionRuleType type) = 0;

    /*!
     * @brief Gets the type of the dimension rule.
     * @param[out] type The type of the dimension rule.
     */
    virtual ErrCode INTERFACE_FUNC getType(DimensionRuleType* type) = 0;

    // [templateType(parameters, IString, IBaseObject), returnSelf]
    /*!
     * @brief Sets a dictionary of string-object key-value pairs representing the parameters used to evaluate the rule.
     * @param parameters The dictionary containing the rule parameter members.
     */
    virtual ErrCode INTERFACE_FUNC setParameters(IDict* parameters) = 0;

    // [templateType(parameters, IString, IBaseObject)]
    /*!
     * @brief Gets a dictionary of string-object key-value pairs representing the parameters used to evaluate the rule.
     * @param[out] parameters The dictionary containing the rule parameter members.
     */
    virtual ErrCode INTERFACE_FUNC getParameters(IDict** parameters) = 0;

    // [returnSelf]
    /*!
     * @brief Adds a string-object pair parameter to the Dictionary of Dimension rule parameters.
     * @param name The string-type name of the parameter.
     * @param parameter The object-type parameter.
     */
    virtual ErrCode INTERFACE_FUNC addParameter(IString* name, IBaseObject* parameter) = 0;

    // [returnSelf]
    /*!
     * @brief Removes the parameter with the given name from the Dictionary of Dimension rule parameters.
     */
    virtual ErrCode INTERFACE_FUNC removeParameter(IString* name) = 0;
};
/*!@}*/

/*!
 * @ingroup cqdaq_dimension_rule
 * @addtogroup cqdaq_dimension_rule_factories Factories
 * @{
 */

/*!
 * @brief Creates a DataRuleConfig with no parameters.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, DimensionRuleBuilder, IDimensionRuleBuilder)

/*!
 * @brief Dimension rule copy factory that creates a builder Rule object from a possibly non-configurable Rule.
 * @param ruleToCopy The rule of which configuration should be copied.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, DimensionRuleBuilderFromExisting, IDimensionRuleBuilder,
    IDimensionRule*, ruleToCopy
)

/*!@}*/

END_NAMESPACE_CQDAQ
