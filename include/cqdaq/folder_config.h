
#pragma once

#include <cqdaq/folder.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_folder Folder
 * @{
 */

/*#
 * [interfaceSmartPtr(IFolder, GenericFolderPtr, "<cqdaq/folder_ptr.h>")]
 * [templated(defaultAliasName: FolderConfigPtr)]
 * [interfaceSmartPtr(IFolderConfig, GenericFolderConfigPtr)]
 */

/*!
 * @brief Allows write access to folder.
 *
 * Provides methods to add and remove items to the folder.
 */
DECLARE_CQDAQ_INTERFACE(IFolderConfig, IFolder)
{
    /*!
     * @brief Adds a component to the folder.
     * @param item The component.
     */
    virtual ErrCode INTERFACE_FUNC addItem(IComponent* item) = 0;

    /*!
     * @brief Removes the item from the folder.
     * @param item The item component.
     */
    virtual ErrCode INTERFACE_FUNC removeItem(IComponent* item) = 0;

    /*!
     * @brief Removes the item from the folder using local id of the component.
     * @param localId The local id of the component.
     */
    virtual ErrCode INTERFACE_FUNC removeItemWithLocalId(IString* localId) = 0;

    /*!
     * @brief Removes all items from the folder.
     */
    virtual ErrCode INTERFACE_FUNC clear() = 0;
};
/*!@}*/

/*!
 * @ingroup cqdaq_folder
 * @addtogroup cqdaq_folder_factories Folder
 * @{
 */

/*!
 * @brief Creates a folder.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Folder.
 * @param parent The parent component.
 * @param localId The local ID of the component.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, Folder, IFolderConfig,
    IContext*, context,
    IComponent*, parent,
    IString*, localId)

/*!
 * @brief Creates a folder with an interface ID that must be implemented by its children.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Folder.
 * @param itemType The ID of interface that child objects of the folder must implement.
 * @param parent The parent component.
 * @param localId The local ID of the component.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, FolderWithItemType, IFolderConfig,
    IntfID, itemType,
    IContext*, context,
    IComponent*, parent,
    IString*, localId)

/*!
 * @brief Creates an IO folder.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Folder.
 * @param parent The parent component.
 * @param localId The local ID of the parent.
 *
 * IO folders are folder created by device and may contain only channels and other IO folders.
 */
CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, IoFolder, IFolderConfig,
    IContext*, context,
    IComponent*, parent,
    IString*, localId)

/*!@}*/

END_NAMESPACE_CQDAQ
