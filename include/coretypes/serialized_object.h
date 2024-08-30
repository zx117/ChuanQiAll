
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/coretype.h>
#include <coretypes/stringobject.h>
#include <coretypes/function.h>

BEGIN_NAMESPACE_CQDAQ

struct IList;
struct ISerializedList;

/*!
 * @ingroup types_serialization
 * @defgroup types_serialized_object SerializedObject
 * @{
 */

DECLARE_CQDAQ_INTERFACE(ISerializedObject, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC readSerializedObject(IString* key, ISerializedObject** plainObj) = 0;
    virtual ErrCode INTERFACE_FUNC readSerializedList(IString* key, ISerializedList** list) = 0;
    virtual ErrCode INTERFACE_FUNC readList(IString* key, IBaseObject* context, IFunction* factoryCallback, IList** list) = 0;
    virtual ErrCode INTERFACE_FUNC readObject(IString* key, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj) = 0;
    virtual ErrCode INTERFACE_FUNC readString(IString* key, IString** string) = 0;
    virtual ErrCode INTERFACE_FUNC readBool(IString* key, Bool* boolean) = 0;
    virtual ErrCode INTERFACE_FUNC readFloat(IString* key, Float* real) = 0;
    virtual ErrCode INTERFACE_FUNC readInt(IString* key, Int* integer) = 0;
    virtual ErrCode INTERFACE_FUNC hasKey(IString* key, Bool* hasKey) = 0;
    virtual ErrCode INTERFACE_FUNC getKeys(IList** list) = 0;
    virtual ErrCode INTERFACE_FUNC getType(IString* key, CoreType* type) = 0;
    virtual ErrCode INTERFACE_FUNC isRoot(Bool* isRoot) = 0;
    virtual ErrCode INTERFACE_FUNC toJson(IString** jsonString) = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
