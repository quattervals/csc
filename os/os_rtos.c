#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "os_rtos.h"

int os_rtos_createTask(TaskCallback taskCallback) {
  printf("Create RTOS Task\n");
  const int taskHandle = 123;
  return taskHandle;
}