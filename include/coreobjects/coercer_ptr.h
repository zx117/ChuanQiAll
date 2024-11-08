//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:54:56.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "coreobjects/coercer.h"
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class CoercerPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::ICoercer>
{
    using SmartPtr = daq::CoercerPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup objects_property
 * @addtogroup objects_coercer Coercer
 * @{

 */


/*!
 * @brief Used by cqDAQ properties to coerce a value to match the restrictions imposed by the Property.

 * Whenever a value is set to on a Property object, if the corresponding Property has a coercer configured, the value will
 * be evaluated and modified to fit the restrictions imposed by the coercer. For example, a coercer can enforce lower-than,
 * greater-than, equality, or other number relations on written values.
 * The coercion conditions are configured with an evaluation string when the coercer is constructed. The string constructs an
 * Eval value that replaces any instance of the keyword "value" or "val" with the value being set. The result of the Eval
 * value evaluation is the output of the `coerce` function call. For example, coercers created with the string
 * "if(value > 5, 5, value)" would enforce that the property value is always equal to or lower than 5.
 */

class CoercerPtr : public daq::ObjectPtr<ICoercer>
{
public:
    using daq::ObjectPtr<ICoercer>::ObjectPtr;
    //using daq::ObjectPtr<ICoercer>::operator=;



    CoercerPtr()
        : daq::ObjectPtr<ICoercer>()

    {
    }

    CoercerPtr(daq::ObjectPtr<ICoercer>&& ptr)
        : daq::ObjectPtr<ICoercer>(std::move(ptr))

    {
    }

    CoercerPtr(const daq::ObjectPtr<ICoercer>& ptr)
        : daq::ObjectPtr<ICoercer>(ptr)

    {
    }

    CoercerPtr(const CoercerPtr& other)
        : daq::ObjectPtr<ICoercer>(other)

    {
    }

    CoercerPtr(CoercerPtr&& other) noexcept
        : daq::ObjectPtr<ICoercer>(std::move(other))

    {
    }
    
    CoercerPtr& operator=(const CoercerPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<ICoercer>::operator =(other);


        return *this;
    }

    CoercerPtr& operator=(CoercerPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<ICoercer>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Coerces `value` to match the coercion restrictions and outputs the result.

     * @param propObj Optional property object parameter required if the coercion depends on other properties of the Property object.
     * @param value The value to be coerced to fit the restrictions.
     * @returns The coercer output containing the modified `value`.
     * @throws CqdaqErrException if `value` cannot be coerced to fit the restrictions.
     * @retval CQDAQ_SUCCESS If the value either already fits the restrictions, or was successfully modified to do so.
     */
    daq::BaseObjectPtr coerce(const daq::BaseObjectPtr& propObj, const daq::BaseObjectPtr& value) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::BaseObjectPtr result;
        auto errCode = this->object->coerce(propObj, value, &result);
        daq::checkErrorInfo(errCode);

        return result;
    }


    /*!
     * @brief Gets the string expression used when creating the coercer.

     * @returns The coercion expression.
     */
    daq::StringPtr getEval() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr eval;
        auto errCode = this->object->getEval(&eval);
        daq::checkErrorInfo(errCode);

        return eval;
    }

#if __has_include(<coreobjects/coercer_ptr.custom.h>)
    #include <coreobjects/coercer_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @addtogroup objects_coercer_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ
