#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "hal_io.h"

void hal_io_out(uint32_t pinNr, bool pinState) {
  printf("Pin Number %u set to %u", pinNr, pinState);
}

int hal_io_leverPosition(void) {
  return 42;
}
