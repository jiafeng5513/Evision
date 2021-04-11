# Evision Elas

set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")

FILE(GLOB INCLUDE_FILES "./include/*.h")
FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 

source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

add_definitions(-D LIB_EXPORTS)

#生成动态链接库
ADD_LIBRARY(EvisionElas SHARED ${SRC_FILES} ${HEAD_FILES} ${INCLUDE_FILES})

# Link your application with OpenCV libraries
target_link_libraries(EvisionElas ${OpenCV_LIBS})
