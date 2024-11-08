#pragma once
#include <loadcommon.h>
#include <cqdaq/function_block_impl.h>
#include <cqdaq/function_block_type_factory.h>
// #include <cqdaq/sample_type.h>
// #include <cqdaq/data_packet_ptr.h>
// #include <cqdaq/sample_type_traits.h>


BEGIN_NAMESPACE_LOAD_MODULE

namespace LoadData
{



class LoadFuncBlock final : public FunctionBlock
{
public:
    explicit LoadFuncBlock(const ContextPtr& ctx, const ComponentPtr& parent, const StringPtr& localId);
    ~LoadFuncBlock() override;

    void onConnected(const InputPortPtr& port) override;
    void onDisconnected(const InputPortPtr& port) override;

    static FunctionBlockTypePtr CreateType();

private:
    void updateInputPorts();

    int inputPortCount;
};


}

END_NAMESPACE_LOAD_MODULE
