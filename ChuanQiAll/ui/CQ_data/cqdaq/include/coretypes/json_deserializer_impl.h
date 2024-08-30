
#pragma once

#include <coretypes/intfs.h>
#include <coretypes/deserializer.h>
#include <coretypes/updatable.h>
#include <rapidjson/document.h>

BEGIN_NAMESPACE_CQDAQ

class JsonDeserializerImpl : public ImplementationOf<IDeserializer>
{
public:
    using JsonDocument = rapidjson::Document;
    using JsonValue = rapidjson::Value;
    using JsonList = rapidjson::GenericArray<false, JsonValue>;

    ErrCode INTERFACE_FUNC deserialize(IString* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** object) override;
    ErrCode INTERFACE_FUNC update(IUpdatable* updatable, IString* serialized) override;
    ErrCode INTERFACE_FUNC callCustomProc(IProcedure* customDeserialize, IString* serialized) override;

    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    static CoreType GetCoreType(const JsonValue& value) noexcept;
    static ErrCode Deserialize(JsonValue& document, IBaseObject* context, IFunction* factoryCallback, IBaseObject** object);

private:
    static ErrCode DeserializeTagged(JsonValue& document, IBaseObject* context, IFunction* factoryCallback, IBaseObject** object);
    static ErrCode DeserializeList(const JsonList& array, IBaseObject* context, IFunction* factoryCallback, IBaseObject** object);
};

END_NAMESPACE_CQDAQ
