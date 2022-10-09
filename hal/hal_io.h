#pragma once

#include <stdint.h>
#include <stdbool.h>

void hal_io_out(uint32_t pinNr, bool pinState);

int hal_io_leverPosition(void);