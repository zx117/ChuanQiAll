
#pragma once
#include <coretypes/enumeration_type_ptr.h>
#include <coretypes/listobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_enumerations_enumeration_type
 * @defgroup types_enumerations_enumeration_type_factories Factories
 * @{
 */

/*!
 * @brief Creates an Enumeration type with a given type name, enumerator names and first enumerator value.
 * Enumerator values are automatically assigned in ascending order, starting from the specified first value.
 * @param typeName The name of the Enumeration type
 * @param enumeratorNames The list of enumerator names (String objects)
 * @param firstEnumeratorIntValue The Int value of first enumerator (Integer)
 */
inline EnumerationTypePtr EnumerationType(
    const StringPtr& typeName,
    const ListPtr<IString>& enumeratorNames,
    const Int firstEnumeratorIntValue = 0)
{
    EnumerationTypePtr obj(EnumerationType_Create(typeName, enumeratorNames, firstEnumeratorIntValue));
    return obj;
}

/*!
 * @brief Creates an Enumeration type for enum with a given type name, and dictionary of enumerator names and
 * values.
 * @param typeName The name of the Enumeration type
 * @param enumerators The dictionary of enumerators (String objects as keys, Integer objects as values)
 */
inline EnumerationTypePtr EnumerationTypeWithValues(
    const StringPtr& typeName,
    const DictPtr<IString, IInteger>& enumerators)
{
    EnumerationTypePtr obj(EnumerationTypeWithValues_Create(typeName, enumerators));
    return obj;
}

/*!@}*/
END_NAMESPACE_CQDAQ
