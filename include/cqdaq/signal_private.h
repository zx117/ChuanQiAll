
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_signals
 * @addtogroup cqdaq_signal Signal
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(ISignalPrivate, IBaseObject)
{
    /*!
     * @brief Sets the domain signal to null without notifying the domain signal
     */
    virtual ErrCode INTERFACE_FUNC clearDomainSignalWithoutNotification() = 0;

    /*!
     * @brief Enable or disable keeping last data packet which is using by Signal method `getLastValue` 
     * @param enabled Option for enabling method getLastValue
     */
    virtual ErrCode INTERFACE_FUNC enableKeepLastValue(Bool enabled) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
