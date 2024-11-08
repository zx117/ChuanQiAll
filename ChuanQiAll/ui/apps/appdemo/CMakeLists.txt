#
# CMakeLists.txt for demoapp
#
cmake_minimum_required(VERSION 3.6)

include(CMakeSettings)

set(LIBNAME appdemo)

#开启qt需要的uic;moc;rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#开启qt需要的uic;moc;rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#设定c++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#指定qt所在目录
if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/msvc2019") # Qt Kit Dir
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "/opt/Qt5.9.6/5.9.6/gcc")

    #指定编译时搜索动态库路径
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

    SET(CMAKE_INSTALL_RPATH "\${ORIGIN}")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Widgets LinguistTools)

#cmake编译时包括自身所在目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ../../appinterface/inc
)

include_directories(
  inc
)

set(DEMO_HEADER_FILES
    appdemo.h
    appplugindemo.h
    ../../appinterface/inc/iapp.h
    ../../appinterface/inc/appsystem.h
    ../../appinterface/inc/appsystemplugin.h
)
source_group("Header Files" FILES ${DEMO_HEADER_FILES})

set(DEMO_SOURCE_FILES
    appdemo.cpp
    appplugindemo.cpp
    ../../appinterface/src/appsystemplugin.cpp
)
source_group("Source Files" FILES ${DEMO_SOURCE_FILES})

file(GLOB_RECURSE file_ui ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE qml_file ${CMAKE_CURRENT_SOURCE_DIR}/*.qml)
set(qrc ./appdemo.qrc)

#指定输出目录
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(THIS_NAME ${PROJECT_NAME}_d)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/debug/apps)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(THIS_NAME ${PROJECT_NAME})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/release/apps)
endif()

set(LINK_DEPENDENCIES
    appinterface
)

add_library(${LIBNAME} SHARED
  ${DEMO_HEADER_FILES}
  ${DEMO_SOURCE_FILES}
  ${qrc}
  ${qml_file}
  ${LIBNAME}.json
)
target_compile_definitions(${LIBNAME} PRIVATE -DAPP_LIBRARY)

if (UNIX)
  set(LINK_DEPENDENCIES ${LINK_DEPENDENCIES} libpthread.so.0)
  set_property(TARGET ${LIBNAME} APPEND PROPERTY COMPILE_FLAGS -pthread)
endif()

#指定链接目录所在位置
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../lib)

#链接动态库
target_link_libraries(${LIBNAME} INTERFACE
    appinterface
)
target_link_libraries(${LIBNAME} PRIVATE
    ${LINK_DEPENDENCIES}
    Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(
    ${LIBNAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

#
# add this to Visual Studio group lib
set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")


