
#pragma once
#include <cstdint>
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/iterator.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_containers
 * @defgroup types_iterable Iterable
 * @{
 */

/*!
 * @brief An iterable object can construct iterators and use them to iterate through items.
 *
 * Use this interface to get the start and end iterators. Use iterators to iterate through
 * available items. Containers such as lists and dictionaries usually implement this interface.
 */
DECLARE_CQDAQ_INTERFACE(IIterable, IBaseObject)
{
    /*!
     * @brief Creates and returns the object's start iterator.
     * @param[out] iterator The object's start iterator.
     */
    virtual ErrCode INTERFACE_FUNC createStartIterator(IIterator** iterator) = 0;

    /*!
     * @brief Creates and returns the object's end iterator.
     * @param[out] iterator The object's end iterator.
     */
    virtual ErrCode INTERFACE_FUNC createEndIterator(IIterator** iterator) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
