/**
 * @file i2cmasterinterface.hpp
 *
 * @date 2024/Aug/16
 * @author: Seiichi  Horie
 * @brief I2C master Interface.
 */

#ifndef _I2CMASTERINTERFACE_HPP_
#define _I2CMASTERINTERFACE_HPP_

#include <stdint.h>
#include <stdlib.h>
#ifdef GTEST_BUILD  // If not build for GTest, include followings.
typedef unsigned uint;
#endif

class I2CMasterInterface {
 public:
  virtual ~I2CMasterInterface() {}
  /**
   * @brief Attempt to read specified number of bytes from address, blocking.
   * @param addr 7-bit address of device to read from
   * @param dst Pointer to buffer to receive data
   * @param len Length of data in bytes to receive
   * @param nostop If true, master retains control of the bus at the end of
   * the transfer (no Stop is issued), and the next transfer will begin with
   * a Restart rather than a Start.
   * @returns Number of bytes read, or PICO_ERROR_GENERIC if address
   * not acknowledged or no device present.
   */

  virtual int i2c_read_blocking(uint8_t addr, uint8_t *dst, size_t len,
                                bool nostop) = 0;
  /**
   * @brief Attempt to write specified number of bytes to address, blocking.
   * @param addr 7-bit address of device to write to
   * @param src Pointer to data to send
   * @param len Length of data in bytes to send
   * @param nostop If true, master retains control of the bus at the end of
   * the transfer (no Stop is issued), and the next transfer will begin with
   * a Restart rather than a Start.
   * @returns Number of bytes written, or PICO_ERROR_GENERIC
   * if address not acknowledged, no device present.
   */
  virtual int i2c_write_blocking(uint8_t addr, const uint8_t *src, size_t len,
                                 bool nostop) = 0;
};

#endif /* _I2CMASTERINTERFACE_HPP_ */