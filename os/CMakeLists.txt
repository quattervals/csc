add_library(libOs OBJECT)

target_sources(
  libOs PRIVATE
  ${PROJECT_SOURCE_DIR}/os/os_rtos.c
)

target_link_libraries(libOs PUBLIC common)