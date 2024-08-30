#
# CMakeLists.txt for api
#
cmake_minimum_required(VERSION 3.1)

set(LIBNAME api)

include_directories(
  inc
)

set(API_HEADER_FILES
    inc/api_acquisition_task_xml.h
    inc/api_block_descriptor_xml.h
    inc/api_block_descriptor_xml_fwd.h
    inc/api_channel_config_changed_xml.h
    inc/api_channel_dataformat_xml.h
    inc/api_channel_list_xml.h
    inc/api_channel_mapping_xml.h
    inc/api_config_item_keys.h
    inc/api_data_set_xml.h
    inc/api_data_set_descriptor_xml.h
    inc/api_data_set_descriptor_xml_fwd.h
    inc/api_error_codes.h
    inc/api_event_ids.h
    inc/api_export_xml.h
    inc/api_logging.h
    inc/api_marker_xml.h
    inc/api_message_ids.h
    inc/api_message_ids.inc
    inc/api_measurement_header_data_xml.h
    inc/api_node_list_xml.h
    inc/api_chuanqi_queries.h
    inc/api_property_xml.h
    inc/api_property_list_xml.h
    inc/api_software_channel_xml.h
    inc/api_timebase_xml.h
    inc/api_timestamp_xml.h
    inc/api_types.h
    inc/api_update_channels_xml.h
    inc/api_update_config_xml.h
    inc/api_utils.h
    inc/api_version_xml.h
)
source_group("Public Header Files" FILES ${API_HEADER_FILES})

set(API_SOURCE_FILES
    src/assert_bimap_size.h
    src/api_acquisition_task_xml.cpp
    src/api_block_descriptor_xml.cpp
    src/api_channel_config_changed_xml.cpp
    src/api_channel_dataformat_xml.cpp
    src/api_channel_list_xml.cpp
    src/api_channel_mapping_xml.cpp
    src/api_data_set_xml.cpp
    src/api_data_set_descriptor_xml.cpp
    src/api_export_xml.cpp
    src/api_marker_xml.cpp
    src/api_measurement_header_data_xml.cpp
    src/api_property_xml.cpp
    src/api_property_list_xml.cpp
    src/api_software_channel_xml.cpp
    src/api_timebase_xml.cpp
    src/api_timestamp_xml.cpp
    src/api_types.cpp
    src/api_update_channels_xml.cpp
    src/api_update_config_xml.cpp
    src/api_utils.cpp
    src/api_version_xml.cpp
)
source_group("Source Files" FILES ${API_SOURCE_FILES})

add_library(${LIBNAME} STATIC ${API_HEADER_FILES} ${API_SOURCE_FILES})

target_link_libraries(${LIBNAME}
    base
    uni
)

target_include_directories(${LIBNAME} INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

set_target_properties(${LIBNAME} PROPERTIES FOLDER "cq")

# Unit Tests
if (WITH_TESTS)
  add_subdirectory(unit_tests)
endif (WITH_TESTS)
