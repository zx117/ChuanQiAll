#pragma once

#include "base_api_object_ptr.h"
#include "base_if_value.h"
#include "base_if_plugin.h"
#include "api_error_codes.h"
#include "api_message_ids.h"
#include "uni_defines.h"

#include <cstdint>

namespace cq
{
namespace framework
{

    class IfMessageHandler
    {
    public:
        virtual std::uint64_t pluginMessage(
            cq::PluginMessageId id,
            std::uint64_t key,
            const cq::IfValue* param,
            const cq::IfValue** ret) = 0;

        virtual void setHost(cq::IfHost* host) { CQ_UNUSED(host); };

    protected:
        virtual ~IfMessageHandler()
        {}
    };

}
}

