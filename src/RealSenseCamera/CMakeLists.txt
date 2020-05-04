#RealSenseCamera: RealSense相机

#设置cmake最小版本号
cmake_minimum_required(VERSION 3.13.0)
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# Find OpenCV
find_package(OpenCV REQUIRED)

#查找需要的Qt库
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED)

#查找RealSense
find_path(RS_SDK_DIR Realsense_SDK_Dir)
set(RS_INCLUDE_DIR ${RS_SDK_DIR}/include/)
set(RS_LIB ${RS_SDK_DIR}/lib/x64/realsense2.lib)
set(RS_BIN_DIR ${RS_SDK_DIR}/bin/x64/)

message(STATUS "RealSense SDK status:")
message(STATUS "RS_INCLUDE_DIR:${RS_INCLUDE_DIR}")
message(STATUS "RS_LIB: ${RS_LIB}")
message(STATUS "RS_BIN_DIR: ${RS_BIN_DIR}")

#包含目录
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories("./include/")
include_directories("../EvisionUtils/include/")
include_directories(${RS_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

#库目录
LINK_DIRECTORIES(../install/lib)
#预处理器定义
add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D QT_MULTIMEDIA_LIB)
add_definitions(-D QT_MULTIMEDIAWIDGETS_LIB)
add_definitions(-D REALSENSECAMERA_LIB)
# Qt foreach 和 RealSense foreach冲突,因此禁用掉Qt foreach
add_definitions(-D QT_NO_FOREACH)

#收集文件
FILE(GLOB UI_FILES "./*.ui") 
FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 
FILE(GLOB RES_FILES "./*.qrc")

#编译ui文件
qt5_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt5_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt5_add_resources(QRC_FILES ${RES_FILES})
 
#文件整理
source_group("include" FILES ${INCLUDE_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

#输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
#set(CMAKE_DEBUG_POSTFIX "_d")
#set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

#编译目标:创建链接库
add_library(RealSenseCamera SHARED ${INCLUDE_FILES} ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})

#链接Qt5依赖项
target_link_libraries(RealSenseCamera Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::MultimediaWidgets)
#链接OpenCV
target_link_libraries(RealSenseCamera ${OpenCV_LIBS})
#链接通用工具类
target_link_libraries(RealSenseCamera EvisionUtils)
#链接RealSense
target_link_libraries(RealSenseCamera ${RS_LIB})
#添加编译前事件

#add_custom_command(TARGET RealSenseCamera PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different  
#        "${RS_BIN_DIR}/Intel.Realsense.dll"
#        "$<$<CONFIG:Debug>:${RS_BIN_DIR}/Intel.Realsense.pdb>"  
#        "$<TARGET_FILE_DIR:RealSenseCamera>") 
#add_custom_command(TARGET RealSenseCamera POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different  
#    "${RS_SDK_DIR}/bin/x64/realsense2.dll"
#    "$<$<CONFIG:Debug>:${RS_SDK_DIR}/bin/x64/realsense2.pdb>"  
#    $<TARGET_FILE_DIR:RealSenseCamera>) 