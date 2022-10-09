#include "fakes/os/os_rtos_fake.h"

DEFINE_FAKE_VALUE_FUNC(int, os_rtos_createTask, TaskCallback)

void os_rtos_fake_reset(void) {
  os_rtos_createTask_reset();
}
