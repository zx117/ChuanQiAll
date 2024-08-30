#pragma once

#include "fw_fwd.h"

#include "api_update_config_xml.h"
#include "uni_defines.h"
#include "api_timestamp_xml.h"
#include "base_basic_values.h"

#include <string>
#include <cstdint>

namespace cq
{
namespace framework
{

    class IfPluginChannelChangeListener
    {
    public:
        virtual void onChannelSetupChanged(const PluginChannel* channel) = 0;
        virtual void onChannelPropertyChanged(const PluginChannel* channel, const std::string& name) = 0;
        virtual bool configChangeAllowed() const = 0;
    protected:
        virtual ~IfPluginChannelChangeListener() = default;
    };

    class IfChannelPropertyChangeListener
    {
    public:
        virtual void onChannelPropertyChanged(const IfChannelProperty* channel) = 0;
    protected:
        virtual ~IfChannelPropertyChangeListener() = default;
    };

    class IfPluginTaskChangeListener
    {
    public:
        virtual void onTaskChannelAdded(PluginTask* task, const PluginChannel* channel) = 0;
        virtual void onTaskChannelRemoved(PluginTask* task, const PluginChannel* channel) = 0;
        virtual void onTaskInputChannelsChanged(PluginTask* task) = 0;
    protected:
        virtual ~IfPluginTaskChangeListener() = default;
    };


    class IfChannelProperty
    {
    public:
        virtual void setChangeListener(IfChannelPropertyChangeListener* l) = 0;
        virtual void addToTelegram(cq::UpdateConfigTelegram::ChannelConfig& telegram, const std::string& property_name) const = 0;
        virtual bool update(const cq::Property& value) = 0;
    protected:
        virtual ~IfChannelProperty() = default;
    };

    class IfTaskWorker
    {
    public:
        virtual void onInitTimebases(cq::IfHost* host, std::uint64_t token) { CQ_UNUSED(host); CQ_UNUSED(token); }
        virtual void onStartProcessing(cq::IfHost* host, std::uint64_t token) { CQ_UNUSED(host); CQ_UNUSED(token); }
        virtual void onProcess(cq::IfHost* host, std::uint64_t token, const cq::IfXMLValue* param) = 0;
        virtual void onStopProcessing(cq::IfHost* host, std::uint64_t token) { CQ_UNUSED(host); CQ_UNUSED(token); }
        virtual void onChannelConfigChanged(cq::IfHost* host, std::uint64_t token) { CQ_UNUSED(host); CQ_UNUSED(token); };

        virtual void onChannelDataformatChanged(std::uint64_t channel_id) { CQ_UNUSED(channel_id); };
    protected:
        virtual ~IfTaskWorker() = default;
    };

}
}
