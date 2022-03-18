###########
# Project #
###########
cmake_minimum_required(VERSION 3.4)
project(SimpleDicomViewer)
set(CODE_ROOT ${CMAKE_SOURCE_DIR}/src)
#######################
# Folder organisation #
#######################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Indicate that previous configuration exists
set(CONFIGURED TRUE)


set(INCLUDE_DIRS
	${CODE_ROOT}/dicomModular
    ${CODE_ROOT}/mainModular
    ${CODE_ROOT}/visualizationModular
    )


###########
# Targets #
###########
add_subdirectory(src)
