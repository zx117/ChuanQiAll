
#pragma once
#include <coretypes/deserializer.h>
#include <coretypes/intfs.h>
#include <rapidjson/document.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class JsonSerializedObject : public ImplementationOf<ISerializedObject>
{
public:
    using JsonObject = rapidjson::GenericObject<false, rapidjson::Value>;

    explicit JsonSerializedObject(const JsonObject& obj);
    explicit JsonSerializedObject(const JsonObject& obj, bool isRoot);

    ErrCode INTERFACE_FUNC readSerializedObject(IString* key, ISerializedObject** plainObj) override;
    ErrCode INTERFACE_FUNC readSerializedList(IString* key, ISerializedList** list) override;
    ErrCode INTERFACE_FUNC readList(IString* key, IBaseObject* context, IFunction* factoryCallback, IList** list) override;
    ErrCode INTERFACE_FUNC readObject(IString* key, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj) override;
    ErrCode INTERFACE_FUNC readString(IString* key, IString** string) override;
    ErrCode INTERFACE_FUNC readBool(IString* key, Bool* boolean) override;
    ErrCode INTERFACE_FUNC readInt(IString* key, Int* integer) override;
    ErrCode INTERFACE_FUNC readFloat(IString* key, Float* real) override;
    ErrCode INTERFACE_FUNC hasKey(IString* key, Bool* hasKey) override;

    ErrCode INTERFACE_FUNC getKeys(IList** list) override;
    ErrCode INTERFACE_FUNC getType(IString* key, CoreType* type) override;
    ErrCode INTERFACE_FUNC isRoot(Bool* isRoot) override;

    ErrCode INTERFACE_FUNC toJson(IString** jsonString) override;

    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;
private:
    static StringPtr objToJson(const rapidjson::Value& val);
    const JsonObject object;
    Bool root;
};

END_NAMESPACE_CQDAQ
