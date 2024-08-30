
#pragma once
#include <coretypes/enumeration.h>
#include <coretypes/coretype.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/dictobject_factory.h>
#include <coretypes/baseobject_factory.h>
#include <coretypes/enumeration_ptr.h>
#include <coretypes/type_manager_ptr.h>
#include <coretypes/enumeration_type_factory.h>
#include <coretypes/stringobject_factory.h>
#include <coretypes/simple_type_factory.h>
#include <coretypes/deserializer.h>

BEGIN_NAMESPACE_CQDAQ

class EnumerationImpl : public ImplementationOf<IEnumeration, IConvertible, ICoreType, ISerializable>
{
public:
    explicit EnumerationImpl(const StringPtr& name, const BaseObjectPtr& value, const TypeManagerPtr& typeManager);
    explicit EnumerationImpl(const EnumerationTypePtr& type, const BaseObjectPtr& value);

    // IBaseObject
    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // IConvertible
    ErrCode INTERFACE_FUNC toFloat(Float* val) override;
    ErrCode INTERFACE_FUNC toInt(Int* val) override;
    ErrCode INTERFACE_FUNC toBool(Bool* val) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IEnumeration
    ErrCode INTERFACE_FUNC getEnumerationType(IEnumerationType** type) override;
    ErrCode INTERFACE_FUNC getValue(IString** value) override;
    ErrCode INTERFACE_FUNC getIntValue(Int* value) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

protected:
    EnumerationTypePtr enumerationType;
    StringPtr value;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(EnumerationImpl)

END_NAMESPACE_CQDAQ
