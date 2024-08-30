#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

namespace cq
{
namespace framework
{

    std::vector<int> splitVersionString(const std::string& ver);

    int compareVersionStrings(const std::string& a, const std::string& b);
}
}
