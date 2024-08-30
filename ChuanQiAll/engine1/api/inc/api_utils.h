#pragma once

#define EXTENSION_FUNCTIONS //enable C++ integration

#include "base_if_host_fwd.h"
#include "base_basic_values.h"

#include "api_timestamp_xml.h"

#include "uni_defines.h"

#include <cmath>
#include <cstring>
#include <limits>

namespace cq
{
    CQ_NODISCARD bool isAnalysisModeActive(cq::IfHost* host);

    CQ_NODISCARD cq::Timestamp getMasterTimestamp(cq::IfHost* host);

    CQ_NODISCARD cq::AbsoluteTime getAcquisitionStartTime(cq::IfHost* host);

    CQ_NODISCARD cq::AbsoluteTime getMeasurementStartTime(cq::IfHost* host);

    /**
     * Sends a cq::host_msg::ADD_CONTIGUOUS_SAMPLES message to the host
     */
    void addSamples(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp, const void* data, size_t data_size);

    /**
     * Sends a cq::host_msg::ADD_SAMPLE message to the host
     */
    void addSample(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp, const void* data, size_t data_size);

    template <class T>
    inline void addSample(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp, const T& data)
    {
        addSample(host, local_channel_id, timestamp, &data, sizeof(T));
    }

    void updateChannelState(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp);

    template <class T>
    bool parseXMLValue(const cq::IfValue* param, T& parser)
    {
        if (param && param->getType() == cq::IfValue::Type::TYPE_XML)
        {
            auto xml_value = static_cast<const cq::IfXMLValue*>(param);
            return parser.parse(xml_value->getValue());
        }
        return false;
    }

    std::uint64_t sendSyncXMLMessage(cq::IfHost* host, cq::MessageId msg_id, std::uint64_t key, const char* param_data, size_t param_size, const cq::IfValue** ret);

    /**
     * Convert from seconds to ticks
     *
     * @param time      sample time in seconds
     * @param frequency sample rate in Hz
     * @return          tick value
     */
    CQ_NODISCARD inline std::uint64_t convertTimeToTickAtOrAfter(double time, double frequency)
    {
        if (time == 0.0)
        {
            return 0;
        }
        return static_cast<std::uint64_t>(std::nextafter(std::nextafter(time, 0.0) * frequency, std::numeric_limits<double>::lowest())) + 1;
    }

    /**
     * Convert from tick values to time in seconds
     * 
     * @param tick      sample position in ticks
     * @param frequency sample rate in Hz
     * @return          tick value converted to seconds
     */
    CQ_NODISCARD inline double convertTickToTime(std::uint64_t tick, double frequency)
    {
        return std::nextafter(tick / frequency, std::numeric_limits<double>::max());
    }
}
