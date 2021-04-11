# EvisionCloudViewer

find_package(VTK)
if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
     set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()
find_package(PCL REQUIRED COMPONENTS io common)
# find_package(OpenGL)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("./include/")

add_definitions(-D QT_DLL)
add_definitions(-D QT_CORE_LIB)
add_definitions(-D QT_GUI_LIB)
add_definitions(-D QT_WIDGETS_LIB)
add_definitions(-D EVISIONCLOUDVIEWER_LIB)

FILE(GLOB INCLUDE_FILES "./include/*.h") 
FILE(GLOB HEAD_FILES "./*.h" "") 
FILE(GLOB SRC_FILES "./*.cpp")

#查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 
#查找当前文件夹中所有的ui文件
FILE(GLOB RES_FILES "./*.qrc") 

#编译ui文件
qt5_wrap_ui(UIC_FILES ${UI_FILES})
#moc
qt5_wrap_cpp(MOC_FILES ${HEAD_FILES} ${INCLUDE_FILES})
#编译qrc资源文件
qt5_add_resources(QRC_FILES ${RES_FILES})

#文件整理
source_group("Form Files" FILES ${UI_FILES})
source_group("Resource Files" FILES ${RES_FILES})
source_group("include" FILES ${INCLUDE_FILES})
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEAD_FILES})
source_group("Generated Files" FILES ${UIC_FILES} ${MOC_FILES} ${QRC_FILES})

add_library(EvisionCloudViewer SHARED ${SRC_FILES} ${HEAD_FILES} ${MOC_FILES} ${RES_FILES} ${INCLUDE_FILES} ${UIC_FILES} ${QRC_FILES})
#链接Qt5依赖项
target_link_libraries(EvisionCloudViewer ${OpenCV_LIBS} ${PCL_LIBRARIES}  ${OPENGL_gl_LIBRARY} ${Qt5OpenGL_LIBRARIES} Qt5::OpenGL Qt5::Widgets Qt5::Core Qt5::Gui)