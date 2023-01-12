#include "fakes/hal/hal_io_fake.hpp"

DEFINE_FAKE_VOID_FUNC(hal_io_out, uint32_t, bool)
DEFINE_FAKE_VALUE_FUNC(int, hal_io_leverPosition)
DEFINE_FAKE_VALUE_FUNC(uint32_t, hal_io_konst, const uint32_t*)

void hal_io_fake_reset(void) {
  hal_io_out_reset();
  hal_io_leverPosition_reset();
  hal_io_konst_reset();
}
