#pragma once

#include <stdint.h>
#include <stdbool.h>

void hal_io_out(uint32_t pinNr, bool pinState);

int hal_io_leverPosition(void);

uint32_t hal_io_konst(const uint32_t* const i_arg1);
