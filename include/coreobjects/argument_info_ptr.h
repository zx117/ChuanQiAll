//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:06.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "coreobjects/argument_info.h"
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ArgumentInfoPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IArgumentInfo>
{
    using SmartPtr = daq::ArgumentInfoPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup objects_utility
 * @addtogroup objects_argument_info ArgumentInfo
 * @{

 */


/*!
 * @brief Provides the name and type of a single function/procedure argument

 * Usually part of a list of arguments in a Callable info object.
 * Argument info objects implement the Struct methods internally and are Core type `ctStruct`.
 */

class ArgumentInfoPtr : public daq::ObjectPtr<IArgumentInfo>
{
public:
    using daq::ObjectPtr<IArgumentInfo>::ObjectPtr;
    //using daq::ObjectPtr<IArgumentInfo>::operator=;



    ArgumentInfoPtr()
        : daq::ObjectPtr<IArgumentInfo>()

    {
    }

    ArgumentInfoPtr(daq::ObjectPtr<IArgumentInfo>&& ptr)
        : daq::ObjectPtr<IArgumentInfo>(std::move(ptr))

    {
    }

    ArgumentInfoPtr(const daq::ObjectPtr<IArgumentInfo>& ptr)
        : daq::ObjectPtr<IArgumentInfo>(ptr)

    {
    }

    ArgumentInfoPtr(const ArgumentInfoPtr& other)
        : daq::ObjectPtr<IArgumentInfo>(other)

    {
    }

    ArgumentInfoPtr(ArgumentInfoPtr&& other) noexcept
        : daq::ObjectPtr<IArgumentInfo>(std::move(other))

    {
    }
    
    ArgumentInfoPtr& operator=(const ArgumentInfoPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IArgumentInfo>::operator =(other);


        return *this;
    }

    ArgumentInfoPtr& operator=(ArgumentInfoPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IArgumentInfo>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the name of the argument.

     * @returns The name of the argument.
     */
    daq::StringPtr getName() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr name;
        auto errCode = this->object->getName(&name);
        daq::checkErrorInfo(errCode);

        return name;
    }


    /*!
     * @brief Gets the core type of the argument.

     * @returns The type of the argument.
     * Dictionary, List and Object types should be avoided in public function/procedure callable objects
     * as their key, item, or base interface type cannot be determined without internal knowledge
     * of the function/procedure.
     */
    daq::CoreType getType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::CoreType type;
        auto errCode = this->object->getType(&type);
        daq::checkErrorInfo(errCode);

        return type;
    }

#if __has_include(<coreobjects/argument_info_ptr.custom.h>)
    #include <coreobjects/argument_info_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @addtogroup objects_argument_info_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ