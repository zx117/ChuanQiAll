
#pragma once
#include <cqdaq/reader_utils.h>
#include <cqdaq/custom_log.h>
#include <cqdaq/logger_component_ptr.h>

BEGIN_NAMESPACE_CQDAQ

struct ReaderDomainInfo
{
    explicit ReaderDomainInfo(LoggerComponentPtr loggerComponent)
        : loggerComponent(std::move(loggerComponent))
    {
    }

    void setMaxResolution(const RatioPtr& maxResolution)
    {
        multiplier = Ratio(
                resolution.getNumerator() * maxResolution.getDenominator(),
                resolution.getDenominator() * maxResolution.getNumerator())
            .simplify();

        LOG_T("Multiplier: {} / {}", multiplier.getNumerator(), multiplier.getDenominator())
    }

    void setEpochOffset(std::chrono::system_clock::time_point minEpoch, const RatioPtr& maxResolution)
    {
        using namespace reader;

#if !defined(NDEBUG)
        readResolution = maxResolution;
        readEpoch = minEpoch;
#endif

        // In system-clock ticks
        offset = epoch.time_since_epoch().count() - minEpoch.time_since_epoch().count();

        LOG_T("Epoch: {}", timePointString(epoch))
        LOG_T("Offset: {}", offset)

        if (offset != 0)
        {
            using SysPeriod = std::chrono::system_clock::period;

            // convert to maxResolution ticks
            offset = offset * (SysPeriod::num * maxResolution.getDenominator()) / (SysPeriod::den * maxResolution.getNumerator());
        }

        LOG_T("Adj. offset: {}", offset)
    }

    RatioPtr resolution{};
    RatioPtr multiplier{};
    std::int64_t offset{};
    std::chrono::system_clock::time_point epoch{};

    LoggerComponentPtr loggerComponent;

#if !defined(NDEBUG)
    RatioPtr readResolution{};
    std::chrono::system_clock::time_point readEpoch{};
#endif
};

END_NAMESPACE_CQDAQ
