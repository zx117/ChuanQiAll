
#pragma once
#include <coretypes/common.h>
#include <coretypes/coretype.h>
#include <coretypes/stringobject.h>
#include <coretypes/function.h>

BEGIN_NAMESPACE_CQDAQ

struct IList;
struct ISerializedObject;

/*!
 * @ingroup types_serialization
 * @defgroup types_serialized_list SerializedList
 * @{
 */

DECLARE_CQDAQ_INTERFACE(ISerializedList, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC readSerializedObject(ISerializedObject** plainObj) = 0;
    virtual ErrCode INTERFACE_FUNC readSerializedList(ISerializedList** list) = 0;
    virtual ErrCode INTERFACE_FUNC readList(IBaseObject* context, IFunction* factoryCallback, IList** list) = 0;
    virtual ErrCode INTERFACE_FUNC readObject(IBaseObject* context, IFunction* factoryCallback, IBaseObject * *obj) = 0;
    virtual ErrCode INTERFACE_FUNC readString(IString** string) = 0;
    virtual ErrCode INTERFACE_FUNC readBool(Bool* boolean) = 0;
    virtual ErrCode INTERFACE_FUNC readFloat(Float* real) = 0;
    virtual ErrCode INTERFACE_FUNC readInt(Int* integer) = 0;
    virtual ErrCode INTERFACE_FUNC getCount(SizeT* size) = 0;
    virtual ErrCode INTERFACE_FUNC getCurrentItemType(CoreType* size) = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
