add_library(libApp OBJECT)

target_sources(
  libApp PRIVATE
  app_1.c
)


# target_include_directories(libApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(libApp PUBLIC common)

