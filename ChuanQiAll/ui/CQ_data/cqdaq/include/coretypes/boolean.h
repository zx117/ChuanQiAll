
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_numerics
 * @{
 */

/*!
 * Represents boolean variable as `IBoolean` interface. Use this interface to wrap boolean
 * variable when you need to add the variable to lists, dictionaries and other containers which
 * accept `IBaseObject` interface.
 *
 * Available factories:
 * @code
 * // Creates a new Boolean. Throws exception if not successful.
 * IBoolean* Boolean_Create(Bool value)
 *
 * // Creates a new Boolean. Returns error code if not successful.
 * ErrCode createBoolean(IBoolean** obj, Bool value)
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(IBoolean, IBaseObject)
{
    /*!
     * @brief Gets a boolean value stored in the object.
     * @param[out] value Stored boolean value.
     * @return CQDAQ_SUCCESS if succeeded, error code otherwise.
     *
     * Call this method to extract the boolean value that is stored in the object.
     */
    virtual ErrCode INTERFACE_FUNC getValue(Bool* value) = 0;

    /*!
     * @brief Compares stored boolean value to the boolean parameter.
     * @param value Value for comparison.
     * @param[out] equal The result of the comparison.
     *
     * Call this method to directly compare the object to the boolean parameter.
     */
    virtual ErrCode INTERFACE_FUNC equalsValue(const Bool value, Bool* equal) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, Boolean, const Bool, value)
CQDAQ_DECLARE_CLASS_FACTORY_FUNC_WITH_INTERFACE(
    LIBRARY_FACTORY,
    BoolObject,
    IBoolean,
    const Bool,
    value
)

END_NAMESPACE_CQDAQ
