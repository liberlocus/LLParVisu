cmake_minimum_required(VERSION 2.6.4)
project(liberParVisu)
find_package(VTK REQUIRED)
include_directories("${VTK_INCLUDE_DIRS}")
#find_package(HDF5 REQUIRED)
#include_directories("${HDF5_INCLUDE_DIRS}")
include_directories("${CMAKE_SOURCE_DIR}")

add_definitions(-Wno-deprecated)

#add_library(parliber liberParVTK.h liberParVTK.cpp liberParXMF.h
#liberParXMF.cpp liberParOut.h liberParOut.cpp)
add_library(liberParVisu liberParVisuVTK.h liberParVisuVTK.cpp liberParVisuOut.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
find_package(liberVisu)
if (liberVisu_FOUND)
  include_directories(${liberVisu_INCLUDE_DIRS})
  target_link_libraries (liberParVisu ${liberVisu_LIBRARIES})
endif (liberVisu_FOUND)

target_link_libraries(liberParVisu ${VTK_LIBRARIES})
#target_link_libraries(liber ${HDF5_LIBRARIES})



