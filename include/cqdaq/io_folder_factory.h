
#pragma once
#include <cqdaq/io_folder_config_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @brief Creates an IO folder.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Folder.
 * @param parent The parent component.
 * @param localId The local ID of the parent.
 * @param propertyMode Enum defining whether standard properties such as "Name" and "Description" are created.
 *                     "Add" to create the default properties; "AddReadOnly" to create the properties, but configure them as "read-only";
 *                     "Skip" to skip creation.
 *
 * IO folders are folder created by device and may contain only channels and other IO folders.
 */
inline IoFolderConfigPtr IoFolder(const ContextPtr& context,
                                  const ComponentPtr& parent,
                                  const StringPtr& localId)
{
    IoFolderConfigPtr obj(IoFolder_Create(context, parent, localId));
    return obj;
}


END_NAMESPACE_CQDAQ
