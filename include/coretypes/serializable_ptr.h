
#pragma once

#include <coretypes/serializable.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_serializable
 * @{
 */

class SerializablePtr;

template <>
struct InterfaceToSmartPtr<ISerializable>
{
    typedef SerializablePtr SmartPtr;
};

class SerializablePtr : public ObjectPtr<ISerializable>
{
public:
    using ObjectPtr<ISerializable>::ObjectPtr;

    static SerializablePtr Borrow(ISerializable*& obj)
    {
        SerializablePtr objPtr;
        objPtr.object = obj;
        objPtr.borrowed = true;
        return objPtr;
    }

    SerializablePtr Borrow(const SerializablePtr& objPtr) const
    {
        SerializablePtr objPtrThis;
        objPtrThis.object = objPtr.object;
        objPtrThis.borrowed = true;
        return objPtrThis;
    }

    void serialize(const ObjectPtr<ISerializer>& serializator) const
    {
        if (!object)
            throw InvalidParameterException();

        ErrCode errCode = object->serialize(serializator);
        checkErrorInfo(errCode);
    }
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
