add_library(libOs OBJECT)

target_sources(
  libOs PRIVATE
  os_rtos.c
)

target_link_libraries(libOs PUBLIC common)