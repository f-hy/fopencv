cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(test)
link_directories(${LIB_PATH})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
add_subdirectory(dg)
set(CV_BASE cvbase)
add_subdirectory(${CV_BASE})