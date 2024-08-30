#
# CMakeLists.txt for base
#
cmake_minimum_required(VERSION 3.1)

set(LIBNAME base)

include_directories(
  ${Boost_INCLUDE_DIRS}
)


set(BASE_HEADER_FILES
    base_api_object_ptr.h
    base_basic_values.h
    base_if_api_object.h
    base_if_host.h
    base_if_host_fwd.h
    base_if_plugin.h
    base_if_value.h
    base_message_return_value_holder.h
)
source_group("Public C++ Header Files" FILES ${BASE_HEADER_FILES})

add_library(${LIBNAME} STATIC ${BASE_HEADER_FILES} base_dummy.cpp)

target_link_libraries(${LIBNAME}
    uni
)

target_include_directories(${LIBNAME} INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
)

set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")
