
#pragma once
#include <cqdaq/config_provider.h>
#include <rapidjson/document.h>
#include <coretypes/baseobject_factory.h>
#include <cqdaq/base_config_provider_impl.h>

BEGIN_NAMESPACE_CQDAQ

class CmdLineArgsConfigProviderImpl final : public BaseConfigProviderImpl
{
public:
    explicit CmdLineArgsConfigProviderImpl(const ListPtr<IString>& cmdLineArgs);
    ErrCode INTERFACE_FUNC populateOptions(IDict* options) override;

private:
    ListPtr<IString> cmdLineArgs;
};

END_NAMESPACE_CQDAQ
