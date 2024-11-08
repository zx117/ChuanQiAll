#pragma once
#include <coretypes/common.h>
#include <coreobjects/core_event_args.h>
#include <coretypes/event_args_impl.h>
#include <coretypes/validation.h>
#include <coreobjects/core_event_args_ptr.h>

BEGIN_NAMESPACE_CQDAQ

namespace core_event_args_impl
{
    static std::string getCoreEventName(const CoreEventId id)
    {
        switch(id)
        {
            case CoreEventId::PropertyValueChanged:
                return "PropertyValueChanged";
            case CoreEventId::PropertyObjectUpdateEnd:
                return "PropertyObjectUpdateEnd";
            case CoreEventId::PropertyAdded:
                return "PropertyAdded";
            case CoreEventId::PropertyRemoved:
                return "PropertyRemoved";
            case CoreEventId::ComponentAdded:
                return "ComponentAdded";
            case CoreEventId::ComponentRemoved:
                return "ComponentRemoved";
            case CoreEventId::SignalConnected:
                return "SignalConnected";
            case CoreEventId::SignalDisconnected:
                return "SignalDisconnected";
            case CoreEventId::DataDescriptorChanged:
                return "DataDescriptorChanged";
            case CoreEventId::ComponentUpdateEnd:
                return "ComponentUpdateEnd";
            case CoreEventId::AttributeChanged:
                return "AttributeChanged";
            case CoreEventId::TagsChanged:
                return "TagsChanged";
            case CoreEventId::StatusChanged:
                return "StatusChanged";
            case CoreEventId::TypeAdded:
                return "TypeAdded";
            case CoreEventId::TypeRemoved:
                return "TypeRemoved";
            case CoreEventId::DeviceDomainChanged:
                return "DeviceDomainChanged";
            default:
                break;
        }

        return "Unknown";
    }
}


class CoreEventArgsImpl : public EventArgsBase<ICoreEventArgs, ISerializable>
{
public:
    explicit CoreEventArgsImpl (CoreEventId id, const DictPtr<IString, IBaseObject>& parameters);
    explicit CoreEventArgsImpl (CoreEventId id, const StringPtr& name, const DictPtr<IString, IBaseObject>& parameters);

    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;
    
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;
    
    static ConstCharPtr SerializeId();

    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    DictPtr<IString, IBaseObject> parameters;
    bool validateParameters() const;
};


inline CoreEventArgsImpl::CoreEventArgsImpl(CoreEventId id, const DictPtr<IString, IBaseObject>& parameters)
    : EventArgsImplTemplate<ICoreEventArgs, ISerializable>(static_cast<int>(id), core_event_args_impl::getCoreEventName(id))
    , parameters(parameters)
{
    if (!validateParameters())
        throw InvalidParameterException{"Core event parameters for event type \"{}\" are invalid", this->eventName};
}

inline CoreEventArgsImpl::CoreEventArgsImpl(CoreEventId id, const StringPtr& name, const DictPtr<IString, IBaseObject>& parameters)
    : EventArgsImplTemplate<ICoreEventArgs, ISerializable>(static_cast<int>(id), name)
    , parameters(parameters)
{
    if (!validateParameters())
        throw InvalidParameterException{"Core event parameters for event type \"{}\" are invalid", this->eventName};
}

inline ErrCode CoreEventArgsImpl::getParameters(IDict** parameters)
{
    CQDAQ_PARAM_NOT_NULL(parameters);

    *parameters = this->parameters.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

inline ErrCode CoreEventArgsImpl::serialize(ISerializer* serializer)
{
    serializer->startTaggedObject(this);

    serializer->key("id");
    serializer->writeInt(this->eventId);

    serializer->key("name");
    serializer->writeString(this->eventName.getCharPtr(), this->eventName.getLength());

    serializer->key("params");
    ISerializable* serializableParams;
    ErrCode errCode = this->parameters->borrowInterface(ISerializable::Id, reinterpret_cast<void**>(&serializableParams));

    if (errCode == CQDAQ_ERR_NOINTERFACE)
        return CQDAQ_ERR_NOT_SERIALIZABLE;

    if (CQDAQ_FAILED(errCode))
        return errCode;

    errCode = serializableParams->serialize(serializer);

    if (CQDAQ_FAILED(errCode))
        return errCode;

    serializer->endObject();

    return CQDAQ_SUCCESS;
}

inline ErrCode CoreEventArgsImpl::getSerializeId(ConstCharPtr* id) const
{
    *id = SerializeId();

    return CQDAQ_SUCCESS;
}

inline ConstCharPtr CoreEventArgsImpl::SerializeId()
{
    return "CoreEventArgs";
}

inline ErrCode CoreEventArgsImpl::Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj)
{
    Int id;
    ErrCode errCode = ser->readInt("id"_daq, &id);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    StringPtr name;
    errCode = ser->readString("name"_daq, &name);
    if (errCode == CQDAQ_ERR_NOTFOUND)
    {
        name = core_event_args_impl::getCoreEventName((CoreEventId) id);
        errCode = CQDAQ_SUCCESS;
    }

    if (CQDAQ_FAILED(errCode))
        return errCode;

    BaseObjectPtr params;
    errCode = ser->readObject("params"_daq, context, factoryCallback, &params);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    try
    {
        CoreEventArgsPtr argsPtr; 
        createCoreEventArgs(&argsPtr, (CoreEventId) id, name, params.asPtr<IDict>());
        *obj = argsPtr.detach();
    }
    catch(const DaqException& e)
    {
        return e.getErrCode();
    }
    catch(...)
    {
        return CQDAQ_ERR_GENERALERROR;
    }

    return CQDAQ_SUCCESS;
}

inline bool CoreEventArgsImpl::validateParameters() const
{
    switch(static_cast<CoreEventId>(eventId))
    {
        case CoreEventId::PropertyValueChanged:
            return parameters.hasKey("Name") && parameters.hasKey("Value") && parameters.hasKey("Path");
        case CoreEventId::PropertyObjectUpdateEnd:
            return parameters.hasKey("UpdatedProperties") && parameters.get("UpdatedProperties").asPtrOrNull<IDict>().assigned() && parameters.hasKey("Path");
        case CoreEventId::PropertyAdded:
            return parameters.hasKey("Property") && parameters.hasKey("Path");
        case CoreEventId::PropertyRemoved:
            return parameters.hasKey("Name") && parameters.hasKey("Path");
        case CoreEventId::ComponentAdded:
            return parameters.hasKey("Component");
        case CoreEventId::ComponentRemoved:
            return parameters.hasKey("Id");
        case CoreEventId::SignalConnected:
            return parameters.hasKey("Signal");
        case CoreEventId::DataDescriptorChanged:
            return parameters.hasKey("DataDescriptor");
        case CoreEventId::AttributeChanged:
            return parameters.hasKey("AttributeName");
        case CoreEventId::TagsChanged:
            return parameters.hasKey("Tags");
        case CoreEventId::TypeAdded:
            return parameters.hasKey("Type");
        case CoreEventId::TypeRemoved:
            return parameters.hasKey("TypeName");
        case CoreEventId::DeviceDomainChanged:
            return parameters.hasKey("DeviceDomain");
        default:
            break;
    }

    return true;
}

CQDAQ_REGISTER_DESERIALIZE_FACTORY(CoreEventArgsImpl)

END_NAMESPACE_CQDAQ
