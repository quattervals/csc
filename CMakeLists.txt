cmake_minimum_required(VERSION 3.22)

project(
  ese
  LANGUAGES CXX C
  VERSION 0.1
  DESCRIPTION "Gtest with C")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_GMOCK OFF)

if(CMAKE_FIND_ROOT_PATH)
  message(STATUS "Appending install prefix to root path")
  list(APPEND CMAKE_FIND_ROOT_PATH ${PROJECT_SOURCE_DIR})

  # list(APPEND CMAKE_FIND_ROOT_PATH ${CMAKE_INSTALL_PREFIX})
endif()



# Get Goolge Test. Instructions from here https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(GoogleTest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG release-1.12.0)
FetchContent_MakeAvailable(googletest)


add_library(common INTERFACE)

add_subdirectory(${PROJECT_SOURCE_DIR}/app)

add_subdirectory(${PROJECT_SOURCE_DIR}/hal)


add_executable(${PROJECT_NAME} target.c)

target_include_directories(common INTERFACE
  ${PROJECT_SOURCE_DIR}/app/
  ${PROJECT_SOURCE_DIR}/hal/
)
target_link_libraries(${PROJECT_NAME} PUBLIC libApp libHal common)


enable_testing()
add_subdirectory(test)
