#pragma once

#include "api_timestamp_xml.h"
#include "uni_defines.h"

#include <boost/utility/string_view.hpp>
#include <cstdint>
#include <string>
#include <vector>

namespace cq
{
    class AddAcquisitionTaskTelegram
    {
    public:
        AddAcquisitionTaskTelegram() noexcept;

        bool parse(const boost::string_view& xml_string);

        CQ_NODISCARD std::string generate() const;

        std::uint64_t m_id;
        std::vector<std::uint64_t> m_input_channels;
        std::vector<std::uint64_t> m_output_channels;
    };

    class AcquisitionTaskProcessTelegram
    {
    public:
        bool parse(const boost::string_view& xml_string);

        CQ_NODISCARD std::string generate() const;

        cq::Timestamp m_start;
        cq::Timestamp m_end;
    };
}
