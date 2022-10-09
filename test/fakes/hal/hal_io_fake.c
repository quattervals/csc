#include "fakes/hal/hal_io_fake.h"

DEFINE_FAKE_VOID_FUNC(hal_io_out, uint32_t, bool)
DEFINE_FAKE_VALUE_FUNC(int, hal_io_leverPosition)

void hal_io_fake_reset(void) {
  hal_io_out_reset();
  hal_io_leverPosition_reset();
}
