# 根 CMAKE
cmake_minimum_required(VERSION 3.20)

# 若要使用vcpkg,必须设置CMAKE_TOOLCHAIN_FILE为"${vcpkg_root}/scripts/buildsystems/vcpkg.cmake"
if(CMAKE_TOOLCHAIN_FILE)
    message(STATUS "custom tool chain file found!")
    message(STATUS "CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")
endif()

project(Evision VERSION 2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 平台区分
if(WIN32)
    message(STATUS "Building on Windows platform!")
elseif(UNIX)
    message(STATUS "Building on unix-like platform!")
endif()

# 三方库
# opencv
find_package(OpenCV REQUIRED)
message(STATUS "Found OpenCV: ${OpenCV_VERSION}")

# Qt6
find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Core
    Gui
    UiPlugin
    Multimedia
    MultimediaWidgets
    OpenGL
    OpenGLWidgets
)
message(STATUS "Found Qt: ${Qt6Widgets_VERSION}")

# opengl
find_package(OpenGL)

# 二进制产物路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)

# 启动工程筛选器
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_CMakeTargets")

option(PointCloudViewer "Point Cloud Viewer" OFF)
option(ObjectDetection "Object Detection" OFF)

# 点云浏览器
if(PointCloudViewer)
    add_subdirectory(EvisionCloudViewer)
    set_target_properties(EvisionCloudViewer PROPERTIES FOLDER Utils)
endif()

# 目标检测
if(ObjectDetection)
    add_subdirectory(EvisionObjDetection)
    add_subdirectory(EvisionObjDetectionEngine)
    set_target_properties(EvisionObjDetectionEngine PROPERTIES FOLDER Algorithm)
    set_target_properties(EvisionObjDetection PROPERTIES FOLDER Ai)
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

# 相机 (阶段 2 启用: 待 Qt6 Multimedia API 迁移)
# add_subdirectory(EvisionCamera)

# 手动参数转换
add_subdirectory(EvisionParamBridge)

# pnplib
add_subdirectory(EvisionPnP)

# 单目几何体追踪
add_subdirectory(EvisionPolyTracker)

# 单目标定
add_subdirectory(EvisionMonocularCalib)

# 配置工程筛选器
set_target_properties(EvisionUtils EvisionParamBridge PROPERTIES FOLDER Utils)
set_target_properties(EvisionADCensus EvisionElas EvisionPnP PROPERTIES FOLDER Algorithm)
set_target_properties(EvisionCalibrate EvisionDisparity EvisionTrace EvisionUndistortion PROPERTIES FOLDER Stereo)
set_target_properties(EvisionPolyTracker EvisionMonocularCalib PROPERTIES FOLDER Monocular)
