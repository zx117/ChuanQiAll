
#pragma once
#include <cqdaq/config_provider.h>
#include <rapidjson/document.h>
#include <coretypes/baseobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

class JsonConfigProviderImpl final : public ImplementationOf<IConfigProvider>
{
public:
    explicit JsonConfigProviderImpl(const StringPtr& filename);

    ErrCode INTERFACE_FUNC populateOptions(IDict* options) override;
private:
    static StringPtr GetEnvironmentVariableValue(StringPtr variableName, StringPtr defaultValue);
    static StringPtr GetDataFromFile(const StringPtr& filename);

    static BaseObjectPtr HandleNumber(const rapidjson::Value& value);
    static BaseObjectPtr HandlePrimitive(const rapidjson::Value& value);
    static void HandleArray(const BaseObjectPtr& options, const rapidjson::Value& value);
    static void HandleObject(const BaseObjectPtr& options, const rapidjson::Value& value);

    StringPtr filename;
};

END_NAMESPACE_CQDAQ
