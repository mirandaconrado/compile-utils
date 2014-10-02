cmake_minimum_required(VERSION 2.6)
project(compile-utils)

include_directories(include)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release.")
  set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(src)
