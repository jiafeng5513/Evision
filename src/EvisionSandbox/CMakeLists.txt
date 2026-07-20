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
    EvisionCamera
    EvisionParamBridge
    EvisionPolyTracker
    EvisionMonocularCalib
)

if(PointCloudViewer)
    target_link_libraries(EvisionSandbox PRIVATE EvisionCloudViewer)
endif()

# ---------------------------------------------------------------------------
# 运行时 DLL 部署 (Windows): 构建成功后自动拷贝第三方 DLL 到 exe 同目录,
# 使 EvisionSandbox.exe 无需设置 PATH 环境变量即可直接运行.
# 项目自身模块 DLL 已由 CMAKE_RUNTIME_OUTPUT_DIRECTORY 统一输出到同一目录.
# 注意: 本文件由根 CMakeLists 最后 add_subdirectory, 确保下列模块目标均已存在.
# ---------------------------------------------------------------------------
if(WIN32)
    # --- Qt6: windeployqt 部署 Qt DLL + 插件(platforms/multimedia 等) + MSVC 运行时 ---
    # 扫描 exe + 所有已启用模块 DLL:
    # MSVC 链接器会剔除 exe 中未被直接引用的 Qt DLL 导入(如 Multimedia 的使用在
    # EvisionCamera.dll 内), 仅扫描 exe 会漏掉模块 DLL 携带的 Qt 依赖.
    set(_deploy_binaries "$<TARGET_FILE:EvisionSandbox>")
    foreach(_mod IN ITEMS
        EvisionADCensus EvisionCalibrate EvisionCamera EvisionDisparity
        EvisionElas EvisionMonocularCalib EvisionParamBridge EvisionPnP
        EvisionPolyTracker EvisionTrace EvisionUndistortion EvisionUtils
        EvisionCloudViewer
    )
        if(TARGET ${_mod})
            list(APPEND _deploy_binaries "$<TARGET_FILE:${_mod}>")
        endif()
    endforeach()

    add_custom_command(TARGET EvisionSandbox POST_BUILD
        COMMAND "$<TARGET_FILE:Qt6::windeployqt>"
                --no-translations
                --compiler-runtime
                ${_deploy_binaries}
        COMMENT "Deploy Qt runtime (windeployqt)"
    )

    # --- MSVC CRT (vcruntime140/msvcp140 等): 取自 vcvars 注入的 VCToolsRedistDir ---
    # (Qt 6.9 的 --compiler-runtime 可能找不到 VS2026 的 redist, 这里显式拷贝)
    if(DEFINED ENV{VCToolsRedistDir})
        file(GLOB _vcrt_dlls "$ENV{VCToolsRedistDir}/x64/Microsoft.VC*.CRT/*.dll")
        if(_vcrt_dlls)
            add_custom_command(TARGET EvisionSandbox POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${_vcrt_dlls}
                        "$<TARGET_FILE_DIR:EvisionSandbox>"
                COMMENT "Deploy MSVC CRT runtime DLLs"
            )
        endif()
    endif()

    # --- OpenCV: 拷贝 bin 目录下的 DLL (opencv_world*, ffmpeg 等) ---
    # OpenCV_DIR 可能是 <build>/x64/vcXX/lib (叶子) 或 <build> (根), 两种布局都兼容
    get_filename_component(_opencv_dir "${OpenCV_DIR}" ABSOLUTE)
    set(_opencv_bin_candidates
        "${_opencv_dir}/../bin"                                # OpenCV_DIR=<build>/x64/vcXX/lib
        "${_opencv_dir}/${OpenCV_ARCH}/${OpenCV_RUNTIME}/bin"  # OpenCV_DIR=<build> (+显式 ARCH/RUNTIME)
        "${_opencv_dir}/bin"                                   # 其他布局
    )
    set(_opencv_bin_dir "")
    foreach(_cand IN LISTS _opencv_bin_candidates)
        if(EXISTS "${_cand}")
            get_filename_component(_opencv_bin_dir "${_cand}" ABSOLUTE)
            break()
        endif()
    endforeach()

    if(_opencv_bin_dir)
        file(GLOB _opencv_runtime_dlls "${_opencv_bin_dir}/*.dll")
        if(_opencv_runtime_dlls)
            add_custom_command(TARGET EvisionSandbox POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${_opencv_runtime_dlls}
                        "$<TARGET_FILE_DIR:EvisionSandbox>"
                COMMENT "Deploy OpenCV runtime DLLs"
            )
            message(STATUS "OpenCV runtime DLL deploy: ${_opencv_bin_dir}")
        endif()
    else()
        message(WARNING "OpenCV bin dir not found - skip OpenCV DLL deployment")
    endif()
endif()
