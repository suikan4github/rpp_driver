#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "adau1361lower.hpp"
#include "i2cmaster.hpp"

class Adau1361LowerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    device_address_ = 31;  // 7bit I2C address
    codec_lower_ = new Adau1361Lower(i2c_, device_address_);
  }

  unsigned int device_address_;  // 7bit I2C address
  MockI2CMaster i2c_;
  Adau1361Lower *codec_lower_;
};

typedef Adau1361LowerTest Adau1361LowerDeathTest;

TEST_F(Adau1361LowerTest, SendCommand) {
  uint8_t cmd[7];

  // nostop parameter must be false. That mean, stop condition of I2C.
  EXPECT_CALL(i2c_,
              i2c_write_blocking(device_address_, cmd, sizeof(cmd), false));
  codec_lower_->SendCommand(cmd, sizeof(cmd));
}

TEST_F(Adau1361LowerTest, SendCommandTable) {
  const uint8_t cmd[][3] = {
      // R0,1, are set by init_freq_xxx table
      {0x40, 0x08, 0x00},  // R2: Digital Mic
      {0x40, 0x09, 0x00},  // R3: Rec Power Management
      {0x40, 0x0a, 0x00}   // R4: Rec Mixer Left 0
  };
  // nostop parameter must be false. That mean, stop condition of I2C.
  using ::testing::InSequence;
  {
    InSequence dummy;

    EXPECT_CALL(i2c_, i2c_write_blocking(device_address_, cmd[0], 3, false));
    EXPECT_CALL(i2c_, i2c_write_blocking(device_address_, cmd[1], 3, false));
    EXPECT_CALL(i2c_, i2c_write_blocking(device_address_, cmd[2], 3, false));
  }
  codec_lower_->SendCommandTable(cmd, sizeof(cmd) / 3);
}

TEST_F(Adau1361LowerTest, IsI2CDeviceExist) {
  uint8_t cmd[7];

  using ::testing::_;
  using ::testing::Return;

  using ::testing::InSequence;
  {
    InSequence dummy;

    // nostop parameter must be false. That mean, stop condition of I2C.
    EXPECT_CALL(i2c_, i2c_write_blocking(device_address_, _, 0, false))
        .WillOnce(Return(PICO_ERROR_GENERIC));
    EXPECT_CALL(i2c_, i2c_write_blocking(device_address_, _, 0, false))
        .WillOnce(Return(3));
  }
  EXPECT_FALSE(codec_lower_->IsI2CDeivceExisting());
  EXPECT_TRUE(codec_lower_->IsI2CDeivceExisting());
}

TEST_F(Adau1361LowerTest, WaitPllLock) {
  const uint8_t lock_status_address[] = {0x40, 0x02};  // R1 : 6 byte register.
  uint8_t status_notlocked[6] = {0, 0, 0, 0, 0, 0};
  uint8_t status_locked[6] = {0, 0, 0, 0, 0, 2};

  using ::testing::Args;
  using ::testing::DoAll;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;
  using ::testing::SetArrayArgument;

  {
    InSequence dummy;

    //  we test unlocked status. Funciton must not return.

    // nostop parameter must be true. That mean repeated start of I2C.
    // The write command give only 2 byte length register address.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(device_address_,  // Arg 0 : I2C Address.
                                   NotNull(),  // Arg 1 : Data buffer address.
                                   2,  // Arg 2 : Data buffer length to send.
                                   true))  // Arg 3 : true to repeated start.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(lock_status_address)))
        .WillOnce(Return(2));  // 2 is the transfered data length

    // nostop parameter must be false. That mean, stop condition of I2C.
    // This will check the status register of ADAU1361A. These status
    // registers must be read 6 byte at once.
    EXPECT_CALL(i2c_,
                i2c_read_blocking(device_address_,  // Arg 0 : I2C Address
                                  NotNull(),  // Arg 1 : Data buffer address
                                  6,          // Arg 2 : Data buffer length
                                  false))     // Arg 3 : fasle to stop I2C.
        .WillOnce(DoAll(
            SetArrayArgument<1>  // parameter position of the array : 0 origin.
            (status_notlocked,   // pointer to the beginning of the data.
             status_notlocked + 6),  // pointer to the end of the data + 1.
            Return(3)));             // 6 is the transfered data length.

    // we test the locked status. The funciton must return.

    // nostop parameter must be true. That mean repeated start of I2C.
    // The write command give only 2 byte length register address.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(device_address_,  // Arg 0 : I2C Address.
                                   NotNull(),  // Arg 1 : Data buffer address.
                                   2,  // Arg 2 : Data buffer length to send.
                                   true))  // Arg 3 : true to repeated start.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(lock_status_address)))
        .WillOnce(Return(2));  // 2 is the transfered data length

    // nostop parameter must be false. That mean, stop condition of I2C.
    // This will check the status register of ADAU1361A. These status
    // registers must be read 6 byte at once.
    EXPECT_CALL(i2c_,
                i2c_read_blocking(device_address_,  // Arg 0 : I2C Address
                                  NotNull(),  // Arg 1 : Data buffer address
                                  6,          // Arg 2 : Data buffer length
                                  false))     // Arg 3 : fasle to stop I2C.
        .WillOnce(DoAll(
            SetArrayArgument<1>   // parameter position of the array : 0 origin.
            (status_locked,       // pointer to the beginning of the data.
             status_locked + 6),  // pointer to the end of the data + 1.
            Return(3)));          // 6 is the transfered data length.
  }

  codec_lower_->WaitPllLock();
}

TEST_F(Adau1361LowerTest, InititializeCore) {
  // Core clock setting
  const uint8_t init_core[] = {
      0x40, 0x00, 0x00};  // R0:Clock control. Core clock disabled. PLL off.

  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;

  //  we test initialization of core.

  EXPECT_CALL(i2c_,
              i2c_write_blocking(device_address_,  // Arg 0 : I2C Address.
                                 NotNull(),  // Arg 1 : Data buffer address.
                                 3,       // Arg 2 : Data buffer length to send.
                                 false))  // Arg 3 : false to stop.
      .With(Args<1,  // parameter position of the array : 0 origin.
                 2>  // parameter position of the size : 0 origin.
            (ElementsAreArray(init_core)));
  codec_lower_->InitializeCore();
}

TEST_F(Adau1361LowerTest, DisablePLL) {
  // PLL Disable.
  // R1 : Must write 6 byte at once.
  const uint8_t disable_pll[] = {0x40, 0x02, 0x00, 0xFD,
                                 0x00, 0x0C, 0x10, 0x00};

  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;

  //  we test initialization of core.

  EXPECT_CALL(i2c_,
              i2c_write_blocking(device_address_,  // Arg 0 : I2C Address.
                                 NotNull(),  // Arg 1 : Data buffer address.
                                 8,       // Arg 2 : Data buffer length to send.
                                 false))  // Arg 3 : false to stop.
      .With(Args<1,  // parameter position of the array : 0 origin.
                 2>  // parameter position of the size : 0 origin.
            (ElementsAreArray(disable_pll)));
  codec_lower_->DisablePLL();
}

// #include <iostream>
static float pll_out(unsigned int mclock, const uint8_t config[]) {
  float x = ((config[6] >> 1) & 0x03) + 1;
  float r = (config[6] >> 3) & 0x0F;
  if (0 == r) r = 8;
  float n = config[4] * 256 + config[5];
  float m = config[2] * 256 + config[3];
  bool fractional = (config[6] & 1) != 0;

  // std::cout << x << "," << r << "," << n << "," << m << std::endl;
  if (fractional)
    return mclock * (1 / x) * (r + n / m);
  else
    return mclock * (1 / x) * r;
}

static bool is_pll_enabled(const uint8_t config[]) {
  // config[7] is the PLL configuration register 5.
  // It must be 1 ( enable PLL ) when setting PLL.
  return (1 == config[7]);
}
// ------------------------------------------------------------
//
//                               48kHz
//
// ------------------------------------------------------------

TEST_F(Adau1361LowerTest, ConfigurePll_48_08000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 8MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 8000000;
    const unsigned int fs = 24000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x7D, 0x00, 0x12, 0x31, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_08000

TEST_F(Adau1361LowerTest, ConfigurePll_48_12000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 12MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 12000000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x7D, 0x00, 0x0C, 0x21, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_12000

TEST_F(Adau1361LowerTest, ConfigurePll_48_13000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 13MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 13000000;
    const unsigned int fs = 32000;
    uint8_t config_pll[] = {0x40, 0x02, 0x06, 0x59, 0x04, 0xF5, 0x19, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_13000

TEST_F(Adau1361LowerTest, ConfigurePll_48_14400) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 14.4MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 14400000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x4B, 0x00, 0x3E, 0x33, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_14400

TEST_F(Adau1361LowerTest, ConfigurePll_48_19200) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.2MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19200000;
    const unsigned int fs = 96000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x19, 0x00, 0x03, 0x2B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }

}  // ConfigurePll_48_19200

TEST_F(Adau1361LowerTest, ConfigurePll_48_19680) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.6MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19680000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0xCD, 0x00, 0xCC, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_19680

TEST_F(Adau1361LowerTest, ConfigurePll_48_19800) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.8MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19800000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x03, 0x39, 0x03, 0x1C, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_19800

TEST_F(Adau1361LowerTest, ConfigurePll_48_24000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 24MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 24000000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x7D, 0x00, 0x0C, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }

}  // ConfigurePll_48_24000

TEST_F(Adau1361LowerTest, ConfigurePll_48_26000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 26MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 26000000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x06, 0x59, 0x04, 0xF5, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_26000

TEST_F(Adau1361LowerTest, ConfigurePll_48_27000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 27000000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x04, 0x65, 0x02, 0xD1, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_27000

TEST_F(Adau1361LowerTest, ConfigurePll_48_12288) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 12288000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x04, 0x65, 0x02, 0xD1, 0x20, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_12288

TEST_F(Adau1361LowerTest, ConfigurePll_48_24576) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_48 = 49152000;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 24576000;
    const unsigned int fs = 48000;
    uint8_t config_pll[] = {0x40, 0x02, 0x04, 0x65, 0x02, 0xD1, 0x10, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_48,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_48_24576

// ------------------------------------------------------------
//
//                               41.1kHz
//
// ------------------------------------------------------------

TEST_F(Adau1361LowerTest, ConfigurePll_441_08000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 8MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 8000000;
    const unsigned int fs = 22050;
    uint8_t config_pll[] = {0x40, 0x02, 0x02, 0x71, 0x01, 0x93, 0x29, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_08000

TEST_F(Adau1361LowerTest, ConfigurePll_441_12000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 12MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 12000000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x02, 0x71, 0x01, 0xDD, 0x19, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_12000

TEST_F(Adau1361LowerTest, ConfigurePll_441_13000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 13MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 13000000;
    const unsigned int fs = 88200;
    uint8_t config_pll[] = {0x40, 0x02, 0x1F, 0xBD, 0x0F, 0x09, 0x19, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_13000

TEST_F(Adau1361LowerTest, ConfigurePll_441_14400) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 14.4MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 14400000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x7D, 0x00, 0x22, 0x33, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_14400

TEST_F(Adau1361LowerTest, ConfigurePll_441_19200) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.2MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19200000;
    const unsigned int fs = 88200;
    uint8_t config_pll[] = {0x40, 0x02, 0x00, 0x7D, 0x00, 0x58, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }

}  // ConfigurePll_441_19200

TEST_F(Adau1361LowerTest, ConfigurePll_441_19680) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.6MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19680000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x04, 0x01, 0x02, 0x5C, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_19680

TEST_F(Adau1361LowerTest, ConfigurePll_441_19800) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 19.8MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 19800000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x05, 0x5F, 0x03, 0x04, 0x23, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_19800

TEST_F(Adau1361LowerTest, ConfigurePll_441_24000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 24MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 24000000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x02, 0x71, 0x01, 0xDD, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }

}  // ConfigurePll_441_24000

TEST_F(Adau1361LowerTest, ConfigurePll_441_26000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 26MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 26000000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x1F, 0xBD, 0x0F, 0x09, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_26000

TEST_F(Adau1361LowerTest, ConfigurePll_441_27000) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 27000000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x07, 0x53, 0x02, 0x87, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_27000

TEST_F(Adau1361LowerTest, ConfigurePll_441_12288) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 12288000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x03, 0xE8, 0x02, 0xA3, 0x19, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_12288

TEST_F(Adau1361LowerTest, ConfigurePll_441_24576) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::NotNull;
  const unsigned int target_pll_freq_441 = 45158400;  // Hz. See data sheet.
  const float acceptable_error = 5;  // Hz. Error of the PLL out.

  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 24576000;
    const unsigned int fs = 44100;
    uint8_t config_pll[] = {0x40, 0x02, 0x03, 0xE8, 0x02, 0xA3, 0x1B, 0x01};
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,     // Arg 0 : I2C Address.
                    NotNull(),           // Arg 1 : Data buffer address.
                    sizeof(config_pll),  // Arg 2 : Data buffer length to send.
                    false))              // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(config_pll)));
    // check the frequency error of the PLL
    EXPECT_NEAR(pll_out(mclock, config_pll), target_pll_freq_441,
                acceptable_error);
    // check whether PLL is enabled or not.
    EXPECT_TRUE(is_pll_enabled(config_pll));
    codec_lower_->ConfigurePll(fs, mclock);
  }
}  // ConfigurePll_441_24576

// Validation test for wrong master clock at fs 48kHz.
TEST_F(Adau1361LowerDeathTest, ConfigurePll_48_wrong_master_clock) {
  {
    const unsigned int mclock = 123;
    const unsigned int fs = 48000;
    // check the assertion for bad mclock.
    ASSERT_DEATH(codec_lower_->ConfigurePll(fs, mclock),
                 "Wrong Master Clock with Fs 48kHz Series");
  }
}  // ConfigurePll_48_wrong_master_clock

// Validation test for wrong master clock at fs 44.1kHz.
TEST_F(Adau1361LowerDeathTest, ConfigurePll_441_wrong_master_clock) {
  {
    const unsigned int mclock = 123;
    const unsigned int fs = 44100;
    ASSERT_DEATH(codec_lower_->ConfigurePll(fs, mclock),
                 "Wrong Master Clock with Fs 44.1kHz Series");
  }
}  // ConfigurePll_441_wrong_master_clock

// Validation test for wrong fs .
TEST_F(Adau1361LowerDeathTest, ConfigurePll_wrong_fs) {
  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int mclock = 8000000;
    const unsigned int fs = 192000;
    // check the assertion for bad mclock.
    ASSERT_DEATH(codec_lower_->ConfigurePll(fs, mclock), "Bad Fs");
  }
}  // ConfigurePll_wrong_fs

// -----------------------------------------------------------------
//
//                          SetLineInputGain()
//
// -----------------------------------------------------------------

// Mute test
TEST_F(Adau1361LowerTest, SetLineInputGain_mute) {
  using ::testing::Args;
  using ::testing::DoAll;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;
  using ::testing::SetArrayArgument;

  // Left check
  {
    InSequence dummy;
    // First two bytes are register number.
    // in the case of mute, bit3:1 are zero.
    uint8_t ltxbuf1[3] = {0x40, 0x0a, 0x01};

    // Expectation of mute
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // First two bytes are register number.
    // in the case of mute, bit3:1 are zero.
    uint8_t rtxbuf1[3] = {0x40, 0x0c, 0x01};

    // Expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to muted.
  codec_lower_->SetLineInputGain(0.0, 0.0, true);
}  // SetLineInputGain_mute

// The gain over 6dB must be truncated to 6dB.
TEST_F(Adau1361LowerTest, SetLineInputGain_overgain) {
  using ::testing::Args;
  using ::testing::DoAll;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;
  using ::testing::SetArrayArgument;

  // Left check
  {
    InSequence dummy;

    uint8_t ltxbuf1[3] = {0x40, 0x0a,
                          0x0f};  // in the case of gain=6dB, bit 3:1 are 111.

    //  expectation of gain setting.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0c,
                          0x0f};  // in the case of gain=6dB, bit 3:1 are 111

    //  expectation of gain setting.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 6dB
  codec_lower_->SetLineInputGain(20.0, 30.0, false);
}  // SetLineInputGain_overgain

// The gain under -12dB must be truncated to -12dB
TEST_F(Adau1361LowerTest, SetLineInputGain_undergain) {
  using ::testing::Args;
  using ::testing::DoAll;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;
  using ::testing::SetArrayArgument;

  // Left check
  {
    InSequence dummy;

    uint8_t ltxbuf1[3] = {0x40, 0x0a,
                          0x03};  // in the case of gain=-12dB, bit 3:1 are 001
    // Set the address to read.

    //  expectation of -12dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0c,
                          0x03};  // in the case of gain=-12dB, bit 3:1 are 001

    //  expectation of -12dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to -12dB
  codec_lower_->SetLineInputGain(-20.0, -30.0, false);
}  // SetLineInputGain_undergain

// The gain between [-12dB, 6dB] must be truncated to 3dB steps.
TEST_F(Adau1361LowerTest, SetLineInputGain_appropriate_gain) {
  using ::testing::Args;
  using ::testing::DoAll;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;
  using ::testing::SetArrayArgument;

  // Left check
  {
    InSequence dummy;

    uint8_t ltxbuf1[3] = {0x40, 0x0a,
                          0x0B};  // in the case of gain=0dB, bit 3:1 are 101

    // expectation of appropriate gain.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0c,
                          0x09};  // in the case of gain=-3dB, bit 3:1 are 100
    // Set the address to read.

    // expectation of appropriate gain.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 0dB and -3dB.
  codec_lower_->SetLineInputGain(1, -1, false);
}  // SetLineInputGain_appropriate_gain

// -----------------------------------------------------------------
//
//                          SetLineOutputGain()
//
// -----------------------------------------------------------------

// Mute test
TEST_F(Adau1361LowerTest, SetLineOutputGain_mute) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x25, 0xff};  // R31

    //  expectation of mute.
    ltxbuf1[2] = (0x39 << 2) | 0x00;  // given 0dB, mute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x26, 0xff};  // L31

    //  expectation of mute.
    rtxbuf1[2] = (0x39 << 2) | 0x00;  // given 0dB, mute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to muted.
  codec_lower_->SetLineOutputGain(0.0, 0.0, true);
}  // SetLineOutputGain_mute

// Overgain test : must be truncated to 6dB
TEST_F(Adau1361LowerTest, SetLineOutputGain_overgain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x25, 0xff};  // R31

    //  expectation of mute.
    ltxbuf1[2] = (0x3F << 2) | 0x02;  // 6dB is 111111, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x26, 0xff};  // L31

    //  expectation of mute.
    rtxbuf1[2] = (0x3F << 2) | 0x02;  // 6dB is 1111, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 6dB, not muted.
  codec_lower_->SetLineOutputGain(12.0, 18.0, false);
}  // SetLineOutputGain_overgain

// Overgain test : The gain under -57dB must be truncated to -57dB
TEST_F(Adau1361LowerTest, SetLineOutputGain_undergain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x25, 0xff};  // R31

    //  expectation of mute.
    ltxbuf1[2] = (0x00 << 2) | 0x02;  // -57dB is 0000, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x26, 0xff};  // L31

    //  expectation of mute.
    rtxbuf1[2] = (0x00 << 2) | 0x02;  // -57dB is 0000, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 57dB, not muted.
  codec_lower_->SetLineOutputGain(-60.0, -70.0, false);
}  // SetLineOutputGain_undergain

// The gain between [-57dB, 6dB] must be truncated to 1dB steps.
// Overgain test : The gain under -57dB must be truncated to -57dB
TEST_F(Adau1361LowerTest, SetLineOutputGain_appropriate_gain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x25, 0xff};  // R31

    //  expectation of mute.
    ltxbuf1[2] = (0x3b << 2) | 0x02;  // 2dB is 110011, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x26, 0xff};  // L31

    //  expectation of mute.
    rtxbuf1[2] = (0x34 << 2) | 0x02;  // -57dB is 000000, unmute, line
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to 2.0 and -5.0dB, not muted.
  codec_lower_->SetLineOutputGain(2.0, -5.0, false);
}  // SetLineOutputGain_appropriate_gain

// -----------------------------------------------------------------
//
//                          SetAuxInputGain()
//
// -----------------------------------------------------------------

// Mute test
TEST_F(Adau1361LowerTest, SetAuxInputGain_mute) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x0b, 0x00};  // R5 : 0 if muted.

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0d, 0x00};  // R7 : 0 if muted.

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to muted.
  codec_lower_->SetAuxInputGain(0.0, 0.0, true);
}  // SetAuxInputGain_mute

// Overgain test : must be truncated to 6dB
TEST_F(Adau1361LowerTest, SetAuxInputGain_overgain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x0b, 0x07};  // R5 : 111 if 6dB.

    //  expectation of 6db.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0d, 0x07};  // R7 : 111 if 6dB.

    //  expectation of 6db.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 6dB, not muted.
  codec_lower_->SetAuxInputGain(12.0, 18.0, false);
}  // SetAuxInputGain_overgain

// Overgain test : The gain under -12dB must be truncated to -12dB
TEST_F(Adau1361LowerTest, SetAuxInputGain_undergain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x0b, 0x01};  // R5 : 001 if -12dB.

    //  expectation of -12dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0d, 0x01};  // R7 : 001 if -12dB.

    //  expectation of -12dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 57dB, not muted.
  codec_lower_->SetAuxInputGain(-60.0, -70.0, false);
}  // SetAuxInputGain_undergain

// The gain between [-12dB, 6dB] must be truncated to 3dB steps.
TEST_F(Adau1361LowerTest, SetAuxInputGain_appropriate_gain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x0b, 0x05};  // R5 : 101 if 0dB.

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x0d, 0x03};  // R7 : 011 if -6dB.

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to 0.0 and -6.0dB, not muted.
  codec_lower_->SetAuxInputGain(2.0, -5.0, false);
}  // SetAuxInputGain_appropriate_gain

// -----------------------------------------------------------------
//
//                          SetHpOutputGain()
//
// -----------------------------------------------------------------

// Mute test
TEST_F(Adau1361LowerTest, SetHpOutputGain_mute) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x23,
                          0xe5};  // R29 : 11001,0,1 ( muted, headphone)

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x24,
                          0xe5};  // R30 : 11001,0,1 ( muted, headphone)

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to muted.
  codec_lower_->SetHpOutputGain(0.0, 0.0, true);
}  // SetHpOutputGain_mute

// Overgain test : must be truncated to 6dB
TEST_F(Adau1361LowerTest, SetHpOutputGain_overgain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x23,
                          0xff};  // R29 : 6dB is 111111, unmute, line

    //  expectation of 6dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x24, 0xff};  // R30 : 6dB is 1111, unmute, line

    //  expectation of 6dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 6dB, not muted.
  codec_lower_->SetHpOutputGain(12.0, 18.0, false);
}  // SetHpOutputGain_overgain

// Overgain test : The gain under -57dB must be truncated to -57dB
TEST_F(Adau1361LowerTest, SetHpOutputGain_undergain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x23,
                          0x03};  // R29 : -57dB is 0000, unmute, line

    //  expectation of -57.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x24,
                          0x03};  // R30 :  -57dB is 0000, unmute, line

    //  expectation of -57dB.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be truncated to 57dB, not muted.
  codec_lower_->SetHpOutputGain(-60.0, -70.0, false);
}  // SetHpOutputGain_undergain

// The gain between [-57dB, 6dB] must be truncated to 1dB steps.
// Overgain test : The gain under -57dB must be truncated to -57dB
TEST_F(Adau1361LowerTest, SetHpOutputGain_appropriate_gain) {
  using ::testing::Args;
  using ::testing::ElementsAreArray;
  using ::testing::InSequence;
  using ::testing::NotNull;
  using ::testing::Return;

  {
    InSequence dummy;

    // Left check
    uint8_t ltxbuf1[3] = {0x40, 0x23,
                          0xef};  // R29 : 2dB is 111011, unmute, line

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(ltxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(ltxbuf1)))
        .WillOnce(Return(sizeof(ltxbuf1)));

    // right check
    uint8_t rtxbuf1[3] = {0x40, 0x24,
                          0xd3};  // R30 : -5dB is 110100, unmute, line

    //  expectation of mute.
    EXPECT_CALL(i2c_,
                i2c_write_blocking(
                    device_address_,  // Arg 0 : I2C Address.
                    NotNull(),        // Arg 1 : Data buffer address.
                    sizeof(rtxbuf1),  // Arg 2 : Data buffer length to send.
                    false))           // Arg 3 : false to stop.
        .With(Args<1,  // parameter position of the array : 0 origin.
                   2>  // parameter position of the size : 0 origin.
              (ElementsAreArray(rtxbuf1)))
        .WillOnce(Return(sizeof(rtxbuf1)));
  }

  // must be set to 2.0 and -5.0dB, not muted.
  codec_lower_->SetHpOutputGain(2.0, -5.0, false);
}  // SetHpOutputGain_appropriate_gain

// -----------------------------------------------------------------
//
//                          SetAuxInputGain()
//
// -----------------------------------------------------------------

// Validation test for wrong master clock at fs 48kHz.
TEST_F(Adau1361LowerDeathTest, ConfigureSRC_wrong_fs) {
  // Test 27MHz master clock for Fs 48kHz series.
  {
    const unsigned int fs = 192000;
    // check the assertion for bad mclock.
    ASSERT_DEATH(codec_lower_->ConfigureSRC(fs), "Bad Fs");
  }
}  // ConfigurePll_48_wrong_master_clock
