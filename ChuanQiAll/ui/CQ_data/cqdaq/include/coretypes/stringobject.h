
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_containers
 * @defgroup types_string String
 * @{
 */

/*!
 * Represents string variable as `IString` interface. Use this interface to wrap string
 * variable when you need to add the variable to lists, dictionaries and other containers which
 * accept `IBaseObject` and derived interfaces.
 *
 * Available factories:
 * @code
 * // Creates a new String object. Throws exception if not successful.
 * IString* String_Create(ConstCharPtr value)
 *
 * // Creates a new String object with predefined length. Returns error code if not successful.
 * ErrCode createString(IString** obj, ConstCharPtr value)
 *
 * // Creates a new String object with predefined length. Throws exception if not successful.
 * IString* StringN_Create(ConstCharPtr data, SizeT length)
 *
 * // Creates a new String object. Returns error code if not successful.
 * ErrCode createStringN(IString** obj, ConstCharPtr data, SizeT length)
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(IString, IBaseObject)
{
    /*!
     * @brief Gets a string value stored in the object.
     * @param[out] value Stored string value.
     * @return CQDAQ_SUCCESS if succeeded, error code otherwise.
     *
     * Call this method to extract the string value that is stored in the object. Method extracts the
     * value as a pointer to 8-bit char type.
     */
    virtual ErrCode INTERFACE_FUNC getCharPtr(ConstCharPtr* value) = 0;

    /*!
     * @brief Gets length of string.
     * @param[out] size The size of the string.
     * @return CQDAQ_SUCCESS if succeeded, error code otherwise.
     *
     * Call this method to get the length of the string. Null char terminator is not included in
     * the size of the string.
     */
    virtual ErrCode INTERFACE_FUNC getLength(SizeT* size) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, String, ConstCharPtr, str)
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(
    LIBRARY_FACTORY,
    StringN,
    IString,
    createStringN,
    ConstCharPtr, str,
    SizeT, length
)

END_NAMESPACE_CQDAQ
