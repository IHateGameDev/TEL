cmake_minimum_required(VERSION 3.10)
project(TEM)

option(BUILD_AS_SHARED "Build tem as shared library" OFF)
option(BUILD_TESTS "Enable build tests" ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

if(EXIST ${CMAKE_SOURCE_DIR}/APIMacros)
  include_directories(${CMAKE_SOURCE_DIR}/APIMacros)
endif()

file(GLOB temSource
  ${CMAKE_SOURCE_DIR}/src/*.c
)

if(BUILD_AS_SHARED)
  add_library(tem SHARED temSource)
else()
  add_library(tem STATIC temSource)
endif()

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
