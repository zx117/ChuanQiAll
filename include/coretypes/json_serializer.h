
#pragma once

BEGIN_NAMESPACE_CQDAQ

extern "C"
ErrCode PUBLIC_EXPORT createJsonSerializer(ISerializer** obj, Bool pretty = False);

inline ISerializer* JsonSerializer_Create(Bool pretty = False)
{
    ISerializer* obj;
    ErrCode res = createJsonSerializer(&obj, pretty);
    if (CQDAQ_SUCCEEDED(res))
        return obj;

    throw std::bad_alloc();
}

END_NAMESPACE_CQDAQ
