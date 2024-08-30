
#pragma once
#include <cqdaq/device_domain_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/struct_impl.h>

BEGIN_NAMESPACE_CQDAQ

class DeviceDomainImpl : public GenericStructImpl<IDeviceDomain, IStruct>
{
public:
    explicit DeviceDomainImpl(RatioPtr tickResolution, StringPtr origin, UnitPtr unit);

    ErrCode INTERFACE_FUNC getTickResolution(IRatio** tickResolution) override;
    ErrCode INTERFACE_FUNC getOrigin(IString** origin) override;
    ErrCode INTERFACE_FUNC getUnit(IUnit** unit) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(DeviceDomainImpl)

END_NAMESPACE_CQDAQ
