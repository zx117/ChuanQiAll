
#pragma once

#include <coreobjects/property.h>
#include <cqdaq/function_block.h>
#include <cqdaq/channel_type.h>
#include <cqdaq/data_packet.h>
#include <mutex>


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
    virtual ErrCode INTERFACE_FUNC setChannelNodeType(ChannelType kind) = 0;
    virtual ErrCode INTERFACE_FUNC getChannelNodeType(ChannelType* kind) const = 0;
    
    virtual ErrCode INTERFACE_FUNC setSampleValueType(SampleValueType svType) = 0;
    virtual ErrCode INTERFACE_FUNC getSampleValueType(SampleValueType* svType) const = 0;

    // [elementType(packages, IDataPacket)]
    virtual ErrCode INTERFACE_FUNC getAllScaledDatas(IList** packages) = 0;

    // [elementType(packages, IDataPacket)]
    virtual ErrCode INTERFACE_FUNC getAllReducedDatas(IList** packages) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
