#include "api_utils.h"

#include "api_message_ids.h"
#include "api_chuanqi_queries.h"
#include "base_if_host.h"
#include "uni_assert.h"
#include <vector>

namespace cq
{
    bool isAnalysisModeActive(cq::IfHost* host)
    {
        auto analysis_active = host->getValue<cq::IfBooleanValue>(cq::queries::ChuanQi, cq::queries::ChuanQi_AnalysisModeActive);

        if (analysis_active)
        {
            return analysis_active->getValue();
        }

        return false;
    }

    cq::Timestamp getMasterTimestamp(cq::IfHost* host)
    {
        if (!isAnalysisModeActive(host))
        {
            auto master_timebase_xml = host->getValue<cq::IfXMLValue>(cq::queries::ChuanQi, cq::queries::ChuanQi_MasterTimebaseValue);

            if (!master_timebase_xml)
            {
                CQ_ASSERT_FAIL("Unable to retrieve master timebase value");
                return {};
            }

            cq::Timestamp master_timebase;
            master_timebase.parse(master_timebase_xml->asStringView());
            return master_timebase;
        }
        return {};
    }

    cq::AbsoluteTime getAcquisitionStartTime(cq::IfHost* host)
    {
        auto xml_value = host->getValue<cq::IfXMLValue>(cq::queries::ChuanQiAcqStartTime, cq::queries::ChuanQiAcqStartTime_AbsXML);
        if (!xml_value)
        {
            CQ_ASSERT_FAIL("Unable to retrieve acquisition start time");
            return {};
        }
        cq::AbsoluteTime time;
        time.parse(xml_value->asStringView());
        return time;
    }

    cq::AbsoluteTime getMeasurementStartTime(cq::IfHost* host)
    {
        auto xml_value = host->getValue<cq::IfXMLValue>(cq::queries::ChuanQiMeasStartTime, cq::queries::ChuanQiAcqStartTime_AbsXML);
        if (!xml_value)
        {
            CQ_ASSERT_FAIL("Unable to retrieve measurement start time");
            return {};
        }
        cq::AbsoluteTime time;
        time.parse(xml_value->asStringView());
        return time;
    }

    void addSamples(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp, const void* data, size_t data_size)
    {
        const std::uint8_t* timestamp_bytes = reinterpret_cast<const std::uint8_t*>(&timestamp);
        const std::uint8_t* data_bytes = reinterpret_cast<const std::uint8_t*>(data);

        std::vector<std::uint8_t> sample;
        sample.reserve(sizeof(std::uint64_t) + data_size); // reserve but do not fill with 0
        sample.insert(sample.end(), timestamp_bytes, timestamp_bytes + sizeof(std::uint64_t));
        sample.insert(sample.end(), data_bytes, data_bytes + data_size);

        host->messageSyncData(cq::host_msg::ADD_CONTIGUOUS_SAMPLES, local_channel_id, sample.data(), sample.size(), nullptr);
    }

    void addSample(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp, const void* data, size_t data_size)
    {
        const std::uint8_t* timestamp_bytes = reinterpret_cast<const std::uint8_t*>(&timestamp);
        const std::uint8_t* data_bytes = reinterpret_cast<const std::uint8_t*>(data);

        std::vector<std::uint8_t> sample;
        sample.reserve(sizeof(std::uint64_t) + data_size); // reserve but do not fill with 0
        sample.insert(sample.end(), timestamp_bytes, timestamp_bytes + sizeof(std::uint64_t));
        sample.insert(sample.end(), data_bytes, data_bytes + data_size);

        host->messageSyncData(cq::host_msg::ADD_SAMPLE, local_channel_id, sample.data(), sample.size(), nullptr);
    }

    void updateChannelState(cq::IfHost* host, std::uint32_t local_channel_id, std::uint64_t timestamp)
    {
        auto timestamp_value = host->createValue<cq::IfUIntValue>();
        timestamp_value->set(timestamp);
        host->messageSync(cq::host_msg::UPDATE_CHANNEL_STATE, local_channel_id, timestamp_value.get(), nullptr);
    }

    std::uint64_t sendSyncXMLMessage(cq::IfHost* host, cq::MessageId msg_id, std::uint64_t key, const char* param_data, size_t param_size, const cq::IfValue** ret)
    {
        CQ_UNUSED(param_size);
        auto xml_msg = host->createValue<cq::IfXMLValue>();
        xml_msg->set(param_data);
        CQ_ASSERT_EQUAL(static_cast<std::size_t>(xml_msg->getLength()), param_size - 1);
        return host->messageSync(msg_id, key, xml_msg.get(), ret);
    }
}
