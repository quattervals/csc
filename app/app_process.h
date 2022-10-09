#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "app_measurement.h"

void app_process_foo(int input);

int app_process_bar(void);

bool app_process_algorithmFix(int threshold);

bool app_process_algorithmDi(TemperatureMeasurement temperatureProcessingFunction, int threshold);
