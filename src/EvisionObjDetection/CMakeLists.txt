# Evision Object Detection (View)
# required cmake version
cmake_minimum_required(VERSION 3.13.0)
# packages

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED)

add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D QT_MULTIMEDIA_LIB)
add_definitions(-D QT_MULTIMEDIAWIDGETS_LIB)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("./include/")
include_directories("../EvisionObjDetectionEngine/include/")
LINK_DIRECTORIES(../install/lib)

add_definitions(-D EVISIONOBJDETECTION_LIB)
add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D OPENCV)
# 文件收集
FILE(GLOB INCLUDE_FILES "./include/*.h") # [include]文件夹中的头文件
FILE(GLOB HEAD_FILES "./*.h")                    # 其他头文件 
FILE(GLOB SRC_FILES "./*.cpp")                     # 其他源文件 
FILE(GLOB UI_FILES "./*.ui") 
FILE(GLOB RES_FILES "./*.qrc") 


#编译ui文件
qt5_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt5_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt5_add_resources(QRC_FILES ${RES_FILES})

#文件整理
source_group("include" FILES ${INCLUDE_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})
source_group("Source Files" FILES ${SRC_FILES})


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)

ADD_LIBRARY(EvisionObjDetection SHARED ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES} ${INCLUDE_FILES} ${HEAD_FILES} ${SRC_FILES})

target_link_libraries(EvisionObjDetection ${OpenCV_LIBS})
target_link_libraries(EvisionObjDetection Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::MultimediaWidgets)
target_link_libraries(EvisionObjDetection EvisionObjDetectionEngine)