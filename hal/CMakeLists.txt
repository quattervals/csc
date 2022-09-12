add_library(libHal OBJECT)

target_sources(
  libHal PRIVATE
  ${PROJECT_SOURCE_DIR}/hal/hal_1.c
)

# target_link_libraries(libHal PUBLIC)
# target_include_directories(libApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(libHal PUBLIC common)