
#pragma once
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_utility
 * @addtogroup cqdaq_tags Tags private
 * @{
 */

/*!
 * @brief Private interface to component tags. Allows for adding/removing tags.
 *
 * Modifying the tags of a component might have unintended sideffects and should in most cases only be done
 * by the component owner module.
 */
DECLARE_CQDAQ_INTERFACE(ITagsPrivate, IBaseObject)
{
    /*!
     * @brief Adds a new tag to the list.
     * @param name The name of the tag to be added.
     * @retval CQDAQ_IGNORED if a node with the `name` is already in the list of tags.
     */
    virtual ErrCode INTERFACE_FUNC add(IString* name) = 0;

    /*!
     * @brief Removes a new tag from the list.
     * @param name The name of the tag to be removed.
     * @retval CQDAQ_IGNORED if a node with the `name` is not in the list of tags.
     */
    virtual ErrCode INTERFACE_FUNC remove(IString* name) = 0;

    // [templateType(tags, IString)]
    /*!
     * @brief Replaces all tags.
     * @param tags The new list of tags.
     */
    virtual ErrCode INTERFACE_FUNC replace(IList* tags) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
