
#pragma once
#include <coretypes/serialized_object.h>
#include <coretypes/stringobject_factory.h>
#include <coretypes/baseobject_factory.h>
#include <coretypes/listobject_factory.h>
#include <coretypes/function_ptr.h>
#include <coretypes/serialized_list_ptr.h>

BEGIN_NAMESPACE_CQDAQ


class SerializedObjectPtr;

template <>
struct InterfaceToSmartPtr<ISerializedObject>
{
    typedef SerializedObjectPtr SmartPtr;
};

/*!
 * @addtogroup types_serialized_object
 * @{
 */

class SerializedObjectPtr : public ObjectPtr<ISerializedObject>
{
public:
    using ObjectPtr<ISerializedObject>::ObjectPtr;

    SerializedObjectPtr()
    {
    }

    static SerializedObjectPtr Borrow(ISerializedObject*& obj)
    {
        SerializedObjectPtr objPtr;
        objPtr.object = obj;
        objPtr.borrowed = true;
        return objPtr;
    }

    static SerializedObjectPtr Borrow(const SerializedObjectPtr& objPtr)
    {
        SerializedObjectPtr objPtrThis;
        objPtrThis.object = objPtr.object;
        objPtrThis.borrowed = true;
        return objPtrThis;
    }

    SerializedObjectPtr readSerializedObject(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        SerializedObjectPtr value;
        checkErrorInfo(object->readSerializedObject(key, &value));

        return value;
    }

    BaseObjectPtr readObject(const StringPtr& key, const BaseObjectPtr& context = nullptr, const FunctionPtr& factoryCallback = nullptr) const
    {
        if (!object)
            throw InvalidParameterException();

        IBaseObject* value;
        checkErrorInfo(object->readObject(key, context, factoryCallback, &value));

        return BaseObjectPtr(std::move(value));
    }

    StringPtr readString(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        StringPtr value;
        checkErrorInfo(object->readString(key, &value));

        return value;
    }

    Bool readBool(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        Bool value;
        checkErrorInfo(object->readBool(key, &value));

        return value;
    }

    Int readInt(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        Int value;
        ErrCode errCode = object->readInt(key, &value);
        checkErrorInfo(errCode);

        return value;
    }

    Float readFloat(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        Float value;
        checkErrorInfo(object->readFloat(key, &value));

        return value;
    }

    ListPtr<IString> getKeys() const
    {
        if (!object)
            throw InvalidParameterException();

        IList* keys;
        checkErrorInfo(object->getKeys(&keys));

        return ListPtr<IString>(std::move(keys));
    }

    Bool hasKey(const StringPtr& hasMember) const
    {
        if (!object)
            throw InvalidParameterException();

        Bool keys;
        checkErrorInfo(object->hasKey(hasMember, &keys));

        return keys;
    }

    template <typename T>
    ListPtr<T> readList(const StringPtr& key, const BaseObjectPtr& context = nullptr, const FunctionPtr& factoryCallback = nullptr) const
    {
        if (!object)
            throw InvalidParameterException();

        IList* value;
        checkErrorInfo(object->readList(key, context, factoryCallback, &value));

        return ListPtr<T>(std::move(value));
    }

    SerializedListPtr readSerializedList(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        SerializedListPtr value;
        checkErrorInfo(object->readSerializedList(key, &value));

        return value;
    }

    CoreType getType(const StringPtr& key) const
    {
        if (!object)
            throw InvalidParameterException();

        CoreType ct;
        checkErrorInfo(object->getType(key, &ct));
        return ct;
    }

    void checkObjectType(const std::string& objectType) const
    {
        if (objectType.empty())
            return;

        const auto type = readString("__type");
        if (type.toStdString() != objectType)
            throw InvalidTypeException(fmt::format("Object not of ""{}"" type", objectType));
    }

    Bool isRoot() const
    {
        if (!object)
            throw InvalidParameterException();
        
        Bool isRoot;
        checkErrorInfo(object->isRoot(&isRoot));
        return isRoot;
    }

    StringPtr toJson() const
    {
        if (!object)
            throw InvalidParameterException();
        
        StringPtr jsonString;
        checkErrorInfo(object->toJson(&jsonString));
        return jsonString;
    }
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ