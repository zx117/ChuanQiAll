
#pragma once
#include <cqdaq/packet_destruct_callback.h>
#include <coretypes/intfs.h>

BEGIN_NAMESPACE_CQDAQ

template <class Callback>
class PacketDestructCallbackImpl : public ImplementationOf<IPacketDestructCallback>
{
public:
    explicit PacketDestructCallbackImpl(Callback callback)
        : callback(callback)
    {
    }

    ErrCode INTERFACE_FUNC onPacketDestroyed() override
    {
        callback();
        return CQDAQ_SUCCESS;
    }

private:
    Callback callback;
};

END_NAMESPACE_CQDAQ
