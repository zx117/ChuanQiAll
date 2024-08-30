

#pragma once
#include <cqdaq/data_descriptor.h>
#include <coretypes/baseobject.h>
#include <coretypes/common.h>
#include <cqdaq/deleter.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_utility
 * @addtogroup cqdaq_allocator Allocator
 * @{
 */

/*!
 * @brief An allocator used to allocate memory.
 *
 * The default BB allocator simply uses `malloc`, but the user can implement a custom allocator to
 * override this behavior (perhaps using a memory pool or different allocation strategy). An
 * example/reference implementation is provided which uses Microsoft `mimalloc`.
 */
DECLARE_CQDAQ_INTERFACE(IAllocator, IBaseObject)
{
    /*!
     * @brief Allocates a chunk of memory for a packet.
     * @param descriptor The OPTIONAL data descriptor of the signal for which memory is to be
     *                   allocated. This can provide hints to the allocator. However, allocator
     *                   implementations MUST accept null values.
     * @param bytes The number of bytes to allocate.
     * @param align The alignment requirement of the caller (typically the element size). This
     *              value may be zero if the caller does not need to specify an alignment
     *              requirement.
     * @param[out] address The address of the allocated memory.
     *
     * The implementation MAY set address value to `nullptr` without returning an error code,
     * if the allocator is out of memory. Alternatively, the implementation MAY return an error
     * code in this case.
     */
    virtual ErrCode INTERFACE_FUNC allocate(
        const IDataDescriptor *descriptor,
        daq::SizeT bytes,
        daq::SizeT align,
        void** address) = 0;

    /*!
     * @brief Releases a chunk of memory allocated by allocate().
     * @param address The address of the allocated memory to release.
     *
     * The implementation MUST ignore calls where @p address is null.
     */
    virtual ErrCode INTERFACE_FUNC free(void* address) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, MallocAllocator,
    IAllocator
)

#ifdef CQDAQ_MIMALLOC_SUPPORT
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, MiMallocAllocator,
    IAllocator
)
#endif

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, ExternalAllocator,
    IAllocator,
    void*, data,
    IDeleter*, deleter
)

END_NAMESPACE_CQDAQ
