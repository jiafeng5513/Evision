#EvisionSandbox:主程序

#设置cmake最小版本号
cmake_minimum_required(VERSION 3.13.0)
 

 
# Find OpenCV
find_package(OpenCV REQUIRED)
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

#查找需要的Qt库
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS UiPlugin REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED)

#Qt版本号
message(STATUS "Qt5Widgets_VERSION:${Qt5Widgets_VERSION}")
#Qt的includes
message(STATUS "Qt5Widgets_INCLUDE_DIRS:${Qt5Widgets_INCLUDE_DIRS}")
#取include的根目录,是列表变量的第一个元素
list(GET Qt5Widgets_INCLUDE_DIRS 0 Qt5_INCLUDE_DIR)
message(STATUS "Qt5Widgets_INCLUDE_DIR:${Qt5_INCLUDE_DIR}")

#查找一些特定的Qt目录
#find_path(QT_INCLUDE_MultimediaWidgets QtMultimediaWidgets_Path)
#find_path(QT_INCLUDE_Multimedia QtMultimedia_Path)
#find_path(QT_INCLUDE_CORE_PRIVATE QtCore_private_path)
#find_path(QT_INCLUDE_CORE_INNER QtCore_version_QtCore_path)

include_directories(${Qt5_INCLUDE_DIR}QtMultimediaWidgets/)
include_directories(${Qt5_INCLUDE_DIR}QtMultimedia/)
include_directories(${Qt5_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/QtCore/private/)
include_directories(${Qt5_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/QtCore/)
include_directories(${Qt5_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/)


#包含自定义组件
include_directories("../EvisionUtils/include/")
include_directories("../EvisionCalibrate/include/")
include_directories("../EvisionDisparity/include/")
include_directories("../EvisionUndistortion/include/")
include_directories("../EvisionTrace/include/")
include_directories("../EvisionCamera/include/")
include_directories("../EvisionParamBridge/include/")
include_directories("../EvisionPolyTracker/include/")
include_directories("../EvisionMonocularCalib/include/")

if (PointCloudViewer)
include_directories("../EvisionCloudViewer/include")
endif()
if(ObjectDetection)
include_directories("../EvisionObjDetection/include/")
endif()
if(RealSense)
include_directories("../RealSenseCamera/include/")
endif()
LINK_DIRECTORIES(../install/lib)


#设置工程包含当前目录
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
#预处理器定义
add_definitions(-D UNICODE)
#add_definitions(-D WIN32)
#add_definitions(-D WIN64)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D QT_MULTIMEDIA_LIB)
add_definitions(-D QT_MULTIMEDIAWIDGETS_LIB)
add_definitions(-D QT_IMAGE_LIB)
add_definitions(-D QT_CORE_PRIVATE)
add_definitions(-D OPENCV)
if (PointCloudViewer)
add_definitions(-D WITH_PCL)
endif()
if (ObjectDetection)
add_definitions(-D WITH_CUDA)
endif()
if(RealSense)
add_definitions(-D WITH_REAL_SENSE)
endif()

# #自定义库的输出路径就是主程序的链接路径
# IF (CMAKE_BUILD_TYPE STREQUAL Debug)
# link_directories(${PROJECT_SOURCE_DIR}/../install/Debug/lib)
# ENDIF()

# IF (CMAKE_BUILD_TYPE STREQUAL Release)
# link_directories(${PROJECT_SOURCE_DIR}/../install/Release/lib)
# ENDIF()

#自动moc,uic,qrc,
#set(CMAKE_AUTOMOC ON) 
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

#查找当前文件夹中的所有源代码文件
FILE(GLOB SRC_FILES "./*.cpp") 
#查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 
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
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
#set(CMAKE_DEBUG_POSTFIX "_d")
#set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

#创建可执行文件工程
add_executable(EvisionSandbox ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})

#链接Qt5依赖项
target_link_libraries(EvisionSandbox Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::MultimediaWidgets)
#链接OpenCV
target_link_libraries(EvisionSandbox ${OpenCV_LIBS})
#链接自定义库
target_link_libraries(EvisionSandbox EvisionUtils)
target_link_libraries(EvisionSandbox EvisionCalibrate)
target_link_libraries(EvisionSandbox EvisionDisparity)
target_link_libraries(EvisionSandbox EvisionUndistortion)
target_link_libraries(EvisionSandbox EvisionTrace)
target_link_libraries(EvisionSandbox EvisionCamera)
target_link_libraries(EvisionSandbox EvisionParamBridge)
target_link_libraries(EvisionSandbox EvisionPolyTracker)
target_link_libraries(EvisionSandbox EvisionMonocularCalib)

if (ObjectDetection)
target_link_libraries(EvisionSandbox EvisionObjDetection)
endif()

if (PointCloudViewer)
target_link_libraries(EvisionSandbox EvisionCloudViewer)
endif()

