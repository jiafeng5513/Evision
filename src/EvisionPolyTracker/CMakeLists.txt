# Evision polygon tracker

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")
include_directories("../EvisionUtils/include/")
include_directories("../EvisionPnP/")

add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D EVISIONPOLYTRACKER_LIB)

FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB HEAD_FILES "./*.h" "") 
FILE(GLOB SRC_FILES "./*.cpp")

#库目录
LINK_DIRECTORIES(../install/lib)

#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 

#编译ui文件
qt6_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt6_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt6_add_resources(QRC_FILES ${RES_FILES})

#文件整理
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("include" FILES ${INCLUDE_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})

#生成目标文件
add_library(EvisionPolyTracker SHARED ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${INCLUDE_FILES} ${UIC_FILES} ${QRC_FILES})
#链接Qt5依赖项
target_link_libraries(EvisionPolyTracker Qt6::OpenGL Qt6::Widgets Qt6::Core Qt6::Gui Qt6::OpenGLWidgets)
#链接OPENGL
target_link_libraries(EvisionPolyTracker ${OPENGL_gl_LIBRARY} ${Qt5OpenGL_LIBRARIES})
#链接OpenCV
target_link_libraries(EvisionPolyTracker ${OpenCV_LIBS})
#链接通用工具类
target_link_libraries(EvisionPolyTracker EvisionUtils)
#链接自定义库
target_link_libraries(EvisionPolyTracker EvisionPnP)