
#pragma once
#include <cqdaq/component_status_container_ptr.h>
#include <cqdaq/component_status_container_private.h>
#include <cqdaq/context_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/validation.h>
#include <coreobjects/core_event_args_impl.h>

BEGIN_NAMESPACE_CQDAQ

class ComponentStatusContainerImpl final : public ImplementationOf<IComponentStatusContainer, IComponentStatusContainerPrivate, ISerializable>
{
public:
    explicit ComponentStatusContainerImpl();
    explicit ComponentStatusContainerImpl(const ProcedurePtr& coreEventCallback);

    // IComponentStatusContainer
    ErrCode INTERFACE_FUNC getStatus(IString* name, IEnumeration** value) override;
    ErrCode INTERFACE_FUNC getStatuses(IDict** statuses) override;

    // IComponentStatusContainerPrivate
    ErrCode INTERFACE_FUNC addStatus(IString* name, IEnumeration* initialValue) override;
    ErrCode INTERFACE_FUNC setStatus(IString* name, IEnumeration* value) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    std::mutex sync;

    DictPtr<IString, IEnumeration> statuses;
    ProcedurePtr triggerCoreEvent;
};

inline ComponentStatusContainerImpl::ComponentStatusContainerImpl()
    : statuses(Dict<IString, IEnumeration>())
{
}

inline ComponentStatusContainerImpl::ComponentStatusContainerImpl(const ProcedurePtr &coreEventCallback)
    : statuses(Dict<IString, IEnumeration>())
    , triggerCoreEvent(coreEventCallback)
{
}

inline ErrCode ComponentStatusContainerImpl::getStatus(IString *name, IEnumeration **value)
{
    CQDAQ_PARAM_NOT_NULL(name);
    CQDAQ_PARAM_NOT_NULL(value);

    std::scoped_lock lock(sync);

    if (!statuses.hasKey(name))
        return CQDAQ_ERR_NOTFOUND;

    *value = statuses.get(name).addRefAndReturn();
    return CQDAQ_SUCCESS;
}

inline ErrCode ComponentStatusContainerImpl::getStatuses(IDict **statuses)
{
    CQDAQ_PARAM_NOT_NULL(statuses);

    std::scoped_lock lock(sync);

    *statuses = this->statuses.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

inline ErrCode ComponentStatusContainerImpl::addStatus(IString *name, IEnumeration *initialValue)
{
    CQDAQ_PARAM_NOT_NULL(name);
    CQDAQ_PARAM_NOT_NULL(initialValue);

    const auto nameObj = StringPtr::Borrow(name);
    if (nameObj == "")
        return CQDAQ_ERR_INVALIDPARAMETER;

    std::scoped_lock lock(sync);

    if (statuses.hasKey(name))
        return CQDAQ_ERR_ALREADYEXISTS;

    return statuses->set(name, initialValue);
}

inline ErrCode ComponentStatusContainerImpl::setStatus(IString *name, IEnumeration *value)
{
    CQDAQ_PARAM_NOT_NULL(name);
    CQDAQ_PARAM_NOT_NULL(value);

    const auto nameObj = StringPtr::Borrow(name);
    if (nameObj == "")
        return CQDAQ_ERR_INVALIDPARAMETER;

    std::scoped_lock lock(sync);

    if (!statuses.hasKey(name))
        return CQDAQ_ERR_NOTFOUND;

    const auto valueObj = EnumerationPtr::Borrow(value);
    const auto oldValue = statuses.get(name);
    if (valueObj.getEnumerationType() != oldValue.getEnumerationType())
        return CQDAQ_ERR_INVALIDTYPE;
    if (valueObj == oldValue)
        return CQDAQ_IGNORED;

    auto errCode = statuses->set(name, value);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    if (triggerCoreEvent.assigned())
    {
        const CoreEventArgsPtr args = createWithImplementation<ICoreEventArgs, CoreEventArgsImpl>(
            CoreEventId::StatusChanged, Dict<IString, IBaseObject>({{name, value}}));
        triggerCoreEvent(args);
    }

    return CQDAQ_SUCCESS;
}

inline ErrCode ComponentStatusContainerImpl::serialize(ISerializer* serializer)
{
    CQDAQ_PARAM_NOT_NULL(serializer);

    serializer->startTaggedObject(this);
    {
        serializer->key("statuses");
        statuses.serialize(serializer);
    }
    serializer->endObject();

    return CQDAQ_SUCCESS;
}

inline ErrCode ComponentStatusContainerImpl::getSerializeId(ConstCharPtr* id) const
{
    CQDAQ_PARAM_NOT_NULL(id);

    *id = SerializeId();

    return CQDAQ_SUCCESS;
}

inline ConstCharPtr ComponentStatusContainerImpl::SerializeId()
{
    return "ComponentStatusContainer";
}

inline ErrCode ComponentStatusContainerImpl::Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj)
{
    CQDAQ_PARAM_NOT_NULL(serialized);
    CQDAQ_PARAM_NOT_NULL(context);
    CQDAQ_PARAM_NOT_NULL(obj);

    ObjectPtr<IComponentStatusContainerPrivate> statusContainer;
    auto errCode = createObject<IComponentStatusContainerPrivate, ComponentStatusContainerImpl>(&statusContainer);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    const auto serializedObj = SerializedObjectPtr::Borrow(serialized);

    DictPtr<IString, IEnumeration> statuses = serializedObj.readObject("statuses", context, factoryCallback);
    for (const auto& [name, value] : statuses)
        statusContainer->addStatus(name, value);

    *obj = statusContainer.detach();

    return CQDAQ_SUCCESS;
}

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ComponentStatusContainerImpl)

END_NAMESPACE_CQDAQ
