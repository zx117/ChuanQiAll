
#pragma once
#include <cqdaq/context_ptr.h>
#include <cqdaq/device_ptr.h>
#include <cqdaq/module_manager_ptr.h>
#include <cqdaq/server.h>
#include <coretypes/impl.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/validation.h>

BEGIN_NAMESPACE_CQDAQ

class ServerImpl;

using Server = ServerImpl;

class ServerImpl : public ImplementationOf<IServer>
{
public:
    using Super = ImplementationOf<IServer>;
    using Self = ServerImpl;

    explicit ServerImpl(PropertyObjectPtr serverConfig,
                        DevicePtr rootDevice,
                        ContextPtr context,
                        ModuleManagerPtr moduleManager)
        : serverConfig(std::move(serverConfig))
        , rootDevice(std::move(rootDevice))
        , context(std::move(context))
        , moduleManager(std::move(moduleManager))
    {
    }

    ErrCode INTERFACE_FUNC stop() override
    {
        return wrapHandler(this, &Self::onStopServer);
    }

protected:
    virtual void onStopServer()
    {

    }

    PropertyObjectPtr serverConfig;
    DevicePtr rootDevice;
    ContextPtr context;
    ModuleManagerPtr moduleManager;
};

END_NAMESPACE_CQDAQ
