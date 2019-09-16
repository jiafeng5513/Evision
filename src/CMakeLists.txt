#根目录CMAKE
cmake_minimum_required(VERSION 3.13)
project(Evision)

# 点云浏览器,生成动态库
add_subdirectory(Evision3dViz)

# ADCensus视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionADCensus)

# libelas视差算法,生成动态库,依赖OpenCV
add_subdirectory(EvisionElas)

# 目标检测,生成动态库
add_subdirectory(EvisionObjDetection)

# 主程序,生成可执行程序
add_subdirectory(EvisionSandbox)
