#include "fakes/hal/hal_1_fake.h"

DEFINE_FAKE_VOID_FUNC(helloHal)
DEFINE_FAKE_VALUE_FUNC(bool, hal_1_setupOk)
DEFINE_FAKE_VALUE_FUNC(int, hal_1_hal_mult, int, int)
