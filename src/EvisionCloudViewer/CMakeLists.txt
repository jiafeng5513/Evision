# EvisionCloudViewer
cmake_minimum_required(VERSION 3.13.0)
find_package(VTK)# 需要看CMake文档确认这个查找方法
find_package(PCL REQUIRED)
find_package(OpenGL)
find_package(OpenCV)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS OpenGL REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")
add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D EVISIONCLOUDVIEWER_LIB)

FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB HEAD_FILES "./*.h" "") 
FILE(GLOB SRC_FILES "./*.cpp")

#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 

#编译ui文件
qt5_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt5_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt5_add_resources(QRC_FILES ${RES_FILES})

#文件整理
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("include" FILES ${INCLUDE_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
# set(CMAKE_DEBUG_POSTFIX "_d")
# set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")


add_library(EvisionCloudViewer SHARED ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${INCLUDE_FILES} ${UIC_FILES} ${QRC_FILES})
#链接Qt5依赖项
target_link_libraries(EvisionCloudViewer ${OpenCV_LIBS} ${PCL_LIBRARIES}  ${OPENGL_gl_LIBRARY} ${Qt5OpenGL_LIBRARIES} Qt5::OpenGL Qt5::Widgets Qt5::Core Qt5::Gui)