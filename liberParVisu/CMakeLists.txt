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

Find_package(liberVisu REQUIRED)
If (liberVisu_FOUND)
  message("parallel found serial")
  include_directories(${liberVisu_INCLUDE_DIRS})
  target_link_libraries (liberParVisu ${liberVisu_LIBRARIES})
Endif (liberVisu_FOUND)

#set(CMAKE_BUILD_TYPE release)
#include_directories(.)
#install(DIRECTORY liberParVisu DESTINATION include FILES_MATCHING PATTERN *.h
#PATTERN .svn EXCLUDE)
#install(TARGETS liberParVisu DESTINATION lib)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LiberLocus Parallel Visualization Library")
SET(CPACK_PACKAGE_VENDOR "LiberLocus")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.TXT")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYRIGHT.TXT")
SET(CPACK_GENERATOR "TGZ" "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Simsek Demir")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "4")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
INCLUDE(CPack)




