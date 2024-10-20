/*
 * Definition of the Pico SDK API Stub.
 *
 * Stubs in this file is weakly bounded. So, if the hardware_xxx or
 * the pico_xxx library is not linked in the application, the stub
 * function in this file will be linked.
 *
 * There are two purposes.
 *
 * The first one to allow programmer not to link the unused library.
 * For example, assume a program which doesn't use hardware_i2c lib.
 * While program doesn't use the API inside this library, the
 * rpp_driver::SdkWrapper class needs the API. On the other hand,
 * linking all library of Pico SDK just suppress the error message is
 * nonsense. So, linking stub is the solution for this problem.
 *
 * The second purpose is warning for the unlinked API. Assume a
 * program which doesn't link the hardware_i2c while it is used.
 * In this case, there is no link error because the weakly bounded
 * stub API function is linked. To let the programmer know, the
 * stub function output the error message to the serial port.
 */
#include <stdint.h>
#include <stdlib.h>

// For arn-eabi-gcc and MSVC
#if __has_include("pico/stdlib.h") || defined(_MSC_VER)
typedef unsigned int uint;
#endif

#include <assert.h>
// Alternate API definitions for the Pico stub.
// To avoid the redefinition error, The pico header must not be included.
#include "pico_api_alternate_defs.hpp"

#ifdef _MSC_VER
// Suppress the C4716 error allowing not to return any value in function.
#pragma warning(disable : 4716)
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void i2c_deinit(i2c_inst_t* i2c);
__attribute__((weak)) void i2c_deinit(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_i2c_deinit(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_i2c_deinit=__weak_i2c_deinit")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:i2c_deinit=_weak_i2c_deinit")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint i2c_get_dreq(i2c_inst_t* i2c, bool is_tx);
__attribute__((weak)) uint i2c_get_dreq(i2c_inst_t* i2c, bool is_tx)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_i2c_get_dreq(i2c_inst_t* i2c, bool is_tx)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_i2c_get_dreq=__weak_i2c_get_dreq")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:i2c_get_dreq=_weak_i2c_get_dreq")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" i2c_hw_t* i2c_get_hw(i2c_inst_t* i2c);
__attribute__((weak)) i2c_hw_t* i2c_get_hw(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" i2c_hw_t* _weak_i2c_get_hw(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_i2c_get_hw=__weak_i2c_get_hw")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:i2c_get_hw=_weak_i2c_get_hw")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint i2c_get_index(i2c_inst_t* i2c);
__attribute__((weak)) uint i2c_get_index(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_i2c_get_index(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_i2c_get_index=__weak_i2c_get_index")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:i2c_get_index=_weak_i2c_get_index")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" i2c_inst_t* i2c_get_instance(uint num);
__attribute__((weak)) i2c_inst_t* i2c_get_instance(uint num)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" i2c_inst_t* _weak_i2c_get_instance(uint num)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_i2c_get_instance=__weak_i2c_get_instance")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_get_instance=_weak_i2c_get_instance")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" size_t i2c_get_read_available(i2c_inst_t* i2c);
__attribute__((weak)) size_t i2c_get_read_available(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" size_t _weak_i2c_get_read_available(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_get_read_available=__weak_i2c_get_read_available")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_get_read_available=_weak_i2c_get_read_available")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" size_t i2c_get_write_available(i2c_inst_t* i2c);
__attribute__((weak)) size_t i2c_get_write_available(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" size_t _weak_i2c_get_write_available(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_get_write_available=__weak_i2c_get_write_available")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_get_write_available=_weak_i2c_get_write_available")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint i2c_init(i2c_inst_t* i2c, uint baudrate);
__attribute__((weak)) uint i2c_init(i2c_inst_t* i2c, uint baudrate)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_i2c_init(i2c_inst_t* i2c, uint baudrate)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_i2c_init=__weak_i2c_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:i2c_init=_weak_i2c_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_read_blocking(i2c_inst_t* i2c, uint8_t addr, uint8_t* dst,
                                 size_t len, bool nostop);
__attribute__((weak)) int i2c_read_blocking(i2c_inst_t* i2c, uint8_t addr,
                                            uint8_t* dst, size_t len,
                                            bool nostop)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_read_blocking(i2c_inst_t* i2c, uint8_t addr,
                                       uint8_t* dst, size_t len, bool nostop)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_i2c_read_blocking=__weak_i2c_read_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_read_blocking=_weak_i2c_read_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_read_blocking_until(i2c_inst_t* i2c, uint8_t addr,
                                       uint8_t* dst, size_t len, bool nostop,
                                       absolute_time_t until);
__attribute__((weak)) int i2c_read_blocking_until(i2c_inst_t* i2c, uint8_t addr,
                                                  uint8_t* dst, size_t len,
                                                  bool nostop,
                                                  absolute_time_t until)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_read_blocking_until(i2c_inst_t* i2c, uint8_t addr,
                                             uint8_t* dst, size_t len,
                                             bool nostop, absolute_time_t until)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_read_blocking_until=__weak_i2c_read_blocking_until")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_read_blocking_until=_weak_i2c_read_blocking_until")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint8_t i2c_read_byte_raw(i2c_inst_t* i2c);
__attribute__((weak)) uint8_t i2c_read_byte_raw(i2c_inst_t* i2c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint8_t _weak_i2c_read_byte_raw(i2c_inst_t* i2c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_i2c_read_byte_raw=__weak_i2c_read_byte_raw")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_read_byte_raw=_weak_i2c_read_byte_raw")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void i2c_read_raw_blocking(i2c_inst_t* i2c, uint8_t* dst,
                                      size_t len);
__attribute__((weak)) void i2c_read_raw_blocking(i2c_inst_t* i2c, uint8_t* dst,
                                                 size_t len)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_i2c_read_raw_blocking(i2c_inst_t* i2c, uint8_t* dst,
                                            size_t len)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_read_raw_blocking=__weak_i2c_read_raw_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_read_raw_blocking=_weak_i2c_read_raw_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_read_timeout_per_char_us(i2c_inst_t* i2c, uint8_t addr,
                                            uint8_t* dst, size_t len,
                                            bool nostop,
                                            uint timeout_per_char_us);
__attribute__((weak)) int i2c_read_timeout_per_char_us(i2c_inst_t* i2c,
                                                       uint8_t addr,
                                                       uint8_t* dst, size_t len,
                                                       bool nostop,
                                                       uint timeout_per_char_us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_read_timeout_per_char_us(i2c_inst_t* i2c, uint8_t addr,
                                                  uint8_t* dst, size_t len,
                                                  bool nostop,
                                                  uint timeout_per_char_us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_read_timeout_per_char_us=__weak_i2c_read_timeout_per_char_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_read_timeout_per_char_us=_weak_i2c_read_timeout_per_char_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_read_timeout_us(i2c_inst_t* i2c, uint8_t addr, uint8_t* dst,
                                   size_t len, bool nostop, uint timeout_us);
__attribute__((weak)) int i2c_read_timeout_us(i2c_inst_t* i2c, uint8_t addr,
                                              uint8_t* dst, size_t len,
                                              bool nostop, uint timeout_us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_read_timeout_us(i2c_inst_t* i2c, uint8_t addr,
                                         uint8_t* dst, size_t len, bool nostop,
                                         uint timeout_us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_i2c_read_timeout_us=__weak_i2c_read_timeout_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:i2c_read_timeout_us=_weak_i2c_read_timeout_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint i2c_set_baudrate(i2c_inst_t* i2c, uint baudrate);
__attribute__((weak)) uint i2c_set_baudrate(i2c_inst_t* i2c, uint baudrate)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_i2c_set_baudrate(i2c_inst_t* i2c, uint baudrate)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_i2c_set_baudrate=__weak_i2c_set_baudrate")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_set_baudrate=_weak_i2c_set_baudrate")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void i2c_set_slave_mode(i2c_inst_t* i2c, bool slave, uint8_t addr);
__attribute__((weak)) void i2c_set_slave_mode(i2c_inst_t* i2c, bool slave,
                                              uint8_t addr)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_i2c_set_slave_mode(i2c_inst_t* i2c, bool slave,
                                         uint8_t addr)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_i2c_set_slave_mode=__weak_i2c_set_slave_mode")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_set_slave_mode=_weak_i2c_set_slave_mode")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_write_blocking(i2c_inst_t* i2c, uint8_t addr,
                                  const uint8_t* src, size_t len, bool nostop);
__attribute__((weak)) int i2c_write_blocking(i2c_inst_t* i2c, uint8_t addr,
                                             const uint8_t* src, size_t len,
                                             bool nostop)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_write_blocking(i2c_inst_t* i2c, uint8_t addr,
                                        const uint8_t* src, size_t len,
                                        bool nostop)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_i2c_write_blocking=__weak_i2c_write_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_write_blocking=_weak_i2c_write_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_write_blocking_until(i2c_inst_t* i2c, uint8_t addr,
                                        const uint8_t* src, size_t len,
                                        bool nostop, absolute_time_t until);
__attribute__((weak)) int i2c_write_blocking_until(i2c_inst_t* i2c,
                                                   uint8_t addr,
                                                   const uint8_t* src,
                                                   size_t len, bool nostop,
                                                   absolute_time_t until)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_write_blocking_until(i2c_inst_t* i2c, uint8_t addr,
                                              const uint8_t* src, size_t len,
                                              bool nostop,
                                              absolute_time_t until)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_write_blocking_until=__weak_i2c_write_blocking_until")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_write_blocking_until=_weak_i2c_write_blocking_until")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void i2c_write_byte_raw(i2c_inst_t* i2c, uint8_t value);
__attribute__((weak)) void i2c_write_byte_raw(i2c_inst_t* i2c, uint8_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_i2c_write_byte_raw(i2c_inst_t* i2c, uint8_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_i2c_write_byte_raw=__weak_i2c_write_byte_raw")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:i2c_write_byte_raw=_weak_i2c_write_byte_raw")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void i2c_write_raw_blocking(i2c_inst_t* i2c, const uint8_t* src,
                                       size_t len);
__attribute__((weak)) void i2c_write_raw_blocking(i2c_inst_t* i2c,
                                                  const uint8_t* src,
                                                  size_t len)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_i2c_write_raw_blocking(i2c_inst_t* i2c,
                                             const uint8_t* src, size_t len)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_write_raw_blocking=__weak_i2c_write_raw_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_write_raw_blocking=_weak_i2c_write_raw_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_write_timeout_per_char_us(i2c_inst_t* i2c, uint8_t addr,
                                             const uint8_t* src, size_t len,
                                             bool nostop,
                                             uint timeout_per_char_us);
__attribute__((weak)) int i2c_write_timeout_per_char_us(
    i2c_inst_t* i2c, uint8_t addr, const uint8_t* src, size_t len, bool nostop,
    uint timeout_per_char_us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_write_timeout_per_char_us(i2c_inst_t* i2c,
                                                   uint8_t addr,
                                                   const uint8_t* src,
                                                   size_t len, bool nostop,
                                                   uint timeout_per_char_us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_write_timeout_per_char_us=__weak_i2c_write_timeout_per_char_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:i2c_write_timeout_per_char_us=_weak_i2c_write_timeout_per_char_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int i2c_write_timeout_us(i2c_inst_t* i2c, uint8_t addr,
                                    const uint8_t* src, size_t len, bool nostop,
                                    uint timeout_us);
__attribute__((weak)) int i2c_write_timeout_us(i2c_inst_t* i2c, uint8_t addr,
                                               const uint8_t* src, size_t len,
                                               bool nostop, uint timeout_us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_i2c_write_timeout_us(i2c_inst_t* i2c, uint8_t addr,
                                          const uint8_t* src, size_t len,
                                          bool nostop, uint timeout_us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_i2c library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_i2c_write_timeout_us=__weak_i2c_write_timeout_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:i2c_write_timeout_us=_weak_i2c_write_timeout_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_add_program(PIO pio, const pio_program_t* program);
__attribute__((weak)) int pio_add_program(PIO pio, const pio_program_t* program)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_add_program(PIO pio, const pio_program_t* program)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_add_program=__weak_pio_add_program")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_add_program=_weak_pio_add_program")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_add_program_at_offset(PIO pio, const pio_program_t* program,
                                         uint offset);
__attribute__((weak)) int pio_add_program_at_offset(
    PIO pio, const pio_program_t* program, uint offset)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_add_program_at_offset(PIO pio,
                                               const pio_program_t* program,
                                               uint offset)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_add_program_at_offset=__weak_pio_add_program_at_offset")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_add_program_at_offset=_weak_pio_add_program_at_offset")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_calculate_clkdiv_from_float(float div, uint16_t* div_int,
                                                uint8_t* div_frac);
__attribute__((weak)) void pio_calculate_clkdiv_from_float(float div,
                                                           uint16_t* div_int,
                                                           uint8_t* div_frac)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_calculate_clkdiv_from_float(float div,
                                                      uint16_t* div_int,
                                                      uint8_t* div_frac)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_calculate_clkdiv_from_float=__weak_pio_calculate_clkdiv_from_float")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_calculate_clkdiv_from_float=_weak_pio_calculate_clkdiv_from_float")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_can_add_program(PIO pio, const pio_program_t* program);
__attribute__((weak)) bool pio_can_add_program(PIO pio,
                                               const pio_program_t* program)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_can_add_program(PIO pio, const pio_program_t* program)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_can_add_program=__weak_pio_can_add_program")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_can_add_program=_weak_pio_can_add_program")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_can_add_program_at_offset(PIO pio,
                                              const pio_program_t* program,
                                              uint offset);
__attribute__((weak)) bool pio_can_add_program_at_offset(
    PIO pio, const pio_program_t* program, uint offset)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_can_add_program_at_offset(
    PIO pio, const pio_program_t* program, uint offset)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_can_add_program_at_offset=__weak_pio_can_add_program_at_offset")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_can_add_program_at_offset=_weak_pio_can_add_program_at_offset")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_claim_free_sm_and_add_program(const pio_program_t* program,
                                                  PIO* pio, uint* sm,
                                                  uint* offset);
__attribute__((weak)) bool pio_claim_free_sm_and_add_program(
    const pio_program_t* program, PIO* pio, uint* sm, uint* offset)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_claim_free_sm_and_add_program(
    const pio_program_t* program, PIO* pio, uint* sm, uint* offset)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_claim_free_sm_and_add_program=__weak_pio_claim_free_sm_and_add_program")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_claim_free_sm_and_add_program=_weak_pio_claim_free_sm_and_add_program")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_claim_free_sm_and_add_program_for_gpio_range(
    const pio_program_t* program, PIO* pio, uint* sm, uint* offset,
    uint gpio_base, uint gpio_count, bool set_gpio_base);
__attribute__((weak)) bool pio_claim_free_sm_and_add_program_for_gpio_range(
    const pio_program_t* program, PIO* pio, uint* sm, uint* offset,
    uint gpio_base, uint gpio_count, bool set_gpio_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_claim_free_sm_and_add_program_for_gpio_range(
    const pio_program_t* program, PIO* pio, uint* sm, uint* offset,
    uint gpio_base, uint gpio_count, bool set_gpio_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_claim_free_sm_and_add_program_for_gpio_range=__weak_pio_claim_free_sm_and_add_program_for_gpio_range")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_claim_free_sm_and_add_program_for_gpio_range=_weak_pio_claim_free_sm_and_add_program_for_gpio_range")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_claim_sm_mask(PIO pio, uint sm_mask);
__attribute__((weak)) void pio_claim_sm_mask(PIO pio, uint sm_mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_claim_sm_mask(PIO pio, uint sm_mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_claim_sm_mask=__weak_pio_claim_sm_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_claim_sm_mask=_weak_pio_claim_sm_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_claim_unused_sm(PIO pio, bool required);
__attribute__((weak)) int pio_claim_unused_sm(PIO pio, bool required)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_claim_unused_sm(PIO pio, bool required)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_claim_unused_sm=__weak_pio_claim_unused_sm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_claim_unused_sm=_weak_pio_claim_unused_sm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_clear_instruction_memory(PIO pio);
__attribute__((weak)) void pio_clear_instruction_memory(PIO pio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_clear_instruction_memory(PIO pio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_clear_instruction_memory=__weak_pio_clear_instruction_memory")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_clear_instruction_memory=_weak_pio_clear_instruction_memory")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_clkdiv_restart_sm_mask(PIO pio, uint32_t mask);
__attribute__((weak)) void pio_clkdiv_restart_sm_mask(PIO pio, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_clkdiv_restart_sm_mask(PIO pio, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_clkdiv_restart_sm_mask=__weak_pio_clkdiv_restart_sm_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_clkdiv_restart_sm_mask=_weak_pio_clkdiv_restart_sm_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_clkdiv_restart_sm_multi_mask(PIO pio, uint32_t mask_prev,
                                                 uint32_t mask,
                                                 uint32_t mask_next);
__attribute__((weak)) void pio_clkdiv_restart_sm_multi_mask(PIO pio,
                                                            uint32_t mask_prev,
                                                            uint32_t mask,
                                                            uint32_t mask_next)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_clkdiv_restart_sm_multi_mask(PIO pio,
                                                       uint32_t mask_prev,
                                                       uint32_t mask,
                                                       uint32_t mask_next)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_clkdiv_restart_sm_multi_mask=__weak_pio_clkdiv_restart_sm_multi_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_clkdiv_restart_sm_multi_mask=_weak_pio_clkdiv_restart_sm_multi_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_enable_sm_mask_in_sync(PIO pio, uint32_t mask);
__attribute__((weak)) void pio_enable_sm_mask_in_sync(PIO pio, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_enable_sm_mask_in_sync(PIO pio, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_enable_sm_mask_in_sync=__weak_pio_enable_sm_mask_in_sync")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_enable_sm_mask_in_sync=_weak_pio_enable_sm_mask_in_sync")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_enable_sm_multi_mask_in_sync(PIO pio, uint32_t mask_prev,
                                                 uint32_t mask,
                                                 uint32_t mask_next);
__attribute__((weak)) void pio_enable_sm_multi_mask_in_sync(PIO pio,
                                                            uint32_t mask_prev,
                                                            uint32_t mask,
                                                            uint32_t mask_next)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_enable_sm_multi_mask_in_sync(PIO pio,
                                                       uint32_t mask_prev,
                                                       uint32_t mask,
                                                       uint32_t mask_next)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_enable_sm_multi_mask_in_sync=__weak_pio_enable_sm_multi_mask_in_sync")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_enable_sm_multi_mask_in_sync=_weak_pio_enable_sm_multi_mask_in_sync")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" pio_sm_config pio_get_default_sm_config(void);
__attribute__((weak)) pio_sm_config pio_get_default_sm_config(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" pio_sm_config _weak_pio_get_default_sm_config(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_get_default_sm_config=__weak_pio_get_default_sm_config")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_get_default_sm_config=_weak_pio_get_default_sm_config")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_get_dreq(PIO pio, uint sm, bool is_tx);
__attribute__((weak)) uint pio_get_dreq(PIO pio, uint sm, bool is_tx)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_get_dreq(PIO pio, uint sm, bool is_tx)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_get_dreq=__weak_pio_get_dreq")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_get_dreq=_weak_pio_get_dreq")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_get_funcsel(PIO pio);
__attribute__((weak)) uint pio_get_funcsel(PIO pio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_get_funcsel(PIO pio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_get_funcsel=__weak_pio_get_funcsel")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_get_funcsel=_weak_pio_get_funcsel")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_get_gpio_base(PIO pio);
__attribute__((weak)) uint pio_get_gpio_base(PIO pio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_get_gpio_base(PIO pio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_get_gpio_base=__weak_pio_get_gpio_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_get_gpio_base=_weak_pio_get_gpio_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_get_index(PIO pio);
__attribute__((weak)) uint pio_get_index(PIO pio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_get_index(PIO pio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_get_index=__weak_pio_get_index")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_get_index=_weak_pio_get_index")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" PIO pio_get_instance(uint instance);
__attribute__((weak)) PIO pio_get_instance(uint instance)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" PIO _weak_pio_get_instance(uint instance)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_get_instance=__weak_pio_get_instance")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_get_instance=_weak_pio_get_instance")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_get_irq_num(PIO pio, uint irqn);
__attribute__((weak)) int pio_get_irq_num(PIO pio, uint irqn)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_get_irq_num(PIO pio, uint irqn)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_get_irq_num=__weak_pio_get_irq_num")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_get_irq_num=_weak_pio_get_irq_num")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" pio_interrupt_source_t pio_get_rx_fifo_not_empty_interrupt_source(
    uint sm);
__attribute__((weak)) pio_interrupt_source_t
pio_get_rx_fifo_not_empty_interrupt_source(uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" pio_interrupt_source_t
_weak_pio_get_rx_fifo_not_empty_interrupt_source(uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_get_rx_fifo_not_empty_interrupt_source=__weak_pio_get_rx_fifo_not_empty_interrupt_source")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_get_rx_fifo_not_empty_interrupt_source=_weak_pio_get_rx_fifo_not_empty_interrupt_source")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" pio_interrupt_source_t pio_get_tx_fifo_not_full_interrupt_source(
    uint sm);
__attribute__((weak)) pio_interrupt_source_t
pio_get_tx_fifo_not_full_interrupt_source(uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" pio_interrupt_source_t
_weak_pio_get_tx_fifo_not_full_interrupt_source(uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_get_tx_fifo_not_full_interrupt_source=__weak_pio_get_tx_fifo_not_full_interrupt_source")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_get_tx_fifo_not_full_interrupt_source=_weak_pio_get_tx_fifo_not_full_interrupt_source")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_gpio_init(PIO pio, uint pin);
__attribute__((weak)) void pio_gpio_init(PIO pio, uint pin)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_gpio_init(PIO pio, uint pin)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_gpio_init=__weak_pio_gpio_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_gpio_init=_weak_pio_gpio_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_interrupt_clear(PIO pio, uint pio_interrupt_num);
__attribute__((weak)) void pio_interrupt_clear(PIO pio, uint pio_interrupt_num)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_interrupt_clear(PIO pio, uint pio_interrupt_num)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_interrupt_clear=__weak_pio_interrupt_clear")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_interrupt_clear=_weak_pio_interrupt_clear")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_interrupt_get(PIO pio, uint pio_interrupt_num);
__attribute__((weak)) bool pio_interrupt_get(PIO pio, uint pio_interrupt_num)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_interrupt_get(PIO pio, uint pio_interrupt_num)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_interrupt_get=__weak_pio_interrupt_get")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_interrupt_get=_weak_pio_interrupt_get")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_remove_program(PIO pio, const pio_program_t* program,
                                   uint loaded_offset);
__attribute__((weak)) void pio_remove_program(PIO pio,
                                              const pio_program_t* program,
                                              uint loaded_offset)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_remove_program(PIO pio, const pio_program_t* program,
                                         uint loaded_offset)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_remove_program=__weak_pio_remove_program")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_remove_program=_weak_pio_remove_program")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_remove_program_and_unclaim_sm(const pio_program_t* program,
                                                  PIO pio, uint sm,
                                                  uint offset);
__attribute__((weak)) void pio_remove_program_and_unclaim_sm(
    const pio_program_t* program, PIO pio, uint sm, uint offset)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_remove_program_and_unclaim_sm(
    const pio_program_t* program, PIO pio, uint sm, uint offset)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_remove_program_and_unclaim_sm=__weak_pio_remove_program_and_unclaim_sm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_remove_program_and_unclaim_sm=_weak_pio_remove_program_and_unclaim_sm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_restart_sm_mask(PIO pio, uint32_t mask);
__attribute__((weak)) void pio_restart_sm_mask(PIO pio, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_restart_sm_mask(PIO pio, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_restart_sm_mask=__weak_pio_restart_sm_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_restart_sm_mask=_weak_pio_restart_sm_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_set_gpio_base(PIO pio, uint gpio_base);
__attribute__((weak)) int pio_set_gpio_base(PIO pio, uint gpio_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_set_gpio_base(PIO pio, uint gpio_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_set_gpio_base=__weak_pio_set_gpio_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_set_gpio_base=_weak_pio_set_gpio_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irq0_source_enabled(PIO pio,
                                            pio_interrupt_source_t source,
                                            bool enabled);
__attribute__((weak)) void pio_set_irq0_source_enabled(
    PIO pio, pio_interrupt_source_t source, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irq0_source_enabled(PIO pio,
                                                  pio_interrupt_source_t source,
                                                  bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irq0_source_enabled=__weak_pio_set_irq0_source_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irq0_source_enabled=_weak_pio_set_irq0_source_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irq0_source_mask_enabled(PIO pio, uint32_t source_mask,
                                                 bool enabled);
__attribute__((weak)) void pio_set_irq0_source_mask_enabled(
    PIO pio, uint32_t source_mask, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irq0_source_mask_enabled(PIO pio,
                                                       uint32_t source_mask,
                                                       bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irq0_source_mask_enabled=__weak_pio_set_irq0_source_mask_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irq0_source_mask_enabled=_weak_pio_set_irq0_source_mask_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irq1_source_enabled(PIO pio,
                                            pio_interrupt_source_t source,
                                            bool enabled);
__attribute__((weak)) void pio_set_irq1_source_enabled(
    PIO pio, pio_interrupt_source_t source, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irq1_source_enabled(PIO pio,
                                                  pio_interrupt_source_t source,
                                                  bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irq1_source_enabled=__weak_pio_set_irq1_source_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irq1_source_enabled=_weak_pio_set_irq1_source_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irq1_source_mask_enabled(PIO pio, uint32_t source_mask,
                                                 bool enabled);
__attribute__((weak)) void pio_set_irq1_source_mask_enabled(
    PIO pio, uint32_t source_mask, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irq1_source_mask_enabled(PIO pio,
                                                       uint32_t source_mask,
                                                       bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irq1_source_mask_enabled=__weak_pio_set_irq1_source_mask_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irq1_source_mask_enabled=_weak_pio_set_irq1_source_mask_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irqn_source_enabled(PIO pio, uint irq_index,
                                            pio_interrupt_source_t source,
                                            bool enabled);
__attribute__((weak)) void pio_set_irqn_source_enabled(
    PIO pio, uint irq_index, pio_interrupt_source_t source, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irqn_source_enabled(PIO pio, uint irq_index,
                                                  pio_interrupt_source_t source,
                                                  bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irqn_source_enabled=__weak_pio_set_irqn_source_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irqn_source_enabled=_weak_pio_set_irqn_source_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_irqn_source_mask_enabled(PIO pio, uint irq_index,
                                                 uint32_t source_mask,
                                                 bool enabled);
__attribute__((weak)) void pio_set_irqn_source_mask_enabled(
    PIO pio, uint irq_index, uint32_t source_mask, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_irqn_source_mask_enabled(PIO pio, uint irq_index,
                                                       uint32_t source_mask,
                                                       bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_irqn_source_mask_enabled=__weak_pio_set_irqn_source_mask_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_irqn_source_mask_enabled=_weak_pio_set_irqn_source_mask_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_sm_mask_enabled(PIO pio, uint32_t mask, bool enabled);
__attribute__((weak)) void pio_set_sm_mask_enabled(PIO pio, uint32_t mask,
                                                   bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_sm_mask_enabled(PIO pio, uint32_t mask,
                                              bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_sm_mask_enabled=__weak_pio_set_sm_mask_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_sm_mask_enabled=_weak_pio_set_sm_mask_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_set_sm_multi_mask_enabled(PIO pio, uint32_t mask_prev,
                                              uint32_t mask, uint32_t mask_next,
                                              bool enabled);
__attribute__((weak)) void pio_set_sm_multi_mask_enabled(PIO pio,
                                                         uint32_t mask_prev,
                                                         uint32_t mask,
                                                         uint32_t mask_next,
                                                         bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_set_sm_multi_mask_enabled(PIO pio, uint32_t mask_prev,
                                                    uint32_t mask,
                                                    uint32_t mask_next,
                                                    bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_set_sm_multi_mask_enabled=__weak_pio_set_sm_multi_mask_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_set_sm_multi_mask_enabled=_weak_pio_set_sm_multi_mask_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_claim(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_claim(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_claim(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_claim=__weak_pio_sm_claim")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_claim=_weak_pio_sm_claim")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_clear_fifos(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_clear_fifos(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_clear_fifos(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_clear_fifos=__weak_pio_sm_clear_fifos")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_clear_fifos=_weak_pio_sm_clear_fifos")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_clkdiv_restart(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_clkdiv_restart(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_clkdiv_restart(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_clkdiv_restart=__weak_pio_sm_clkdiv_restart")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_clkdiv_restart=_weak_pio_sm_clkdiv_restart")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_drain_tx_fifo(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_drain_tx_fifo(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_drain_tx_fifo(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_drain_tx_fifo=__weak_pio_sm_drain_tx_fifo")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_sm_drain_tx_fifo=_weak_pio_sm_drain_tx_fifo")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_exec(PIO pio, uint sm, uint instr);
__attribute__((weak)) void pio_sm_exec(PIO pio, uint sm, uint instr)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_exec(PIO pio, uint sm, uint instr)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_exec=__weak_pio_sm_exec")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_exec=_weak_pio_sm_exec")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_exec_wait_blocking(PIO pio, uint sm, uint instr);
__attribute__((weak)) void pio_sm_exec_wait_blocking(PIO pio, uint sm,
                                                     uint instr)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_exec_wait_blocking(PIO pio, uint sm, uint instr)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_exec_wait_blocking=__weak_pio_sm_exec_wait_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_exec_wait_blocking=_weak_pio_sm_exec_wait_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t pio_sm_get(PIO pio, uint sm);
__attribute__((weak)) uint32_t pio_sm_get(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_pio_sm_get(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_get=__weak_pio_sm_get")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_get=_weak_pio_sm_get")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t pio_sm_get_blocking(PIO pio, uint sm);
__attribute__((weak)) uint32_t pio_sm_get_blocking(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_pio_sm_get_blocking(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_get_blocking=__weak_pio_sm_get_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_sm_get_blocking=_weak_pio_sm_get_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint8_t pio_sm_get_pc(PIO pio, uint sm);
__attribute__((weak)) uint8_t pio_sm_get_pc(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint8_t _weak_pio_sm_get_pc(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_get_pc=__weak_pio_sm_get_pc")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_get_pc=_weak_pio_sm_get_pc")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_sm_get_rx_fifo_level(PIO pio, uint sm);
__attribute__((weak)) uint pio_sm_get_rx_fifo_level(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_sm_get_rx_fifo_level(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_get_rx_fifo_level=__weak_pio_sm_get_rx_fifo_level")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_get_rx_fifo_level=_weak_pio_sm_get_rx_fifo_level")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint pio_sm_get_tx_fifo_level(PIO pio, uint sm);
__attribute__((weak)) uint pio_sm_get_tx_fifo_level(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_pio_sm_get_tx_fifo_level(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_get_tx_fifo_level=__weak_pio_sm_get_tx_fifo_level")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_get_tx_fifo_level=_weak_pio_sm_get_tx_fifo_level")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_sm_init(PIO pio, uint sm, uint initial_pc,
                           const pio_sm_config* config);
__attribute__((weak)) int pio_sm_init(PIO pio, uint sm, uint initial_pc,
                                      const pio_sm_config* config)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_sm_init(PIO pio, uint sm, uint initial_pc,
                                 const pio_sm_config* config)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_init=__weak_pio_sm_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_init=_weak_pio_sm_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_claimed(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_claimed(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_claimed(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_sm_is_claimed=__weak_pio_sm_is_claimed")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_is_claimed=_weak_pio_sm_is_claimed")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_exec_stalled(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_exec_stalled(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_exec_stalled(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_is_exec_stalled=__weak_pio_sm_is_exec_stalled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_is_exec_stalled=_weak_pio_sm_is_exec_stalled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_rx_fifo_empty(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_rx_fifo_empty(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_rx_fifo_empty(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_is_rx_fifo_empty=__weak_pio_sm_is_rx_fifo_empty")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_is_rx_fifo_empty=_weak_pio_sm_is_rx_fifo_empty")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_rx_fifo_full(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_rx_fifo_full(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_rx_fifo_full(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_is_rx_fifo_full=__weak_pio_sm_is_rx_fifo_full")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_is_rx_fifo_full=_weak_pio_sm_is_rx_fifo_full")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_tx_fifo_empty(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_tx_fifo_empty(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_tx_fifo_empty(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_is_tx_fifo_empty=__weak_pio_sm_is_tx_fifo_empty")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_is_tx_fifo_empty=_weak_pio_sm_is_tx_fifo_empty")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool pio_sm_is_tx_fifo_full(PIO pio, uint sm);
__attribute__((weak)) bool pio_sm_is_tx_fifo_full(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_pio_sm_is_tx_fifo_full(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_is_tx_fifo_full=__weak_pio_sm_is_tx_fifo_full")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_is_tx_fifo_full=_weak_pio_sm_is_tx_fifo_full")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_put(PIO pio, uint sm, uint32_t data);
__attribute__((weak)) void pio_sm_put(PIO pio, uint sm, uint32_t data)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_put(PIO pio, uint sm, uint32_t data)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_put=__weak_pio_sm_put")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_put=_weak_pio_sm_put")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_put_blocking(PIO pio, uint sm, uint32_t data);
__attribute__((weak)) void pio_sm_put_blocking(PIO pio, uint sm, uint32_t data)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_put_blocking(PIO pio, uint sm, uint32_t data)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_put_blocking=__weak_pio_sm_put_blocking")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_sm_put_blocking=_weak_pio_sm_put_blocking")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_restart(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_restart(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_restart(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_restart=__weak_pio_sm_restart")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_restart=_weak_pio_sm_restart")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_clkdiv(PIO pio, uint sm, float div);
__attribute__((weak)) void pio_sm_set_clkdiv(PIO pio, uint sm, float div)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_clkdiv(PIO pio, uint sm, float div)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_sm_set_clkdiv=__weak_pio_sm_set_clkdiv")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_set_clkdiv=_weak_pio_sm_set_clkdiv")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_clkdiv_int_frac(PIO pio, uint sm, uint16_t div_int,
                                           uint8_t div_frac);
__attribute__((weak)) void pio_sm_set_clkdiv_int_frac(PIO pio, uint sm,
                                                      uint16_t div_int,
                                                      uint8_t div_frac)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_clkdiv_int_frac(PIO pio, uint sm,
                                                 uint16_t div_int,
                                                 uint8_t div_frac)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_set_clkdiv_int_frac=__weak_pio_sm_set_clkdiv_int_frac")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_set_clkdiv_int_frac=_weak_pio_sm_set_clkdiv_int_frac")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_sm_set_config(PIO pio, uint sm, const pio_sm_config* config);
__attribute__((weak)) int pio_sm_set_config(PIO pio, uint sm,
                                            const pio_sm_config* config)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_sm_set_config(PIO pio, uint sm,
                                       const pio_sm_config* config)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_sm_set_config=__weak_pio_sm_set_config")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_set_config=_weak_pio_sm_set_config")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int pio_sm_set_consecutive_pindirs(PIO pio, uint sm, uint pins_base,
                                              uint pin_count, bool is_out);
__attribute__((weak)) int pio_sm_set_consecutive_pindirs(PIO pio, uint sm,
                                                         uint pins_base,
                                                         uint pin_count,
                                                         bool is_out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_pio_sm_set_consecutive_pindirs(PIO pio, uint sm,
                                                    uint pins_base,
                                                    uint pin_count, bool is_out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_set_consecutive_pindirs=__weak_pio_sm_set_consecutive_pindirs")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_set_consecutive_pindirs=_weak_pio_sm_set_consecutive_pindirs")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_enabled(PIO pio, uint sm, bool enabled);
__attribute__((weak)) void pio_sm_set_enabled(PIO pio, uint sm, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_enabled(PIO pio, uint sm, bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_set_enabled=__weak_pio_sm_set_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_set_enabled=_weak_pio_sm_set_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_in_pins(PIO pio, uint sm, uint in_base);
__attribute__((weak)) void pio_sm_set_in_pins(PIO pio, uint sm, uint in_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_in_pins(PIO pio, uint sm, uint in_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_set_in_pins=__weak_pio_sm_set_in_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_set_in_pins=_weak_pio_sm_set_in_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_jmp_pin(PIO pio, uint sm, uint pin);
__attribute__((weak)) void pio_sm_set_jmp_pin(PIO pio, uint sm, uint pin)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_jmp_pin(PIO pio, uint sm, uint pin)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_set_jmp_pin=__weak_pio_sm_set_jmp_pin")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:pio_sm_set_jmp_pin=_weak_pio_sm_set_jmp_pin")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_out_pins(PIO pio, uint sm, uint out_base,
                                    uint out_count);
__attribute__((weak)) void pio_sm_set_out_pins(PIO pio, uint sm, uint out_base,
                                               uint out_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_out_pins(PIO pio, uint sm, uint out_base,
                                          uint out_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_set_out_pins=__weak_pio_sm_set_out_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_sm_set_out_pins=_weak_pio_sm_set_out_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_pindirs_with_mask(PIO pio, uint sm,
                                             uint32_t pin_dirs,
                                             uint32_t pin_mask);
__attribute__((weak)) void pio_sm_set_pindirs_with_mask(PIO pio, uint sm,
                                                        uint32_t pin_dirs,
                                                        uint32_t pin_mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_pindirs_with_mask(PIO pio, uint sm,
                                                   uint32_t pin_dirs,
                                                   uint32_t pin_mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_set_pindirs_with_mask=__weak_pio_sm_set_pindirs_with_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_set_pindirs_with_mask=_weak_pio_sm_set_pindirs_with_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_pins(PIO pio, uint sm, uint32_t pin_values);
__attribute__((weak)) void pio_sm_set_pins(PIO pio, uint sm,
                                           uint32_t pin_values)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_pins(PIO pio, uint sm, uint32_t pin_values)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_sm_set_pins=__weak_pio_sm_set_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_set_pins=_weak_pio_sm_set_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_pins_with_mask(PIO pio, uint sm, uint32_t pin_values,
                                          uint32_t pin_mask);
__attribute__((weak)) void pio_sm_set_pins_with_mask(PIO pio, uint sm,
                                                     uint32_t pin_values,
                                                     uint32_t pin_mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_pins_with_mask(PIO pio, uint sm,
                                                uint32_t pin_values,
                                                uint32_t pin_mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_set_pins_with_mask=__weak_pio_sm_set_pins_with_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_set_pins_with_mask=_weak_pio_sm_set_pins_with_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_set_pins(PIO pio, uint sm, uint set_base,
                                    uint set_count);
__attribute__((weak)) void pio_sm_set_set_pins(PIO pio, uint sm, uint set_base,
                                               uint set_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_set_pins(PIO pio, uint sm, uint set_base,
                                          uint set_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_pio_sm_set_set_pins=__weak_pio_sm_set_set_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:pio_sm_set_set_pins=_weak_pio_sm_set_set_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_sideset_pins(PIO pio, uint sm, uint sideset_base);
__attribute__((weak)) void pio_sm_set_sideset_pins(PIO pio, uint sm,
                                                   uint sideset_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_sideset_pins(PIO pio, uint sm,
                                              uint sideset_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_pio_sm_set_sideset_pins=__weak_pio_sm_set_sideset_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:pio_sm_set_sideset_pins=_weak_pio_sm_set_sideset_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_set_wrap(PIO pio, uint sm, uint wrap_target, uint wrap);
__attribute__((weak)) void pio_sm_set_wrap(PIO pio, uint sm, uint wrap_target,
                                           uint wrap)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_set_wrap(PIO pio, uint sm, uint wrap_target,
                                      uint wrap)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_pio_sm_set_wrap=__weak_pio_sm_set_wrap")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_set_wrap=_weak_pio_sm_set_wrap")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void pio_sm_unclaim(PIO pio, uint sm);
__attribute__((weak)) void pio_sm_unclaim(PIO pio, uint sm)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_pio_sm_unclaim(PIO pio, uint sm)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_pio_sm_unclaim=__weak_pio_sm_unclaim")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:pio_sm_unclaim=_weak_pio_sm_unclaim")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_clkdiv(pio_sm_config* c, float div);
__attribute__((weak)) void sm_config_set_clkdiv(pio_sm_config* c, float div)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_clkdiv(pio_sm_config* c, float div)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_clkdiv=__weak_sm_config_set_clkdiv")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:sm_config_set_clkdiv=_weak_sm_config_set_clkdiv")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_clkdiv_int_frac(pio_sm_config* c,
                                              uint16_t div_int,
                                              uint8_t div_frac);
__attribute__((weak)) void sm_config_set_clkdiv_int_frac(pio_sm_config* c,
                                                         uint16_t div_int,
                                                         uint8_t div_frac)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_clkdiv_int_frac(pio_sm_config* c,
                                                    uint16_t div_int,
                                                    uint8_t div_frac)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_clkdiv_int_frac=__weak_sm_config_set_clkdiv_int_frac")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_clkdiv_int_frac=_weak_sm_config_set_clkdiv_int_frac")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_fifo_join(pio_sm_config* c,
                                        enum pio_fifo_join join);
__attribute__((weak)) void sm_config_set_fifo_join(pio_sm_config* c,
                                                   enum pio_fifo_join join)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_fifo_join(pio_sm_config* c,
                                              enum pio_fifo_join join)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_fifo_join=__weak_sm_config_set_fifo_join")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_fifo_join=_weak_sm_config_set_fifo_join")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_in_pin_base(pio_sm_config* c, uint in_base);
__attribute__((weak)) void sm_config_set_in_pin_base(pio_sm_config* c,
                                                     uint in_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_in_pin_base(pio_sm_config* c, uint in_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_in_pin_base=__weak_sm_config_set_in_pin_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_in_pin_base=_weak_sm_config_set_in_pin_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_in_pin_count(pio_sm_config* c, uint in_count);
__attribute__((weak)) void sm_config_set_in_pin_count(pio_sm_config* c,
                                                      uint in_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_in_pin_count(pio_sm_config* c,
                                                 uint in_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_in_pin_count=__weak_sm_config_set_in_pin_count")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_in_pin_count=_weak_sm_config_set_in_pin_count")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_in_pins(pio_sm_config* c, uint in_base);
__attribute__((weak)) void sm_config_set_in_pins(pio_sm_config* c, uint in_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_in_pins(pio_sm_config* c, uint in_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_in_pins=__weak_sm_config_set_in_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_in_pins=_weak_sm_config_set_in_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_in_shift(pio_sm_config* c, bool shift_right,
                                       bool autopush, uint push_threshold);
__attribute__((weak)) void sm_config_set_in_shift(pio_sm_config* c,
                                                  bool shift_right,
                                                  bool autopush,
                                                  uint push_threshold)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_in_shift(pio_sm_config* c, bool shift_right,
                                             bool autopush, uint push_threshold)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_in_shift=__weak_sm_config_set_in_shift")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_in_shift=_weak_sm_config_set_in_shift")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_jmp_pin(pio_sm_config* c, uint pin);
__attribute__((weak)) void sm_config_set_jmp_pin(pio_sm_config* c, uint pin)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_jmp_pin(pio_sm_config* c, uint pin)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_jmp_pin=__weak_sm_config_set_jmp_pin")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_jmp_pin=_weak_sm_config_set_jmp_pin")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_mov_status(pio_sm_config* c,
                                         enum pio_mov_status_type status_sel,
                                         uint status_n);
__attribute__((weak)) void sm_config_set_mov_status(
    pio_sm_config* c, enum pio_mov_status_type status_sel, uint status_n)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_mov_status(
    pio_sm_config* c, enum pio_mov_status_type status_sel, uint status_n)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_mov_status=__weak_sm_config_set_mov_status")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_mov_status=_weak_sm_config_set_mov_status")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_out_pin_base(pio_sm_config* c, uint out_base);
__attribute__((weak)) void sm_config_set_out_pin_base(pio_sm_config* c,
                                                      uint out_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_out_pin_base(pio_sm_config* c,
                                                 uint out_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_out_pin_base=__weak_sm_config_set_out_pin_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_out_pin_base=_weak_sm_config_set_out_pin_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_out_pin_count(pio_sm_config* c, uint out_count);
__attribute__((weak)) void sm_config_set_out_pin_count(pio_sm_config* c,
                                                       uint out_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_out_pin_count(pio_sm_config* c,
                                                  uint out_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_out_pin_count=__weak_sm_config_set_out_pin_count")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_out_pin_count=_weak_sm_config_set_out_pin_count")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_out_pins(pio_sm_config* c, uint out_base,
                                       uint out_count);
__attribute__((weak)) void sm_config_set_out_pins(pio_sm_config* c,
                                                  uint out_base, uint out_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_out_pins(pio_sm_config* c, uint out_base,
                                             uint out_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_out_pins=__weak_sm_config_set_out_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_out_pins=_weak_sm_config_set_out_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_out_shift(pio_sm_config* c, bool shift_right,
                                        bool autopull, uint pull_threshold);
__attribute__((weak)) void sm_config_set_out_shift(pio_sm_config* c,
                                                   bool shift_right,
                                                   bool autopull,
                                                   uint pull_threshold)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_out_shift(pio_sm_config* c,
                                              bool shift_right, bool autopull,
                                              uint pull_threshold)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_out_shift=__weak_sm_config_set_out_shift")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_out_shift=_weak_sm_config_set_out_shift")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_out_special(pio_sm_config* c, bool sticky,
                                          bool has_enable_pin,
                                          uint enable_pin_index);
__attribute__((weak)) void sm_config_set_out_special(pio_sm_config* c,
                                                     bool sticky,
                                                     bool has_enable_pin,
                                                     uint enable_pin_index)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_out_special(pio_sm_config* c, bool sticky,
                                                bool has_enable_pin,
                                                uint enable_pin_index)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_out_special=__weak_sm_config_set_out_special")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_out_special=_weak_sm_config_set_out_special")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_set_pin_base(pio_sm_config* c, uint set_base);
__attribute__((weak)) void sm_config_set_set_pin_base(pio_sm_config* c,
                                                      uint set_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_set_pin_base(pio_sm_config* c,
                                                 uint set_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_set_pin_base=__weak_sm_config_set_set_pin_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_set_pin_base=_weak_sm_config_set_set_pin_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_set_pin_count(pio_sm_config* c, uint set_count);
__attribute__((weak)) void sm_config_set_set_pin_count(pio_sm_config* c,
                                                       uint set_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_set_pin_count(pio_sm_config* c,
                                                  uint set_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_set_pin_count=__weak_sm_config_set_set_pin_count")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_set_pin_count=_weak_sm_config_set_set_pin_count")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_set_pins(pio_sm_config* c, uint set_base,
                                       uint set_count);
__attribute__((weak)) void sm_config_set_set_pins(pio_sm_config* c,
                                                  uint set_base, uint set_count)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_set_pins(pio_sm_config* c, uint set_base,
                                             uint set_count)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_set_pins=__weak_sm_config_set_set_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_set_pins=_weak_sm_config_set_set_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_sideset(pio_sm_config* c, uint bit_count,
                                      bool optional, bool pindirs);
__attribute__((weak)) void sm_config_set_sideset(pio_sm_config* c,
                                                 uint bit_count, bool optional,
                                                 bool pindirs)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_sideset(pio_sm_config* c, uint bit_count,
                                            bool optional, bool pindirs)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_sideset=__weak_sm_config_set_sideset")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_sideset=_weak_sm_config_set_sideset")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_sideset_pin_base(pio_sm_config* c,
                                               uint sideset_base);
__attribute__((weak)) void sm_config_set_sideset_pin_base(pio_sm_config* c,
                                                          uint sideset_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_sideset_pin_base(pio_sm_config* c,
                                                     uint sideset_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_sideset_pin_base=__weak_sm_config_set_sideset_pin_base")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_sideset_pin_base=_weak_sm_config_set_sideset_pin_base")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_sideset_pins(pio_sm_config* c, uint sideset_base);
__attribute__((weak)) void sm_config_set_sideset_pins(pio_sm_config* c,
                                                      uint sideset_base)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_sideset_pins(pio_sm_config* c,
                                                 uint sideset_base)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_sm_config_set_sideset_pins=__weak_sm_config_set_sideset_pins")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:sm_config_set_sideset_pins=_weak_sm_config_set_sideset_pins")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sm_config_set_wrap(pio_sm_config* c, uint wrap_target,
                                   uint wrap);
__attribute__((weak)) void sm_config_set_wrap(pio_sm_config* c,
                                              uint wrap_target, uint wrap)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sm_config_set_wrap(pio_sm_config* c, uint wrap_target,
                                         uint wrap)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_pio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_sm_config_set_wrap=__weak_sm_config_set_wrap")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:sm_config_set_wrap=_weak_sm_config_set_wrap")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_acknowledge_irq(uint gpio, uint32_t event_mask);
__attribute__((weak)) void gpio_acknowledge_irq(uint gpio, uint32_t event_mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_acknowledge_irq(uint gpio, uint32_t event_mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_acknowledge_irq=__weak_gpio_acknowledge_irq")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:gpio_acknowledge_irq=_weak_gpio_acknowledge_irq")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler(uint gpio, irq_handler_t handler);
__attribute__((weak)) void gpio_add_raw_irq_handler(uint gpio,
                                                    irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler(uint gpio, irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler=__weak_gpio_add_raw_irq_handler")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler=_weak_gpio_add_raw_irq_handler")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler_masked(uint32_t gpio_mask,
                                                irq_handler_t handler);
__attribute__((weak)) void gpio_add_raw_irq_handler_masked(
    uint32_t gpio_mask, irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler_masked(uint32_t gpio_mask,
                                                      irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler_masked=__weak_gpio_add_raw_irq_handler_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler_masked=_weak_gpio_add_raw_irq_handler_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler_masked64(uint64_t gpio_mask,
                                                  irq_handler_t handler);
__attribute__((weak)) void gpio_add_raw_irq_handler_masked64(
    uint64_t gpio_mask, irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler_masked64(uint64_t gpio_mask,
                                                        irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler_masked64=__weak_gpio_add_raw_irq_handler_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler_masked64=_weak_gpio_add_raw_irq_handler_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler_with_order_priority(
    uint gpio, irq_handler_t handler, uint8_t order_priority);
__attribute__((weak)) void gpio_add_raw_irq_handler_with_order_priority(
    uint gpio, irq_handler_t handler, uint8_t order_priority)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler_with_order_priority(
    uint gpio, irq_handler_t handler, uint8_t order_priority)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler_with_order_priority=__weak_gpio_add_raw_irq_handler_with_order_priority")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler_with_order_priority=_weak_gpio_add_raw_irq_handler_with_order_priority")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler_with_order_priority_masked(
    uint32_t gpio_mask, irq_handler_t handler, uint8_t order_priority);
__attribute__((weak)) void gpio_add_raw_irq_handler_with_order_priority_masked(
    uint32_t gpio_mask, irq_handler_t handler, uint8_t order_priority)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler_with_order_priority_masked(
    uint32_t gpio_mask, irq_handler_t handler, uint8_t order_priority)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler_with_order_priority_masked=__weak_gpio_add_raw_irq_handler_with_order_priority_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler_with_order_priority_masked=_weak_gpio_add_raw_irq_handler_with_order_priority_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_add_raw_irq_handler_with_order_priority_masked64(
    uint64_t gpio_mask, irq_handler_t handler, uint8_t order_priority);
__attribute__((weak)) void
gpio_add_raw_irq_handler_with_order_priority_masked64(uint64_t gpio_mask,
                                                      irq_handler_t handler,
                                                      uint8_t order_priority)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_add_raw_irq_handler_with_order_priority_masked64(
    uint64_t gpio_mask, irq_handler_t handler, uint8_t order_priority)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_add_raw_irq_handler_with_order_priority_masked64=__weak_gpio_add_raw_irq_handler_with_order_priority_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_add_raw_irq_handler_with_order_priority_masked64=_weak_gpio_add_raw_irq_handler_with_order_priority_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_assign_to_ns(uint gpio, bool ns);
__attribute__((weak)) void gpio_assign_to_ns(uint gpio, bool ns)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_assign_to_ns(uint gpio, bool ns)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_assign_to_ns=__weak_gpio_assign_to_ns")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_assign_to_ns=_weak_gpio_assign_to_ns")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_clr_mask(uint32_t mask);
__attribute__((weak)) void gpio_clr_mask(uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_clr_mask(uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_clr_mask=__weak_gpio_clr_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_clr_mask=_weak_gpio_clr_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_clr_mask64(uint64_t mask);
__attribute__((weak)) void gpio_clr_mask64(uint64_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_clr_mask64(uint64_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_clr_mask64=__weak_gpio_clr_mask64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_clr_mask64=_weak_gpio_clr_mask64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_clr_mask_n(uint n, uint32_t mask);
__attribute__((weak)) void gpio_clr_mask_n(uint n, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_clr_mask_n(uint n, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_clr_mask_n=__weak_gpio_clr_mask_n")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_clr_mask_n=_weak_gpio_clr_mask_n")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_debug_pins_init(void);
__attribute__((weak)) void gpio_debug_pins_init(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_debug_pins_init(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_debug_pins_init=__weak_gpio_debug_pins_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:gpio_debug_pins_init=_weak_gpio_debug_pins_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_deinit(uint gpio);
__attribute__((weak)) void gpio_deinit(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_deinit(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_deinit=__weak_gpio_deinit")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_deinit=_weak_gpio_deinit")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_disable_pulls(uint gpio);
__attribute__((weak)) void gpio_disable_pulls(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_disable_pulls(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_disable_pulls=__weak_gpio_disable_pulls")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_disable_pulls=_weak_gpio_disable_pulls")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_get(uint gpio);
__attribute__((weak)) bool gpio_get(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_get(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_get=__weak_gpio_get")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_get=_weak_gpio_get")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t gpio_get_all(void);
__attribute__((weak)) uint32_t gpio_get_all(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_gpio_get_all(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_get_all=__weak_gpio_get_all")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_get_all=_weak_gpio_get_all")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint64_t gpio_get_all64(void);
__attribute__((weak)) uint64_t gpio_get_all64(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint64_t _weak_gpio_get_all64(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_get_all64=__weak_gpio_get_all64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_get_all64=_weak_gpio_get_all64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint gpio_get_dir(uint gpio);
__attribute__((weak)) uint gpio_get_dir(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_gpio_get_dir(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_get_dir=__weak_gpio_get_dir")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_get_dir=_weak_gpio_get_dir")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" enum gpio_drive_strength gpio_get_drive_strength(uint gpio);
__attribute__((weak)) enum gpio_drive_strength gpio_get_drive_strength(
    uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" enum gpio_drive_strength _weak_gpio_get_drive_strength(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_get_drive_strength=__weak_gpio_get_drive_strength")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_get_drive_strength=_weak_gpio_get_drive_strength")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" gpio_function_t gpio_get_function(uint gpio);
__attribute__((weak)) gpio_function_t gpio_get_function(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" gpio_function_t _weak_gpio_get_function(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_get_function=__weak_gpio_get_function")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_get_function=_weak_gpio_get_function")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t gpio_get_irq_event_mask(uint gpio);
__attribute__((weak)) uint32_t gpio_get_irq_event_mask(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_gpio_get_irq_event_mask(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_get_irq_event_mask=__weak_gpio_get_irq_event_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_get_irq_event_mask=_weak_gpio_get_irq_event_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_get_out_level(uint gpio);
__attribute__((weak)) bool gpio_get_out_level(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_get_out_level(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_get_out_level=__weak_gpio_get_out_level")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_get_out_level=_weak_gpio_get_out_level")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" enum gpio_slew_rate gpio_get_slew_rate(uint gpio);
__attribute__((weak)) enum gpio_slew_rate gpio_get_slew_rate(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" enum gpio_slew_rate _weak_gpio_get_slew_rate(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_get_slew_rate=__weak_gpio_get_slew_rate")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_get_slew_rate=_weak_gpio_get_slew_rate")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_init(uint gpio);
__attribute__((weak)) void gpio_init(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_init(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_init=__weak_gpio_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_init=_weak_gpio_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_init_mask(uint gpio_mask);
__attribute__((weak)) void gpio_init_mask(uint gpio_mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_init_mask(uint gpio_mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_init_mask=__weak_gpio_init_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_init_mask=_weak_gpio_init_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_is_dir_out(uint gpio);
__attribute__((weak)) bool gpio_is_dir_out(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_is_dir_out(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_is_dir_out=__weak_gpio_is_dir_out")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_is_dir_out=_weak_gpio_is_dir_out")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_is_input_hysteresis_enabled(uint gpio);
__attribute__((weak)) bool gpio_is_input_hysteresis_enabled(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_is_input_hysteresis_enabled(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_is_input_hysteresis_enabled=__weak_gpio_is_input_hysteresis_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_is_input_hysteresis_enabled=_weak_gpio_is_input_hysteresis_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_is_pulled_down(uint gpio);
__attribute__((weak)) bool gpio_is_pulled_down(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_is_pulled_down(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_is_pulled_down=__weak_gpio_is_pulled_down")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:gpio_is_pulled_down=_weak_gpio_is_pulled_down")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool gpio_is_pulled_up(uint gpio);
__attribute__((weak)) bool gpio_is_pulled_up(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_gpio_is_pulled_up(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_is_pulled_up=__weak_gpio_is_pulled_up")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_is_pulled_up=_weak_gpio_is_pulled_up")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_pull_down(uint gpio);
__attribute__((weak)) void gpio_pull_down(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_pull_down(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_pull_down=__weak_gpio_pull_down")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_pull_down=_weak_gpio_pull_down")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_pull_up(uint gpio);
__attribute__((weak)) void gpio_pull_up(uint gpio)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_pull_up(uint gpio)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_pull_up=__weak_gpio_pull_up")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_pull_up=_weak_gpio_pull_up")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put(uint gpio, bool value);
__attribute__((weak)) void gpio_put(uint gpio, bool value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put(uint gpio, bool value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_put=__weak_gpio_put")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_put=_weak_gpio_put")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put_all(uint32_t value);
__attribute__((weak)) void gpio_put_all(uint32_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put_all(uint32_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_put_all=__weak_gpio_put_all")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_put_all=_weak_gpio_put_all")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put_all64(uint64_t value);
__attribute__((weak)) void gpio_put_all64(uint64_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put_all64(uint64_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_put_all64=__weak_gpio_put_all64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_put_all64=_weak_gpio_put_all64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put_masked(uint32_t mask, uint32_t value);
__attribute__((weak)) void gpio_put_masked(uint32_t mask, uint32_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put_masked(uint32_t mask, uint32_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_put_masked=__weak_gpio_put_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_put_masked=_weak_gpio_put_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put_masked64(uint64_t mask, uint64_t value);
__attribute__((weak)) void gpio_put_masked64(uint64_t mask, uint64_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put_masked64(uint64_t mask, uint64_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_put_masked64=__weak_gpio_put_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_put_masked64=_weak_gpio_put_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_put_masked_n(uint n, uint32_t mask, uint32_t value);
__attribute__((weak)) void gpio_put_masked_n(uint n, uint32_t mask,
                                             uint32_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_put_masked_n(uint n, uint32_t mask, uint32_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_put_masked_n=__weak_gpio_put_masked_n")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_put_masked_n=_weak_gpio_put_masked_n")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_remove_raw_irq_handler(uint gpio, irq_handler_t handler);
__attribute__((weak)) void gpio_remove_raw_irq_handler(uint gpio,
                                                       irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_remove_raw_irq_handler(uint gpio,
                                                  irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_remove_raw_irq_handler=__weak_gpio_remove_raw_irq_handler")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_remove_raw_irq_handler=_weak_gpio_remove_raw_irq_handler")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_remove_raw_irq_handler_masked(uint32_t gpio_mask,
                                                   irq_handler_t handler);
__attribute__((weak)) void gpio_remove_raw_irq_handler_masked(
    uint32_t gpio_mask, irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_remove_raw_irq_handler_masked(uint32_t gpio_mask,
                                                         irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_remove_raw_irq_handler_masked=__weak_gpio_remove_raw_irq_handler_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_remove_raw_irq_handler_masked=_weak_gpio_remove_raw_irq_handler_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_remove_raw_irq_handler_masked64(uint64_t gpio_mask,
                                                     irq_handler_t handler);
__attribute__((weak)) void gpio_remove_raw_irq_handler_masked64(
    uint64_t gpio_mask, irq_handler_t handler)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_remove_raw_irq_handler_masked64(
    uint64_t gpio_mask, irq_handler_t handler)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_remove_raw_irq_handler_masked64=__weak_gpio_remove_raw_irq_handler_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_remove_raw_irq_handler_masked64=_weak_gpio_remove_raw_irq_handler_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir(uint gpio, bool out);
__attribute__((weak)) void gpio_set_dir(uint gpio, bool out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir(uint gpio, bool out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_set_dir=__weak_gpio_set_dir")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_dir=_weak_gpio_set_dir")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_all_bits(uint32_t values);
__attribute__((weak)) void gpio_set_dir_all_bits(uint32_t values)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_all_bits(uint32_t values)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_all_bits=__weak_gpio_set_dir_all_bits")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_all_bits=_weak_gpio_set_dir_all_bits")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_all_bits64(uint64_t values);
__attribute__((weak)) void gpio_set_dir_all_bits64(uint64_t values)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_all_bits64(uint64_t values)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_all_bits64=__weak_gpio_set_dir_all_bits64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_all_bits64=_weak_gpio_set_dir_all_bits64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_in_masked(uint32_t mask);
__attribute__((weak)) void gpio_set_dir_in_masked(uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_in_masked(uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_in_masked=__weak_gpio_set_dir_in_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_in_masked=_weak_gpio_set_dir_in_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_in_masked64(uint64_t mask);
__attribute__((weak)) void gpio_set_dir_in_masked64(uint64_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_in_masked64(uint64_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_in_masked64=__weak_gpio_set_dir_in_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_in_masked64=_weak_gpio_set_dir_in_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_masked(uint32_t mask, uint32_t value);
__attribute__((weak)) void gpio_set_dir_masked(uint32_t mask, uint32_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_masked(uint32_t mask, uint32_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_set_dir_masked=__weak_gpio_set_dir_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:gpio_set_dir_masked=_weak_gpio_set_dir_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_masked64(uint64_t mask, uint64_t value);
__attribute__((weak)) void gpio_set_dir_masked64(uint64_t mask, uint64_t value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_masked64(uint64_t mask, uint64_t value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_masked64=__weak_gpio_set_dir_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_masked64=_weak_gpio_set_dir_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_out_masked(uint32_t mask);
__attribute__((weak)) void gpio_set_dir_out_masked(uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_out_masked(uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_out_masked=__weak_gpio_set_dir_out_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_out_masked=_weak_gpio_set_dir_out_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dir_out_masked64(uint64_t mask);
__attribute__((weak)) void gpio_set_dir_out_masked64(uint64_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dir_out_masked64(uint64_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dir_out_masked64=__weak_gpio_set_dir_out_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dir_out_masked64=_weak_gpio_set_dir_out_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_dormant_irq_enabled(uint gpio, uint32_t event_mask,
                                             bool enabled);
__attribute__((weak)) void gpio_set_dormant_irq_enabled(uint gpio,
                                                        uint32_t event_mask,
                                                        bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_dormant_irq_enabled(uint gpio,
                                                   uint32_t event_mask,
                                                   bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_dormant_irq_enabled=__weak_gpio_set_dormant_irq_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_dormant_irq_enabled=_weak_gpio_set_dormant_irq_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_drive_strength(uint gpio,
                                        enum gpio_drive_strength drive);
__attribute__((weak)) void gpio_set_drive_strength(
    uint gpio, enum gpio_drive_strength drive)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_drive_strength(uint gpio,
                                              enum gpio_drive_strength drive)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_drive_strength=__weak_gpio_set_drive_strength")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_drive_strength=_weak_gpio_set_drive_strength")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_function(uint gpio, gpio_function_t fn);
__attribute__((weak)) void gpio_set_function(uint gpio, gpio_function_t fn)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_function(uint gpio, gpio_function_t fn)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_function=__weak_gpio_set_function")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_set_function=_weak_gpio_set_function")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_function_masked(uint32_t gpio_mask,
                                         gpio_function_t fn);
__attribute__((weak)) void gpio_set_function_masked(uint32_t gpio_mask,
                                                    gpio_function_t fn)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_function_masked(uint32_t gpio_mask,
                                               gpio_function_t fn)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_function_masked=__weak_gpio_set_function_masked")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_function_masked=_weak_gpio_set_function_masked")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_function_masked64(uint64_t gpio_mask,
                                           gpio_function_t fn);
__attribute__((weak)) void gpio_set_function_masked64(uint64_t gpio_mask,
                                                      gpio_function_t fn)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_function_masked64(uint64_t gpio_mask,
                                                 gpio_function_t fn)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_function_masked64=__weak_gpio_set_function_masked64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_function_masked64=_weak_gpio_set_function_masked64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_inover(uint gpio, uint value);
__attribute__((weak)) void gpio_set_inover(uint gpio, uint value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_inover(uint gpio, uint value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_inover=__weak_gpio_set_inover")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_inover=_weak_gpio_set_inover")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_input_enabled(uint gpio, bool enabled);
__attribute__((weak)) void gpio_set_input_enabled(uint gpio, bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_input_enabled(uint gpio, bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_input_enabled=__weak_gpio_set_input_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_input_enabled=_weak_gpio_set_input_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_input_hysteresis_enabled(uint gpio, bool enabled);
__attribute__((weak)) void gpio_set_input_hysteresis_enabled(uint gpio,
                                                             bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_input_hysteresis_enabled(uint gpio, bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_input_hysteresis_enabled=__weak_gpio_set_input_hysteresis_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_input_hysteresis_enabled=_weak_gpio_set_input_hysteresis_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_irq_callback(gpio_irq_callback_t callback);
__attribute__((weak)) void gpio_set_irq_callback(gpio_irq_callback_t callback)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_irq_callback(gpio_irq_callback_t callback)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_irq_callback=__weak_gpio_set_irq_callback")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_irq_callback=_weak_gpio_set_irq_callback")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_irq_enabled(uint gpio, uint32_t event_mask,
                                     bool enabled);
__attribute__((weak)) void gpio_set_irq_enabled(uint gpio, uint32_t event_mask,
                                                bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_irq_enabled(uint gpio, uint32_t event_mask,
                                           bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_irq_enabled=__weak_gpio_set_irq_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:gpio_set_irq_enabled=_weak_gpio_set_irq_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_irq_enabled_with_callback(
    uint gpio, uint32_t event_mask, bool enabled, gpio_irq_callback_t callback);
__attribute__((weak)) void gpio_set_irq_enabled_with_callback(
    uint gpio, uint32_t event_mask, bool enabled, gpio_irq_callback_t callback)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_irq_enabled_with_callback(
    uint gpio, uint32_t event_mask, bool enabled, gpio_irq_callback_t callback)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_gpio_set_irq_enabled_with_callback=__weak_gpio_set_irq_enabled_with_callback")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:gpio_set_irq_enabled_with_callback=_weak_gpio_set_irq_enabled_with_callback")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_irqover(uint gpio, uint value);
__attribute__((weak)) void gpio_set_irqover(uint gpio, uint value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_irqover(uint gpio, uint value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_irqover=__weak_gpio_set_irqover")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_set_irqover=_weak_gpio_set_irqover")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_mask(uint32_t mask);
__attribute__((weak)) void gpio_set_mask(uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_mask(uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_set_mask=__weak_gpio_set_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_mask=_weak_gpio_set_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_mask64(uint64_t mask);
__attribute__((weak)) void gpio_set_mask64(uint64_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_mask64(uint64_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_mask64=__weak_gpio_set_mask64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_mask64=_weak_gpio_set_mask64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_mask_n(uint n, uint32_t mask);
__attribute__((weak)) void gpio_set_mask_n(uint n, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_mask_n(uint n, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_mask_n=__weak_gpio_set_mask_n")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_mask_n=_weak_gpio_set_mask_n")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_oeover(uint gpio, uint value);
__attribute__((weak)) void gpio_set_oeover(uint gpio, uint value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_oeover(uint gpio, uint value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_oeover=__weak_gpio_set_oeover")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_oeover=_weak_gpio_set_oeover")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_outover(uint gpio, uint value);
__attribute__((weak)) void gpio_set_outover(uint gpio, uint value)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_outover(uint gpio, uint value)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_set_outover=__weak_gpio_set_outover")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_set_outover=_weak_gpio_set_outover")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_pulls(uint gpio, bool up, bool down);
__attribute__((weak)) void gpio_set_pulls(uint gpio, bool up, bool down)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_pulls(uint gpio, bool up, bool down)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_set_pulls=__weak_gpio_set_pulls")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_set_pulls=_weak_gpio_set_pulls")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew);
__attribute__((weak)) void gpio_set_slew_rate(uint gpio,
                                              enum gpio_slew_rate slew)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_gpio_set_slew_rate=__weak_gpio_set_slew_rate")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:gpio_set_slew_rate=_weak_gpio_set_slew_rate")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_xor_mask(uint32_t mask);
__attribute__((weak)) void gpio_xor_mask(uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_xor_mask(uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_gpio_xor_mask=__weak_gpio_xor_mask")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_xor_mask=_weak_gpio_xor_mask")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_xor_mask64(uint64_t mask);
__attribute__((weak)) void gpio_xor_mask64(uint64_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_xor_mask64(uint64_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_xor_mask64=__weak_gpio_xor_mask64")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_xor_mask64=_weak_gpio_xor_mask64")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void gpio_xor_mask_n(uint n, uint32_t mask);
__attribute__((weak)) void gpio_xor_mask_n(uint n, uint32_t mask)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_gpio_xor_mask_n(uint n, uint32_t mask)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_gpio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_gpio_xor_mask_n=__weak_gpio_xor_mask_n")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:gpio_xor_mask_n=_weak_gpio_xor_mask_n")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool check_sys_clock_hz(uint32_t freq_hz, uint* vco_freq_out,
                                   uint* post_div1_out, uint* post_div2_out);
__attribute__((weak)) bool check_sys_clock_hz(uint32_t freq_hz,
                                              uint* vco_freq_out,
                                              uint* post_div1_out,
                                              uint* post_div2_out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_check_sys_clock_hz(uint32_t freq_hz, uint* vco_freq_out,
                                         uint* post_div1_out,
                                         uint* post_div2_out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_check_sys_clock_hz=__weak_check_sys_clock_hz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:check_sys_clock_hz=_weak_check_sys_clock_hz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool check_sys_clock_khz(uint32_t freq_khz, uint* vco_freq_out,
                                    uint* post_div1_out, uint* post_div2_out);
__attribute__((weak)) bool check_sys_clock_khz(uint32_t freq_khz,
                                               uint* vco_freq_out,
                                               uint* post_div1_out,
                                               uint* post_div2_out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_check_sys_clock_khz(uint32_t freq_khz, uint* vco_freq_out,
                                          uint* post_div1_out,
                                          uint* post_div2_out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_check_sys_clock_khz=__weak_check_sys_clock_khz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:check_sys_clock_khz=_weak_check_sys_clock_khz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool clock_configure(clock_handle_t clock, uint32_t src,
                                uint32_t auxsrc, uint32_t src_freq,
                                uint32_t freq);
__attribute__((weak)) bool clock_configure(clock_handle_t clock, uint32_t src,
                                           uint32_t auxsrc, uint32_t src_freq,
                                           uint32_t freq)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_clock_configure(clock_handle_t clock, uint32_t src,
                                      uint32_t auxsrc, uint32_t src_freq,
                                      uint32_t freq)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_clock_configure=__weak_clock_configure")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:clock_configure=_weak_clock_configure")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool clock_configure_gpin(clock_handle_t clock, uint gpio,
                                     uint32_t src_freq, uint32_t freq);
__attribute__((weak)) bool clock_configure_gpin(clock_handle_t clock, uint gpio,
                                                uint32_t src_freq,
                                                uint32_t freq)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_clock_configure_gpin(clock_handle_t clock, uint gpio,
                                           uint32_t src_freq, uint32_t freq)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_clock_configure_gpin=__weak_clock_configure_gpin")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:clock_configure_gpin=_weak_clock_configure_gpin")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_configure_int_divider(clock_handle_t clock, uint32_t src,
                                            uint32_t auxsrc, uint32_t src_freq,
                                            uint32_t int_divider);
__attribute__((weak)) void clock_configure_int_divider(clock_handle_t clock,
                                                       uint32_t src,
                                                       uint32_t auxsrc,
                                                       uint32_t src_freq,
                                                       uint32_t int_divider)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_configure_int_divider(clock_handle_t clock,
                                                  uint32_t src, uint32_t auxsrc,
                                                  uint32_t src_freq,
                                                  uint32_t int_divider)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_clock_configure_int_divider=__weak_clock_configure_int_divider")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:clock_configure_int_divider=_weak_clock_configure_int_divider")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_configure_undivided(clock_handle_t clock, uint32_t src,
                                          uint32_t auxsrc, uint32_t src_freq);
__attribute__((weak)) void clock_configure_undivided(clock_handle_t clock,
                                                     uint32_t src,
                                                     uint32_t auxsrc,
                                                     uint32_t src_freq)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_configure_undivided(clock_handle_t clock,
                                                uint32_t src, uint32_t auxsrc,
                                                uint32_t src_freq)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_clock_configure_undivided=__weak_clock_configure_undivided")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:clock_configure_undivided=_weak_clock_configure_undivided")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t clock_get_hz(clock_handle_t clock);
__attribute__((weak)) uint32_t clock_get_hz(clock_handle_t clock)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_clock_get_hz(clock_handle_t clock)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_clock_get_hz=__weak_clock_get_hz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:clock_get_hz=_weak_clock_get_hz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_gpio_init(uint gpio, uint src, float div);
__attribute__((weak)) void clock_gpio_init(uint gpio, uint src, float div)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_gpio_init(uint gpio, uint src, float div)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_clock_gpio_init=__weak_clock_gpio_init")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:clock_gpio_init=_weak_clock_gpio_init")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_gpio_init_int_frac(uint gpio, uint src, uint32_t div_int,
                                         uint8_t div_frac);
__attribute__((weak)) void clock_gpio_init_int_frac(uint gpio, uint src,
                                                    uint32_t div_int,
                                                    uint8_t div_frac)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_gpio_init_int_frac(uint gpio, uint src,
                                               uint32_t div_int,
                                               uint8_t div_frac)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_clock_gpio_init_int_frac=__weak_clock_gpio_init_int_frac")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:clock_gpio_init_int_frac=_weak_clock_gpio_init_int_frac")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_set_reported_hz(clock_handle_t clock, uint hz);
__attribute__((weak)) void clock_set_reported_hz(clock_handle_t clock, uint hz)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_set_reported_hz(clock_handle_t clock, uint hz)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_clock_set_reported_hz=__weak_clock_set_reported_hz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:clock_set_reported_hz=_weak_clock_set_reported_hz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clock_stop(clock_handle_t clock);
__attribute__((weak)) void clock_stop(clock_handle_t clock)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clock_stop(clock_handle_t clock)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_clock_stop=__weak_clock_stop")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:clock_stop=_weak_clock_stop")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void clocks_enable_resus(resus_callback_t resus_callback);
__attribute__((weak)) void clocks_enable_resus(resus_callback_t resus_callback)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_clocks_enable_resus(resus_callback_t resus_callback)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_clocks_enable_resus=__weak_clocks_enable_resus")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:clocks_enable_resus=_weak_clocks_enable_resus")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t frequency_count_khz(uint src);
__attribute__((weak)) uint32_t frequency_count_khz(uint src)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_frequency_count_khz(uint src)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_frequency_count_khz=__weak_frequency_count_khz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:frequency_count_khz=_weak_frequency_count_khz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" float frequency_count_mhz(uint src);
__attribute__((weak)) float frequency_count_mhz(uint src)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" float _weak_frequency_count_mhz(uint src)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_frequency_count_mhz=__weak_frequency_count_mhz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:frequency_count_mhz=_weak_frequency_count_mhz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void set_sys_clock_48mhz(void);
__attribute__((weak)) void set_sys_clock_48mhz(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_set_sys_clock_48mhz(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_set_sys_clock_48mhz=__weak_set_sys_clock_48mhz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:set_sys_clock_48mhz=_weak_set_sys_clock_48mhz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool set_sys_clock_hz(uint32_t freq_hz, bool required);
__attribute__((weak)) bool set_sys_clock_hz(uint32_t freq_hz, bool required)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_set_sys_clock_hz(uint32_t freq_hz, bool required)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_set_sys_clock_hz=__weak_set_sys_clock_hz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:set_sys_clock_hz=_weak_set_sys_clock_hz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool set_sys_clock_khz(uint32_t freq_khz, bool required);
__attribute__((weak)) bool set_sys_clock_khz(uint32_t freq_khz, bool required)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_set_sys_clock_khz(uint32_t freq_khz, bool required)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_set_sys_clock_khz=__weak_set_sys_clock_khz")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:set_sys_clock_khz=_weak_set_sys_clock_khz")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void set_sys_clock_pll(uint32_t vco_freq, uint post_div1,
                                  uint post_div2);
__attribute__((weak)) void set_sys_clock_pll(uint32_t vco_freq, uint post_div1,
                                             uint post_div2)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_set_sys_clock_pll(uint32_t vco_freq, uint post_div1,
                                        uint post_div2)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The hardware_clocks library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_set_sys_clock_pll=__weak_set_sys_clock_pll")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:set_sys_clock_pll=_weak_set_sys_clock_pll")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int64_t absolute_time_diff_us(absolute_time_t from,
                                         absolute_time_t to);
__attribute__((weak)) int64_t absolute_time_diff_us(absolute_time_t from,
                                                    absolute_time_t to)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int64_t _weak_absolute_time_diff_us(absolute_time_t from,
                                               absolute_time_t to)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_absolute_time_diff_us=__weak_absolute_time_diff_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:absolute_time_diff_us=_weak_absolute_time_diff_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t absolute_time_min(absolute_time_t a,
                                             absolute_time_t b);
__attribute__((weak)) absolute_time_t absolute_time_min(absolute_time_t a,
                                                        absolute_time_t b)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_absolute_time_min(absolute_time_t a,
                                                   absolute_time_t b)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_absolute_time_min=__weak_absolute_time_min")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:absolute_time_min=_weak_absolute_time_min")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t add_alarm_at(absolute_time_t time,
                                   alarm_callback_t callback, void* user_data,
                                   bool fire_if_past);
__attribute__((weak)) alarm_id_t add_alarm_at(absolute_time_t time,
                                              alarm_callback_t callback,
                                              void* user_data,
                                              bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_add_alarm_at(absolute_time_t time,
                                         alarm_callback_t callback,
                                         void* user_data, bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_add_alarm_at=__weak_add_alarm_at")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:add_alarm_at=_weak_add_alarm_at")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t add_alarm_in_ms(uint32_t ms, alarm_callback_t callback,
                                      void* user_data, bool fire_if_past);
__attribute__((weak)) alarm_id_t add_alarm_in_ms(uint32_t ms,
                                                 alarm_callback_t callback,
                                                 void* user_data,
                                                 bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_add_alarm_in_ms(uint32_t ms,
                                            alarm_callback_t callback,
                                            void* user_data, bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_add_alarm_in_ms=__weak_add_alarm_in_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:add_alarm_in_ms=_weak_add_alarm_in_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t add_alarm_in_us(uint64_t us, alarm_callback_t callback,
                                      void* user_data, bool fire_if_past);
__attribute__((weak)) alarm_id_t add_alarm_in_us(uint64_t us,
                                                 alarm_callback_t callback,
                                                 void* user_data,
                                                 bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_add_alarm_in_us(uint64_t us,
                                            alarm_callback_t callback,
                                            void* user_data, bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_add_alarm_in_us=__weak_add_alarm_in_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:add_alarm_in_us=_weak_add_alarm_in_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool add_repeating_timer_ms(int32_t delay_ms,
                                       repeating_timer_callback_t callback,
                                       void* user_data, repeating_timer_t* out);
__attribute__((weak)) bool add_repeating_timer_ms(
    int32_t delay_ms, repeating_timer_callback_t callback, void* user_data,
    repeating_timer_t* out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_add_repeating_timer_ms(
    int32_t delay_ms, repeating_timer_callback_t callback, void* user_data,
    repeating_timer_t* out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_add_repeating_timer_ms=__weak_add_repeating_timer_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:add_repeating_timer_ms=_weak_add_repeating_timer_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool add_repeating_timer_us(int64_t delay_us,
                                       repeating_timer_callback_t callback,
                                       void* user_data, repeating_timer_t* out);
__attribute__((weak)) bool add_repeating_timer_us(
    int64_t delay_us, repeating_timer_callback_t callback, void* user_data,
    repeating_timer_t* out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_add_repeating_timer_us(
    int64_t delay_us, repeating_timer_callback_t callback, void* user_data,
    repeating_timer_t* out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_add_repeating_timer_us=__weak_add_repeating_timer_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:add_repeating_timer_us=_weak_add_repeating_timer_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t alarm_pool_add_alarm_at(alarm_pool_t* pool,
                                              absolute_time_t time,
                                              alarm_callback_t callback,
                                              void* user_data,
                                              bool fire_if_past);
__attribute__((weak)) alarm_id_t alarm_pool_add_alarm_at(
    alarm_pool_t* pool, absolute_time_t time, alarm_callback_t callback,
    void* user_data, bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_alarm_pool_add_alarm_at(alarm_pool_t* pool,
                                                    absolute_time_t time,
                                                    alarm_callback_t callback,
                                                    void* user_data,
                                                    bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_alarm_at=__weak_alarm_pool_add_alarm_at")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_alarm_at=_weak_alarm_pool_add_alarm_at")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t alarm_pool_add_alarm_at_force_in_context(
    alarm_pool_t* pool, absolute_time_t time, alarm_callback_t callback,
    void* user_data);
__attribute__((weak)) alarm_id_t alarm_pool_add_alarm_at_force_in_context(
    alarm_pool_t* pool, absolute_time_t time, alarm_callback_t callback,
    void* user_data)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_alarm_pool_add_alarm_at_force_in_context(
    alarm_pool_t* pool, absolute_time_t time, alarm_callback_t callback,
    void* user_data)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_alarm_at_force_in_context=__weak_alarm_pool_add_alarm_at_force_in_context")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_alarm_at_force_in_context=_weak_alarm_pool_add_alarm_at_force_in_context")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t alarm_pool_add_alarm_in_ms(alarm_pool_t* pool,
                                                 uint32_t ms,
                                                 alarm_callback_t callback,
                                                 void* user_data,
                                                 bool fire_if_past);
__attribute__((weak)) alarm_id_t alarm_pool_add_alarm_in_ms(
    alarm_pool_t* pool, uint32_t ms, alarm_callback_t callback, void* user_data,
    bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_alarm_pool_add_alarm_in_ms(
    alarm_pool_t* pool, uint32_t ms, alarm_callback_t callback, void* user_data,
    bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_alarm_in_ms=__weak_alarm_pool_add_alarm_in_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_alarm_in_ms=_weak_alarm_pool_add_alarm_in_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_id_t alarm_pool_add_alarm_in_us(alarm_pool_t* pool,
                                                 uint64_t us,
                                                 alarm_callback_t callback,
                                                 void* user_data,
                                                 bool fire_if_past);
__attribute__((weak)) alarm_id_t alarm_pool_add_alarm_in_us(
    alarm_pool_t* pool, uint64_t us, alarm_callback_t callback, void* user_data,
    bool fire_if_past)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_id_t _weak_alarm_pool_add_alarm_in_us(
    alarm_pool_t* pool, uint64_t us, alarm_callback_t callback, void* user_data,
    bool fire_if_past)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_alarm_in_us=__weak_alarm_pool_add_alarm_in_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_alarm_in_us=_weak_alarm_pool_add_alarm_in_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool alarm_pool_add_repeating_timer_ms(
    alarm_pool_t* pool, int32_t delay_ms, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out);
__attribute__((weak)) bool alarm_pool_add_repeating_timer_ms(
    alarm_pool_t* pool, int32_t delay_ms, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_alarm_pool_add_repeating_timer_ms(
    alarm_pool_t* pool, int32_t delay_ms, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_repeating_timer_ms=__weak_alarm_pool_add_repeating_timer_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_repeating_timer_ms=_weak_alarm_pool_add_repeating_timer_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool alarm_pool_add_repeating_timer_us(
    alarm_pool_t* pool, int64_t delay_us, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out);
__attribute__((weak)) bool alarm_pool_add_repeating_timer_us(
    alarm_pool_t* pool, int64_t delay_us, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_alarm_pool_add_repeating_timer_us(
    alarm_pool_t* pool, int64_t delay_us, repeating_timer_callback_t callback,
    void* user_data, repeating_timer_t* out)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_add_repeating_timer_us=__weak_alarm_pool_add_repeating_timer_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_add_repeating_timer_us=_weak_alarm_pool_add_repeating_timer_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool alarm_pool_cancel_alarm(alarm_pool_t* pool,
                                        alarm_id_t alarm_id);
__attribute__((weak)) bool alarm_pool_cancel_alarm(alarm_pool_t* pool,
                                                   alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_alarm_pool_cancel_alarm(alarm_pool_t* pool,
                                              alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_cancel_alarm=__weak_alarm_pool_cancel_alarm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_cancel_alarm=_weak_alarm_pool_cancel_alarm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint alarm_pool_core_num(alarm_pool_t* pool);
__attribute__((weak)) uint alarm_pool_core_num(alarm_pool_t* pool)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_alarm_pool_core_num(alarm_pool_t* pool)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_alarm_pool_core_num=__weak_alarm_pool_core_num")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:alarm_pool_core_num=_weak_alarm_pool_core_num")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_t* alarm_pool_create(uint timer_alarm_num,
                                           uint max_timers);
__attribute__((weak)) alarm_pool_t* alarm_pool_create(uint timer_alarm_num,
                                                      uint max_timers)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_t* _weak_alarm_pool_create(uint timer_alarm_num,
                                                 uint max_timers)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_alarm_pool_create=__weak_alarm_pool_create")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:alarm_pool_create=_weak_alarm_pool_create")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_t* alarm_pool_create_on_timer(alarm_pool_timer_t* timer,
                                                    uint timer_alarm_num,
                                                    uint max_timers);
__attribute__((weak)) alarm_pool_t* alarm_pool_create_on_timer(
    alarm_pool_timer_t* timer, uint timer_alarm_num, uint max_timers)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_t* _weak_alarm_pool_create_on_timer(
    alarm_pool_timer_t* timer, uint timer_alarm_num, uint max_timers)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_create_on_timer=__weak_alarm_pool_create_on_timer")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_create_on_timer=_weak_alarm_pool_create_on_timer")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_t* alarm_pool_create_on_timer_with_unused_hardware_alarm(
    alarm_pool_timer_t* timer, uint max_timers);
__attribute__((weak)) alarm_pool_t*
alarm_pool_create_on_timer_with_unused_hardware_alarm(alarm_pool_timer_t* timer,
                                                      uint max_timers)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_t*
_weak_alarm_pool_create_on_timer_with_unused_hardware_alarm(
    alarm_pool_timer_t* timer, uint max_timers)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_create_on_timer_with_unused_hardware_alarm=__weak_alarm_pool_create_on_timer_with_unused_hardware_alarm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_create_on_timer_with_unused_hardware_alarm=_weak_alarm_pool_create_on_timer_with_unused_hardware_alarm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_t* alarm_pool_create_with_unused_hardware_alarm(
    uint max_timers);
__attribute__((weak)) alarm_pool_t*
alarm_pool_create_with_unused_hardware_alarm(uint max_timers)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_t* _weak_alarm_pool_create_with_unused_hardware_alarm(
    uint max_timers)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_create_with_unused_hardware_alarm=__weak_alarm_pool_create_with_unused_hardware_alarm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_create_with_unused_hardware_alarm=_weak_alarm_pool_create_with_unused_hardware_alarm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void alarm_pool_destroy(alarm_pool_t* pool);
__attribute__((weak)) void alarm_pool_destroy(alarm_pool_t* pool)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_alarm_pool_destroy(alarm_pool_t* pool)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_alarm_pool_destroy=__weak_alarm_pool_destroy")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:alarm_pool_destroy=_weak_alarm_pool_destroy")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_t* alarm_pool_get_default(void);
__attribute__((weak)) alarm_pool_t* alarm_pool_get_default(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_t* _weak_alarm_pool_get_default(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_get_default=__weak_alarm_pool_get_default")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_get_default=_weak_alarm_pool_get_default")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_timer_t* alarm_pool_get_default_timer(void);
__attribute__((weak)) alarm_pool_timer_t* alarm_pool_get_default_timer(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_timer_t* _weak_alarm_pool_get_default_timer(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_get_default_timer=__weak_alarm_pool_get_default_timer")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_get_default_timer=_weak_alarm_pool_get_default_timer")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint alarm_pool_hardware_alarm_num(alarm_pool_t* pool);
__attribute__((weak)) uint alarm_pool_hardware_alarm_num(alarm_pool_t* pool)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_alarm_pool_hardware_alarm_num(alarm_pool_t* pool)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_hardware_alarm_num=__weak_alarm_pool_hardware_alarm_num")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_hardware_alarm_num=_weak_alarm_pool_hardware_alarm_num")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void alarm_pool_init_default(void);
__attribute__((weak)) void alarm_pool_init_default(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_alarm_pool_init_default(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_init_default=__weak_alarm_pool_init_default")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_init_default=_weak_alarm_pool_init_default")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int32_t alarm_pool_remaining_alarm_time_ms(alarm_pool_t* pool,
                                                      alarm_id_t alarm_id);
__attribute__((weak)) int32_t
alarm_pool_remaining_alarm_time_ms(alarm_pool_t* pool, alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int32_t _weak_alarm_pool_remaining_alarm_time_ms(alarm_pool_t* pool,
                                                            alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_remaining_alarm_time_ms=__weak_alarm_pool_remaining_alarm_time_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_remaining_alarm_time_ms=_weak_alarm_pool_remaining_alarm_time_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int64_t alarm_pool_remaining_alarm_time_us(alarm_pool_t* pool,
                                                      alarm_id_t alarm_id);
__attribute__((weak)) int64_t
alarm_pool_remaining_alarm_time_us(alarm_pool_t* pool, alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int64_t _weak_alarm_pool_remaining_alarm_time_us(alarm_pool_t* pool,
                                                            alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_remaining_alarm_time_us=__weak_alarm_pool_remaining_alarm_time_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_remaining_alarm_time_us=_weak_alarm_pool_remaining_alarm_time_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint alarm_pool_timer_alarm_num(alarm_pool_t* pool);
__attribute__((weak)) uint alarm_pool_timer_alarm_num(alarm_pool_t* pool)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint _weak_alarm_pool_timer_alarm_num(alarm_pool_t* pool)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_timer_alarm_num=__weak_alarm_pool_timer_alarm_num")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_timer_alarm_num=_weak_alarm_pool_timer_alarm_num")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" alarm_pool_timer_t* alarm_pool_timer_for_timer_num(uint timer_num);
__attribute__((weak)) alarm_pool_timer_t* alarm_pool_timer_for_timer_num(
    uint timer_num)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" alarm_pool_timer_t* _weak_alarm_pool_timer_for_timer_num(
    uint timer_num)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_alarm_pool_timer_for_timer_num=__weak_alarm_pool_timer_for_timer_num")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:alarm_pool_timer_for_timer_num=_weak_alarm_pool_timer_for_timer_num")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool best_effort_wfe_or_timeout(absolute_time_t timeout_timestamp);
__attribute__((weak)) bool best_effort_wfe_or_timeout(
    absolute_time_t timeout_timestamp)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_best_effort_wfe_or_timeout(
    absolute_time_t timeout_timestamp)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_best_effort_wfe_or_timeout=__weak_best_effort_wfe_or_timeout")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:best_effort_wfe_or_timeout=_weak_best_effort_wfe_or_timeout")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool cancel_alarm(alarm_id_t alarm_id);
__attribute__((weak)) bool cancel_alarm(alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_cancel_alarm(alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_cancel_alarm=__weak_cancel_alarm")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:cancel_alarm=_weak_cancel_alarm")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool cancel_repeating_timer(repeating_timer_t* timer);
__attribute__((weak)) bool cancel_repeating_timer(repeating_timer_t* timer)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_cancel_repeating_timer(repeating_timer_t* timer)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_cancel_repeating_timer=__weak_cancel_repeating_timer")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:cancel_repeating_timer=_weak_cancel_repeating_timer")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t delayed_by_ms(const absolute_time_t t, uint32_t ms);
__attribute__((weak)) absolute_time_t delayed_by_ms(const absolute_time_t t,
                                                    uint32_t ms)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_delayed_by_ms(const absolute_time_t t,
                                               uint32_t ms)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_delayed_by_ms=__weak_delayed_by_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:delayed_by_ms=_weak_delayed_by_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t delayed_by_us(const absolute_time_t t, uint64_t us);
__attribute__((weak)) absolute_time_t delayed_by_us(const absolute_time_t t,
                                                    uint64_t us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_delayed_by_us(const absolute_time_t t,
                                               uint64_t us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_delayed_by_us=__weak_delayed_by_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:delayed_by_us=_weak_delayed_by_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t get_absolute_time(void);
__attribute__((weak)) absolute_time_t get_absolute_time(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_get_absolute_time(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_get_absolute_time=__weak_get_absolute_time")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:get_absolute_time=_weak_get_absolute_time")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool is_at_the_end_of_time(absolute_time_t t);
__attribute__((weak)) bool is_at_the_end_of_time(absolute_time_t t)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_is_at_the_end_of_time(absolute_time_t t)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_is_at_the_end_of_time=__weak_is_at_the_end_of_time")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:is_at_the_end_of_time=_weak_is_at_the_end_of_time")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool is_nil_time(absolute_time_t t);
__attribute__((weak)) bool is_nil_time(absolute_time_t t)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_is_nil_time(absolute_time_t t)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_is_nil_time=__weak_is_nil_time")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:is_nil_time=_weak_is_nil_time")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t make_timeout_time_ms(uint32_t ms);
__attribute__((weak)) absolute_time_t make_timeout_time_ms(uint32_t ms)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_make_timeout_time_ms(uint32_t ms)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_make_timeout_time_ms=__weak_make_timeout_time_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:make_timeout_time_ms=_weak_make_timeout_time_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" absolute_time_t make_timeout_time_us(uint64_t us);
__attribute__((weak)) absolute_time_t make_timeout_time_us(uint64_t us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" absolute_time_t _weak_make_timeout_time_us(uint64_t us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_make_timeout_time_us=__weak_make_timeout_time_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:make_timeout_time_us=_weak_make_timeout_time_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int32_t remaining_alarm_time_ms(alarm_id_t alarm_id);
__attribute__((weak)) int32_t remaining_alarm_time_ms(alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int32_t _weak_remaining_alarm_time_ms(alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_remaining_alarm_time_ms=__weak_remaining_alarm_time_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:remaining_alarm_time_ms=_weak_remaining_alarm_time_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int64_t remaining_alarm_time_us(alarm_id_t alarm_id);
__attribute__((weak)) int64_t remaining_alarm_time_us(alarm_id_t alarm_id)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int64_t _weak_remaining_alarm_time_us(alarm_id_t alarm_id)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_remaining_alarm_time_us=__weak_remaining_alarm_time_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:remaining_alarm_time_us=_weak_remaining_alarm_time_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void runtime_init_default_alarm_pool(void);
__attribute__((weak)) void runtime_init_default_alarm_pool(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_runtime_init_default_alarm_pool(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_runtime_init_default_alarm_pool=__weak_runtime_init_default_alarm_pool")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:runtime_init_default_alarm_pool=_weak_runtime_init_default_alarm_pool")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sleep_ms(uint32_t ms);
__attribute__((weak)) void sleep_ms(uint32_t ms)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sleep_ms(uint32_t ms)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_sleep_ms=__weak_sleep_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:sleep_ms=_weak_sleep_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sleep_until(absolute_time_t target);
__attribute__((weak)) void sleep_until(absolute_time_t target)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sleep_until(absolute_time_t target)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_sleep_until=__weak_sleep_until")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:sleep_until=_weak_sleep_until")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void sleep_us(uint64_t us);
__attribute__((weak)) void sleep_us(uint64_t us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_sleep_us(uint64_t us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_sleep_us=__weak_sleep_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:sleep_us=_weak_sleep_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t to_ms_since_boot(absolute_time_t t);
__attribute__((weak)) uint32_t to_ms_since_boot(absolute_time_t t)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_to_ms_since_boot(absolute_time_t t)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_to_ms_since_boot=__weak_to_ms_since_boot")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:to_ms_since_boot=_weak_to_ms_since_boot")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" uint32_t us_to_ms(uint64_t us);
__attribute__((weak)) uint32_t us_to_ms(uint64_t us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" uint32_t _weak_us_to_ms(uint64_t us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_time library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_us_to_ms=__weak_us_to_ms")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:us_to_ms=_weak_us_to_ms")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int getchar_timeout_us(uint32_t timeout_us);
__attribute__((weak)) int getchar_timeout_us(uint32_t timeout_us)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_getchar_timeout_us(uint32_t timeout_us)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_getchar_timeout_us=__weak_getchar_timeout_us")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:getchar_timeout_us=_weak_getchar_timeout_us")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int putchar_raw(int c);
__attribute__((weak)) int putchar_raw(int c)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_putchar_raw(int c)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_putchar_raw=__weak_putchar_raw")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:putchar_raw=_weak_putchar_raw")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int puts_raw(const char* s);
__attribute__((weak)) int puts_raw(const char* s)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_puts_raw(const char* s)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_puts_raw=__weak_puts_raw")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:puts_raw=_weak_puts_raw")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool stdio_deinit_all(void);
__attribute__((weak)) bool stdio_deinit_all(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_stdio_deinit_all(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_stdio_deinit_all=__weak_stdio_deinit_all")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:stdio_deinit_all=_weak_stdio_deinit_all")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void stdio_filter_driver(stdio_driver_t* driver);
__attribute__((weak)) void stdio_filter_driver(stdio_driver_t* driver)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_stdio_filter_driver(stdio_driver_t* driver)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker, "/alternatename:_stdio_filter_driver=__weak_stdio_filter_driver")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker, "/alternatename:stdio_filter_driver=_weak_stdio_filter_driver")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void stdio_flush(void);
__attribute__((weak)) void stdio_flush(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_stdio_flush(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_stdio_flush=__weak_stdio_flush")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:stdio_flush=_weak_stdio_flush")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int stdio_get_until(char* buf, int len, absolute_time_t until);
__attribute__((weak)) int stdio_get_until(char* buf, int len,
                                          absolute_time_t until)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_stdio_get_until(char* buf, int len, absolute_time_t until)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_stdio_get_until=__weak_stdio_get_until")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:stdio_get_until=_weak_stdio_get_until")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" bool stdio_init_all(void);
__attribute__((weak)) bool stdio_init_all(void)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" bool _weak_stdio_init_all(void)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, "/alternatename:_stdio_init_all=__weak_stdio_init_all")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, "/alternatename:stdio_init_all=_weak_stdio_init_all")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" int stdio_put_string(const char* s, int len, bool newline,
                                bool cr_translation);
__attribute__((weak)) int stdio_put_string(const char* s, int len, bool newline,
                                           bool cr_translation)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" int _weak_stdio_put_string(const char* s, int len, bool newline,
                                      bool cr_translation)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment(linker, \
                "/alternatename:_stdio_put_string=__weak_stdio_put_string")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment(linker, \
                "/alternatename:stdio_put_string=_weak_stdio_put_string")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void stdio_set_driver_enabled(stdio_driver_t* driver, bool enabled);
__attribute__((weak)) void stdio_set_driver_enabled(stdio_driver_t* driver,
                                                    bool enabled)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_stdio_set_driver_enabled(stdio_driver_t* driver,
                                               bool enabled)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_stdio_set_driver_enabled=__weak_stdio_set_driver_enabled")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:stdio_set_driver_enabled=_weak_stdio_set_driver_enabled")
#endif  // x86 or amd64
#endif  // _MSC_VER
// --------------------------------------------------
#if defined(__GNUC__) || defined(__clang__)  // Compiler detection
extern "C" void stdio_set_translate_crlf(stdio_driver_t* driver,
                                         bool translate);
__attribute__((weak)) void stdio_set_translate_crlf(stdio_driver_t* driver,
                                                    bool translate)
#elif defined(_MSC_VER)  // Microsoft Visual C
extern "C" void _weak_stdio_set_translate_crlf(stdio_driver_t* driver,
                                               bool translate)
#else                    // Other compilers are not supported
#error "Unknown compiler."
#endif  // Compiler detection
{
  assert(false &&
         "Error : The pico_stdio library is missing in the link phase.");
}
#if defined(_MSC_VER)  // weak binding in MSVC must be after definition
#if defined(_M_IX86)   // for x86
#pragma comment( \
    linker,      \
    "/alternatename:_stdio_set_translate_crlf=__weak_stdio_set_translate_crlf")
#elif defined(_M_AMD64)  // for AMD64
#pragma comment( \
    linker,      \
    "/alternatename:stdio_set_translate_crlf=_weak_stdio_set_translate_crlf")
#endif  // x86 or amd64
#endif  // _MSC_VER
