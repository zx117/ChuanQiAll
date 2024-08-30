
#pragma once
#include <coretypes/version_info.h>
#include <coretypes/intfs.h>

BEGIN_NAMESPACE_CQDAQ

class VersionInfoImpl : public ImplementationOf<IVersionInfo>
{
public:
    VersionInfoImpl(SizeT major, SizeT minor, SizeT patch);

    ErrCode INTERFACE_FUNC getMajor(SizeT* major) override;
    ErrCode INTERFACE_FUNC getMinor(SizeT* minor) override;
    ErrCode INTERFACE_FUNC getPatch(SizeT* patch) override;

private:
    SizeT major;
    SizeT minor;
    SizeT patch;
};

END_NAMESPACE_CQDAQ
