# 根CMAKE
cmake_minimum_required(VERSION 3.20)
# 若要使用vcpkg,必须设置CMAKE_TOOLCHAIN_FILE为"${vcpkg_root}/scripts/buildsystems/vcpkg.cmake"
if(CMAKE_TOOLCHAIN_FILE)
    message(STATUS "custom tool chain file found!")
    message(STATUS "CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")
endif(CMAKE_TOOLCHAIN_FILE)
# project name
project(Evision)
# 平台区分
if(WIN32)
    message(STATUS "Building on Windows platform!")
ELSEIF (UNIX)
    message(STATUS "Building on unix-like platform!")
ENDIF()

# 三方库
# opencv
find_package(OpenCV REQUIRED)
message(STATUS "Found OpenCV: ${OpenCV_VERSION}")

# Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS UiPlugin REQUIRED)
find_package(Qt6 COMPONENTS Multimedia REQUIRED)
find_package(Qt6 COMPONENTS MultimediaWidgets REQUIRED)
find_package(Qt6 COMPONENTS OpenGL REQUIRED)
find_package(Qt6 COMPONENTS OpenGLWidgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
# message(STATUS "Qt5Widgets_INCLUDE_DIRS:${Qt5Widgets_INCLUDE_DIRS}")  # Qt的includes
list(GET Qt6Widgets_INCLUDE_DIRS 0 Qt6_INCLUDE_DIR)  # 取include的根目录,是列表变量的第一个元素
message(STATUS "Found Qt: ${Qt6Widgets_VERSION}")
# message(STATUS "Qt5Widgets_INCLUDE_DIR:${Qt5_INCLUDE_DIR}")
#查找一些特定的Qt目录
#find_path(QT_INCLUDE_MultimediaWidgets QtMultimediaWidgets_Path)
#find_path(QT_INCLUDE_Multimedia QtMultimedia_Path)
#find_path(QT_INCLUDE_CORE_PRIVATE QtCore_private_path)
#find_path(QT_INCLUDE_CORE_INNER QtCore_version_QtCore_path)

# opengl
find_package(OpenGL)

# 二进制产物路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
# set(CMAKE_DEBUG_POSTFIX "_d")
# set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

# 启动工程筛选器
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
# 重命名CMake items 筛选器的名字,默认名为:CMakePredefinedTargets
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_CMakeTargets")

option(PointCloudViewer "Point Cloud Viewer" OFF)
option(ObjectDetection "Object Detection" OFF)


# 点云浏览器
if (PointCloudViewer)
    add_subdirectory(EvisionCloudViewer)
    SET_TARGET_PROPERTIES(EvisionCloudViewer PROPERTIES FOLDER Utils) 
endif()

# 目标检测
if (ObjectDetection)
    add_subdirectory(EvisionObjDetection)
    add_subdirectory(EvisionObjDetectionEngine)
    SET_TARGET_PROPERTIES(EvisionObjDetectionEngine PROPERTIES FOLDER Algorithm) 
    SET_TARGET_PROPERTIES(EvisionObjDetection PROPERTIES FOLDER Ai) 
endif()


# ADCensus视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionADCensus)

# libelas视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionElas)

# 主程序,生成可执行程序
add_subdirectory(EvisionSandbox)

# 通用工具类
add_subdirectory(EvisionUtils)

# 标定
add_subdirectory(EvisionCalibrate)

# 视差
add_subdirectory(EvisionDisparity)

# 校正
add_subdirectory(EvisionUndistortion)

# 测量
add_subdirectory(EvisionTrace)

# 相机
#add_subdirectory(EvisionCamera)

# 手动参数转换
add_subdirectory(EvisionParamBridge)

# pnplib
add_subdirectory(EvisionPnP)

# 单目几何体追踪
add_subdirectory(EvisionPolyTracker)

# 单目标定
add_subdirectory(EvisionMonocularCalib)

# 配置工程筛选器
SET_TARGET_PROPERTIES(EvisionUtils  EvisionParamBridge PROPERTIES FOLDER Utils)  # EvisionCamera
SET_TARGET_PROPERTIES(EvisionADCensus EvisionElas EvisionPnP PROPERTIES FOLDER Algorithm)
SET_TARGET_PROPERTIES(EvisionCalibrate EvisionDisparity EvisionTrace EvisionUndistortion PROPERTIES FOLDER Stereo) 
SET_TARGET_PROPERTIES(EvisionPolyTracker EvisionMonocularCalib PROPERTIES FOLDER Monocular)