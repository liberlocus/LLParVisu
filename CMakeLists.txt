#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6C)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
# The version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
#Name your project here
project(maestro)

add_definitions(-Wno-deprecated )
add_executable(maestro.x main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

find_package(MPI REQUIRED)
if (MPI_FOUND)
#3  set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
#  set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
#  include_directories(${MPI_INCLUDE_DIRS})
  include_directories(${MPI_INCLUDE_PATH})
  target_link_libraries (maestro.x ${MPI_LIBRARIES})
endif (MPI_FOUND)

find_package(liberVisu REQUIRED)
if (liberVisu_FOUND)
  message("serial found")
  include_directories(${liberVisu_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${liberVisu_LIBRARIES})
endif (liberVisu_FOUND)

find_package(liberParVisu REQUIRED)
if (liberParVisu_FOUND)
  message("parallel found")
  include_directories(${liberParVisu_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${liberParVisu_LIBRARIES} ${liberVisu_LIBRARIES})
endif (liberParVisu_FOUND)

find_package(VTK REQUIRED)
if (VTK_FOUND)
  include_directories(${VTK_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${VTK_LIBRARIES})
endif (VTK_FOUND)

find_package(HDF5 1.8.6 REQUIRED)
if (HDF5_FOUND)
  include_directories(${HDF5_INCLUDE_DIRS})
  target_link_libraries (maestro.x /usr/global/hdf5/1.8.6/lib/libhdf5_cpp.so ${HDF5_LIBRARIES})
endif (HDF5_FOUND)

############## TESTING ###############
ENABLE_TESTING()
include(CTest)
ADD_TEST(SimpleTest mpirun maestro.x)
ADD_TEST(SimpleTest2 mpirun maestro.x)
