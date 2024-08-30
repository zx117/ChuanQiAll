
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_scaling Scaling
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(IScalingCalcPrivate, IBaseObject)
{
    /*!
     * @brief Scales the packet data.
     * @param data Pointer to the packet data.
     * @param sampleCount The number of samples in the packet.
     * @returns A pointer to the scaled data.
     */
    virtual void* INTERFACE_FUNC scaleData(void* data, SizeT sampleCount) const = 0;

    /*!
     * @brief Scales the packet data.
     * @param data Pointer to the packet data.
     * @param sampleCount The number of samples in the packet.
     * @param[out] A pointer to the scaled data.
     */
    virtual void INTERFACE_FUNC scaleData(void* data, SizeT sampleCount, void** output) const = 0;

    /*!
     * @brief Checks whether the Scaling Calculator is available for packet or not.
     * @return True if the Scaling Calculator is initialized within the implementation; false otherwise.
     */
    virtual bool INTERFACE_FUNC hasScalingCalc() const = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
