
 #pragma once

#pragma pack(push, 1)

BEGIN_NAMESPACE_CQDAQ

template <typename T>
struct RangeType
{
    using Type = T;

    static const constexpr T ImplicitNext = static_cast<T>(-1);

    RangeType()
        : start(static_cast<T>(0))
        , end(static_cast<T>(0))
    {
    }

    RangeType(T begin, T end)
        : start(begin)
        , end(end)
    {
    }

    RangeType(T begin)
        : RangeType(begin, ImplicitNext)
    {
    }

    friend bool operator==(const RangeType<T>& lhs, const RangeType<T>& rhs)
    {
        return (lhs.start == rhs.start) && (lhs.end == rhs.end);
    }

    friend bool operator!=(const RangeType<T>& lhs, const RangeType<T>& rhs)
    {
        return (lhs.start != rhs.start) || (lhs.end != rhs.end);
    }

    friend RangeType<T> operator+(const RangeType<T>& range, std::int64_t offset)
    {
        T start = range.start + offset;
        T end = -1;
        if (range.end != -1)
        {
            end = range.end + offset;
        }

        return RangeType<T>(start, end);
    }

    friend RangeType<T> operator-(const RangeType<T>& range, std::int64_t offset)
    {
        T start = range.start - offset;
        T end = -1;
        if (range.end != -1)
        {
            end = range.end - offset;
        }

        return RangeType<T>(start, end);
    }

    T start;
    T end;
};

using RangeType64 = RangeType<int64_t>;

static_assert(std::is_standard_layout_v<RangeType64>, "RangeType64 is not standard layout");
static_assert(std::is_trivially_copyable_v<RangeType64>, "RangeType64 is not trivially copyable");

#pragma pack(pop)

END_NAMESPACE_CQDAQ
