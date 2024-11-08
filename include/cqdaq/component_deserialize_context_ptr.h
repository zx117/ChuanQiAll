//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:20.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/component_deserialize_context.h"
#include <coretypes/span.h>
#include <coretypes/objectptr.h>
#include <cqdaq/component_ptr.h>
#include <coretypes/string_ptr.h>
#include <cqdaq/context_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ComponentDeserializeContextPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IComponentDeserializeContext>
{
    using SmartPtr = daq::ComponentDeserializeContextPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ




class ComponentDeserializeContextPtr : public daq::ObjectPtr<IComponentDeserializeContext>
{
public:
    using daq::ObjectPtr<IComponentDeserializeContext>::ObjectPtr;
    //using daq::ObjectPtr<IComponentDeserializeContext>::operator=;



    ComponentDeserializeContextPtr()
        : daq::ObjectPtr<IComponentDeserializeContext>()

    {
    }

    ComponentDeserializeContextPtr(daq::ObjectPtr<IComponentDeserializeContext>&& ptr)
        : daq::ObjectPtr<IComponentDeserializeContext>(std::move(ptr))

    {
    }

    ComponentDeserializeContextPtr(const daq::ObjectPtr<IComponentDeserializeContext>& ptr)
        : daq::ObjectPtr<IComponentDeserializeContext>(ptr)

    {
    }

    ComponentDeserializeContextPtr(const ComponentDeserializeContextPtr& other)
        : daq::ObjectPtr<IComponentDeserializeContext>(other)

    {
    }

    ComponentDeserializeContextPtr(ComponentDeserializeContextPtr&& other) noexcept
        : daq::ObjectPtr<IComponentDeserializeContext>(std::move(other))

    {
    }
    
    ComponentDeserializeContextPtr& operator=(const ComponentDeserializeContextPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IComponentDeserializeContext>::operator =(other);


        return *this;
    }

    ComponentDeserializeContextPtr& operator=(ComponentDeserializeContextPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IComponentDeserializeContext>::operator =(std::move(other));

        return *this;
    }


    
    daq::ComponentPtr getParent() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentPtr parent;
        auto errCode = this->object->getParent(&parent);
        daq::checkErrorInfo(errCode);

        return parent;
    }

    
    daq::ComponentPtr getRoot() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentPtr root;
        auto errCode = this->object->getRoot(&root);
        daq::checkErrorInfo(errCode);

        return root;
    }

    
    daq::StringPtr getLocalId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr localId;
        auto errCode = this->object->getLocalId(&localId);
        daq::checkErrorInfo(errCode);

        return localId;
    }

    
    daq::ContextPtr getContext() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ContextPtr context;
        auto errCode = this->object->getContext(&context);
        daq::checkErrorInfo(errCode);

        return context;
    }

    
    daq::IntfID getIntfID() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::IntfID intfID;
        auto errCode = this->object->getIntfID(&intfID);
        daq::checkErrorInfo(errCode);

        return intfID;
    }

    
    daq::ComponentDeserializeContextPtr clone(const daq::ComponentPtr& newParent, const daq::StringPtr& newLocalId, daq::IntfID* newIntfID) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ComponentDeserializeContextPtr newComponentDeserializeContext;
        auto errCode = this->object->clone(newParent, newLocalId, &newComponentDeserializeContext, newIntfID);
        daq::checkErrorInfo(errCode);

        return newComponentDeserializeContext;
    }

#if __has_include(<cqdaq/component_deserialize_context_ptr.custom.h>)
    #include <cqdaq/component_deserialize_context_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ
