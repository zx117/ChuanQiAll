
#pragma once
#include <coretypes/common.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_types
 * @defgroup types_types_type Type
 * @{
 */

/*#
 * [templated]
 */

/*!
 * @brief The base object type that is inherited by all Types (eg. Struct type, Simple type, Property object class)
 * in cqDAQ.
 * 
 * Types are used for the construction of objects that are require validation/have pre-defined fields such as
 * Structs and Property objects. Types should be inserted into the Type manager to be used by different parts
 * of the SDK.
 */
DECLARE_CQDAQ_INTERFACE(IType, IBaseObject)
{
    /*!
     * @brief Gets the name of the Type
     * @param[out] typeName The name of the Type.
     */
    virtual ErrCode INTERFACE_FUNC getName(IString** typeName) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
