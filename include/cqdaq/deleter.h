
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_deleter Deleter
 * @{
 */

/*!
 * @brief Callback which is called when external memory is no longer needed and can be freed.
 *
 * This interface is used with blueberry packets that are created with external memory. Provider
 * of external memory is responsible to provide a custom deleter, which is called when the packet is
 * destroyed.
 */
DECLARE_CQDAQ_INTERFACE(IDeleter, IBaseObject)
{
    /*!
     * @brief Deletes or frees the memory associated with `address` parameter.
     * @param[out] address The address of the external memory.
     */
    virtual ErrCode INTERFACE_FUNC deleteMemory(void* address) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
