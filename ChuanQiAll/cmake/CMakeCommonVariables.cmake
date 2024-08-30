#
# Definitions of variables
#

if(my_module_CommonVars_included)
  return()
endif(my_module_CommonVars_included)
set(my_module_CommonVars_included true)

# guess APP_ROOT
if (NOT DEFINED APP_ROOT)
  file(GLOB FIND_APP_ROOT_PUGI_PATHS "${ROOT}/../../../3rdparty/pugixml-*" "${ROOT}/3rdparty/pugixml-*")
  find_path(FIND_APP_ROOT_PUGI_ROOT NAMES "src/pugixml.hpp" PATHS ${FIND_APP_ROOT_PUGI_PATHS})

  get_filename_component(APP_ROOT "${FIND_APP_ROOT_PUGI_ROOT}/../.." ABSOLUTE)
endif ()

if (NOT DEFINED LIB_ROOT)
  get_filename_component(LIB_ROOT ${APP_ROOT}/lib ABSOLUTE)
endif ()

#
# old 3rdparty
if (NOT DEFINED 3RDPARTY_ROOT)
  get_filename_component(3RDPARTY_ROOT ${APP_ROOT}/3rdparty ABSOLUTE)
else()
  get_filename_component(3RDPARTY_ROOT ${3RDPARTY_ROOT} ABSOLUTE)
endif ()

#
# new 3rdparty
if (NOT DEFINED OPT_ROOT)
  if (EXISTS /opt AND NOT WIN32)
    set(OPT_ROOT "/opt")  
  else()
    get_filename_component(OPT_ROOT ${APP_ROOT}/opt ABSOLUTE)
  endif()
else()
  get_filename_component(OPT_ROOT ${OPT_ROOT} ABSOLUTE)
endif ()

# determine build type: release, debug
if(NOT CMAKE_BUILD_TYPE)
  # default build type is debug
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL None)
  set(BIN_STAGE_INTDIR Debug)
elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
  set(BIN_STAGE_INTDIR Debug)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
  set(BIN_STAGE_INTDIR Release)
elseif(CMAKE_BUILD_TYPE STREQUAL RelWithDebInfo)
  set(BIN_STAGE_INTDIR RelWithDebInfo)
elseif(CMAKE_BUILD_TYPE STREQUAL MinSizeRel)
  set(BIN_STAGE_INTDIR MinSizeRel)
endif()

if (CMAKE_SCRIPT_DEBUG)
  message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
  message("BIN_STAGE_INTDIR = ${BIN_STAGE_INTDIR}")
endif()
