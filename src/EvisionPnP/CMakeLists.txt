# EvisionPnP

file(GLOB SRC_FILES  CONFIGURE_DEPENDS "./*.cpp")
file(GLOB HEAD_FILES CONFIGURE_DEPENDS "./*.h")

source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

# 生成动态库
add_library(EvisionPnP SHARED
    ${HEAD_FILES}
    ${SRC_FILES}
)

# include 目录 (PUBLIC: 下游 EvisionPolyTracker 需要 PnP 头文件)
target_include_directories(EvisionPnP PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 链接 OpenCV
target_link_libraries(EvisionPnP PUBLIC ${OpenCV_LIBS})
