#设定cmake最低版本需求
cmake_minimum_required(VERSION 3.14) # CMake install : Download | CMake

#指定工程名称
project(ChuanQiAll VERSION 0.1 LANGUAGES CXX)

#cmake编译时包括自身所在目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(WIN32)
  set(3RDPARTY_LINK_TYPE "static")
elseif(UNIX)
  set(3RDPARTY_LINK_TYPE "shared")
endif()

get_filename_component(ROOT . ABSOLUTE)
message(STATUS "ROOT = ${ROOT}")
# expand cmake search path to check for project settings
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ROOT}/cmake )
#
# Get general cmake settings
include(CMakeSettings)

#
# Set static runtime
if(WIN32)
  SetLinkStaticRuntime()
endif(WIN32)

SetBoostOptions() # set static, dynamic ...
set(BOOST_MODULES)

set(BOOST_ROOT "C:/boost_1_79_0")
find_package(Boost REQUIRED)

if (EXISTS "${ROOT}/3rdparty/pugixml-1.9/scripts")
  AddUniqueTargetFromSubdirectory(pugixml "${ROOT}/3rdparty/pugixml-1.9/scripts" "3rdparty/pugixml-1.9")
else()
  get_filename_component(APP_ROOT ../../.. ABSOLUTE)

  if(EXISTS "${APP_ROOT}/3rdparty/pugixml-1.9/scripts")
    AddUniqueTargetFromSubdirectory(pugixml "${APP_ROOT}/3rdparty/pugixml-1.9/scripts" "3rdparty/pugixml-1.9")
  else()
    message(FATAL_ERROR "pugixml library not found")
  endif()
endif()

if (EXISTS "${ROOT}/3rdparty/spdlog")
  AddUniqueTargetFromSubdirectory(spdlog "${ROOT}/3rdparty/spdlog" "3rdparty/spdlog")
else()
  get_filename_component(APP_ROOT ../../.. ABSOLUTE)

  if(EXISTS "${APP_ROOT}/3rdparty/spdlog")
    AddUniqueTargetFromSubdirectory(spdlog "${APP_ROOT}/3rdparty/spdlog" "3rdparty/spdlog")
  else()
    message(FATAL_ERROR "spdlog library not found")
  endif()
endif()

#定义debug后缀_d
set(CMAKE_DEBUG_POSTFIX -d)

#指定输出目录
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(THIS_NAME ${PROJECT_NAME}_d)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}../bin/debug)

elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(THIS_NAME ${PROJECT_NAME})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}../bin/release)
endif()

#指定头文件目录位置
include_directories(../include)

#指定链接目录所在位置
link_directories(../lib)

#生成可执行文件
#add_executable(${THIS_NAME}
#    WIN32 ${HEADER_FILES} ${SOURCE_FILES} ${file_ui} ${qrc} ${qml_file}
#)

#add_subdirectory(engine)
add_subdirectory(ui)






