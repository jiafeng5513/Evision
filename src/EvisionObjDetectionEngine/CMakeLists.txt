# Evision ObjectDetection Engine (algorithm)
cmake_minimum_required(VERSION 3.13.0)

option(DarkNetExamples "build Object Detection Examples" OFF)
# packages
enable_language(CUDA)
find_package(CUDA)
message(STATUS "CUDA_CUDA_LIBRARY: ${CUDA_CUDA_LIBRARY}")
message(STATUS "CUDA_BLAS_LIBRARY: ${CUDA_BLAS_LIBRARY}")
message(STATUS "CUDA_RANDOM_LIBRARY: ${CUDA_RANDOM_LIBRARY}")
find_package(OpenCV REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${CUDA_TOOLKIT_INCLUDE})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")
include_directories("./Core/")
include_directories("./CrossPlatform/")
if(DarkNetExamples)
include_directories("./Examples/")
endif()
include_directories("./Models/")
include_directories("./Utils/")
include_directories("../../package/pthread/include/")

# find_library(CUDA_BLAS_LIBRARY cublas ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})
# find_library(CUDA_RANDOM_LIBRARY curand ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

set(CUDA_SEPARABLE_COMPILATION ON)
set(CUDA_PROPAGATE_HOST_FLAGS ON)
set(CUDA_BUILD_EMULATION OFF)

set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-arch=sm_52;-O3;-G;-g;-std=c++11)
if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 11)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()
link_directories("../../package/pthread/lib/")
add_compile_options(-Xcompiler "/wd4819 ")
add_definitions(-D OPENCV)
add_definitions(-D _MBCS)
add_definitions(-D LIB_EXPORTS)
add_definitions(-D _TIMESPEC_DEFINED)
add_definitions(-D _SCL_SECURE_NO_WARNINGS)
add_definitions(-D _CRT_SECURE_NO_WARNINGS)
add_definitions(-D GPU)
add_definitions(-D WIN32)
add_definitions(-D NDEBUG)
add_definitions(-D _CONSOLE)
add_definitions(-D _LIB)
FILE(GLOB INCLUDE_FILES "./include/*.h" "./include/*.hpp")
FILE(GLOB CORE_FILES "./Core/*.h" "./Core/*.hpp" "./Core/*.c" "./Core/*.cpp" "./Core/*.cu") 
FILE(GLOB CROSS_PLATFORM_FILES "./CrossPlatform/*.h" "./CrossPlatform/*.hpp" "./CrossPlatform/*.c" "./CrossPlatform/*.cpp" "./CrossPlatform/*.cu") 
if(DarkNetExamples)
FILE(GLOB EXAMPLES_FILES "./Examples/*.h" "./Examples/*.hpp" "./Examples/*.c" "./Examples/*.cpp" "./Examples/*.cu") 
endif()
FILE(GLOB MODELS_FILES "./Models/*.h" "./Models/*.hpp" "./Models/*.c" "./Models/*.cpp" "./Models/*.cu") 
FILE(GLOB UTILS_FILES "./Utils/*.h" "./Utils/*.hpp" "./Utils/*.c" "./Utils/*.cpp" "./Utils/*.cu")

source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Core" FILES ${CORE_FILES})
source_group("CrossPlatform" FILES ${CROSS_PLATFORM_FILES})
if(DarkNetExamples)
source_group("Examples" FILES ${EXAMPLES_FILES})
endif()
source_group("Models" FILES ${MODELS_FILES})
source_group("Utils" FILES ${UTILS_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)

set(BUILD_SRC ${CORE_FILES} ${INCLUDE_FILES} ${CROSS_PLATFORM_FILES} ${UTILS_FILES} ${MODELS_FILES} )
if(DarkNetExamples)
list(APPEND BUILD_SRC ${EXAMPLES_FILES})
endif()
#SET_SOURCE_FILES_PROPERTIES(${BUILD_SRC} PROPERTIES LANGUAGE CXX )
ADD_LIBRARY(EvisionObjDetectionEngine SHARED ${BUILD_SRC})
target_link_libraries(EvisionObjDetectionEngine ${OpenCV_LIBS})
set_target_properties(EvisionObjDetectionEngine PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
#链接pthread
target_link_libraries(EvisionObjDetectionEngine ../../package/pthread/lib/pthreadVC2)
#链接CUDA
target_link_libraries(EvisionObjDetectionEngine ${CUDA_BLAS_LIBRARY} ${CUDA_RANDOM_LIBRARY} ${CUDA_CUDA_LIBRARY} ${CUDA_cublas_LIBRARY} ${CUDA_curand_LIBRARY} ${CUDA_CUDART_LIBRARY})
# 添加编译前事件
# -E copy_if_different 拷贝文件,相同则跳过
# -E copy_directory 拷贝目录下的所有文件
add_custom_command(TARGET EvisionObjDetectionEngine POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_directory  # which executes "cmake - E copy_if_different..."
        "../../package/pthread/dll/"      # <--this is in-file
        $<TARGET_FILE_DIR:EvisionObjDetectionEngine>)                 # <--this is out-file path