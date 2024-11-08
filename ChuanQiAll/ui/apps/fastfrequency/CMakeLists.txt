#
# CMakeLists.txt for fastfrequency
#
cmake_minimum_required(VERSION 3.6)

include(CMakeSettings)

set(LIBNAME fastfrequency)

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

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Quick PrintSupport LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Quick PrintSupport LinguistTools)

# 设置 QCustomPlot 路径变量
set(QCUSTOMPLOT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/customplot")
set(QCUSTOMPLOT_SRC "${QCUSTOMPLOT_INCLUDE_DIR}/qcustomplot.cpp")

# 将 QCustomPlot 添加为静态库
add_library(qcustomplot STATIC ${QCUSTOMPLOT_SRC})

# 添加头文件路径
target_include_directories(qcustomplot PUBLIC ${QCUSTOMPLOT_INCLUDE_DIR})

#cmake编译时包括自身所在目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ../../appinterface/inc
)

include_directories(
  inc
)

set(FAST_FREQUENCY_HEADER_FILES
    inc/fastfrequency.h
    inc/appplugindemo.h
    ../../appinterface/inc/iapp.h
    ../../appinterface/inc/appsystem.h
    ../../appinterface/inc/appsystemplugin.h

)
source_group("Header Files" FILES ${DEMO_HEADER_FILES})

set(FAST_FREQUENCY_SOURCE_FILES
    src/fastfrequency.cpp
    src/appplugindemo.cpp
    ../../appinterface/src/appsystemplugin.cpp
)
source_group("Source Files" FILES ${DEMO_SOURCE_FILES})

file(GLOB_RECURSE file_ui ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE qml_file ${CMAKE_CURRENT_SOURCE_DIR}/qml/*.qml)
set(qrc ./fastfrequency.qrc)

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
include_directories(${Qt5Core_INCLUDE_DIRS})
add_library(${LIBNAME} SHARED
  ${FAST_FREQUENCY_HEADER_FILES}
  ${FAST_FREQUENCY_SOURCE_FILES}
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
    Qt5::Widgets
    Qt5::PrintSupport
    qcustomplot
)

target_include_directories(
    ${LIBNAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc

)

#
# add this to Visual Studio group lib
set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")


