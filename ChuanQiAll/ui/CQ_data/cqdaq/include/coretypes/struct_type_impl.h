
#pragma once
#include <coretypes/struct_type_ptr.h>
#include <coretypes/type_impl.h>
#include <coretypes/listobject_factory.h>
#include <coretypes/stringobject_factory.h>
#include <coretypes/serialized_object_ptr.h>
#include <coretypes/deserializer.h>

BEGIN_NAMESPACE_CQDAQ

class StructTypeImpl : public GenericTypeImpl<IStructType>
{
public:
    explicit StructTypeImpl(StringPtr name, ListPtr<IString> names, ListPtr<IBaseObject> defaultValues, ListPtr<IType> types);
    explicit StructTypeImpl(StringPtr name, ListPtr<IString> names, ListPtr<IType> types);

    ErrCode INTERFACE_FUNC getFieldNames(IList** names) override;
    ErrCode INTERFACE_FUNC getFieldDefaultValues(IList** defaultValues) override;
    ErrCode INTERFACE_FUNC getFieldTypes(IList** types) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();

    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    ListPtr<IString> names;
    ListPtr<IBaseObject> defaultValues;
    ListPtr<IType> types;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(StructTypeImpl)

END_NAMESPACE_CQDAQ
