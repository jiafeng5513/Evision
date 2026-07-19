#EvisionSandbox:主程序

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 收集源文件
file(GLOB SRC_FILES CONFIGURE_DEPENDS "./*.cpp")
file(GLOB HEAD_FILES CONFIGURE_DEPENDS "./*.h")
file(GLOB UI_FILES CONFIGURE_DEPENDS "./*.ui")
file(GLOB RES_FILES CONFIGURE_DEPENDS "./*.qrc")

# Qt 处理
qt6_wrap_ui(UIC_FILES ${UI_FILES})
qt6_wrap_cpp(MOC_FILES ${HEAD_FILES})
qt6_add_resources(QRC_FILES ${RES_FILES})

# 文件整理
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

# 创建可执行文件
add_executable(EvisionSandbox
    ${SRC_FILES}
    ${HEAD_FILES}
    ${MOC_FILES}
    ${RES_FILES}
    ${UIC_FILES}
    ${QRC_FILES}
)

# 预处理器定义
target_compile_definitions(EvisionSandbox PRIVATE
    UNICODE
    QT_CORE_LIB
    QT_GUI_LIB
    QT_WIDGETS_LIB
    QT_MULTIMEDIA_LIB
    QT_MULTIMEDIAWIDGETS_LIB
    QT_IMAGE_LIB
    QT_CORE_PRIVATE
    OPENCV
)

# include 目录 (Qt6:: targets 自动传递 Qt 头文件路径,无需手动拼接)
target_include_directories(EvisionSandbox PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    "../EvisionUtils/include/"
    "../EvisionCalibrate/include/"
    "../EvisionDisparity/include/"
    "../EvisionUndistortion/include/"
    "../EvisionTrace/include/"
    "../EvisionCamera/include/"
    "../EvisionParamBridge/include/"
    "../EvisionPolyTracker/include/"
    "../EvisionMonocularCalib/include/"
)

if(PointCloudViewer)
    target_include_directories(EvisionSandbox PRIVATE "../EvisionCloudViewer/include")
    target_compile_definitions(EvisionSandbox PRIVATE WITH_PCL)
endif()

if(ObjectDetection)
    target_include_directories(EvisionSandbox PRIVATE "../EvisionObjDetection/include/")
    target_compile_definitions(EvisionSandbox PRIVATE WITH_CUDA)
endif()

if(RealSense)
    target_include_directories(EvisionSandbox PRIVATE "../RealSenseCamera/include/")
    target_compile_definitions(EvisionSandbox PRIVATE WITH_REAL_SENSE)
endif()

# 链接库
target_link_libraries(EvisionSandbox PRIVATE
    Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::MultimediaWidgets
    ${OpenCV_LIBS}
    EvisionUtils
    EvisionCalibrate
    EvisionDisparity
    EvisionUndistortion
    EvisionTrace
    EvisionParamBridge
    EvisionPolyTracker
    EvisionMonocularCalib
)

if(ObjectDetection)
    target_link_libraries(EvisionSandbox PRIVATE EvisionObjDetection)
endif()

if(PointCloudViewer)
    target_link_libraries(EvisionSandbox PRIVATE EvisionCloudViewer)
endif()
