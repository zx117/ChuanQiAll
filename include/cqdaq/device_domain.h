

#pragma once
#include <coreobjects/unit.h>
#include <coretypes/ratio.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_device_domain Device domain
 * @{
 */

/*#
 * [interfaceLibrary(IUnit, CoreObjects)]
 */

/*!
 * @brief Contains information about the domain of the device.
 *
 * The device domain contains a general view into the device's domain data. While devices most often operate
 * in the time domain, this interface allows for description of any other domain commonly used in signal processing.
 * For example, common domains include the angle domain, frequency domain, the spatial domain, and the wavelet domain.
 *
 * The device domain allows for users to query a device for its current domain value via `getTicksSinceOrigin`
 * and convert that into its domain unit by multiplying the tick count with the resolution. To get the absolute
 * domain value, we can then also add the value to the Origin, which is most often provided
 * as a time epoch in the ISO 8601 format.
 *
 * Note that all devices might note provide a device domain implementation. Such devices cannot be directly queried
 * for their domain data. In such a case, the domain data can be obtained through the device's output signals.
 */
DECLARE_CQDAQ_INTERFACE(IDeviceDomain, IBaseObject)
{
    /*!
     * @brief Gets domain (usually time) between two consecutive ticks. Resolution is provided in a domain unit.
     * @param[out] tickResolution The device's resolution.
     */
    virtual ErrCode INTERFACE_FUNC getTickResolution(IRatio** tickResolution) = 0;

    /*!
     * @brief Gets the device's absolute origin. Most often this is a time epoch in the ISO 8601 format.
     * @param[out] origin The origin.
     */
    virtual ErrCode INTERFACE_FUNC getOrigin(IString** origin) = 0;

    /*!
     * @brief Gets the domain unit (eg. seconds, hours, degrees...)
     * @param[out] unit The domain unit.
     */
    virtual ErrCode INTERFACE_FUNC getUnit(IUnit** unit) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, DeviceDomain,
    IRatio*, tickResolution,
    IString*, origin,
    IUnit*, unit
)


END_NAMESPACE_CQDAQ
