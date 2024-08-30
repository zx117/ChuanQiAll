#pragma once

#include <cstdint>

namespace cq
{
namespace framework
{

    class CallbackError
    {
    public:
        explicit CallbackError(std::uint64_t error_code)
            : m_error_code(error_code)
        {
        }

        std::uint64_t getErrorCode() const
        {
            return m_error_code;
        }

    private:
        std::uint64_t m_error_code;
    };

}
}
