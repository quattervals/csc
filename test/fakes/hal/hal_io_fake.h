#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "lib/fff.h"

DECLARE_FAKE_VOID_FUNC(hal_io_out, uint32_t, bool)

// todo: cleanup for fakes
// cleanup environment
