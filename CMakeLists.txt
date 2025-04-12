cmake_minimum_required(VERSION 3.10)
project(TEM)

###### OPTIONS SECTION ######

option(BUILD_DOC      "Build doxygen docs"    OFF)
option(BUILD_SHARED   "Build shared library"  OFF)
option(BUILD_EXAMPLES "Build examples"        OFF)
option(BUILD_STATIC   "Build static library"  ON)
option(EXAMPLES_USE   "Library type of tem"   "Static")

##### DOC SECTION ######

if(BUILD_DOC)
  find_package(Doxygen REQUIRED)
  set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
  
  add_custom_target(doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
  VERBATIM)
endif()

###### SETUP C SECTION ######

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to \"Release\"")
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif()

###### LIBRARY SECTION ######

file(GLOB temSources
  ${CMAKE_SOURCE_DIR}/src/*.c
)

if(BUILD_SHARED)
  add_library(tem-shared SHARED ${temSources})
endif()

if(BUILD_STATIC)
  add_library(tem-static STATIC ${temSources})
endif()

if(EXAMPLES_USE STREQUAL "Shared")
  set(tem tem-shared)
elseif(EXAMPLES_USE STREQUAL "Static")
  set(tem tem-static)
else()
  set(EXAMPLES_USE "Static")
  message(STATUS "EXAMPLES_USE not set currently, defaulting to \"Static\"")
  set(tem tem-static)
endif()

###### INSTALL SECTION ######

install(TARGETS ${tem} DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/TEM DESTINATION include)

###### EXAMPLES SECTION ######

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
