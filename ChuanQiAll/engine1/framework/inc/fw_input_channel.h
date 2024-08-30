#pragma once

#define EXTENSION_FUNCTIONS
#include "base_if_host.h"
#include "base_basic_values.h"

#include "api_channel_dataformat_xml.h"
#include "api_property_xml.h"
#include "api_timebase_xml.h"
#include "api_chuanqi_queries.h"
#include "api_update_config_xml.h"

#include "uni_xpugixml.h"

#include <cstdint>
#include <string>
#include <vector>


namespace cq
{
namespace framework
{

    class InputChannel;
    typedef std::shared_ptr<InputChannel> InputChannelPtr;

    class InputChannel
    {
    public:
        struct InputChannelData
        {
            std::uint64_t m_channel_id;
            cq::ChannelDataformat dataformat;
            cq::Timebase m_time_base;
        };

        InputChannel(cq::IfHost* host, std::uint64_t channel_id,
            cq::ChannelDataformat dataformat = {})
            : m_input_channel_data({channel_id, dataformat, cq::Timebase()})
            , m_host(host)
        {}

        virtual ~InputChannel() = default;

        void setChannelId(std::uint64_t id);

        std::uint64_t getChannelId() const;

        bool isUsable() const;

        bool isIdValid() const;

        cq::ChannelDataformat getDataFormat() const;

        cq::Timebase getTimeBase() const;

        bool updateTimeBase();

        bool updateDataFormat();

        cq::Range getRange() const;

        cq::Scalar getSampleRate() const;

        std::string getUnit() const;

        std::string getName() const;

        std::string getLongName() const;

        std::string getDefaultName() const;

        Property getConfigProperty(const std::string& key) const;
        void setConfigProperty(const std::string& key, const Property& property);

        std::vector<cq::UpdateConfigTelegram::Constraint> getConfigPropertyConstraints(const std::string& key) const;

    private:
        template <class T>
        cq::detail::ApiObjectPtr<const T> getInputChannelParam(const char* const key) const
        {
            if (isIdValid())
            {
                std::string channel_context = cq::queries::ChuanQiChannels;
                channel_context += "#";
                channel_context += std::to_string(getChannelId());

                return m_host->getValue<T>(channel_context.c_str(), key);
            }
            return cq::detail::ApiObjectPtr<const T>{};
        }

        template <class T>
        cq::detail::ApiObjectPtr<const T> getInputChannelConfigParam(const char* const key) const
        {
            if (isIdValid())
            {
                std::string channel_context = cq::queries::ChuanQiChannels;
                channel_context += "#";
                channel_context += std::to_string(getChannelId());
                channel_context += "#Config#";
                channel_context += key;

                return m_host->getValue<T>(channel_context.c_str(), "Value");
            }
            return cq::detail::ApiObjectPtr<const T>{};
        }

        std::string extractDataFormat(const cq::IfXMLValue& xml_value) const;

    private:
        InputChannelData m_input_channel_data;
        cq::IfHost* m_host;
    };

}
}
