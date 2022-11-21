#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "lib/fff.h"

DECLARE_FAKE_VOID_FUNC(hal_io_out, uint32_t, bool)
DECLARE_FAKE_VALUE_FUNC(int, hal_io_leverPosition)

void hal_io_fake_reset(void);