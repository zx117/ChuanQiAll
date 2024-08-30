cmake_minimum_required(VERSION 3.1)

set(LIBNAME uni)

include_directories(
  SYSTEM
  ${Boost_INCLUDE_DIRS}
  ${SW_APP_ROOT}/pugixml-1.9/src
)

include_directories(
  inc
)

set(UNI_HEADER_FILES
    inc/uni_assert.h
    inc/uni_defines.h
    inc/uni_logger.h
    inc/uni_string_util.h
    inc/uni_uuid.h
    inc/uni_xpugixml.h
    inc/uni_xpugixml_fwd.h
)
source_group("Public Header Files" FILES ${UNI_HEADER_FILES})

set(UNI_SOURCE_FILES
    src/uni_xpugixml.cpp
)
source_group("Source Files" FILES ${UNI_SOURCE_FILES})

add_library(${LIBNAME} STATIC ${UNI_HEADER_FILES} ${UNI_SOURCE_FILES})

target_link_libraries(${LIBNAME}
    pugixml
)

target_include_directories(${LIBNAME} SYSTEM
  PUBLIC ${SW_APP_ROOT}/pugixml-1.9/src
  )

target_include_directories(${LIBNAME} INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")

