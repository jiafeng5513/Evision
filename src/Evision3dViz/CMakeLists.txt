# Evision3dVis
cmake_minimum_required(VERSION 3.13.0)

find_package(VTK)# 需要看CMake文档确认这个查找方法
find_package(PCL REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS UiPlugin REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON) 

include_directories(${PCL_INCLUDE_DIRS})

add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D EVISION3DVIZ_LIB)
add_definitions(-D QT_MULTIMEDIA_LIB)
add_definitions(-D QT_MULTIMEDIAWIDGETS_LIB)

FILE(GLOB INCLUDE_FILES "./include/*.h")
FILE(GLOB HEAD_FILES "Evision3dViz.h") 
FILE(GLOB SRC_FILES "Evision3dViz.cpp") 
#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 

#编译ui文件
qt5_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt5_wrap_cpp(MOC_FILES ${HEAD_FILES})
#编译qrc资源文件
qt5_add_resources(QRC_FILES ${RES_FILES})

#文件整理
source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES} ${INCLUDE_FILES})

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/Debug/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/Release/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/Debug/bin)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/Release/bin)
set(CMAKE_DEBUG_POSTFIX "_d")
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")


add_library(Evision3dViz SHARED ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})
#链接Qt5依赖项
target_link_libraries(Evision3dViz ${PCL_LIBRARIES} Qt5::Widgets Qt5::Core Qt5::Gui)
#链接PCL,OpenCV,VTK,OpenNI,Boost

#自定义库的导出和安装
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../install/Evision3dViz)

target_include_directories(Evision3dViz PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

set_target_properties(Evision3dViz PROPERTIES PUBLIC_HEADER "${INCLUDE_FILES}")

install(TARGETS Evision3dViz
    EXPORT Evision3dViz-targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(EXPORT Evision3dViz-targets
    NAMESPACE Evision3dViz::
    FILE Evision3dViz-config.cmake
    DESTINATION lib/cmake/Evision3dViz)