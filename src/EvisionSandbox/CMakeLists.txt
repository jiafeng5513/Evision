#EvisionSandbox:主程序

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Qt6_INCLUDE_DIR}QtMultimediaWidgets/)
include_directories(${Qt6_INCLUDE_DIR}QtMultimedia/)
include_directories(${Qt6_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/QtCore/private/)
include_directories(${Qt6_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/QtCore/)
include_directories(${Qt6_INCLUDE_DIR}QtCore/${Qt5Widgets_VERSION}/)
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


#查找当前文件夹中的所有源代码文件
FILE(GLOB SRC_FILES "./*.cpp") 
#查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 
#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 
#编译ui文件
qt6_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt6_wrap_cpp(MOC_FILES ${HEAD_FILES})
#编译qrc资源文件
qt6_add_resources(QRC_FILES ${RES_FILES})
 
#文件整理
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})


#创建可执行文件工程
add_executable(EvisionSandbox ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})

#链接Qt5依赖项
target_link_libraries(EvisionSandbox Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::MultimediaWidgets)
#链接OpenCV
target_link_libraries(EvisionSandbox ${OpenCV_LIBS})
#链接自定义库
target_link_libraries(EvisionSandbox EvisionUtils)
target_link_libraries(EvisionSandbox EvisionCalibrate)
target_link_libraries(EvisionSandbox EvisionDisparity)
target_link_libraries(EvisionSandbox EvisionUndistortion)
target_link_libraries(EvisionSandbox EvisionTrace)
#target_link_libraries(EvisionSandbox EvisionCamera)
target_link_libraries(EvisionSandbox EvisionParamBridge)
target_link_libraries(EvisionSandbox EvisionPolyTracker)
target_link_libraries(EvisionSandbox EvisionMonocularCalib)

if (ObjectDetection)
    target_link_libraries(EvisionSandbox EvisionObjDetection)
endif()

if (PointCloudViewer)
    target_link_libraries(EvisionSandbox EvisionCloudViewer)
endif()
