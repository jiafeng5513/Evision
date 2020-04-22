#根目录CMAKE
cmake_minimum_required(VERSION 3.13)
project(Evision)

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


if (PointCloudViewer)
# 点云浏览器,生成动态库
add_subdirectory(EvisionCloudViewer)
endif()

# ADCensus视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionADCensus)

# libelas视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionElas)

if (ObjectDetection)
# 目标检测,生成动态库
add_subdirectory(EvisionObjDetection)
add_subdirectory(EvisionObjDetectionEngine)
endif()

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