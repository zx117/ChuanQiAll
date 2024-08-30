
#pragma once
#include <cqdaq/server_type.h>
#include <coreobjects/component_type_impl.h>

BEGIN_NAMESPACE_CQDAQ

class ServerTypeImpl : public GenericComponentTypeImpl<IServerType>
{
public:
    using Self = ServerTypeImpl;
    using Super = GenericComponentTypeImpl<IServerType>;

    explicit ServerTypeImpl(const StringPtr& id,
                            const StringPtr& name,
                            const StringPtr& description,
                            const FunctionPtr& createDefaultConfigCallback);
};

END_NAMESPACE_CQDAQ
