//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:19.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/deserialize_component.h"
#include <coretypes/objectptr.h>
#include <coretypes/serialized_object_ptr.h>
#include <coretypes/function_ptr.h>
#include <coretypes/string_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class DeserializeComponentPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IDeserializeComponent>
{
    using SmartPtr = daq::DeserializeComponentPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ




class DeserializeComponentPtr : public daq::ObjectPtr<IDeserializeComponent>
{
public:
    using daq::ObjectPtr<IDeserializeComponent>::ObjectPtr;
    //using daq::ObjectPtr<IDeserializeComponent>::operator=;



    DeserializeComponentPtr()
        : daq::ObjectPtr<IDeserializeComponent>()

    {
    }

    DeserializeComponentPtr(daq::ObjectPtr<IDeserializeComponent>&& ptr)
        : daq::ObjectPtr<IDeserializeComponent>(std::move(ptr))

    {
    }

    DeserializeComponentPtr(const daq::ObjectPtr<IDeserializeComponent>& ptr)
        : daq::ObjectPtr<IDeserializeComponent>(ptr)

    {
    }

    DeserializeComponentPtr(const DeserializeComponentPtr& other)
        : daq::ObjectPtr<IDeserializeComponent>(other)

    {
    }

    DeserializeComponentPtr(DeserializeComponentPtr&& other) noexcept
        : daq::ObjectPtr<IDeserializeComponent>(std::move(other))

    {
    }
    
    DeserializeComponentPtr& operator=(const DeserializeComponentPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IDeserializeComponent>::operator =(other);


        return *this;
    }

    DeserializeComponentPtr& operator=(DeserializeComponentPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IDeserializeComponent>::operator =(std::move(other));

        return *this;
    }


    
    void deserializeValues(const daq::SerializedObjectPtr& serializedObject, const daq::BaseObjectPtr& context, const daq::FunctionPtr& callbackFactory) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->deserializeValues(serializedObject, context, callbackFactory);
        daq::checkErrorInfo(errCode);
    }

    
    void complete() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->complete();
        daq::checkErrorInfo(errCode);
    }

    
    daq::BaseObjectPtr getDeserializedParameter(const daq::StringPtr& parameter) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::BaseObjectPtr value;
        auto errCode = this->object->getDeserializedParameter(parameter, &value);
        daq::checkErrorInfo(errCode);

        return value;
    }

#if __has_include(<cqdaq/deserialize_component_ptr.custom.h>)
    #include <cqdaq/deserialize_component_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ