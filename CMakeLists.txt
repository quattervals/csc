cmake_minimum_required(VERSION 3.22)

project(
  csc
  LANGUAGES CXX C
  VERSION 0.1
  DESCRIPTION "Conference Sample Code: Testing microcontroller FW in C")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_GMOCK OFF)

# Set a default build type if none was specified
set(default_build_type "Debug")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
    STRING "Choose the type of build." FORCE)
endif()

if(CMAKE_FIND_ROOT_PATH)
  message(STATUS "Appending install prefix to root path")
  list(APPEND CMAKE_FIND_ROOT_PATH ${PROJECT_SOURCE_DIR})
endif()

# Caching to speedup compile time
# need to apt install ccache
find_program(CCACHE_PROGRAM "ccache")

if(CCACHE_PROGRAM)
  set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
  message(STATUS "Using ${CCACHE_PROGRAM}")
else()
  message(NOTICE "${CCACHE_PROGRAM} not found. Install ${CCACHE_PROGRAM} for faster builds.")
endif(CCACHE_PROGRAM)

# Include Goolge Test. Instructions from here https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(GoogleTest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG release-1.12.0)
FetchContent_MakeAvailable(googletest)

add_library(common INTERFACE)

add_subdirectory(${PROJECT_SOURCE_DIR}/app)

add_subdirectory(${PROJECT_SOURCE_DIR}/hal)

add_subdirectory(${PROJECT_SOURCE_DIR}/os)

add_executable(${PROJECT_NAME} target.c)

target_include_directories(common INTERFACE
  ${PROJECT_SOURCE_DIR}/app/
  ${PROJECT_SOURCE_DIR}/hal/
  ${PROJECT_SOURCE_DIR}/os/
)
target_link_libraries(${PROJECT_NAME} PUBLIC libApp libHal libOs common)

enable_testing()
add_subdirectory(test)
