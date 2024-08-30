
#pragma once
#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger
 * @addtogroup cqdaq_logger_source_location Source location
 * @{
 */

#ifdef __cplusplus
    #define CQDAQ_CONSTEXPR constexpr
    #define CQDAQ_NOEXCEPT noexcept
#else
    #define CQDAQ_CONSTEXPR
    #define CQDAQ_NOEXCEPT
#endif

#pragma pack(push, 1)

/*!
 * @brief Represents a position in source code.
 */
struct SourceLocation
{
    CQDAQ_CONSTEXPR SourceLocation() = default;
    CQDAQ_CONSTEXPR SourceLocation(const char* fileName, Int line, const char* funcName)
        : fileName{fileName}
        , line{line}
        , funcName{funcName}
    {
    }

    CQDAQ_CONSTEXPR bool empty() const CQDAQ_NOEXCEPT
    {
        return line == 0;
    }

    const char* fileName{nullptr};  ///< Source file name
    Int line{0};                    ///< Line number
    const char* funcName{nullptr};  ///< Function name
};

/*!@}*/

#pragma pack(pop)

END_NAMESPACE_CQDAQ
