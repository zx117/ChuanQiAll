
#pragma once

#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

class IdsParser
{
public:
    static bool splitRelativeId(const std::string& id, std::string& start, std::string& rest)
    {
        const auto equalsIdx = id.find_first_of('/');
        if (std::string::npos != equalsIdx)
        {
            start = id.substr(0, equalsIdx);
            rest = id.substr(equalsIdx + 1);
            return true;
        }

        return false;
    }

    static bool isNestedComponentId(const std::string& ancestorGlobalId, const std::string& descendantGlobalId)
    {
        return descendantGlobalId.find(ancestorGlobalId + "/") == 0;
    }

    static bool idEndsWith(const std::string& id, const std::string& idEnding)
    {
        if (idEnding.length() > id.length())
            return false;
        return std::equal(idEnding.rbegin(), idEnding.rend(), id.rbegin());
    }
};

END_NAMESPACE_CQDAQ
