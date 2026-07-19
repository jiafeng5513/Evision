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
# 注意: ${CMAKE_CURRENT_SOURCE_DIR} 必须保留 — image.h/descriptor.h/matrix.h 等
# 使用 #include <libapi.h> (尖括号=系统包含), 而 libapi.h 位于源码根目录而非 include/
target_include_directories(EvisionElas PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 OpenCV
target_link_libraries(EvisionElas PUBLIC ${OpenCV_LIBS})
