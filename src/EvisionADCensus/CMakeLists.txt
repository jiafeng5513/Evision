# Evision ADCensus
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
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")

FILE(GLOB INCLUDE_FILES "./include/*.h")
FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 

source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

add_definitions(-D LIB_EXPORTS)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
# set(CMAKE_DEBUG_POSTFIX "_d")
# set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

#生成动态链接库
ADD_LIBRARY(EvisionADCensus SHARED ${SRC_FILES} ${HEAD_FILES} ${INCLUDE_FILES})

# Link your application with OpenCV libraries
target_link_libraries(EvisionADCensus ${OpenCV_LIBS})

#自定义库的导出和安装
# SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../install/EvisionADCensus)

# target_include_directories(EvisionADCensus PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     $<INSTALL_INTERFACE:include>)

# set_target_properties(EvisionADCensus PROPERTIES PUBLIC_HEADER "${INCLUDE_FILES}")

# install(TARGETS EvisionADCensus
#     EXPORT EvisionADCensus-targets
#     PUBLIC_HEADER DESTINATION include
#     ARCHIVE DESTINATION lib
#     LIBRARY DESTINATION lib
#     RUNTIME DESTINATION bin)

# install(EXPORT EvisionADCensus-targets
#     NAMESPACE EvisionADCensus::
#     FILE EvisionADCensus-config.cmake
#     DESTINATION lib/cmake/EvisionADCensus)