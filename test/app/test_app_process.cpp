#include "gtest/gtest.h"

#include "fakes/hal/hal_io_fake.hpp"
#include "fakes/os/os_rtos_fake.hpp"

extern "C" {
#include "app_process.h"
#include "os_rtos.h"
}

class SpyOnFoo : public ::testing::Test
{
protected:
  void SetUp() override {}

  void TearDown() override {
    os_rtos_fake_reset();
    hal_io_fake_reset();
  }
};

TEST_F(SpyOnFoo, Foo_PathWithHighInput_Pin4IsHigh) {
  app_process_foo(50);

  EXPECT_EQ(4, hal_io_out_fake.arg0_val);
  EXPECT_EQ(true, hal_io_out_fake.arg1_val);
}

TEST_F(SpyOnFoo, Foo_PathWithLowInput_Pin4IsLow) {
  app_process_foo(-69);

  EXPECT_EQ(56, hal_io_out_fake.arg0_val);
  EXPECT_EQ(false, hal_io_out_fake.arg1_val);
}

class StubForBar : public ::testing::Test
{
protected:
  void TearDown() override {
    hal_io_fake_reset();
  }
};

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

namespace {
int testHighTemperatureMeasurement(int scaleFactor) {
  return 500;
};

int testLowTemperatureMeasurement(int scaleFactor) {
  return -5;
};

FAKE_VALUE_FUNC(int, testFlexibleTemperatureMeasurement, int)
}

class DiForAlgorithm : public ::testing::Test
{
protected:
  const uint32_t threshold = 5;
};

TEST_F(DiForAlgorithm, AlgorithmFix_MeasuredTemperatureFixed_SemiUsefulTest) {
  EXPECT_EQ(true, app_process_algorithmFix(threshold));
}

TEST_F(DiForAlgorithm, AlgorithmDi_MeasuredHighTemperature_IsAboveThreshold) {
  EXPECT_EQ(true, app_process_algorithmDi(testHighTemperatureMeasurement, threshold));
}

TEST_F(DiForAlgorithm, AlgorithmDi_MeasuredLowTemperature_IsBelowThreshold) {
  EXPECT_EQ(false, app_process_algorithmDi(testLowTemperatureMeasurement, threshold));
}

TEST_F(DiForAlgorithm, AlgorithmDi_FlexibleTemperatureFffMeasurementHighTemperature_IsAboveThreshold) {
  testFlexibleTemperatureMeasurement_fake.return_val = 500;
  EXPECT_EQ(true, app_process_algorithmDi(testFlexibleTemperatureMeasurement, threshold));
}

TEST_F(DiForAlgorithm, AlgorithmDi_FlexibleTemperatureLambdaMeasurementLowTemperature_IsBelowThreshold) {
  EXPECT_EQ(false,
            app_process_algorithmDi(
              [](int scaleFactor) {
                return -9;
              },
              threshold));
}

class FakingOs : public ::testing::Test
{};

namespace {
static TaskCallback capturedCallback = nullptr;

int testCreateTask(TaskCallback taskCallback) {
  capturedCallback = taskCallback;
  return 0;
}

int testFakeOsRunningCreatedTask(void) {
  return capturedCallback();
}
}

TEST_F(FakingOs, FakeOsFunction_RunCallbackOfCreatedTask_ProductionCallbackExecuted) {
  os_rtos_createTask_fake.custom_fake = testCreateTask;
  app_process_setup();

  EXPECT_EQ(77, testFakeOsRunningCreatedTask());
}