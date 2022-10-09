add_library(libHal OBJECT)

target_sources(
  libHal PRIVATE
  ${PROJECT_SOURCE_DIR}/hal/hal_1.c
  ${PROJECT_SOURCE_DIR}/hal/hal_io.c
)

target_link_libraries(libHal PUBLIC common)
