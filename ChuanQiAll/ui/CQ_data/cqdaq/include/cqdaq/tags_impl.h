
#pragma once
#include <cqdaq/tags_ptr.h>
#include <cqdaq/tags_private_ptr.h>
#include <cqdaq/component_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/validation.h>
#include <coreobjects/eval_value_factory.h>
#include <coreobjects/core_event_args_impl.h>

BEGIN_NAMESPACE_CQDAQ

class TagsImpl : public ImplementationOf<ITags, ITagsPrivate, ISerializable>
{
public:
    explicit TagsImpl();
    explicit TagsImpl(const ProcedurePtr& coreEventCallback);

    // ITags

    ErrCode INTERFACE_FUNC getList(IList** value) override;
    ErrCode INTERFACE_FUNC add(IString* name) override;
    ErrCode INTERFACE_FUNC remove(IString* name) override;
    ErrCode INTERFACE_FUNC replace(IList* tags) override;
    ErrCode INTERFACE_FUNC contains(IString* name, Bool* value) override;
    ErrCode INTERFACE_FUNC query(IString* query, Bool* value) override;
    
    // IBaseObject

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable

    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

protected:
    std::unordered_set<std::string> tags;

private:
    ProcedurePtr triggerCoreEvent;
};


inline TagsImpl::TagsImpl()
{
}

inline TagsImpl::TagsImpl(const ProcedurePtr& coreEventCallback)
    : triggerCoreEvent(coreEventCallback)
{
}

inline ErrCode TagsImpl::getList(IList** value)
{
    CQDAQ_PARAM_NOT_NULL(value);

    auto list = List<IString>();

    for (auto& item: tags)
    {
        list.pushBack(item);
    }

    *value = list.detach();
    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::add(IString* name)
{
    CQDAQ_PARAM_NOT_NULL(name);

    auto str = StringPtr::Borrow(name).toStdString();

    if (tags.count(str) > 0)
        return CQDAQ_IGNORED;

    tags.emplace(str);

    if (triggerCoreEvent.assigned())
    {
        const auto thisPtr = this->borrowPtr<TagsPtr>();
        const CoreEventArgsPtr args = createWithImplementation<ICoreEventArgs, CoreEventArgsImpl>(
            CoreEventId::TagsChanged, Dict<IString, IBaseObject>({{"Tags", thisPtr}}));
        triggerCoreEvent(args);
    }

    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::remove(IString* name)
{
    CQDAQ_PARAM_NOT_NULL(name);

    const auto str = StringPtr::Borrow(name).toStdString();
    if (tags.count(str) == 0)
        return CQDAQ_IGNORED;

    tags.erase(str);

    if (triggerCoreEvent.assigned())
    {
        const auto thisPtr = this->borrowPtr<TagsPtr>();
        const CoreEventArgsPtr args = createWithImplementation<ICoreEventArgs, CoreEventArgsImpl>(
            CoreEventId::TagsChanged, Dict<IString, IBaseObject>({{"Tags", thisPtr}}));
        triggerCoreEvent(args);
    }

    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::replace(IList* tags)
{
    CQDAQ_PARAM_NOT_NULL(tags);
    this->tags.clear();

    const auto tagsPtr = ListPtr<IString>::Borrow(tags);
    for (const auto& tag : tagsPtr)
        this->tags.insert(tag);
    
    if (triggerCoreEvent.assigned())
    {
        const auto thisPtr = this->borrowPtr<TagsPtr>();
        const CoreEventArgsPtr args = createWithImplementation<ICoreEventArgs, CoreEventArgsImpl>(
            CoreEventId::TagsChanged, Dict<IString, IBaseObject>({{"Tags", thisPtr}}));
        triggerCoreEvent(args);
    }

    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::contains(IString* name, Bool* value)
{
    CQDAQ_PARAM_NOT_NULL(value);
    CQDAQ_PARAM_NOT_NULL(name);

    const auto str = StringPtr::Borrow(name).toStdString();
    *value = tags.count(str) > 0;
    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::query(IString* query, Bool* value)
{
    CQDAQ_PARAM_NOT_NULL(value);
    CQDAQ_PARAM_NOT_NULL(query);

    const auto tagEvalValue = EvalValueFunc(query,
                                      [this](const std::string& tagStr)
                                      {
                                          return this->tags.count(tagStr) > 0 ? True : False;
                                      });

    *value = tagEvalValue;
    return CQDAQ_SUCCESS;
}

inline ErrCode INTERFACE_FUNC TagsImpl::equals(IBaseObject* other, Bool* equals) const
{
    CQDAQ_PARAM_NOT_NULL(equals);
    *equals = false;

    if (other == nullptr)
        return CQDAQ_SUCCESS;

    auto tagsOther = BaseObjectPtr::Borrow(other).asPtrOrNull<ITags>();
    if (tagsOther == nullptr)
        return CQDAQ_SUCCESS;

    const auto listOther = tagsOther.getList();
    if (listOther.getCount() != tags.size())
        return CQDAQ_SUCCESS;

    for (const auto& tag : listOther)
    {
        if (tags.count(tag) == 0)
            return CQDAQ_SUCCESS;
    }

    *equals = true;
    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::serialize(ISerializer* serializer)
{
    CQDAQ_PARAM_NOT_NULL(serializer);

    serializer->startTaggedObject(this);
    {
        serializer->key("list");
        serializer->startList();
        for (const auto& tag : tags)
            serializer->writeString(tag.c_str(), tag.size());
        serializer->endList();
    }
    serializer->endObject();

    return CQDAQ_SUCCESS;
}

inline ErrCode TagsImpl::getSerializeId(ConstCharPtr* id) const
{
    CQDAQ_PARAM_NOT_NULL(id);

    *id = SerializeId();

    return CQDAQ_SUCCESS;
}

inline ConstCharPtr TagsImpl::SerializeId()
{
    return "Tags";
}

inline ErrCode TagsImpl::Deserialize(ISerializedObject* serialized, IBaseObject*, IFunction*, IBaseObject** obj)
{
    CQDAQ_PARAM_NOT_NULL(serialized);
    CQDAQ_PARAM_NOT_NULL(obj);

    ObjectPtr<ITagsPrivate> tags;
    auto errCode = createObject<ITagsPrivate, TagsImpl>(&tags);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    const auto serializedObj = SerializedObjectPtr::Borrow(serialized);

    const auto list = serializedObj.readList<IString>("list");
    for (const auto& tag : list)
        tags->add(tag);

    *obj = tags.detach();

    return CQDAQ_SUCCESS;
}

CQDAQ_REGISTER_DESERIALIZE_FACTORY(TagsImpl)

END_NAMESPACE_CQDAQ
