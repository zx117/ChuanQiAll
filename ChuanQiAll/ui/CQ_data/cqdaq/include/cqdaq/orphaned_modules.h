
#pragma once

#include <cqdaq/boost_dll.h>
#include <coretypes/common.h>
#include <mutex>
#include <vector>

BEGIN_NAMESPACE_CQDAQ

class OrphanedModules
{
public:
    OrphanedModules();
    ~OrphanedModules();

    void add(boost::dll::shared_library sharedLib);
    void tryUnload();

    static bool canUnloadModule(const boost::dll::shared_library& moduleSharedLib);
private:
    std::vector<boost::dll::shared_library> moduleSharedLibs;
    std::mutex sync;
};

END_NAMESPACE_CQDAQ
