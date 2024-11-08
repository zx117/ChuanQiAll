
#pragma once
#include <cqdaq/server_capability_config.h>
#include <coretypes/validation.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/type_manager_ptr.h>
#include <coretypes/enumeration_type_ptr.h>
#include <coretypes/enumeration_ptr.h>
#include <coreobjects/property_object_impl.h>
#include <cqdaq/context_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ServerCapabilityConfigImpl : public GenericPropertyObjectImpl<IServerCapabilityConfig>
{
public:
    using Super = GenericPropertyObjectImpl<IServerCapabilityConfig>;

    explicit ServerCapabilityConfigImpl(const StringPtr& protocolId, const StringPtr& protocolName, ProtocolType protocolType);

    ErrCode INTERFACE_FUNC getConnectionString(IString** connectionString) override;
    ErrCode INTERFACE_FUNC setConnectionString(IString* connectionString) override;

    ErrCode INTERFACE_FUNC getConnectionStrings(IList** connectionStrings) override;
    ErrCode INTERFACE_FUNC addConnectionString(IString* connectionString) override;
        
    ErrCode INTERFACE_FUNC getProtocolName(IString** protocolName) override;
    ErrCode INTERFACE_FUNC setProtocolName(IString* protocolName) override;

    ErrCode INTERFACE_FUNC getProtocolId(IString** protocolId) override;
    ErrCode INTERFACE_FUNC setProtocolId(IString* protocolId) override;
    
    ErrCode INTERFACE_FUNC getProtocolType(ProtocolType* type) override;
    ErrCode INTERFACE_FUNC setProtocolType(ProtocolType type) override;

    ErrCode INTERFACE_FUNC getPrefix(IString** prefix) override;
    ErrCode INTERFACE_FUNC setPrefix(IString* prefix) override;
    
    ErrCode INTERFACE_FUNC getConnectionType(IString** type) override;
    ErrCode INTERFACE_FUNC setConnectionType(IString* type) override;
    
    ErrCode INTERFACE_FUNC getCoreEventsEnabled(Bool* enabled) override;
    ErrCode INTERFACE_FUNC setCoreEventsEnabled(Bool enabled) override;    
    
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    ErrCode INTERFACE_FUNC getInterfaceIds(SizeT* idCount, IntfID** ids) override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

protected:
    PropertyObjectPtr createCloneBase() override;

private:
    template <typename T>
    typename InterfaceToSmartPtr<T>::SmartPtr getTypedProperty(const StringPtr& name);

    static StringPtr ProtocolTypeToString(ProtocolType type);
    static ProtocolType StringToProtocolType(const StringPtr& type);
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ServerCapabilityConfigImpl)

END_NAMESPACE_CQDAQ
