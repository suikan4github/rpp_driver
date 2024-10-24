/**
 * @file gpiobasic.hpp
 *
 * @brief basic GPIO controller.
 * @date 2024/Sep/20
 * @author Seiichi  Horie
 * @brief Collection of the basic fuction of GPIO .
 * @copyright COPYRIGHT 2024 Seiichi Horie
 */

#ifndef PICO_DRIVER_SRC_GPIO_GPIOBASIC_HPP_
#define PICO_DRIVER_SRC_GPIO_GPIOBASIC_HPP_

#include <stdint.h>

#if __has_include(<hardware/gpio.h>)
#include "hardware/gpio.h"
#else
// Alternate definition for unit test.
#endif  // __has_include(<hardware/i2c.h>)

#include "sdk/sdkwrapper.hpp"

namespace rpp_driver {
/**
 * @brief Basic GPIO driver class.
 * @details
 * This class provides the handy way to control GPIO. To use
 * this class, pass a GPIO pin# through the constructor.
 * So, this class initialize and deinitialize that pin in the constructor and
 * destructor, respectively.
 *
 * ### Usage of mock
 * In the case of the testing of the user program which uses this class,
 * a programmer can use the pre-defined mock class ::rpp_driver::MockGpioBasic.
 * inside gpiobasic.hpp.
 *
 * ```cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "gpio/gpiobasic.hpp"
#include "sdk/sdkwrapper.hpp"


using ::testing::_;
class UserCodeTest : public ::testing::Test {
 protected:
  ::rpp_driver::MockSdkWrapper mock_sdk_;
  ::rpp_driver::MockGpioBasic* mock_gpio_;

  virtual void SetUp() {
    EXPECT_CALL(mock_sdk_, gpio_init(_)).Times(1);
    mock_gpio_ = new ::rpp_driver::MockGpioBasic(mock_sdk_);
  }

  virtual void TearDown() {
    EXPECT_CALL(mock_sdk_, gpio_deinit(_)).Times(1);
    delete (mock_gpio_);
  }
};

TEST_F(UserCodeTest, foo) {
  // Write Test code here.
}
 * ```
 */
class GpioBasic {
 public:
  /**
   * @brief Initialize the given GPIO pin and setup the pins.
   * @param sdk Sdk wrapper to inject the dependency.
   * @param pin GPIO pin number.
   * @details
   * Receive the GPIO pin.
   * And then, init it by SdkWrapper::gpio_init().
   */
  GpioBasic(SdkWrapper &sdk, uint pin);
  GpioBasic() = delete;
  /**
   * @brief deinit the GPIO by SdkWrapper::gpio_deinit();
   */
  virtual ~GpioBasic();
  /**
   * @brief Set a single GPIO direction.
   * @param out true for out, false for in.
   */
  virtual void SetDir(bool out);

  /**
   * @brief Enable GPIO input.
   * @param enabled true to enable input on this GPIO.
   */
  virtual void SetInputEnabled(bool enabled);

  /**
   * @brief Drive a single GPIO high/low.
   * @param value If false clear the GPIO, otherwise set it.
   */
  virtual void Put(bool value);

  /**
   * @brief Get state of a single GPIO.
   * @returns Current state of this GPIO. 0 for low, non-zero for high
   */
  virtual bool Get();

  /**
   * @brief Toggle the output level of this GPIO.
   * @details
   * If the current level is "H", set it to "L".
   * If the current level is "L", set it to "H".
   */
  virtual void Toggle();

  /**
   * @brief Set this GPIO to be pulled up.
   * @
   */
  virtual void PullUp();

  /**
   * @brief Set this GPIO to be pulled down.
   */
  virtual void PullDown();

  /**
   * @brief Unset pulls on this GPIO.
   *
   */
  virtual void DisablePulls();

 private:
  SdkWrapper &sdk_;
  const uint pin_;
};
#if __has_include(<gmock/gmock.h>)
// GCOVR_EXCL_START
class MockGpioBasic : public GpioBasic {
 public:
  MockGpioBasic(SdkWrapper &sdk)
      : GpioBasic(sdk, 0) {};  // 0 is dummy. We don't care.
  MOCK_METHOD1(SetDir, void(bool));
  MOCK_METHOD1(SetInputEnabled, void(bool));
  MOCK_METHOD1(Put, void(bool));
  MOCK_METHOD0(Get, bool(void));
  MOCK_METHOD0(Toggle, void(void));
  MOCK_METHOD0(PullUp, void(void));
  MOCK_METHOD0(PullDown, void(void));
  MOCK_METHOD0(DisablePulls, void(void));
};  // MockGpioBasic
// GCOVR_EXCL_STOP
#endif  //  __has_include(<gmock/gmock.h>)
};  // namespace rpp_driver

#endif /* PICO_DRIVER_SRC_GPIO_GPIOBASIC_HPP_ */