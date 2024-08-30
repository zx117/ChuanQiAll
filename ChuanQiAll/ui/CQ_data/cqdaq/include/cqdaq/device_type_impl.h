
#pragma once
#include <cqdaq/device_type.h>
#include <coreobjects/component_type_impl.h>

BEGIN_NAMESPACE_CQDAQ

class DeviceTypeImpl : public GenericComponentTypeImpl<IDeviceType>
{
public:
    using Self = DeviceTypeImpl;
    using Super = GenericComponentTypeImpl<IDeviceType>;
    explicit DeviceTypeImpl(const StringPtr& id,
                            const StringPtr& name,
                            const StringPtr& description,
                            const FunctionPtr& createDefaultConfigCallback);
};

END_NAMESPACE_CQDAQ
