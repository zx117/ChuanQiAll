
#pragma once
#include <coretypes/common.h>
#include <coretypes/stringobject.h>
#include <coretypes/integer.h>
#include <coretypes/coretype.h>
#include <coretypes/type_manager.h>
#include <coretypes/enumeration_type.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_enumerations
 * @defgroup types_enumerations_enumeration Enumeration
 * @{
 */

/*!
 * @brief Enumerations are immutable objects that encapsulate a value within a predefined set of named integral constants.
 * These constants are predefined in an Enumeration type with the same name as the Enumeration.
 *
 * The Enumeration types are stored within a Type manager. In any given instance of cqDAQ, a single Type manager should
 * exist that is part of its Context.
 *
 * When creating an Enumeration object, the Type manager is used to validate the given enumerator value name against the
 * Enumeration type stored within the manager. If no type with the given Enumeration name is currently stored,
 * construction of the Enumeration object will fail. Similarly, if the provided enumerator value name is not part of
 * the Enumeration type, the construction of the Enumeration object will also fail.
 *
 * Since the Enumerations objects are immutable the value of an existing Enumeration object cannot be modified.
 * However, the Enumeration object encapsulated by a smart pointer of the corresponding type can be replaced
 * with a newly created one. This replacement is accomplished using the assignment operator with the right
 * operand being a constant string literal containing the enumerator value name valid for the Enumeration type
 * of the original Enumeration object.
 */
DECLARE_CQDAQ_INTERFACE(IEnumeration, IBaseObject)
{
    /*!
     * @brief Gets the Enumeration's type.
     * @param[out] type The Enumeration type
     */
    virtual ErrCode INTERFACE_FUNC getEnumerationType(IEnumerationType** type) = 0;

    /*!
     * @brief Gets the Enumeration value as String containing the name of the enumerator constant.
     * @param[out] value Emumeration value.
     */
    virtual ErrCode INTERFACE_FUNC getValue(IString** value) = 0;

    /*!
     * @brief Gets the Enumeration value as Integer enumerator constant.
     * @param[out] value Emumeration Integer value.
     */
    virtual ErrCode INTERFACE_FUNC getIntValue(Int* value) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, Enumeration,
    IString*, name,
    IString*, value,
    ITypeManager*, typeManager
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, EnumerationWithIntValue, IEnumeration,
    IString*, name,
    IInteger*, value,
    ITypeManager*, typeManager
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, EnumerationWithType, IEnumeration,
    IEnumerationType*, type,
    IString*, value
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, EnumerationWithIntValueAndType, IEnumeration,
    IEnumerationType*, type,
    IInteger*, value
)

END_NAMESPACE_CQDAQ
