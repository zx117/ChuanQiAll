
#pragma once
#include <coretypes/type.h>
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IType>
class GenericTypePtr;

using TypePtr = GenericTypePtr<>;

template <>
struct InterfaceToSmartPtr<IType>
{
    using SmartPtr = daq::GenericTypePtr<daq::IType>;
};

/*!
 * @ingroup types_types
 * @defgroup types_types_simple_type Type
 * @{
 */

/*!
 * @brief The base object type that is inherited by all Types (eg. Struct type, Simple type, Property object class)
 * in cqDAQ.
 *
 * Types are used for the construction of objects that are require validation/have pre-defined fields such as
 * Structs and Property objects. Types should be inserted into the Type manager to be used by different parts
 * of the SDK.
 */
template <typename InterfaceType>
class GenericTypePtr : public ObjectPtr<InterfaceType>
{
public:
    using ObjectPtr<InterfaceType>::ObjectPtr;
    
    GenericTypePtr()
        : daq::ObjectPtr<InterfaceType>()
    {
    }

    GenericTypePtr(ObjectPtr<InterfaceType>&& ptr)
        : ObjectPtr<InterfaceType>(std::move(ptr))
    {
    }

    GenericTypePtr(const ObjectPtr<InterfaceType>& ptr)
        : ObjectPtr<InterfaceType>(ptr)
    {
    }


    GenericTypePtr(const TypePtr& ptr)
        : daq::ObjectPtr<InterfaceType>(ptr)

    {
    }

    GenericTypePtr(TypePtr&& ptr) noexcept
        : daq::ObjectPtr<InterfaceType>(std::move(ptr))

    {
    }
        
    GenericTypePtr& operator=(const TypePtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<InterfaceType>::operator =(other);
        return *this;
    }

    GenericTypePtr& operator=(TypePtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }

        daq::ObjectPtr<InterfaceType>::operator =(std::move(other));
        return *this;
    }

    /*!
     * @brief Gets the name of the Type
     * @returns The name of the Type.
     */
    StringPtr getName() const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        StringPtr typeName;
        const auto errCode = this->object->getName(&typeName);
        checkErrorInfo(errCode);

        return typeName;
    }
};

/*!@}*/

END_NAMESPACE_CQDAQ
