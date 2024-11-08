#include "loadfuncblock.h"

// #include <cqdaq/event_packet_ids.h>
// #include <cqdaq/event_packet_params.h>
// #include <cqdaq/event_packet_ptr.h>
// #include <cqdaq/data_descriptor_ptr.h>
// #include <coreobjects/eval_value_factory.h>

#include <iostream>

BEGIN_NAMESPACE_LOAD_MODULE

namespace LoadData
{

LoadFuncBlock::LoadFuncBlock(const ContextPtr& ctx, const ComponentPtr& parent, const StringPtr& localId)
    : FunctionBlock(CreateType(), ctx, parent, localId),
    inputPortCount(0)
{
    // updateInputPorts();
}

LoadFuncBlock::~LoadFuncBlock()
{

}


FunctionBlockTypePtr LoadFuncBlock::CreateType()
{
    return FunctionBlockType(
        "ref_fb_module_loader",
        "Loader",
        "Signal visualization"
        );
}

void LoadFuncBlock::updateInputPorts()
{
    // const auto inputPort = createAndAddInputPort(fmt::format("Input{}", inputPortCount++), PacketReadyNotification::SameThread);

}

void LoadFuncBlock::onConnected(const InputPortPtr &inputPort)
{
    std::cout << "========onConnected\n";
    std::scoped_lock lock(sync);
    updateInputPorts();
    LOG_T("Connected to port {}", inputPort.getLocalId());
}

void LoadFuncBlock::onDisconnected(const InputPortPtr &inputPort)
{
    std::scoped_lock lock(sync);
    updateInputPorts(); // todo zxx
    LOG_T("Disconnected from port {}", inputPort.getLocalId());
}



}
END_NAMESPACE_LOAD_MODULE
