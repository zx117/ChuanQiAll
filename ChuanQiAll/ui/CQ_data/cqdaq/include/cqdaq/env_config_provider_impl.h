
#pragma once
#include <cqdaq/config_provider.h>
#include <rapidjson/document.h>
#include <coretypes/baseobject_factory.h>
#include <cqdaq/base_config_provider_impl.h>

BEGIN_NAMESPACE_CQDAQ

class EnvConfigProviderImpl final : public BaseConfigProviderImpl
{
public:
    ErrCode INTERFACE_FUNC populateOptions(IDict* options) override;

private:
    static ListPtr<IString> GetEnvValues();
};

END_NAMESPACE_CQDAQ
