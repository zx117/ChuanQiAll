
#pragma once
#include <cqdaq/function_block_type.h>
#include <coreobjects/component_type_impl.h>
#include <cqdaq/function_block_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

class FunctionBlockTypeImpl : public GenericComponentTypeImpl<IFunctionBlockType>
{
public:
    using Self = FunctionBlockTypeImpl;
    using Super = GenericComponentTypeImpl<IFunctionBlockType>;

    explicit FunctionBlockTypeImpl(const StringPtr& id,
                                   const StringPtr& name,
                                   const StringPtr& description,
                                   const FunctionPtr& createDefaultConfigCallback);

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);
};


inline FunctionBlockTypeImpl::FunctionBlockTypeImpl(const StringPtr& id,
                                                    const StringPtr& name,
                                                    const StringPtr& description,
                                                    const FunctionPtr& createDefaultConfigCallback)
    : Super(FunctionBlockTypeStructType(), id, name, description, createDefaultConfigCallback)
{
}

inline ErrCode FunctionBlockTypeImpl::serialize(ISerializer* serializer)
{
    CQDAQ_PARAM_NOT_NULL(serializer);

    const auto serializerPtr = SerializerPtr::Borrow(serializer);

    return daqTry(
        [this, &serializerPtr]
        {
            serializerPtr.startTaggedObject(borrowPtr<SerializablePtr>());
            {
                serializerPtr.key("id");
                serializerPtr.writeString(id);

                if (name.assigned())
                {
                    serializerPtr.key("name");
                    serializerPtr.writeString(name);
                }

                if (description.assigned())
                {
                    serializerPtr.key("description");
                    serializerPtr.writeString(description);
                }

                if (createDefaultConfigCallback.assigned())
                {
                    const auto defaultConfig = createDefaultConfigCallback.call();
                    if (defaultConfig.assigned())
                    {
                        serializerPtr.key("defaultConfig");
                        defaultConfig.serialize(serializerPtr);
                    }
                }
            }

            serializerPtr.endObject();
        });
}

inline ErrCode FunctionBlockTypeImpl::getSerializeId(ConstCharPtr* id) const
{
    CQDAQ_PARAM_NOT_NULL(id);

    *id = SerializeId();
    return CQDAQ_SUCCESS;
}

inline ConstCharPtr FunctionBlockTypeImpl::SerializeId()
{
    return "FunctionBlockType";
}

inline ErrCode FunctionBlockTypeImpl::Deserialize(ISerializedObject* serialized,
                                                  IBaseObject* context,
                                                  IFunction* factoryCallback,
                                                  IBaseObject** obj)
{
    CQDAQ_PARAM_NOT_NULL(serialized);
    CQDAQ_PARAM_NOT_NULL(obj);

    const auto serializedObj = SerializedObjectPtr::Borrow(serialized);
    const auto contextPtr = BaseObjectPtr::Borrow(context);
    const auto factoryCallbackPtr = FunctionPtr::Borrow(factoryCallback);

    return daqTry(
        [&serializedObj, &contextPtr, &factoryCallbackPtr, &obj]
        {
            const auto id = serializedObj.readString("id");

            StringPtr name;
            if (serializedObj.hasKey("name"))
                name = serializedObj.readString("name");

            StringPtr description;
            if (serializedObj.hasKey("description"))
                description = serializedObj.readString("description");

            FunctionPtr createDefaultConfig;
            if (serializedObj.hasKey("defaultConfig"))
            {
                PropertyObjectPtr defaultConfig = serializedObj.readObject("defaultConfig", contextPtr, factoryCallbackPtr);
                createDefaultConfig = Function([defaultConfig] { return defaultConfig; });
            }

            *obj = createWithImplementation<IFunctionBlockType, FunctionBlockTypeImpl>(id, name, description, createDefaultConfig).detach();
        });
}

CQDAQ_REGISTER_DESERIALIZE_FACTORY(FunctionBlockTypeImpl)

END_NAMESPACE_CQDAQ
