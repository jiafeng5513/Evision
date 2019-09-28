# Evision Elas
# cmake needs this line
cmake_minimum_required(VERSION 3.13.0)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

FILE(GLOB INCLUDE_FILES "EvisionElas.h" "elas.h")# will be included by apps
FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/Debug/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/Release/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/Debug/bin)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/Release/bin)
set(CMAKE_DEBUG_POSTFIX "_d")
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

#生成动态链接库
ADD_LIBRARY(EvisionElas SHARED ${SRC_FILES} ${HEAD_FILES} ${INCLUDE_FILES})

# Link your application with OpenCV libraries
target_link_libraries(EvisionElas ${OpenCV_LIBS})

# 自定义库导出安装设置
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../install/EvisionElas)

target_include_directories(EvisionElas PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

set_target_properties(EvisionElas PROPERTIES PUBLIC_HEADER "${INCLUDE_FILES}")

install(TARGETS EvisionElas
    EXPORT EvisionElas-targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(EXPORT EvisionElas-targets
    NAMESPACE EvisionElas:: FILE EvisionElas-config.cmake DESTINATION lib/cmake/EvisionElas)

