cmake_minimum_required(VERSION 2.6.4)
project(liberParVisu)

add_definitions(-Wno-deprecated)

add_library(liberParVisu liberParVisuHDF.h liberParVisuHDF.cpp liberParVisuXMF.h liberParVisuXMF.cpp liberParVisuVTK.h liberParVisuVTK.cpp liberParVisu.h)

find_package(VTK REQUIRED)
if (VTK_FOUND)
  include_directories("${VTK_INCLUDE_DIRS}")
  target_link_libraries(liberParVisu ${VTK_LIBRARIES})
endif (VTK_FOUND)

find_package(HDF5 1.8.6 REQUIRED)
if (HDF5_FOUND)
  include_directories("${HDF5_INCLUDE_DIRS}")
  target_link_libraries(liberParVisu ${HDF5_LIBRARIES})
endif (HDF5_FOUND)

include_directories("${CMAKE_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

find_package(liberVisu REQUIRED)
if (liberVisu_FOUND)
  include_directories(${liberVisu_INCLUDE_DIRS})
  target_link_libraries (liberParVisu ${liberVisu_LIBRARIES})
endif (liberVisu_FOUND)






