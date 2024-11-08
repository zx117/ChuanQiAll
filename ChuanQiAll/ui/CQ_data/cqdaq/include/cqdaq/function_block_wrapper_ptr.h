//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:36.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/function_block_wrapper.h"
#include <coretypes/objectptr.h>
#include <coretypes/string_ptr.h>
#include <coreobjects/coercer_ptr.h>
#include <coreobjects/validator_ptr.h>
#include <coretypes/list_ptr.h>
#include <cqdaq/function_block_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class FunctionBlockWrapperPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IFunctionBlockWrapper>
{
    using SmartPtr = daq::FunctionBlockWrapperPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_function_blocks
 * @addtogroup cqdaq_function_block Function block
 * @{

 */


/*!
 * @brief Enables to change the configuration behaviour of a function block.

 * Function block wrapper is used when a parent function block creates a child function block.
 * Often it is required that the child function block does not expose all configuration features
 * to the client SDK code. Some configuration is performed by the parent function block. Therefore
 * it is required that the parent function block is able to hide and/or change configuration
 * parameters of the child function block.
 * The parent function block should create an instance of a function block wrapper to modify the
 * configuration interface of the child function block. The original function block is passed as
 * a parameter to factory function. The parent function block should configure access to the
 * original child function block using the functions on function block wrapper. Then it should
 * publish the wrapped function block.
 */

class FunctionBlockWrapperPtr : public daq::ObjectPtr<IFunctionBlockWrapper>
{
public:
    using daq::ObjectPtr<IFunctionBlockWrapper>::ObjectPtr;
    //using daq::ObjectPtr<IFunctionBlockWrapper>::operator=;



    FunctionBlockWrapperPtr()
        : daq::ObjectPtr<IFunctionBlockWrapper>()

    {
    }

    FunctionBlockWrapperPtr(daq::ObjectPtr<IFunctionBlockWrapper>&& ptr)
        : daq::ObjectPtr<IFunctionBlockWrapper>(std::move(ptr))

    {
    }

    FunctionBlockWrapperPtr(const daq::ObjectPtr<IFunctionBlockWrapper>& ptr)
        : daq::ObjectPtr<IFunctionBlockWrapper>(ptr)

    {
    }

    FunctionBlockWrapperPtr(const FunctionBlockWrapperPtr& other)
        : daq::ObjectPtr<IFunctionBlockWrapper>(other)

    {
    }

    FunctionBlockWrapperPtr(FunctionBlockWrapperPtr&& other) noexcept
        : daq::ObjectPtr<IFunctionBlockWrapper>(std::move(other))

    {
    }
    
    FunctionBlockWrapperPtr& operator=(const FunctionBlockWrapperPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IFunctionBlockWrapper>::operator =(other);


        return *this;
    }

    FunctionBlockWrapperPtr& operator=(FunctionBlockWrapperPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IFunctionBlockWrapper>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Includes the input port to a list of input ports on the function block.

     * @param inputPortName The name of the input port.
     */
    void includeInputPort(const daq::StringPtr& inputPortName) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->includeInputPort(inputPortName);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Excludes the input port from a list of input ports on the function block.

     * @param inputPortName The name of the input port.
     */
    void excludeInputPort(const daq::StringPtr& inputPortName) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->excludeInputPort(inputPortName);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Includes the signal to a list of signals on the function block.

     * @param signalLocalId The local id of the signal.
     */
    void includeSignal(const daq::StringPtr& signalLocalId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->includeSignal(signalLocalId);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Excludes the signal from a list of signals on the function block.

     * @param signalLocalId The name of the signal.
     */
    void excludeSignal(const daq::StringPtr& signalLocalId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->excludeSignal(signalLocalId);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Includes the property to a list of visible properties on the function block.

     * @param propertyName The name of the property.
     * Note that if the property is not visible in the wrapped function block,
     * the property will not be included. The method the return value
     * of `IFunctionBlock.GetVisibleProperties` method.
     */
    void includeProperty(const daq::StringPtr& propertyName) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->includeProperty(propertyName);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Excludes the property from a list of visible properties on the function block.

     * @param propertyName The name of the property.
     * Note that if the property is not visible in the wrapped function block,
     * this method will have no effect. The method affects the return value
     * of `IFunctionBlock.GetVisibleProperties` method.
     */
    void excludeProperty(const daq::StringPtr& propertyName) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->excludeProperty(propertyName);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Includes the function block to a list of sub-function blocks on the function block.

     * @param functionBlockLocalId The local id of the sub-function block.
     */
    void includeFunctionBlock(const daq::StringPtr& functionBlockLocalId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->includeFunctionBlock(functionBlockLocalId);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Excludes the function block from a list of sub-function blocks on the function block.

     * @param functionBlockLocalId The local id of the function block.
     */
    void excludeFunctionBlock(const daq::StringPtr& functionBlockLocalId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->excludeFunctionBlock(functionBlockLocalId);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Sets a custom coercer for the property.

     * @param propertyName The name of the property.
     * @param coercer The custom coercer.
     * The custom coercer is applied before the standard coercer of the property.
     */
    void setPropertyCoercer(const daq::StringPtr& propertyName, const daq::CoercerPtr& coercer) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setPropertyCoercer(propertyName, coercer);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Sets a custom validator for the property.

     * @param propertyName The name of the property.
     * @param validator The custom validator.
     * The custom validator is applied before the standard validator of the property.
     */
    void setPropertyValidator(const daq::StringPtr& propertyName, const daq::ValidatorPtr& validator) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setPropertyValidator(propertyName, validator);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Sets a list of accepted selection values.

     * @param propertyName The name of the property.
     * @param enumValues The list of accepted selection values. An element of a list is selection index (int).
     * The list of accepted selection values must be a subset of property selection values.
     */
    void setPropertySelectionValues(const daq::StringPtr& propertyName, const daq::ListPtr<daq::IString>& enumValues) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setPropertySelectionValues(propertyName, enumValues);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Returns the wrapped function block which was passed as a parameter to the 
     * constructor/factory.

     * @returns The wrapped function block.
     */
    daq::FunctionBlockPtr getWrappedFunctionBlock() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::FunctionBlockPtr functionBlock;
        auto errCode = this->object->getWrappedFunctionBlock(&functionBlock);
        daq::checkErrorInfo(errCode);

        return functionBlock;
    }

#if __has_include(<cqdaq/function_block_wrapper_ptr.custom.h>)
    #include <cqdaq/function_block_wrapper_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
