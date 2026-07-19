# Evision ADCensus

file(GLOB INCLUDE_FILES CONFIGURE_DEPENDS "./include/*.h")
file(GLOB SRC_FILES     CONFIGURE_DEPENDS "./*.cpp")
file(GLOB HEAD_FILES    CONFIGURE_DEPENDS "./*.h")

source_group("Include Files" FILES ${INCLUDE_FILES})
source_group("Source Files"  FILES ${SRC_FILES})
source_group("Header Files"  FILES ${HEAD_FILES})

# 生成动态库
add_library(EvisionADCensus SHARED
    ${SRC_FILES}
    ${HEAD_FILES}
    ${INCLUDE_FILES}
)

# 预处理器定义
target_compile_definitions(EvisionADCensus PRIVATE LIB_EXPORTS)

# include 目录 (PUBLIC: 下游 EvisionDisparity 需要 ADCensus 头文件)
# 注意: ${CMAKE_CURRENT_SOURCE_DIR} 必须保留 — aggregation.h/adcensuscv.h 等
# 使用 #include <libapi.h> (尖括号=系统包含), 而 libapi.h 位于源码根目录而非 include/
target_include_directories(EvisionADCensus PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 OpenCV
target_link_libraries(EvisionADCensus PUBLIC ${OpenCV_LIBS})
