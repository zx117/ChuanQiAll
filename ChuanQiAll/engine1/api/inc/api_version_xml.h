#pragma once

#include "api_pugixml_fwd.h"
#include "uni_defines.h"
#include <string>

namespace cq
{
    struct Version
    {
        unsigned m_major;
        unsigned m_minor;

        Version(unsigned major = 0, unsigned minor = 0) noexcept;

        CQ_NODISCARD bool isValid() const noexcept;

        CQ_NODISCARD std::string generate() const;
        CQ_NODISCARD static Version parse(const char* str);

        CQ_NODISCARD bool operator==(const Version& other) const noexcept;
        CQ_NODISCARD bool operator!=(const Version& other) const noexcept;
        CQ_NODISCARD bool operator<=(const Version& other) const noexcept;
        CQ_NODISCARD bool operator>=(const Version& other) const noexcept;
    };

    CQ_NODISCARD Version getProtocolVersion(const pugi::xml_node& node);
    void setProtocolVersion(pugi::xml_node& node, const Version& version);
}
