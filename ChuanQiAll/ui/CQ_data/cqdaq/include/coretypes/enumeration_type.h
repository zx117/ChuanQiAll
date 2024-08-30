
#pragma once
#include <coretypes/common.h>
#include <coretypes/type.h>
#include <coretypes/dictobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_enumerations
 * @defgroup types_enumerations_enumeration_type EnumerationType
 * @{
 */

/*#
 * [interfaceSmartPtr(IType, GenericTypePtr, "<coretypes/type_ptr.h>")]
 */
/*!
 * @brief Enumeration types define the enumerator names and values of Enumerations with a name matching
 * that of the Enumeration type.
 *
 * An Enumeration type provides a String-type name, a list of enumerator names (list of Strings) and
 * a list of enumerator values (list of Integer objects). To use Enumeration types for creating Enumeration
 * objects, they must be added to the Type Manager. Alternatively, if an Enumeration is created without
 * a matching Enumeration type in the manager, a default Enumeration type is generated based on the
 * enumerator names and values of the created Enumeration object. This generated Enumeration type is then
 * added to the Type Manager.
 *
 * The enumerator values are represented as a list of Integer objects. These values can be explicitly specified
 * during Enumeration type creation, or only the first enumerator value can be specified, with the rest
 * automatically assigned in ascending order, starting from that value (or from the default '0' value if not
 * specified).
 */
DECLARE_CQDAQ_INTERFACE(IEnumerationType, IType)
{
    // [elementType(names, IString)]
    /*!
     * @brief Gets the list of enumerator names.
     * @param[out] names The list of enumerator names (String objects)
     */
    virtual ErrCode INTERFACE_FUNC getEnumeratorNames(IList** names) = 0;

    // [elementType(dictionary, IString, IInteger)]
    /*!
     * @brief Gets the enumerator names and values as a Dictionary.
     * @param[out] dictionary The Dictionary object with enumerator names as keys, and enumerator values
     * as its values.
     */
    virtual ErrCode INTERFACE_FUNC getAsDictionary(IDict** dictionary) = 0;

    /*!
     * @brief Gets the value of enumerator with the specified name.
     * @param name The name of the enumerator (String object).
     * @param[out] value The integer value of the enumerator with the specified name.
     */
    virtual ErrCode INTERFACE_FUNC getEnumeratorIntValue(IString* name, Int* value) = 0;

    /*!
     * @brief Gets the number of enumerators within the Enumeration Type.
     * @param[out] count The number of enumerators within the Enumeration Type.
     */
    virtual ErrCode INTERFACE_FUNC getCount(SizeT* count) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, EnumerationType,
    IString*, typeName,
    IList*, enumeratorNames,
    Int, firstEnumeratorIntValue
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, EnumerationTypeWithValues, IEnumerationType,
    IString*, typeName,
    IDict*, enumerators
)

END_NAMESPACE_CQDAQ
