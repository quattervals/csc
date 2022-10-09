#include <stdint.h>
#include <stdbool.h>

#include "app_measurement.h"

int app_measurement_temperatureMeasurement(int scaleFactor) {
  const int measuredTemperature = 451;
  return measuredTemperature * scaleFactor;
}
