#
# CMakeLists.txt for daq
#
cmake_minimum_required(VERSION 3.1)

set(LIBNAME daq)

include_directories(
  inc
)

set(DAQ_HEADER_FILES
   inc/daq_observer_model.h
   inc/daq_runcommand.h
   inc/daq_runmanager.h   
   inc/daq_exception.h
   inc/daq_runstate.h
   inc/daq_parameter.h
   inc/daq_manager.h
   inc/daq_object.h
   inc/daq_module.h   
   inc/daq_thread.h
   inc/daq_timer.h   
   inc/daq_id.h

)
source_group("Public Header Files" FILES ${DAQ_HEADER_FILES})

set(DAQ_SOURCE_FILES
    src/daq_id.cpp
    src/daq_thread.cpp
    src/daq_module.cpp
    src/daq_manager.cpp
    src/daq_parameter.cpp
    src/daq_runstate.cpp
    src/daq_exception.cpp
    src/daq_runmanager.cpp
    src/daq_runcommand.cpp
)
source_group("Source Files" FILES ${DAQ_SOURCE_FILES})

add_library(${LIBNAME} STATIC ${DAQ_HEADER_FILES} ${DAQ_SOURCE_FILES})

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
  add_subdirectory(daq_tests)
endif (WITH_TESTS)
