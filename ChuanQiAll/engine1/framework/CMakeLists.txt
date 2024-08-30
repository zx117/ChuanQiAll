#
# CMakeLists.txt for framework
#
include(CMakeSettings)

set(LIBNAME framework)

include_directories(
    SYSTEM
    ${Boost_INCLUDE_DIRS}
)

include_directories(
  inc
)

set(HEADER_FILES
  inc/fw_block_iterator.h
  inc/fw_channels.h
  inc/fw_custom_request_handler.h
  inc/fw_data_requester.h
  inc/fw_exceptions.h
  inc/fw_export_instance.h
  inc/fw_export_plugin.h
  inc/fw_fwd.h
  inc/fw_if_message_handler.h
  inc/fw_input_channel.h
  inc/fw_interfaces.h
  inc/fw_plugin_base.h
  inc/fw_properties.h
  inc/fw_property_list_utils.h
  inc/fw_resampler.h
  inc/fw_software_channel_instance.h
  inc/fw_software_channel_plugin.h
  inc/fw_stream_iterator.h
  inc/fw_stream_reader.h
  inc/fw_version_check.h
)
source_group("Header Files" FILES ${HEADER_FILES})

set(SOURCE_FILES
  src/fw_block_iterator.cpp
  src/fw_channels.cpp
  src/fw_custom_request_handler.cpp
  src/fw_data_requester.cpp
  src/fw_export_instance.cpp
  src/fw_export_plugin.cpp
  src/fw_input_channel.cpp
  src/fw_plugin_base.cpp
  src/fw_properties.cpp
  src/fw_property_list_utils.cpp
  src/fw_resampler.cpp
  src/fw_stream_iterator.cpp
  src/fw_stream_reader.cpp
  src/fw_software_channel_instance.cpp
  src/fw_software_channel_plugin.cpp
  src/fw_version_check.cpp
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
