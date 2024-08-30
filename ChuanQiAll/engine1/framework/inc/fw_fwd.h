#pragma once

#include <memory>

namespace cq
{
namespace framework
{

    class PluginChannel;
    class PluginChannels;
    class PluginTask;
    class IfChannelProperty;
    class EditableUnsignedProperty;
    class EditableStringProperty;
    class BooleanProperty;
    class RangeProperty;
    typedef std::shared_ptr<PluginChannel> PluginChannelPtr;
    typedef std::shared_ptr<PluginChannels> PluginChannelsPtr;
    typedef std::shared_ptr<PluginTask> PluginTaskPtr;
    typedef std::shared_ptr<IfChannelProperty> ChannelPropertyPtr;


}
}
