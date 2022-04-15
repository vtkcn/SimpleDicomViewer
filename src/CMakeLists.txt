cmake_minimum_required( VERSION 3.18 )  

###########
# Project #
###########
SET(PROJECT_NAME SimpleDicomViewer)
project(${PROJECT_NAME})  

set(CMAKE_INCLUDE_CURRENT_DIR ON)  
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#########################
# External Dependencies #
#########################
#find_package( ITK REQUIRED )  
#include( ${ITK_USE_FILE}) 
find_package( VTK REQUIRED )  
#include( ${VTK_USE_FILE} )
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 REQUIRED QUIET COMPONENTS Core Widgets OpenGL)
#find_package(Qt5Widgets)  
include_directories(${PROJECT_SOURCE_DIR}  
                    ${CMAKE_CURRENT_BINARY_DIR}  
					${VTK_DIR}
					#${ITK_DIR}
                    #${OpenCV_LIBRARY_DIRS}
					) 
					
					
###########
# Targets #
###########

FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEAD_FILES "./*.h")
FILE(GLOB UI_FILES "./*.ui")
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
set(RCC_FILES SimpleDicomViewer.qrc)
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${WRAP_FILES})

TARGET_LINK_LIBRARIES ( 
    ${PROJECT_NAME}
    ${VTK_LIBRARIES}
    #${ITK_LIBRARIES}
    #${OpenCV_LIBS}
	Qt5::Widgets  
	Qt5::Core
	Qt5::Gui
  )
vtk_module_autoinit(TARGETS SimpleDicomViewer MODULES ${VTK_LIBRARIES})