
#pragma once
#include <cqdaq/deleter_impl.h>
#include <cqdaq/deleter_ptr.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_deleter
 * @addtogroup cqdaq_deleter_factories Factories
 * @{
 */

/*!
 * @brief Creates a deleter callback which is called when external memory is no longer needed and can be freed.
 *
 * This object returned is used with blueberry packets that are created with external memory. Provider
 * of external memory is responsible to provide a custom deleter, which is called when the packet is
 * destroyed.
 */
template <class Callback>
DeleterPtr Deleter(Callback&& callback)
{
    auto obj = createWithImplementation<IDeleter, DeleterImpl<Callback>>(std::forward<Callback>(callback));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
