add_library(libApp OBJECT)

target_sources(
  libApp PRIVATE
  app_process.c
  app_measurement.c
)

target_link_libraries(libApp PUBLIC common)

