
#pragma once
#include <coretypes/errorinfo.h>
#include <coretypes/freezable.h>
#include <coretypes/intfs.h>

BEGIN_NAMESPACE_CQDAQ

class ErrorInfoImpl : public ImplementationOf<IErrorInfo, IFreezable>
{
public:
    ErrorInfoImpl();
    ~ErrorInfoImpl() override;

    ErrCode INTERFACE_FUNC setMessage(IString* message) override;
    ErrCode INTERFACE_FUNC getMessage(IString** message) override;
    ErrCode INTERFACE_FUNC getSource(IString** source) override;
    ErrCode INTERFACE_FUNC setSource(IString* source) override;

    ErrCode INTERFACE_FUNC freeze() override;
    ErrCode INTERFACE_FUNC isFrozen(Bool* frozen) const override;

private:
    IString* message;
    IString* source;
    Bool frozen;
};

class ErrorInfoHolder
{
public:
    ErrorInfoHolder();
#ifndef __MINGW32__
    ~ErrorInfoHolder();
#endif

    void setErrorInfo(IErrorInfo* errorInfo);
    IErrorInfo* getErrorInfo() const;
private:
    IErrorInfo* errorInfo;
};

END_NAMESPACE_CQDAQ
