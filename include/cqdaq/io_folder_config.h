
#pragma once

#include <cqdaq/folder_config.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component IoFolder
 * @{
 */

/*#
 * [interfaceSmartPtr(IFolderConfig, GenericFolderConfigPtr, "<cqdaq/folder_config_ptr.h>")]
 */

/*!
 * @brief Acts as a container for channels and other io folders.
 *
 * Every device has an IO folder, which allows only other IO folders and
 * channels as children.
 */
DECLARE_CQDAQ_INTERFACE(IIoFolderConfig, IFolderConfig)
{
};
/*!@}*/

END_NAMESPACE_CQDAQ
