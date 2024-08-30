
#pragma once
#include <coretypes/version_info_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline VersionInfoPtr VersionInfo(SizeT major, SizeT minor, SizeT patch)
{
    return VersionInfoPtr(VersionInfo_Create(major, minor, patch));
}

END_NAMESPACE_CQDAQ
