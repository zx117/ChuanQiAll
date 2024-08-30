
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_containers
 * @defgroup types_binary_data BinaryData
 * @{
 */

/*!
 * @brief Represents binary large object (BLOB).
 *
 * Binary data is just a continuously allocated memory of a specific size. A client can get a pointer to
 * internal buffer and size it.
 */
DECLARE_CQDAQ_INTERFACE(IBinaryData, IBaseObject)
{
    /*!
     * @brief Gets the address of the buffer.
     * @param[out] data The buffer's starting address.
     */
    virtual ErrCode INTERFACE_FUNC getAddress(void** data) = 0;
    /*!
     * @brief Gets the size of the buffer.
     * @param[out] size The buffer's size.
     */
    virtual ErrCode INTERFACE_FUNC getSize(SizeT * size) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, BinaryData, const SizeT, size)

END_NAMESPACE_CQDAQ
