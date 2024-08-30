
#pragma once
#include <cqdaq/config_provider.h>
#include <rapidjson/document.h>
#include <coretypes/baseobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

class BaseConfigProviderImpl : public ImplementationOf<IConfigProvider>
{
protected:
    static BaseObjectPtr TryConvertToBoolean(const std::string& value);
    static BaseObjectPtr TryConvertToFloat(const std::string& value);
    static BaseObjectPtr TryConvertToInteger(const std::string& value);

    static std::string ToLowerCase(const std::string& input);
    static ListPtr<IString> SplitKey(const std::string& envKey, const std::string& prefix, char delimiter);
    static DictPtr<IString, IString> GetValuesStartingWith(const ListPtr<IString>& cmdLineArgs, const std::string& prefix);

    static BaseObjectPtr HandleUnderfineValue(const std::string& value);
    static bool HandleOptionLeaf(DictPtr<IString, IBaseObject> optionsValue, StringPtr envKey, StringPtr envValue);

    static bool WriteValue(DictPtr<IString,IBaseObject> options, const ListPtr<IString>& tokens, const std::string& value);
};

END_NAMESPACE_CQDAQ
