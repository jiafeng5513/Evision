# Evision Elas

file(GLOB INCLUDE_FILES CONFIGURE_DEPENDS "./include/*.h")
file(GLOB SRC_FILES     CONFIGURE_DEPENDS "./*.cpp")
file(GLOB HEAD_FILES    CONFIGURE_DEPENDS "./*.h")

source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Source Files"  FILES ${SRC_FILES})
source_group("Header Files"  FILES ${HEAD_FILES})

# 生成动态库
add_library(EvisionElas SHARED
    ${SRC_FILES}
    ${HEAD_FILES}
    ${INCLUDE_FILES}
)

# 预处理器定义
target_compile_definitions(EvisionElas PRIVATE LIB_EXPORTS)

# include 目录 (PUBLIC: 下游 EvisionDisparity 需要 ELAS 头文件)
target_include_directories(EvisionElas PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 OpenCV
target_link_libraries(EvisionElas PUBLIC ${OpenCV_LIBS})
