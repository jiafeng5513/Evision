#EvisionSandbox:主程序

#设置cmake最小版本号
cmake_minimum_required(VERSION 3.13.0)


# Find OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} )

#包含自定义组件
include_directories("../pnplib/")
#设置工程包含当前目录
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
#库目录
LINK_DIRECTORIES(../install/lib)

#查找当前文件夹中的所有源代码文件
FILE(GLOB SRC_FILES "./*.cpp") 
#查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 

#文件整理
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/../install/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../install/bin/Release)
#set(CMAKE_DEBUG_POSTFIX "_d")
#set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

#创建可执行文件工程
add_executable(pnpRegistration ${SRC_FILES} ${HEAD_FILES})

#链接OpenCV
target_link_libraries(pnpRegistration ${OpenCV_LIBS})
#链接自定义库
target_link_libraries(pnpRegistration pnplib)