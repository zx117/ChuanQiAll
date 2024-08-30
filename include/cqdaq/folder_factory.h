
#pragma once
#include <cqdaq/folder_config_ptr.h>

BEGIN_NAMESPACE_CQDAQ

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
template <class TInterface = IComponent>
inline FolderConfigPtr Folder(const ContextPtr& context, const ComponentPtr& parent, const StringPtr& localId)
{
    FolderConfigPtr obj(FolderWithItemType_Create(TInterface::Id, context, parent, localId));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
