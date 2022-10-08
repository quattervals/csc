#include "gtest/gtest.h"

extern "C" {
#include "app_process.h"
#include "fakes/hal/hal_io_fake.h"
}

// using ::testing::Invoke;
// using ::testing::Return;

class AppProcess : public ::testing::Test
{
protected:
  void SetUp() override {
    std::cout << "Setting up App Process Test" << std::endl;
  }

  void TearDown() override {
    std::cout << "Teardown up App Process Test" << std::endl;
  }
};

TEST_F(AppProcess, Foo_PathWithHighInput_Pin4IsHigh) {
  app_process_foo(50);

  EXPECT_EQ(4, hal_io_out_fake.arg0_val);
  EXPECT_EQ(true, hal_io_out_fake.arg1_val);
}

TEST_F(AppProcess, Foo_PathWithLowInput_Pin4IsLow) {
  app_process_foo(-69);

  EXPECT_EQ(4, hal_io_out_fake.arg0_val);
  EXPECT_EQ(false, hal_io_out_fake.arg1_val);
}
