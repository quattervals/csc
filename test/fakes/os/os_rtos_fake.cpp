#include "fakes/os/os_rtos_fake.hpp"

DEFINE_FAKE_VALUE_FUNC(int, os_rtos_createTask, TaskCallback)
DEFINE_FAKE_VALUE_FUNC(int, os_rtos_getPid)

void os_rtos_fake_reset(void) {
  os_rtos_createTask_reset();
}
