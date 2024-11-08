//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:35.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/function_block_type.h"
#include <coreobjects/component_type_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class FunctionBlockTypePtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IFunctionBlockType>
{
    using SmartPtr = daq::FunctionBlockTypePtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_function_blocks
 * @addtogroup cqdaq_function_block_type Function block type
 * @{

 */


/*!
 * @brief Provides information about the function block.

 */

class FunctionBlockTypePtr : public GenericComponentTypePtr<IFunctionBlockType>
{
public:
    using GenericComponentTypePtr<IFunctionBlockType>::GenericComponentTypePtr;
    //using GenericComponentTypePtr<IFunctionBlockType>::operator=;



    FunctionBlockTypePtr()
        : GenericComponentTypePtr<IFunctionBlockType>()

    {
    }

    FunctionBlockTypePtr(daq::ObjectPtr<IFunctionBlockType>&& ptr)
        : GenericComponentTypePtr<IFunctionBlockType>(std::move(ptr))

    {
    }

    FunctionBlockTypePtr(const daq::ObjectPtr<IFunctionBlockType>& ptr)
        : GenericComponentTypePtr<IFunctionBlockType>(ptr)

    {
    }

    FunctionBlockTypePtr(const FunctionBlockTypePtr& other)
        : GenericComponentTypePtr<IFunctionBlockType>(other)

    {
    }

    FunctionBlockTypePtr(FunctionBlockTypePtr&& other) noexcept
        : GenericComponentTypePtr<IFunctionBlockType>(std::move(other))

    {
    }
    
    FunctionBlockTypePtr& operator=(const FunctionBlockTypePtr& other)
    {
        if (this == &other)
            return *this;

        GenericComponentTypePtr<IFunctionBlockType>::operator =(other);


        return *this;
    }

    FunctionBlockTypePtr& operator=(FunctionBlockTypePtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericComponentTypePtr<IFunctionBlockType>::operator =(std::move(other));

        return *this;
    }




#if __has_include(<cqdaq/function_block_type_ptr.custom.h>)
    #include <cqdaq/function_block_type_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @ingroup cqdaq_function_block_type
 * @addtogroup cqdaq_function_block_type_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ
