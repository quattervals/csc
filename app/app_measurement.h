#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef int (*TemperatureMeasurement)(int);

int app_measurement_temperatureMeasurement(int scaleFactor);
