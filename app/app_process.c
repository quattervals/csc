#include <stdint.h>
#include <stdbool.h>

#include "app_process.h"
#include "app_measurement.h"
#include "hal_io.h"
#include "os_rtos.h"

void app_process_foo(int input) {
  if (input >= 42) {
    hal_io_out(4, true);
  }
  else {
    hal_io_out(56, false);
  }
}

int app_process_bar(void) {
  if (hal_io_leverPosition() > 42) {
    return 9;
  }
  else if (hal_io_leverPosition() < -23) {
    return -9;
  }
  else {
    return 0;
  }
}

bool app_process_algorithmFix(int threshold) {
  const int scaleFactor = 42;
  return app_measurement_temperatureMeasurement(scaleFactor) > threshold;
}

bool app_process_algorithmDi(TemperatureMeasurement temperatureProcessingFunction, int threshold) {
  const int scaleFactor = 42;
  return temperatureProcessingFunction(scaleFactor) > threshold;
}

void app_process_setup(void) {
  const int taskHandle = os_rtos_createTask(app_process_callback);
}

int app_process_callback(void) {
  return 77;
}

uint32_t app_process_konstantin(void) {
  uint32_t val = 99;
  return hal_io_konst(&val);
}
