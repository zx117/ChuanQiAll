
#pragma once
#include <cstdint>
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_containers
 * @{
 */

/*!
 * @brief Use this interface to iterator through items of a container object.
 *
 * Call moveNext function in a loop until it returns CQDAQ_NO_MORE_ITEMS. Iteration
 * cannot be restarted. In this case a new iterator must be created.
 *
 * Example:
 * @code
 * IIterator* it = ...;
 *
 * while (it->moveNext() != CQDAQ_NO_MORE_ITEMS)
 * {
 *      IBaseObject* obj;
 *      it->getCurrent(&obj);
 *      // do something with obj
 * }
  @endcode
 */
DECLARE_CQDAQ_INTERFACE(IIterator, IBaseObject)
{
    /*!
     * @brief Moves iterator to next position.
     */
    virtual ErrCode INTERFACE_FUNC moveNext() = 0;

    /*!
     * @brief Gets the object at current iterator position.
     * @param[out] obj Object at current iterator position.
     * @retval CQDAQ_NO_MORE_ITEMS Iterator is over the last item position.
     */
    virtual ErrCode INTERFACE_FUNC getCurrent(IBaseObject** obj) const = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
