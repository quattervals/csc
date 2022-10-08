#include "gtest/gtest.h"

extern "C" {
#include "app_1.h"
#include "fakes/hal/hal_1_fake.h"
}

// using ::testing::Invoke;
// using ::testing::Return;

class FirstTest : public ::testing::Test
{
protected:
  void SetUp() override {
    std::cout << "Setting up MathCollection Test" << std::endl;
  }

  void TearDown() override {
    std::cout << "Teardown up MathCollection Test" << std::endl;
  }
};

TEST_F(FirstTest, summation) {
  EXPECT_EQ(42, app_add(21, 21));
}

TEST_F(FirstTest, calc_with_dep) {
  EXPECT_EQ(42, app_do_calc_using_dep(21, 21));
}
