#include "gtest/gtest.h"
#include "lib/fff_wrapper.h"

#include "fakes/os/os_rtos_fake.hpp"
#include "fakes/hal/hal_io_fake.hpp"
extern "C" {
#include "app_process.h"
#include "os_rtos.h"
}

namespace {
class Number
{
private:
  int m_number{ 0 };

public:
  int add_to_number(int summand) {
    m_number += summand;
    return m_number;
  }
};

class HAL_IO
{
public:
  HAL_IO(){};
  HAL_IO(const HAL_IO&) = delete;   // this way we get a warning when we forget to bind by reference

  bool m_pinState{ false };
  uint32_t m_pinNr{ 0 };

  void hal_io_out(uint32_t pinNr, bool pinState) {
    m_pinNr = pinNr;
    m_pinState = pinState;
  }
};
}

class FakingWithStdFunction : public ::testing::Test
{
protected:
  void SetUp() override {}

  void TearDown() override {
    os_rtos_fake_reset();
    hal_io_fake_reset();
  }
};

TEST_F(FakingWithStdFunction, lambda_with_capture) {
  TaskCallback thecallback = nullptr;
  os_rtos_createTask_fake.custom_fake = [&thecallback](TaskCallback taskCallback) {
    thecallback = taskCallback;
    return 0;
  };
  app_process_setup();

  EXPECT_EQ(77, thecallback());
}

namespace {
FAKE_VALUE_FUNC(int, some_foo, int, const int*)
}

TEST_F(FakingWithStdFunction, const_lambda_with_capture) {
  int to_be_captured{ 5 };

  some_foo_fake.custom_fake = [&to_be_captured](int param_1, const int* param_2) {
    to_be_captured = *param_2;
    return 99;
  };

  int a_number{ 7 };
  int res = some_foo(16, &a_number);

  EXPECT_EQ(to_be_captured, a_number);
}

namespace {
FAKE_VALUE_FUNC(int, add_to_number, int)
}

TEST_F(FakingWithStdFunction, bind_member_function_to_custom_fake) {
  Number zahl;

  add_to_number_fake.custom_fake = std::bind(&Number::add_to_number, &zahl, std::placeholders::_1);

  EXPECT_EQ(44, add_to_number(44));
}

TEST_F(FakingWithStdFunction, bind_member_function_to_custom_fake_pass_object_by_reference) {
  HAL_IO hal_io;

  hal_io_out_fake.custom_fake = std::bind(&HAL_IO::hal_io_out, &hal_io, std::placeholders::_1, std::placeholders::_2);

  app_process_foo(-69);

  EXPECT_EQ(56, hal_io.m_pinNr);
  EXPECT_EQ(false, hal_io.m_pinState);
}

TEST_F(FakingWithStdFunction, fake_const_const_with_const) {
  hal_io_konst_fake.custom_fake = [](const uint32_t* i_val) {
    return *i_val + 99;
  };

  EXPECT_EQ(198, app_process_konstantin());
}
