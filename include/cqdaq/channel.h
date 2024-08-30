
#pragma once
#include <cqdaq/function_block.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IFunctionBlock, GenericFunctionBlockPtr)]
 */

/*!
 * @ingroup cqdaq_function_blocks
 * @addtogroup cqdaq_channel Channel
 * @{
 */

/*!
 * @brief Channels represent physical sensors of cqDAQ devices. Internally
 * they are standard function blocks with an additional option to provide a list of
 * tags.
 */
DECLARE_CQDAQ_INTERFACE(IChannel, IFunctionBlock)
{
};
/*!@}*/

END_NAMESPACE_CQDAQ
