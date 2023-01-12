#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "hal_io.h"

void hal_io_out(uint32_t pinNr, bool pinState) {
  printf("HAL: Pin Number %u set to %u\n", pinNr, pinState);
}

int hal_io_leverPosition(void) {
  return 42;
}

uint32_t hal_io_konst(const uint32_t* const i_arg1) {
  return 7 + *i_arg1;
}
