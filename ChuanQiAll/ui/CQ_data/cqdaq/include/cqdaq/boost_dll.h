
#pragma once

#if __has_include(<filesystem>)
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;

    #if defined(BOOST_DLL_USE_STD_FS)
        namespace std { namespace filesystem = std::experimental::filesystem; }
    #endif

    #if !defined(_WIN32)
        namespace std::experimental::filesystem
        {
            inline path relative(const path& p)
            {
                #pragma message "Experimental std::filesystem does not have `relative()`."
                return p;
            }
        }
    #endif
#endif

#include <boost/dll/shared_library.hpp>
#include <boost/dll.hpp>
