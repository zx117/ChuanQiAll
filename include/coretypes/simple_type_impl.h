

#pragma once
#include <coretypes/simple_type.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/type_impl.h>
#include <string>
#include <coretypes/serialized_object_ptr.h>
#include <coretypes/deserializer.h>

BEGIN_NAMESPACE_CQDAQ

class SimpleTypeImpl : public GenericTypeImpl<ISimpleType>
{
public:
    SimpleTypeImpl(CoreType coreType);
    
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();

    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    static std::string coreTypeToString(CoreType coreType);
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(SimpleTypeImpl)

END_NAMESPACE_CQDAQ
