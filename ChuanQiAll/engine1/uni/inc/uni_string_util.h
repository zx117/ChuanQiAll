#pragma once

#include <cstring>

namespace cq
{

    inline bool strequal(const char* a, const char* b)
    {
        if (a == b)
        {
            return true;
        }
        else if (a && b)
        {
            return std::strcmp(a, b) == 0;
        }
        else
        {
            return false;
        }
    }

}
