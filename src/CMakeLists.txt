cmake_minimum_required( VERSION 3.18 )  

###########
# Project #
###########
SET(PROJECT_NAME SimpleDicomViewer)
project(${PROJECT_NAME})  
set(CMAKE_INCLUDE_CURRENT_DIR ON)  


#########################
# External Dependencies #
#########################
find_package( ITK REQUIRED )  
include( ${ITK_USE_FILE}) 
find_package( VTK REQUIRED )  
#include( ${VTK_USE_FILE} )
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 REQUIRED QUIET COMPONENTS Core Widgets OpenGL)
find_package(Qt5Widgets)  
include_directories(${PROJECT_SOURCE_DIR}  
                    ${CMAKE_CURRENT_BINARY_DIR}  
					${VTK_USE_FILE}
					${ITK_USE_FILE}
                    #${OpenCV_LIBRARY_DIRS}
					) 
					
					
###########
# Targets #
###########
set(PROJECT_HDRS
mainModular/SimpleDicomViewer.h
mainModular/FourViews.h
mainModular/sdvInclude.h
)

set(PROJECT_SRCS 
mainModular/main.cpp
mainModular/FourViews.cpp
mainModular/SimpleDicomViewer.cpp
)

file(GLOB PROJECT_UIS "mainModular/*.ui")
QT5_WRAP_UI(PROJECT_UIS_H ${PROJECT_UIS})

set(PROJECT_MOC_HDRS
mainModular/SimpleDicomViewer.h
)
QT5_WRAP_CPP(PROJECT_MOC_SRCS ${PROJECT_MOC_HDRS})

set(RESOURCE_FILE mainModular/SimpleDicomViewer.qrc)
QT5_ADD_RESOURCES(RESOURCE ${RESOURCE_FILE})

file(GLOB DICOMFlie dicomModular/*)

file(GLOB visualizationFile visualizationModular/*)

add_library(dicomModular STATIC ${DICOMFlie})

add_library(visualizationModular STATIC ${visualizationFile})

TARGET_LINK_LIBRARIES ( 
	dicomModular
    ${VTK_LIBRARIES}
    ${ITK_LIBRARIES}
  )
  
TARGET_LINK_LIBRARIES ( 
	visualizationModular
	${VTK_LIBRARIES}
	${ITK_LIBRARIES}
)

ADD_EXECUTABLE(${PROJECT_NAME}
	${PROJECT_HDRS}
	${PROJECT_SRCS}
	${PROJECT_UIS_H}
	${PROJECT_MOC_SRCS}
	${RESOURCE}
)

TARGET_LINK_LIBRARIES ( 
    ${PROJECT_NAME}
    ${VTK_LIBRARIES}
    ${ITK_LIBRARIES}
    #${OpenCV_LIBS}
	Qt5::Widgets  
	Qt5::Core
	Qt5::Gui
	dicomModular
	visualizationModular
  )
#vtk_module_autoinit(TARGETS SimpleDicomViewer MODULES ${VTK_LIBRARIES})