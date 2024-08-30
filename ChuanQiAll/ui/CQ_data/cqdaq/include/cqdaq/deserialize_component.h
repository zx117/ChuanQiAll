
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/serialized_object.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(IDeserializeComponent, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC deserializeValues(ISerializedObject* serializedObject, IBaseObject* context, IFunction* callbackFactory) = 0;
    virtual ErrCode INTERFACE_FUNC complete() = 0;
    virtual ErrCode INTERFACE_FUNC getDeserializedParameter(IString* parameter, IBaseObject** value) = 0;
};

END_NAMESPACE_CQDAQ
