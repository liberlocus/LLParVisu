cmake_minimum_required(VERSION 2.6.4)
project(parliber)
find_package(VTK REQUIRED)
include_directories("${VTK_INCLUDE_DIRS}")
#find_package(HDF5 REQUIRED)
#include_directories("${HDF5_INCLUDE_DIRS}")
include_directories("${CMAKE_SOURCE_DIR}")

add_definitions(-Wno-deprecated)

add_library(parliber liberParVTK.h liberParVTK.cpp liberParXMF.h
liberParXMF.cpp liberParOut.h liberParOut.cpp)

target_link_libraries(parliber ${VTK_LIBRARIES})
#target_link_libraries(liber ${HDF5_LIBRARIES})



