
#pragma once
#include <coretypes/enumeration_type_ptr.h>
#include <coretypes/type_impl.h>
#include <coretypes/listobject_factory.h>
#include <coretypes/stringobject_factory.h>
#include <coretypes/serialized_object_ptr.h>
#include <coretypes/deserializer.h>

BEGIN_NAMESPACE_CQDAQ

class EnumerationTypeImpl : public GenericTypeImpl<IEnumerationType>
{
public:
    explicit EnumerationTypeImpl(StringPtr typeName, DictPtr<IString, IInteger> enumerators);
    explicit EnumerationTypeImpl(StringPtr typeName, ListPtr<IString> enumeratorNames, Int firstEnumeratorIntValue);

    // IEnumerationType
    ErrCode INTERFACE_FUNC getEnumeratorNames(IList** names) override;
    ErrCode INTERFACE_FUNC getAsDictionary(IDict** dictionary) override;
    ErrCode INTERFACE_FUNC getEnumeratorIntValue(IString* name, Int* value) override;
    ErrCode INTERFACE_FUNC getCount(SizeT* count) override;

    // IBaseObject
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    DictPtr<IString, IInteger> enumerators;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(EnumerationTypeImpl)

END_NAMESPACE_CQDAQ
