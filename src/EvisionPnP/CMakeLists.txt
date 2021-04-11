# pnp

set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories(${OpenCV_INCLUDE_DIRS})

#查找当前文件夹中的所有源代码文件
FILE(GLOB SRC_FILES "./*.cpp") 
#查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 

#文件整理
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

#创建动态链接库
ADD_LIBRARY(EvisionPnP SHARED ${HEAD_FILES} ${SRC_FILES} )

#链接OpenCV
target_link_libraries(EvisionPnP ${OpenCV_LIBS})