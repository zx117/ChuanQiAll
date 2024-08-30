
#pragma once

#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_input_port Input port
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(IInputPortPrivate, IBaseObject)
{
    /*!
     * @brief Disconnects the signal without notification to the signal.
     */
    virtual ErrCode INTERFACE_FUNC disconnectWithoutSignalNotification() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
