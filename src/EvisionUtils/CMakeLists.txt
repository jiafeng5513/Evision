#EvisionUtils: 通用工具类

#设置工程包含当前目录
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")
#预处理器定义
add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D EVISIONUTILS_LIB)
LINK_DIRECTORIES(../install/lib)

FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB SRC_FILES "./*.cpp") 
#查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 
#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 
#编译ui文件
qt6_wrap_ui(UIC_FILES ${UI_FILES})
#mc
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
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
#创建可执行文件工程
add_library(EvisionUtils SHARED ${INCLUDE_FILES} ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${UIC_FILES} ${QRC_FILES})

#链接Qt5依赖项
target_link_libraries(EvisionUtils Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Core5Compat)
#链接OpenCV
target_link_libraries(EvisionUtils ${OpenCV_LIBS})
