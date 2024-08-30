#
# CMakeLists.txt for framework
#
include(CMakeSettings)

set(LIBNAME core)

include_directories(
    SYSTEM
    ${Boost_INCLUDE_DIRS}
)

include_directories(
  inc
)

set(HEADER_FILES
  inc/core_values.h
#  inc/core_engine.h
)
source_group("Header Files" FILES ${HEADER_FILES})

set(SOURCE_FILES
  src/core_values.cpp
#  src/core_engine.cpp
)
source_group("Source Files" FILES ${SOURCE_FILES})

set(LINK_DEPENDENCIES
  api
  uni
)

add_library(${LIBNAME} STATIC
  ${HEADER_FILES}
  ${SOURCE_FILES}

)

if (UNIX)
  set(LINK_DEPENDENCIES ${LINK_DEPENDENCIES} libpthread.so.0)
  set_property(TARGET ${LIBNAME} APPEND PROPERTY COMPILE_FLAGS -pthread)
endif()

target_link_libraries(${LIBNAME}
  ${LINK_DEPENDENCIES}
)

target_include_directories(
    ${LIBNAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

#
# add this to Visual Studio group lib
set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")

# Unit Tests
if (WITH_TESTS)
  add_subdirectory(unit_tests)
endif()
