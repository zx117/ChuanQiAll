#pragma once

#include <coretypes/string_ptr.h>
#include <coretypes/objectptr.h>
#include <fmt/format.h>

template <>
struct fmt::formatter<daq::StringPtr> : fmt::formatter<std::string_view>
{
    using Base = fmt::formatter<std::string_view>;

    template <typename FormatContext>
    auto format(const daq::StringPtr& c, FormatContext& ctx) const
    {
        if (!c.assigned())
        {
            return Base::format("<empty>", ctx);
        }

        return Base::format(c.toView(), ctx);
    }
};

template <typename T>
struct fmt::formatter<daq::ObjectPtr<T>> : fmt::formatter<std::string>
{
    template <typename FormatContext>
    auto format(const daq::ObjectPtr<T> c, FormatContext& ctx) const
    {
        if (!c.assigned())
        {
            return formatter<std::string>::format("<empty>", ctx);
        }

        return formatter<std::string>::format(c.template getValue<std::string>(""), ctx);
    }
};
