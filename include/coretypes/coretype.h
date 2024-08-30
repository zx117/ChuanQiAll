
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ


/*!
 * @ingroup types_base_concepts
 * @defgroup types_core_type CoreType
 * @{
 */

/// Core type enumeration
enum CoreType : int
{
    ctBool = 0,             ///< Boolean, True or False
    ctInt,                  ///< 64 bit signed integer
    ctFloat,                ///< IEEE 754 64 bit floating point
    ctString,               ///< UTF8 zero terminated string
    ctList,                 ///< List of IBaseObject
    ctDict,                 ///< Dictionary of (key: IBaseObject, value: IBaseObject)
    ctRatio,                ///< Rational number (numerator / denominator)
    ctProc,                 ///< Callback without return value
    ctObject,               ///< Generic object
    ctBinaryData,           ///< Binary buffer with predefined size
    ctFunc,                 ///< Callback with return value
    ctComplexNumber,        ///< Complex number (real, imaginary)
    ctStruct,               ///< Constant structure with dictionary of fields and types
    ctEnumeration,          ///< Enumeration representing a predefined set of named integral constants
    ctUndefined = 0xFFFF,   ///< Undefined
};


/*!
 * @brief Adds the ability for cqDAQ objects to report what type of object they represent.
 *
 * An object can implement this interface to give clients introspection ability on the type
 * of the object. The client can use this information to further query for the interface of the
 * specific type. For example, if the `CoreType` reported is ctInt, the object is expected to
 * implement the IIntObject interface.
 */
DECLARE_CQDAQ_INTERFACE(ICoreType, IBaseObject)
{
    /*!
     * @brief Gets the object's CoreType.
     * @param[out] coreType The object's CoreType.
     */
    virtual ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
