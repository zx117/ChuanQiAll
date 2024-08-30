
#pragma once
#include <coretypes/binarydata.h>
#include <coretypes/intfs.h>
#include <coretypes/coretype.h>

BEGIN_NAMESPACE_CQDAQ

class BinaryDataImpl : public ImplementationOf<IBinaryData, ICoreType>
{
public:
    explicit BinaryDataImpl(SizeT size);

    ErrCode INTERFACE_FUNC getAddress(void** data) override;
    ErrCode INTERFACE_FUNC getSize(SizeT* size) override;

    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

protected:
    void internalDispose(bool) override;

private:
    char* data;
    size_t size;
};

END_NAMESPACE_CQDAQ
