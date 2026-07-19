#EvisionUtils: 通用工具类

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 收集源文件
file(GLOB INCLUDE_FILES CONFIGURE_DEPENDS "./include/*.h")
file(GLOB SRC_FILES     CONFIGURE_DEPENDS "./*.cpp")
file(GLOB HEAD_FILES    CONFIGURE_DEPENDS "./*.h")
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
add_library(EvisionUtils SHARED
    ${INCLUDE_FILES}
    ${SRC_FILES}
    ${HEAD_FILES}
    ${MOC_FILES}
    ${RES_FILES}
    ${UIC_FILES}
    ${QRC_FILES}
)

# 预处理器定义 (EVISIONUTILS_LIB 控制 Q_DECL_EXPORT/Q_DECL_IMPORT)
target_compile_definitions(EvisionUtils PRIVATE
    UNICODE
    QT_CORE_LIB
    QT_GUI_LIB
    QT_WIDGETS_LIB
    EVISIONUTILS_LIB
)

# include 目录
target_include_directories(EvisionUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接依赖
target_link_libraries(EvisionUtils PUBLIC
    Qt6::Widgets Qt6::Core Qt6::Gui
    ${OpenCV_LIBS}
)
