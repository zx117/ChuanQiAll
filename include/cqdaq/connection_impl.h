
#pragma once
#include <cqdaq/connection.h>
#include <cqdaq/input_port_config_ptr.h>
#include <cqdaq/context_ptr.h>
#include <coretypes/intfs.h>
#include <coretypes/weakrefobj.h>

#ifdef CQDAQ_THREAD_SAFE
    #include <mutex>
#endif

#include <queue>

BEGIN_NAMESPACE_CQDAQ

class ConnectionImpl : public ImplementationOfWeak<IConnection>
{
public:
    explicit ConnectionImpl(
        const InputPortPtr& port,
        const SignalPtr& signal,
        ContextPtr context
    );

    ErrCode INTERFACE_FUNC enqueue(IPacket* packet) override;
    ErrCode INTERFACE_FUNC enqueueOnThisThread(IPacket* packet) override;
    ErrCode INTERFACE_FUNC dequeue(IPacket** packet) override;
    ErrCode INTERFACE_FUNC peek(IPacket** packet) override;
    ErrCode INTERFACE_FUNC getPacketCount(SizeT* packetCount) override;
    ErrCode INTERFACE_FUNC getSignal(ISignal** signal) override;
    ErrCode INTERFACE_FUNC getInputPort(IInputPort** inputPort) override;

    ErrCode INTERFACE_FUNC getAvailableSamples(SizeT* samples) override;
    ErrCode INTERFACE_FUNC getSamplesUntilNextDescriptor(SizeT* samples) override;

    ErrCode INTERFACE_FUNC isRemote(Bool* remote) override;

    [[nodiscard]] const std::deque<PacketPtr>& getPackets() const noexcept;

#ifdef CQDAQ_THREAD_SAFE
    template <typename Func>
    auto withLock(Func&& func) const
    {
        std::lock_guard guard(mutex);
        return func();
    }
#else
    template <typename Func>
    auto withLock(Func&& func) const
    {
        return func();
    }
#endif

private:
    InputPortConfigPtr port;
    WeakRefPtr<ISignal> signalRef;
    ContextPtr context;

#ifdef CQDAQ_THREAD_SAFE
    mutable std::mutex mutex;
#endif

protected:
    std::deque<PacketPtr> packets;
};

END_NAMESPACE_CQDAQ
