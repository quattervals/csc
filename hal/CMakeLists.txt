add_library(libHal OBJECT)

target_sources(
  libHal PRIVATE
  hal_io.c
)

target_link_libraries(libHal PUBLIC common)
