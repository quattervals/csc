#include "gtest/gtest.h"

extern "C" {
#include "app_process.h"
#include "fakes/hal/hal_io_fake.h"
}

// using ::testing::Invoke;
// using ::testing::Return;

class SpyOnFoo : public ::testing::Test
{
protected:
  void SetUp() override {
    std::cout << "Setting up App Process Test" << std::endl;
  }

  void TearDown() override {
    std::cout << "Teardown up App Process Test" << std::endl;
  }
};

TEST_F(SpyOnFoo, Foo_PathWithHighInput_Pin4IsHigh) {
  app_process_foo(50);

  EXPECT_EQ(4, hal_io_out_fake.arg0_val);
  EXPECT_EQ(true, hal_io_out_fake.arg1_val);
}

TEST_F(SpyOnFoo, Foo_PathWithLowInput_Pin4IsLow) {
  app_process_foo(-69);

  EXPECT_EQ(4, hal_io_out_fake.arg0_val);
  EXPECT_EQ(false, hal_io_out_fake.arg1_val);
}

class StubForBar : public ::testing::Test
{};

TEST_F(StubForBar, Bar_PathWithLeverHigh_BarIs9) {
  hal_io_leverPosition_fake.return_val = 56;
  EXPECT_EQ(9, app_process_bar());
}

TEST_F(StubForBar, Bar_PathWithLeverLow_BarIsMinus9) {
  hal_io_leverPosition_fake.return_val = -33;
  EXPECT_EQ(-9, app_process_bar());
}

TEST_F(StubForBar, Bar_PathWithLeverMid_BarIsZero) {
  hal_io_leverPosition_fake.return_val = -4;
  EXPECT_EQ(0, app_process_bar());
}