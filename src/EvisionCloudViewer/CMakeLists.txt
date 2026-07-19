# EvisionCloudViewer: 三维点云查看

find_package(VTK)
if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()
find_package(PCL REQUIRED COMPONENTS io common)

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
add_library(EvisionCloudViewer SHARED
    ${SRC_FILES}
    ${HEAD_FILES}
    ${INCLUDE_FILES}
    ${MOC_FILES}
    ${RES_FILES}
    ${UIC_FILES}
    ${QRC_FILES}
)

# 预处理器定义
target_compile_definitions(EvisionCloudViewer PRIVATE
    UNICODE
    QT_CORE_LIB
    QT_GUI_LIB
    QT_WIDGETS_LIB
    EVISIONCLOUDVIEWER_LIB
)

# include 目录
target_include_directories(EvisionCloudViewer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${PCL_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)

# 链接依赖 (Qt6::OpenGL 自动传递 Qt OpenGL 头文件与库,无需 Qt5OpenGL_LIBRARIES)
target_link_libraries(EvisionCloudViewer PRIVATE
    Qt6::OpenGL Qt6::Widgets Qt6::Core Qt6::Gui
    ${OpenCV_LIBS}
    ${PCL_LIBRARIES}
)
