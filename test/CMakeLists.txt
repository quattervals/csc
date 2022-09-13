message(STATUS "Enable testing with google test discovery")

set(TEST_APP_NAME ${PROJECT_NAME}_test)

# Following the instructions in https://google.github.io/googletest/quickstart-cmake.html
add_executable(${PROJECT_NAME}_test
  main.cpp
  firstTest.cpp
  ${PROJECT_SOURCE_DIR}/test/fakes/hal/hal_1_fake.c
  ${PROJECT_SOURCE_DIR}/test/lib/fff.h
)

target_include_directories(${PROJECT_NAME}_test PUBLIC
  ${PROJECT_SOURCE_DIR}/app
  ${PROJECT_SOURCE_DIR}/lib/googletest
  ${PROJECT_SOURCE_DIR}/test
)

target_link_libraries(${TEST_APP_NAME} gtest libApp common)

add_custom_target(${TEST_APP_NAME}_execution ALL
  DEPENDS ${TEST_APP_NAME})


include(GoogleTest)
gtest_discover_tests(${TEST_APP_NAME})

add_custom_command(
  TARGET ${TEST_APP_NAME}_execution
  POST_BUILD
  COMMAND ctest --output-on-failure -V
  VERBATIM
)