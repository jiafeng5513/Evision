#EvisionTrace: 交互式测量

#包含目录
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")
include_directories("../EvisionUtils/include/")
#库目录
LINK_DIRECTORIES(../install/lib)
#预处理器定义
add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D QT_MULTIMEDIA_LIB)
add_definitions(-D QT_MULTIMEDIAWIDGETS_LIB)
add_definitions(-D EVISIONTRACE_LIB)

#收集文件
FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 
FILE(GLOB UI_FILES "./*.ui") 
FILE(GLOB RES_FILES "./*.qrc")

#编译ui文件
qt6_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt6_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt6_add_resources(QRC_FILES ${RES_FILES})
 
#文件整理
source_group("include" FILES ${INCLUDE_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})

#编译目标:创建链接库
add_library(EvisionTrace SHARED ${INCLUDE_FILES} ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})

#链接Qt5依赖项
target_link_libraries(EvisionTrace Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::MultimediaWidgets)
#链接OpenCV
target_link_libraries(EvisionTrace ${OpenCV_LIBS})
#链接通用工具类
target_link_libraries(EvisionTrace EvisionUtils)