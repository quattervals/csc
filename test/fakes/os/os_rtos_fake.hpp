#pragma once
#include <stdint.h>
#include <stdbool.h>
extern "C" {
#include "os_rtos.h"
}

#include "lib/fff_wrapper.h"

DECLARE_FAKE_VALUE_FUNC(int, os_rtos_createTask, TaskCallback)
DECLARE_FAKE_VALUE_FUNC(int, os_rtos_getPid)

void os_rtos_fake_reset(void);
