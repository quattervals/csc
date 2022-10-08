#pragma once
#include <stdbool.h>
#include "lib/fff.h"

DECLARE_FAKE_VOID_FUNC(helloHal)
DECLARE_FAKE_VALUE_FUNC(bool, hal_1_setupOk)
DECLARE_FAKE_VALUE_FUNC(int, hal_1_hal_mult, int, int)

// todo: cleanup for fakes
// cleanup environment


