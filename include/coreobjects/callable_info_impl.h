#pragma once

#include <coretypes/intfs.h>
#include <coreobjects/callable_info.h>
#include <coreobjects/argument_info_ptr.h>
#include <coretypes/list_factory.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class CallableInfoImpl : public GenericStructImpl<ICallableInfo, IStruct>
{
public:
    CallableInfoImpl(ListPtr<IArgumentInfo> arguments, CoreType returnType);

    ErrCode INTERFACE_FUNC getReturnType(CoreType* type) override;
    ErrCode INTERFACE_FUNC getArguments(IList** argumentInfo) override;
    
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    CoreType returnType{};
    ListPtr<IArgumentInfo> arguments;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(CallableInfoImpl)

END_NAMESPACE_CQDAQ
