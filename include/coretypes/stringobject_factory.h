
#pragma once
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline StringPtr String(ConstCharPtr str)
{
    StringPtr obj(String_Create(str));
    return obj;
}

inline StringPtr String(ConstCharPtr str, SizeT length)
{
    StringPtr obj(StringN_Create(str, length));
    return obj;
}

inline StringPtr String(const std::string& str)
{
    StringPtr obj(String_Create(str.c_str()));
    return obj;
}

inline StringPtr operator"" _daq(const char* str)
{
    return String(str);
}

inline StringPtr operator"" _daq(const char* str, std::size_t length)
{
    return String(str, length);
}

inline StringPtr operator+(const char lhs[], const StringPtr& rhs)
{
    return String(std::string(lhs) + rhs.toStdString());
}

inline StringPtr operator+(const std::string& lhs, const StringPtr& rhs)
{
    return String(lhs + rhs.toStdString());
}

END_NAMESPACE_CQDAQ
