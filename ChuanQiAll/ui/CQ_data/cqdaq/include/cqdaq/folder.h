
#pragma once

#include <cqdaq/component.h>
#include <cqdaq/search_filter.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_folder Folder
 * @{
 */

/*#
 * [interfaceSmartPtr(IComponent, GenericComponentPtr, "<cqdaq/component_ptr.h>")]
 * [templated(defaultAliasName: FolderPtr)]
 * [interfaceSmartPtr(IFolder, GenericFolderPtr)]
 */


/*!
 * @brief Acts as a container for other components
 *
 * Other components use the folder component to organize the children components, 
 * such as channels, signals, function blocks, etc.
 */
DECLARE_CQDAQ_INTERFACE(IFolder, IComponent)
{
    // [elementType(items, IComponent)]
    /*!
     * @brief Gets the list of the items in the folder.
     * @param searchFilter Provides an optional filter that filters out unwanted components and allows for recursion.
     * @param[out] items The list of the items.
     *
     * If searchFilter is not provided, the returned list contains only immediate children with visible set to `true`.
     */
    virtual ErrCode INTERFACE_FUNC getItems(IList** items, ISearchFilter* searchFilter = nullptr) = 0;

    /*!
     * @brief Returns True if the folder is empty.
     * @param[out] empty True if the folder is empty.
     */
    virtual ErrCode INTERFACE_FUNC isEmpty(Bool* empty) = 0;

    /*!
     * @brief Returns True if the folder has an item with local ID.
     * @param localId The local ID of the item.
     * @param[out] value True if the folder contains item with local ID.
     */
    virtual ErrCode INTERFACE_FUNC hasItem(IString* localId, Bool* value) = 0;

    // [templateType(item, IComponent)]
    /*!
     * @brief Gets the item component with the specified localId.
     * @param localId The local id of the child component.
     * @param[out] item The item component.
     * @retval CQDAQ_SUCCESS if succeeded.
     * @retval CQDAQ_NOT_FOUND if folder with the specified ID not found.
     */
    virtual ErrCode INTERFACE_FUNC getItem(IString* localId, IComponent** item) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
