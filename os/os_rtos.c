#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "os_rtos.h"

int os_rtos_createTask(TaskCallback taskCallback) {
  printf("OS: Create RTOS Task\n");
  return 123;
}
