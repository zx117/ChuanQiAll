set(LIB_NAME ref_save_module)
cmake_minimum_required(VERSION 3.6)
project(RefSaveModule VERSION 0.1 LANGUAGES CXX)

add_definitions(-DCQDAQ_MODULE_EXPORTS=1)
add_definitions(-DCQDAQ_LINKS_CORE_OBJECTS=1)
add_definitions(-DCQDAQ_LINKS_CQDAQ=1)
add_definitions(-DBUILDING_SHARED_LIBRARY=1)
add_definitions(-DCQDAQ_TRACK_SHARED_LIB_OBJECT_COUNT=1)

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#设定c++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "C:/boost_1_79_0")
find_package(Boost REQUIRED)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick LinguistTools)


# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# 动态库文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../../bin/debug)

# 定义debug后缀_d
set(CMAKE_DEBUG_POSTFIX -d.module)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_library(${LIB_NAME} SHARED
    ${srcs}
)

# target_compile_definitions(${LIB_NAME} PRIVATE CQDAQ_MODULE_EXPORTS)

# 生成
# add_executable(${LIB_NAME}
#     ${srcs}
#     main.cpp
# )

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")
    target_link_libraries(${LIB_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        ${CMAKE_CURRENT_SOURCE_DIR}/soci/lib/debug/libsoci_sqlite3_4_1.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/soci/lib/debug/libsoci_core_4_1.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/cqdaq/lib/fmtd.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/cqdaq/lib/cqdaq-64-1-debug.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/cqdaq/lib/daqcoreobjects-64-1-debug.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/cqdaq/lib/daqcoretypes-64-1-debug.lib
    )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MD")
    target_link_libraries(${LIB_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/soci/lib/release/libsoci_sqlite3_4_1.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/soci/lib/release/libsoci_core_4_1.lib
    )
endif()

target_link_libraries(${LIB_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3/lib/sqlite3.lib
)


target_include_directories(${LIB_NAME} PUBLIC
    include
    soci/include
    sqlite3/include
    cqdaq/include
)


# add_custom_command(TARGET CQSave POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy
#     $<TARGET_FILE:CQSave>
#     ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
# )

# add_executable()
