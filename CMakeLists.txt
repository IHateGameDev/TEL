cmake_minimum_required(VERSION 3.10)
project(TEM)

option(BUILD_AS_SHARED "Build as shared library" OFF)
option(BUILD_TESTS "Enable build tests" ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

if(EXISTS ${CMAKE_SOURCE_DIR}/APIMacros)
  include_directories(${CMAKE_SOURCE_DIR}/APIMacros)
endif()

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to \"Release\"")
  set(CMAKE_BUILD_TYPE "Release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif()


file(GLOB temSources
  ${CMAKE_SOURCE_DIR}/src/*.c
)

if(BUILD_AS_SHARED)
  add_library(tem SHARED ${temSources})
else()
  add_library(tem STATIC ${temSources})
endif()

install(TARGETS tem DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/TEM DESTINATION include)

if(BUILD_TESTS)
  add_subdirectory(examples)
endif()
