#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef int (*TaskCallback)(void);

int os_rtos_createTask(TaskCallback taskCallback);
int os_rtos_getPid(void);