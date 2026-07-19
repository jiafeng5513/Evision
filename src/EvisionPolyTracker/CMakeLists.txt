# EvisionPolyTracker: 单目几何体追踪

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 收集源文件
file(GLOB INCLUDE_FILES CONFIGURE_DEPENDS "./include/*.h")
file(GLOB HEAD_FILES    CONFIGURE_DEPENDS "./*.h")
file(GLOB SRC_FILES     CONFIGURE_DEPENDS "./*.cpp")
file(GLOB UI_FILES      CONFIGURE_DEPENDS "./*.ui")
file(GLOB RES_FILES     CONFIGURE_DEPENDS "./*.qrc")

# Qt 处理
qt6_wrap_ui(UIC_FILES ${UI_FILES})
qt6_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
qt6_add_resources(QRC_FILES ${RES_FILES})

# 文件整理
source_group("include"         FILES ${INCLUDE_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files"      FILES ${UI_FILES})
source_group("Resource Files"  FILES ${RES_FILES})
source_group("Source Files"    FILES ${SRC_FILES})
source_group("Header Files"    FILES ${HEAD_FILES})

# 生成动态库
add_library(EvisionPolyTracker SHARED
    ${SRC_FILES}
    ${HEAD_FILES}
    ${INCLUDE_FILES}
    ${MOC_FILES}
    ${RES_FILES}
    ${UIC_FILES}
    ${QRC_FILES}
)

# 预处理器定义
target_compile_definitions(EvisionPolyTracker PRIVATE
    UNICODE
    QT_CORE_LIB
    QT_GUI_LIB
    QT_WIDGETS_LIB
    EVISIONPOLYTRACKER_LIB
)

# include 目录
target_include_directories(EvisionPolyTracker
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ../EvisionUtils/include
        ../EvisionPnP
)

# 链接依赖
target_link_libraries(EvisionPolyTracker PRIVATE
    Qt6::OpenGL Qt6::OpenGLWidgets Qt6::Widgets Qt6::Core Qt6::Gui
    ${OpenCV_LIBS}
    EvisionUtils
    EvisionPnP
)
