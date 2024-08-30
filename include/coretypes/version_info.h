
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_utility
 * @defgroup types_version_info VersionInfo
 * @{
 */

/*!
 * @brief Represents a semantic version
 * composing of:
 *  - major version representing breaking changes
 *  - minor version representing new features
 *  - patch version representing only bug fixes.
 */
DECLARE_CQDAQ_INTERFACE(IVersionInfo, IBaseObject)
{
    /*!
     * @brief The major version incremented at breaking changes.
     * @param[out] major The major version component.
     */
    virtual ErrCode INTERFACE_FUNC getMajor(SizeT* major) = 0;

    /*!
     * @brief The minor version incremented at new features with full backwards compatibility.
     * @param[out] minor The minor version component.
     */
    virtual ErrCode INTERFACE_FUNC getMinor(SizeT* minor) = 0;

    /*!
     * @brief The patch version incremented when only bug-fixes are added.
     * @param[out] patch The patch version component.
     */
    virtual ErrCode INTERFACE_FUNC getPatch(SizeT* patch) = 0;
};

/*!
 * @}
 */

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, VersionInfo, SizeT, major, SizeT, minor, SizeT, patch);

END_NAMESPACE_CQDAQ
