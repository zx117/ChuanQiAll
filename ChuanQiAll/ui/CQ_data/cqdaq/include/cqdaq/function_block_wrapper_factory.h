
#pragma once
#include <cqdaq/function_block_wrapper_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_function_block
 * @addtogroup cqdaq_function_block_factories Factories
 * @{
 */

/*!
 * @brief Creates a FunctionBlockWrapper from an existing function block instance.
 * @param functionBlock The existing function block.
 * @param includeInputPortsByDefault If true, input ports will be included in the list of input ports by default.
 * @param includeSignalsByDefault If true, signals will be included in the list of signals by default.
 * @param includePropertiesByDefault If true, properties will be included in the list of properties by default.
 * @param includeFunctionBlocksByDefault If true, function blocks will be included in the list of sub-function blocks by default.
 */
inline FunctionBlockPtr FunctionBlockWrapper(
    const FunctionBlockPtr& functionBlock,
    Bool includeInputPortsByDefault,
    Bool includeSignalsByDefault,
    Bool includePropertiesByDefault,
    Bool includeFunctionBlocksByDefault)
{
    FunctionBlockPtr obj(FunctionBlockWrapper_Create(functionBlock, includeInputPortsByDefault, includeSignalsByDefault, includePropertiesByDefault, includeFunctionBlocksByDefault));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
