#
# CMakeLists.txt for appinterface
#
cmake_minimum_required(VERSION 3.6)

include(CMakeSettings)

set(LIBNAME appinterface)

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

# #指定qt所在目录
# if(WIN32)
#     set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64") # Qt Kit Dir
# elseif(UNIX)
#     set(CMAKE_PREFIX_PATH "/opt/Qt5.9.6/5.9.6/gcc_64")

#     #指定编译时搜索动态库路径
#     SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

#     SET(CMAKE_INSTALL_RPATH "\${ORIGIN}")

# endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick LinguistTools)

#cmake编译时包括自身所在目录
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
  inc
)

set(IT_HEADER_FILES
    inc/appsystemglobal.h
    inc/appsystemplugin.h
    inc/appsystem.h
    inc/appfactory.h
    inc/apploader.h
    inc/iapphost.h
    inc/iapp.h
    inc/app.h
)
source_group("Header Files" FILES ${IT_HEADER_FILES})

set(IT_SOURCE_FILES
    src/appsystemplugin.cpp
    src/appsystem.cpp
    src/appfactory.cpp
    src/apploader.cpp
    src/iapp.cpp
)
source_group("Source Files" FILES ${IT_SOURCE_FILES})

#指定输出目录
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(THIS_NAME ${PROJECT_NAME}_d)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/debug)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(THIS_NAME ${PROJECT_NAME})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/release)
endif()

add_library(${LIBNAME} SHARED
  ${IT_HEADER_FILES}
  ${IT_SOURCE_FILES}  
)
target_compile_definitions(${LIBNAME} PRIVATE APP_LIBRARY)

if (UNIX)
  set(LINK_DEPENDENCIES ${LINK_DEPENDENCIES} libpthread.so.0)
  set_property(TARGET ${LIBNAME} APPEND PROPERTY COMPILE_FLAGS -pthread)
endif()

#链接动态库
target_link_libraries(${LIBNAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

target_include_directories(
    ${LIBNAME} PUBLIC
    inc
)


#
# add this to Visual Studio group lib
set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")


