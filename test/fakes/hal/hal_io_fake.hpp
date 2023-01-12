#pragma once
#include <stdint.h>
#include <stdbool.h>

extern "C" {
#include "hal_io.h"
}

#include "lib/fff_wrapper.h"

DECLARE_FAKE_VOID_FUNC(hal_io_out, uint32_t, bool)
DECLARE_FAKE_VALUE_FUNC(int, hal_io_leverPosition)

DECLARE_FAKE_VALUE_FUNC(uint32_t, hal_io_konst, const uint32_t*)

void hal_io_fake_reset(void);
