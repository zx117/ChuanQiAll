
#pragma once
#include <cqdaq/dimension.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_signals
 * @addtogroup cqdaq_dimension Dimension
 * @{
 */

/*#
 * [interfaceLibrary(IUnit, CoreObjects)]
 */

/*!
 * @brief Configuration component of Dimension objects. Contains setter methods that allow for Dimension
 * parameter configuration, and a `build` method that builds the Dimension.
 */
DECLARE_CQDAQ_INTERFACE(IDimensionBuilder, IBaseObject)
{
    /*!
     * @brief Builds and returns a Dimension object using the currently set values of the Builder.
     * @param[out] dimension The built Dimension.
     */
    virtual ErrCode INTERFACE_FUNC build(IDimension** dimension) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the name of the dimension.
     * @param name The name of the dimension.
     *
     * The name that best describes the dimension, in example "Frequency" for spectrum data.
     */
    virtual ErrCode INTERFACE_FUNC setName(IString* name) = 0;

    /*!
     * @brief Gets the name of the dimension.
     * @param[out] name The name of the dimension.
     */
    virtual ErrCode INTERFACE_FUNC getName(IString** name) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the unit of the dimension's labels.
     * @param unit The unit of the dimension.
     */  
    virtual ErrCode INTERFACE_FUNC setUnit(IUnit* unit) = 0;

    /*!
     * @brief Gets the unit of the dimension's labels.
     * @param[out] unit The unit of the dimension.
     */
    virtual ErrCode INTERFACE_FUNC getUnit(IUnit** unit) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the rule that defines the labels and size of the dimension.
     * @param rule The dimension rule.
     * @retval CQDAQ_ERR_FROZEN if the dimension object is frozen.
     *
     * The rule takes as input the index of data value in a sample and produces a label associated
     * with that index.
     */
    virtual ErrCode INTERFACE_FUNC setRule(IDimensionRule* rule) = 0;

    /*!
     * @brief Gets the rule that defines the labels and size of the dimension.
     * @param[out] rule The dimension rule.
     */
    virtual ErrCode INTERFACE_FUNC getRule(IDimensionRule** rule) = 0;
};
/*!@}*/

/*!
 * @ingroup cqdaq_dimension
 * @addtogroup cqdaq_dimension_factories Factories
 * @{
 */

/*!
 * @brief Creates a Dimension builder object with no configuration parameters.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, DimensionBuilder, IDimensionBuilder)

/*!
 * @brief Creates a builder copy of the dimension object passed as parameter.
 * @param dimensionToCopy The dimension object to be copied.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, DimensionBuilderFromExisting, IDimensionBuilder,
    IDimension*, dimensionToCopy
)

/*!@}*/

END_NAMESPACE_CQDAQ
