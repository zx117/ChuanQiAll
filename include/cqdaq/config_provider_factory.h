
#pragma once
#include <cqdaq/config_provider_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ConfigProviderPtr JsonConfigProvider(const StringPtr& filename = nullptr)
{
    ConfigProviderPtr obj(JsonConfigProvider_Create(filename));
    return obj;
}

inline ConfigProviderPtr EnvConfigProvider()
{
    ConfigProviderPtr obj(EnvConfigProvider_Create());
    return obj;
}

inline ConfigProviderPtr CmdLineArgsConfigProvider(const ListPtr<IString>& args)
{
    ConfigProviderPtr obj(CmdLineArgsConfigProvider_Create(args));
    return obj;
}

END_NAMESPACE_CQDAQ
