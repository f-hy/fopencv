set(CMAKE_VERSION 3.26)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)# 静态库生成的路径
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)# 测试程序生成的路径
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXEC_PATH})# 设置可执行文件的输出目录，dll,ilk,pad将输出到${EXEC_PATH}
project(cv)
#OpenCV
find_package(OpenCV REQUIRED PATHS "D:/App/dev/util/opencv4.8.0/build")
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libs: ${OpenCV_LIBS}")#${OpenCV_LIBRARIES}
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
#https://blog.csdn.net/jjjstephen/article/details/129943678
add_definitions(-DSHARED_LIB_BUILD)#构建动态库时定义
add_definitions(-DSHARED_LIB_EXPORT)#动态库导出时定义，导入不需要定义
set(DG_LIB fdg)
add_subdirectory(dg)
add_subdirectory(test)