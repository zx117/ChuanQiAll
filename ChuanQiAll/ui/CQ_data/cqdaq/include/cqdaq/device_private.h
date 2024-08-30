
#pragma once

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_device Device private
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IDevicePrivate, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC setAsRoot() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
