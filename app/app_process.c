#include <stdint.h>
#include <stdbool.h>

#include "app_process.h"
#include "hal_io.h"

void app_process_foo(int input) {
  if (input >= 42) {
    hal_io_out(4, true);
  }
  else {
    hal_io_out(4, false);
  }
}
