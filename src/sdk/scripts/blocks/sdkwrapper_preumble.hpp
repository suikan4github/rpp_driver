#ifndef PICO_DRIVER_SRC_SDK_SDKWRAPPER_HPP_
#define PICO_DRIVER_SRC_SDK_SDKWRAPPER_HPP_

#if __has_include("pico/stdlib.h")
// For Pico
#include "pico/stdlib.h"
#include "pico_sdk_headers.h"

#else
// Alternative include and definition for Unix/Win32
#include <stdint.h>
#include <stdlib.h>

#include "pico_api_alternate_defs.hpp"
#ifdef _MSC_VER
typedef unsigned int uint;
#endif
#endif

#if __has_include(<gmock/gmock.h>)
#include <gmock/gmock.h>
#endif

/**
 * @brief Collection of the RP2040/RP2350 control.
 *
 */
namespace rpp_driver {
/**
 * @brief Wrapper class for the RasPi Pico SDK functions.
 * @details
 * The member function declaration follow the SDK APIs. Also, the doxygen
 * comments are copied from the RasPi Pico SDK source code.
 *
 * This wrapper class is convenient for the dependency injection to allow
 * the unit test.
 *
 * The mock of this class is declared in the same file with this class.
 */
class SdkWrapper {
 public:
  virtual ~SdkWrapper() {}