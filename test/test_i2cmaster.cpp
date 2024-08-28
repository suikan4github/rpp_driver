#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "i2cmaster.hpp"

using testing::Return;

// Constructor test
TEST(I2CMaster, Constructor) {
  ::pico_driver::MockSDKWrapper sdk;
  i2c_inst_t i2c_inst;

  uint freq = 100 * 1000;
  uint sda_pin = 17;
  uint scl_pin = 18;

  using ::testing::_;

  EXPECT_CALL(sdk, i2c_init(&i2c_inst, freq));
  EXPECT_CALL(sdk, gpio_set_function(scl_pin, GPIO_FUNC_I2C));
  EXPECT_CALL(sdk, gpio_set_function(sda_pin, GPIO_FUNC_I2C));
  EXPECT_CALL(sdk, gpio_pull_up(scl_pin));
  EXPECT_CALL(sdk, gpio_pull_up(sda_pin));

  ::pico_driver::I2CMaster i2c(sdk, i2c_inst, freq, scl_pin, sda_pin);
  // We can ignore these call inside destructor
  EXPECT_CALL(sdk, i2c_deinit(_));

}  // Constructor

// Destructor test
TEST(I2CMaster, Destructor) {
  ::pico_driver::MockSDKWrapper sdk;
  i2c_inst_t i2c_inst;

  uint freq = 100 * 1000;
  uint sda_pin = 17;
  uint scl_pin = 18;

  using ::testing::_;

  // We can ignore these call inside constructor
  EXPECT_CALL(sdk, i2c_init(_, _));
  EXPECT_CALL(sdk, gpio_set_function(_, _)).Times(2);
  EXPECT_CALL(sdk, gpio_pull_up(_)).Times(2);
  ::pico_driver::I2CMaster i2c(sdk, i2c_inst, freq, scl_pin, sda_pin);

  EXPECT_CALL(sdk, i2c_deinit(&i2c_inst));

}  // Destructor

TEST(I2CMaster, ReadBlocking) {
  ::pico_driver::MockSDKWrapper sdk;
  i2c_inst_t i2c_inst;

  uint8_t addr = 3;
  uint8_t buf[5];
  bool nostop = true;
  int return_value = 11;

  using ::testing::_;

  // We can ignore these call inside constructor
  EXPECT_CALL(sdk, i2c_init(_, _));
  EXPECT_CALL(sdk, gpio_set_function(_, _)).Times(2);
  EXPECT_CALL(sdk, gpio_pull_up(_)).Times(2);
  ::pico_driver::I2CMaster i2c(sdk, i2c_inst, 100 * 1000, 17, 23);

  EXPECT_CALL(sdk, i2c_read_blocking(&i2c_inst, addr, buf, sizeof(buf), nostop))
      .WillOnce(Return(return_value));

  EXPECT_CALL(sdk,
              i2c_read_blocking(&i2c_inst, addr, buf, sizeof(buf), !nostop))
      .WillOnce(Return(return_value));

  EXPECT_EQ(i2c.ReadBlocking(addr, buf, sizeof(buf), nostop), return_value);
  EXPECT_EQ(i2c.ReadBlocking(addr, buf, sizeof(buf), !nostop), return_value);
  // We can ignore these call inside destructor
  EXPECT_CALL(sdk, i2c_deinit(_));
}  // ReadBlocking

TEST(I2CMaster, WriteBlocking) {
  ::pico_driver::MockSDKWrapper sdk;
  i2c_inst_t i2c_inst;

  uint8_t addr = 3;
  uint8_t buf[5];
  bool nostop = true;
  int return_value = 11;

  using ::testing::_;

  // We can ignore these call inside constructor
  EXPECT_CALL(sdk, i2c_init(_, _));
  EXPECT_CALL(sdk, gpio_set_function(_, _)).Times(2);
  EXPECT_CALL(sdk, gpio_pull_up(_)).Times(2);
  ::pico_driver::I2CMaster i2c(sdk, i2c_inst, 100 * 1000, 17, 23);

  EXPECT_CALL(sdk,
              i2c_write_blocking(&i2c_inst, addr, buf, sizeof(buf), nostop))
      .WillOnce(Return(return_value));
  EXPECT_CALL(sdk,
              i2c_write_blocking(&i2c_inst, addr, buf, sizeof(buf), !nostop))
      .WillOnce(Return(return_value));

  EXPECT_EQ(i2c.WriteBlocking(addr, buf, sizeof(buf), nostop), return_value);
  EXPECT_EQ(i2c.WriteBlocking(addr, buf, sizeof(buf), !nostop), return_value);
  // We can ignore these call inside destructor
  EXPECT_CALL(sdk, i2c_deinit(_));
}  // WriteBlocking

TEST(I2CMaster, IsDeviceExisting) {
  ::pico_driver::MockSDKWrapper sdk;
  i2c_inst_t i2c_inst;

  uint8_t addr[] = {17, 23};
  bool nostop = false;
  int return_value[] = {-1, 1};

  using ::testing::_;

  // We can ignore these call inside constructor
  EXPECT_CALL(sdk, i2c_init(_, _));
  EXPECT_CALL(sdk, gpio_set_function(_, _)).Times(2);
  EXPECT_CALL(sdk, gpio_pull_up(_)).Times(2);
  ::pico_driver::I2CMaster i2c(sdk, i2c_inst, 100 * 1000, 17, 23);

  EXPECT_CALL(sdk, i2c_read_blocking(_, addr[0], _, 1, nostop))
      .WillOnce(Return(return_value[0]));

  EXPECT_CALL(sdk, i2c_read_blocking(_, addr[1], _, 1, nostop))
      .WillOnce(Return(return_value[1]));

  EXPECT_FALSE(i2c.IsDeviceExisting(addr[0]));
  EXPECT_TRUE(i2c.IsDeviceExisting(addr[1]));

  // We can ignore these call inside destructor
  EXPECT_CALL(sdk, i2c_deinit(_));
}
