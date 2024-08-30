
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/number_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_scaling Data rule
 * @{
 */

/*!
 * @brief Internal functions used by cqDAQ core. This interface should never be used in
 * client SDK or module code.
 */
DECLARE_CQDAQ_INTERFACE(IDataRuleCalcPrivate, IBaseObject)
{
    /*!
     * @brief Calculates the data according to the rule.
     * @param packetOffset Packet offset.
     * @param sampleCount The number of samples in the packet.
     * @returns A pointer to the calculated data.
     */
    virtual void* INTERFACE_FUNC calculateRule(const NumberPtr& packetOffset, SizeT sampleCount, void* input, SizeT inputSize) const = 0;

    /*!
     * @brief Calculates the data according to the rule.
     * @param packetOffset Packet offset.
     * @param sampleCount The number of samples in the packet.
     * @param[out] output A pointer to the calculated data.
     */
    virtual void INTERFACE_FUNC calculateRule(const NumberPtr& packetOffset, SizeT sampleCount, void* input, SizeT inputSize, void** output)
        const = 0;

    /*!
     * @brief Checks whether the Data Rule Calculator is available for packet or not.
     * @returns True if the Data Rule Calculator is initialized within the implementation; false otherwise.
     */
    virtual bool INTERFACE_FUNC hasDataRuleCalc() const = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
