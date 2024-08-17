#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "i2cmaster.hpp"

using testing::Return;

TEST(I2CMaster, i2c_read_blocking) {
  MockPicoWrapper sdk;
  i2c_inst_t i2c_inst;

  uint8_t addr = 3;
  uint8_t buf[5];
  bool nostop = true;
  int return_value = 11;

  I2CMaster i2c(i2c_inst, sdk);

  EXPECT_CALL(sdk, i2c_read_blocking(&i2c_inst, addr, buf, sizeof(buf), nostop))
      .WillOnce(Return(return_value));

  EXPECT_CALL(sdk,
              i2c_read_blocking(&i2c_inst, addr, buf, sizeof(buf), !nostop))
      .WillOnce(Return(return_value));

  EXPECT_EQ(i2c.i2c_read_blocking(addr, buf, sizeof(buf), nostop),
            return_value);
  EXPECT_EQ(i2c.i2c_read_blocking(addr, buf, sizeof(buf), !nostop),
            return_value);
}

TEST(I2CMaster, i2c_write_blocking) {
  MockPicoWrapper sdk;
  i2c_inst_t i2c_inst;

  uint8_t addr = 3;
  uint8_t buf[5];
  bool nostop = true;
  int return_value = 11;

  I2CMaster i2c(i2c_inst, sdk);

  EXPECT_CALL(sdk,
              i2c_write_blocking(&i2c_inst, addr, buf, sizeof(buf), nostop))
      .WillOnce(Return(return_value));
  EXPECT_CALL(sdk,
              i2c_write_blocking(&i2c_inst, addr, buf, sizeof(buf), !nostop))
      .WillOnce(Return(return_value));

  EXPECT_EQ(i2c.i2c_write_blocking(addr, buf, sizeof(buf), nostop),
            return_value);
  EXPECT_EQ(i2c.i2c_write_blocking(addr, buf, sizeof(buf), !nostop),
            return_value);
}