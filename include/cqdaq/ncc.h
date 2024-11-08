
#pragma once
#include <cqdaq/logger.h>
#include <cqdaq/worker.h>
#include <cqdaq/channel.h>
#include <cqdaq/device.h>


BEGIN_NAMESPACE_CQDAQ

enum class OperationMode : EnumType
{
    Configuration,
    Operation,
    Realtime
};

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_ncc Ncc
 * @{
 */

/*!
 * @brief The ncc object. 
 *
 * It forwards all Device and PropertyObject calls to the current root device, making the calls on the Instance
 * and root device equivalen.
 */
DECLARE_CQDAQ_INTERFACE(INcc, IWorker)
{
    virtual ErrCode INTERFACE_FUNC getStartAbsTime(Int* value) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, Ncc,
    IDevice*, device,
    ILogger*, logger
)


END_NAMESPACE_CQDAQ
