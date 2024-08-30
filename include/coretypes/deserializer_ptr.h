
#pragma once
#include <coretypes/string_ptr.h>
#include <coretypes/baseobject_factory.h>
#include <coretypes/deserializer.h>
#include <coretypes/updatable_ptr.h>
#include <coretypes/function_ptr.h>
#include <coretypes/procedure_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_deserializer
 * @{
 */

class DeserializerPtr : public ObjectPtr<IDeserializer>
{
public:
    using ObjectPtr<IDeserializer>::ObjectPtr;

    BaseObjectPtr deserialize(const StringPtr& serialized, const BaseObjectPtr& context = nullptr, const FunctionPtr& factoryCallback = nullptr) const
    {
        if (!object)
        {
            throw InvalidParameterException();
        }

        BaseObjectPtr baseObj;
        checkErrorInfo(object->deserialize(serialized, context, factoryCallback, &baseObj));

        return baseObj;
    }

    void update(const UpdatablePtr& updatable, const StringPtr& serialized) const
    {
        if (!object)
        {
            throw InvalidParameterException();
        }

        checkErrorInfo(object->update(updatable, serialized));
    }


    void callCustomProc(const ProcedurePtr& customProc, const StringPtr& serialized) const
    {
        if (!object)
        {
            throw InvalidParameterException();
        }

        checkErrorInfo(object->callCustomProc(customProc, serialized));
    }
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
