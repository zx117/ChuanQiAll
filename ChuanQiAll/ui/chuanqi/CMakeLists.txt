#
# CMakeLists.txt for desktop
#
cmake_minimum_required(VERSION 3.6)

include(CMakeSettings)

#指定工程名称
project(chuanqi VERSION 0.1 LANGUAGES CXX)

#开启qt需要的uic;moc;rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#设定c++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#指定qt所在目录
if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/msvc_64") # Qt Kit Dir
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "/opt/Qt5.9.6/5.9.6/gcc_64")

    #指定编译时搜索动态库路径
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

    SET(CMAKE_INSTALL_RPATH "\${ORIGIN}")

endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick LinguistTools Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick LinguistTools Widgets )
#cmake编译时包括自身所在目录
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QML_IMPORT_PATH "./qml/components" ${CMAKE_CURRENT_SOURCE_DIR}/qml/components CACHE STRING "" FORCE)

include_directories(
  inc
  ../appinterface/inc
)

#set(TS_FILES ChuanQiAll_zh_CN.ts)

# #添加源文件
# #aux_source_directory(./src srcs)
# set(HEADER_FILES
#     inc/listmodel.h
#     inc/tablemodel.h
#     inc/treeitem.h
#     inc/treemodel.h
#     inc/apphost.h
#     inc/displayfilesystemmodel.h
#     inc/interface.h
#     inc/pugixmlinterface.h
#     inc/customformat.h
#     inc/logoperations.h
# )
# source_group("Header Files" FILES ${HEADER_FILES})

# set(SOURCE_FILES
#     main.cpp
#     src/listmodel.cpp
#     src/tablemodel.cpp
#     src/treeitem.cpp
#     src/treemodel.cpp
#     src/apphost.cpp
#     src/displayfilesystemmodel.cpp
#     src/interface.cpp
#     src/pugixmlinterface.cpp
#     src/customformat.cpp
#     src/logoperations.cpp
# )
# source_group("Source Files" FILES ${SOURCE_FILES})

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp inc/*.h)


file(GLOB_RECURSE file_ui ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE qml_file ${CMAKE_CURRENT_SOURCE_DIR}/qml/*.qml)
set(qrc ./chuanqi.qrc)


#生成可执行文件
#set(NAME ChuanQiAll)

#指定输出目录
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(THIS_NAME ${PROJECT_NAME}_d)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/debug)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(THIS_NAME ${PROJECT_NAME})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/release)
endif()


# add_executable(${PROJECT_NAME}
#     WIN32 ${HEADER_FILES} ${SOURCE_FILES} ${file_ui} ${qrc} ${qml_file}
# )
add_executable(${PROJECT_NAME}
    WIN32 main.cpp ${srcs} ${file_ui} ${qrc} ${qml_file}
)

#指定链接目录所在位置
#link_directories(../lib)

set(LINK_DEPENDENCIES
    appinterface
#  engine
)

if (UNIX)
  set(LINK_DEPENDENCIES ${LINK_DEPENDENCIES} libpthread.so.0)
  set_property(TARGET ${LIBNAME} APPEND PROPERTY COMPILE_FLAGS -pthread)
endif()

#链接动态库
# target_link_libraries(${PROJECT_NAME} INTERFACE
#    appinterface
# )
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${LINK_DEPENDENCIES}
    Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick pugixml
    Qt${QT_VERSION_MAJOR}::Widgets
    spdlog::spdlog
    cqdaq-64-1-debug
    daqcoreobjects-64-1-debug
    daqcoretypes-64-1-debug
    sqlite3
    ref_save_module
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    inc
)


#生成翻译文件
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
#if(${QT_VERSION} VERSION_LESS 6.1.0)
#  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ChuanQiAll)
#endif()
set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

