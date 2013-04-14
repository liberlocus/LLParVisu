#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6C)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
# The version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
#Name your project here
project(maestro)
ENABLE_TESTING()
include(CTest)

add_definitions(-Wno-deprecated)
add_executable(maestro.x main.cpp)
find_package(parliber)
if (parliber_FOUND)
  include_directories(${parliber_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${parliber_LIBRARIES})
endif (parliber_FOUND)

find_package(VTK REQUIRED)
if (VTK_FOUND)
  include_directories(${VTK_INCLUDE_DIRS})
  target_link_libraries (maestro.x ${VTK_LIBRARIES})
endif (VTK_FOUND)

ADD_TEST(SimpleTest maestro.x)
