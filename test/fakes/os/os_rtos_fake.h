#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "lib/fff.h"
#include "os_rtos.h"

DECLARE_FAKE_VALUE_FUNC(int, os_rtos_createTask, TaskCallback)

void os_rtos_fake_reset(void);