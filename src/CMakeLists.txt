#根目录CMAKE
cmake_minimum_required(VERSION 3.13)
project(Evision)
# 启动工程筛选器
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
# 重命名CMake items 筛选器的名字,默认名为:CMakePredefinedTargets
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_CMakeTargets")
#set path
if(WIN32)
    #set(OpenCV_DIR "D:/Libraries/OpenCV/4.1.2/build_vc16_withcuda/install")
    #set(Qt5_DIR "D:/Libraries/Qt/5.13.2/msvc2017_64/lib/cmake/Qt5")
    #CUDA
    #PCL
ELSEIF (UNIX)
    #set(Qt5_DIR "/usr/local/Qt/5.13.1/gcc_64/lib/cmake/Qt5")
ENDIF()

option(PointCloudViewer "Point Cloud Viewer" ON)
option(ObjectDetection "Object Detection" ON)

#add_definitions(-DTEST_DEBUG)

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
add_subdirectory(EvisionCamera)

# 手动参数转换
add_subdirectory(EvisionParamBridge)

# pnplib
add_subdirectory(EvisionPnP)

# 单目几何体追踪
add_subdirectory(EvisionPolyTracker)

# 单目标定
add_subdirectory(EvisionMonocularCalib)

# 配置工程筛选器
SET_TARGET_PROPERTIES(EvisionUtils EvisionCamera EvisionParamBridge PROPERTIES FOLDER Utils) 
SET_TARGET_PROPERTIES(EvisionADCensus EvisionElas EvisionPnP PROPERTIES FOLDER Algorithm)
SET_TARGET_PROPERTIES(EvisionCalibrate EvisionDisparity EvisionTrace EvisionUndistortion PROPERTIES FOLDER Stereo) 
SET_TARGET_PROPERTIES(EvisionPolyTracker EvisionMonocularCalib PROPERTIES FOLDER Monocular)