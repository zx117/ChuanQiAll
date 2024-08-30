#pragma once

#include <coreobjects/argument_info.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class ArgumentInfoImpl : public GenericStructImpl<IArgumentInfo, IStruct>
{
public:
    ArgumentInfoImpl(StringPtr name, CoreType type);

    ErrCode INTERFACE_FUNC getName(IString** argName) override;
    ErrCode INTERFACE_FUNC getType(CoreType* type) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    StringPtr name;
    CoreType argType;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ArgumentInfoImpl)

END_NAMESPACE_CQDAQ
