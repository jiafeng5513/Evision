#根目录CMAKE
cmake_minimum_required(VERSION 3.13)
project(Evision)

option(PointCloudViewer "Point Cloud Viewer" OFF)
option(ObjectDetection "Object Detection" OFF)


#add_definitions(-DTEST_DEBUG)


if (PointCloudViewer)
# 点云浏览器,生成动态库
add_subdirectory(Evision3dViz)
add_subdirectory(EvisionCloudViewer)
endif()

# ADCensus视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionADCensus)

# libelas视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionElas)

if (ObjectDetection)
# 目标检测,生成动态库
add_subdirectory(EvisionObjDetection)
endif()

# 主程序,生成可执行程序
add_subdirectory(EvisionSandbox)
