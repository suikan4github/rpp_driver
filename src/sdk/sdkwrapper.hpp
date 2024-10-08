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
/// @brief Alternate definition for Google Test build.
enum pio_fifo_join { a, b };
/// @brief Alternate definition for Google Test build.
enum gpio_drive_strength { c, d };
/// @brief Alternate definition for Google Test build.
enum gpio_slew_rate { e, f };
/// @brief Alternate definition for Google Test build.
enum pio_mov_status_type { g, h };

/// @brief Alternate definition for Google Test build.
typedef int stdio_driver_t;
/// @brief Alternate definition for Google Test build.
typedef int alarm_id_t;
/// @brief Alternate definition for Google Test build.
typedef int alarm_pool_t;
/// @brief Alternate definition for Google Test build.
typedef int alarm_pool_timer_t;
/// @brief Alternate definition for Google Test build.
typedef int repeating_timer_t;
/// @brief Alternate definition for Google Test build.
typedef int alarm_callback_t;
/// @brief Alternate definition for Google Test build.
typedef int repeating_timer_callback_t;
/// @brief Alternate definition for Google Test build.
typedef int gpio_irq_callback_t;
/// @brief Alternate definition for Google Test build.
typedef int irq_handler_t;
/// @brief Alternate definition for Google Test build.
typedef int resus_callback_t;
/// @brief Alternate definition for Google Test build.
typedef int pio_interrupt_source_t;
/// @brief Alternate definition for Google Test build.
typedef int absolute_time_t;
/// @brief Alternate definition for Google Test build.
typedef int i2c_inst_t;
/// @brief Alternate definition for Google Test build.
typedef int i2c_hw_t;
/// @brief Alternate definition for Google Test build.
typedef int gpio_function_t;
/// @brief Alternate definition for Google Test build.
typedef unsigned int PIO;
/// @brief Alternate definition for Google Test build.
typedef unsigned int pio_sm_config;
/// @brief Alternate definition for Google Test build.
typedef unsigned int clock_handle_t;
/// @brief Alternate definition for Google Test build.
typedef unsigned int pio_program_t;
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
  virtual void i2c_deinit(i2c_inst_t *i2c);
  virtual uint i2c_get_dreq(i2c_inst_t *i2c, bool is_tx);
  virtual i2c_hw_t *i2c_get_hw(i2c_inst_t *i2c);
  virtual uint i2c_get_index(i2c_inst_t *i2c);
  virtual i2c_inst_t *i2c_get_instance(uint num);
  virtual size_t i2c_get_read_available(i2c_inst_t *i2c);
  virtual size_t i2c_get_write_available(i2c_inst_t *i2c);
  virtual uint i2c_init(i2c_inst_t *i2c, uint baudrate);
  virtual int i2c_read_blocking(i2c_inst_t *i2c, uint8_t addr, uint8_t *dst,
                                size_t len, bool nostop);
  virtual int i2c_read_blocking_until(i2c_inst_t *i2c, uint8_t addr,
                                      uint8_t *dst, size_t len, bool nostop,
                                      absolute_time_t until);
  virtual uint8_t i2c_read_byte_raw(i2c_inst_t *i2c);
  virtual void i2c_read_raw_blocking(i2c_inst_t *i2c, uint8_t *dst, size_t len);
  virtual int i2c_read_timeout_per_char_us(i2c_inst_t *i2c, uint8_t addr,
                                           uint8_t *dst, size_t len,
                                           bool nostop,
                                           uint timeout_per_char_us);
  virtual int i2c_read_timeout_us(i2c_inst_t *i2c, uint8_t addr, uint8_t *dst,
                                  size_t len, bool nostop, uint timeout_us);
  virtual uint i2c_set_baudrate(i2c_inst_t *i2c, uint baudrate);
  virtual void i2c_set_slave_mode(i2c_inst_t *i2c, bool slave, uint8_t addr);
  virtual int i2c_write_blocking(i2c_inst_t *i2c, uint8_t addr,
                                 const uint8_t *src, size_t len, bool nostop);
  virtual int i2c_write_blocking_until(i2c_inst_t *i2c, uint8_t addr,
                                       const uint8_t *src, size_t len,
                                       bool nostop, absolute_time_t until);
  virtual void i2c_write_byte_raw(i2c_inst_t *i2c, uint8_t value);
  virtual void i2c_write_raw_blocking(i2c_inst_t *i2c, const uint8_t *src,
                                      size_t len);
  virtual int i2c_write_timeout_per_char_us(i2c_inst_t *i2c, uint8_t addr,
                                            const uint8_t *src, size_t len,
                                            bool nostop,
                                            uint timeout_per_char_us);
  virtual int i2c_write_timeout_us(i2c_inst_t *i2c, uint8_t addr,
                                   const uint8_t *src, size_t len, bool nostop,
                                   uint timeout_us);
  virtual int pio_add_program(PIO pio, const pio_program_t *program);
  virtual int pio_add_program_at_offset(PIO pio, const pio_program_t *program,
                                        uint offset);
  virtual void pio_calculate_clkdiv_from_float(float div, uint16_t *div_int,
                                               uint8_t *div_frac);
  virtual bool pio_can_add_program(PIO pio, const pio_program_t *program);
  virtual bool pio_can_add_program_at_offset(PIO pio,
                                             const pio_program_t *program,
                                             uint offset);
  virtual bool pio_claim_free_sm_and_add_program(const pio_program_t *program,
                                                 PIO *pio, uint *sm,
                                                 uint *offset);
  virtual bool pio_claim_free_sm_and_add_program_for_gpio_range(
      const pio_program_t *program, PIO *pio, uint *sm, uint *offset,
      uint gpio_base, uint gpio_count, bool set_gpio_base);
  virtual void pio_claim_sm_mask(PIO pio, uint sm_mask);
  virtual int pio_claim_unused_sm(PIO pio, bool required);
  virtual void pio_clear_instruction_memory(PIO pio);
  virtual void pio_clkdiv_restart_sm_mask(PIO pio, uint32_t mask);
  virtual void pio_clkdiv_restart_sm_multi_mask(PIO pio, uint32_t mask_prev,
                                                uint32_t mask,
                                                uint32_t mask_next);
  virtual void pio_enable_sm_mask_in_sync(PIO pio, uint32_t mask);
  virtual void pio_enable_sm_multi_mask_in_sync(PIO pio, uint32_t mask_prev,
                                                uint32_t mask,
                                                uint32_t mask_next);
  virtual pio_sm_config pio_get_default_sm_config(void);
  virtual uint pio_get_dreq(PIO pio, uint sm, bool is_tx);
  virtual uint pio_get_funcsel(PIO pio);
  virtual uint pio_get_gpio_base(PIO pio);
  virtual uint pio_get_index(PIO pio);
  virtual PIO pio_get_instance(uint instance);
  virtual int pio_get_irq_num(PIO pio, uint irqn);
  virtual pio_interrupt_source_t pio_get_rx_fifo_not_empty_interrupt_source(
      uint sm);
  virtual pio_interrupt_source_t pio_get_tx_fifo_not_full_interrupt_source(
      uint sm);
  virtual void pio_gpio_init(PIO pio, uint pin);
  virtual void pio_interrupt_clear(PIO pio, uint pio_interrupt_num);
  virtual bool pio_interrupt_get(PIO pio, uint pio_interrupt_num);
  virtual void pio_remove_program(PIO pio, const pio_program_t *program,
                                  uint loaded_offset);
  virtual void pio_remove_program_and_unclaim_sm(const pio_program_t *program,
                                                 PIO pio, uint sm, uint offset);
  virtual void pio_restart_sm_mask(PIO pio, uint32_t mask);
  virtual int pio_set_gpio_base(PIO pio, uint gpio_base);
  virtual void pio_set_irq0_source_enabled(PIO pio,
                                           pio_interrupt_source_t source,
                                           bool enabled);
  virtual void pio_set_irq0_source_mask_enabled(PIO pio, uint32_t source_mask,
                                                bool enabled);
  virtual void pio_set_irq1_source_enabled(PIO pio,
                                           pio_interrupt_source_t source,
                                           bool enabled);
  virtual void pio_set_irq1_source_mask_enabled(PIO pio, uint32_t source_mask,
                                                bool enabled);
  virtual void pio_set_irqn_source_enabled(PIO pio, uint irq_index,
                                           pio_interrupt_source_t source,
                                           bool enabled);
  virtual void pio_set_irqn_source_mask_enabled(PIO pio, uint irq_index,
                                                uint32_t source_mask,
                                                bool enabled);
  virtual void pio_set_sm_mask_enabled(PIO pio, uint32_t mask, bool enabled);
  virtual void pio_set_sm_multi_mask_enabled(PIO pio, uint32_t mask_prev,
                                             uint32_t mask, uint32_t mask_next,
                                             bool enabled);
  virtual void pio_sm_claim(PIO pio, uint sm);
  virtual void pio_sm_clear_fifos(PIO pio, uint sm);
  virtual void pio_sm_clkdiv_restart(PIO pio, uint sm);
  virtual void pio_sm_drain_tx_fifo(PIO pio, uint sm);
  virtual void pio_sm_exec(PIO pio, uint sm, uint instr);
  virtual void pio_sm_exec_wait_blocking(PIO pio, uint sm, uint instr);
  virtual uint32_t pio_sm_get(PIO pio, uint sm);
  virtual uint32_t pio_sm_get_blocking(PIO pio, uint sm);
  virtual uint8_t pio_sm_get_pc(PIO pio, uint sm);
  virtual uint pio_sm_get_rx_fifo_level(PIO pio, uint sm);
  virtual uint pio_sm_get_tx_fifo_level(PIO pio, uint sm);
  virtual int pio_sm_init(PIO pio, uint sm, uint initial_pc,
                          const pio_sm_config *config);
  virtual bool pio_sm_is_claimed(PIO pio, uint sm);
  virtual bool pio_sm_is_exec_stalled(PIO pio, uint sm);
  virtual bool pio_sm_is_rx_fifo_empty(PIO pio, uint sm);
  virtual bool pio_sm_is_rx_fifo_full(PIO pio, uint sm);
  virtual bool pio_sm_is_tx_fifo_empty(PIO pio, uint sm);
  virtual bool pio_sm_is_tx_fifo_full(PIO pio, uint sm);
  virtual void pio_sm_put(PIO pio, uint sm, uint32_t data);
  virtual void pio_sm_put_blocking(PIO pio, uint sm, uint32_t data);
  virtual void pio_sm_restart(PIO pio, uint sm);
  virtual void pio_sm_set_clkdiv(PIO pio, uint sm, float div);
  virtual void pio_sm_set_clkdiv_int_frac(PIO pio, uint sm, uint16_t div_int,
                                          uint8_t div_frac);
  virtual int pio_sm_set_config(PIO pio, uint sm, const pio_sm_config *config);
  virtual int pio_sm_set_consecutive_pindirs(PIO pio, uint sm, uint pins_base,
                                             uint pin_count, bool is_out);
  virtual void pio_sm_set_enabled(PIO pio, uint sm, bool enabled);
  virtual void pio_sm_set_in_pins(PIO pio, uint sm, uint in_base);
  virtual void pio_sm_set_jmp_pin(PIO pio, uint sm, uint pin);
  virtual void pio_sm_set_out_pins(PIO pio, uint sm, uint out_base,
                                   uint out_count);
  virtual void pio_sm_set_pindirs_with_mask(PIO pio, uint sm, uint32_t pin_dirs,
                                            uint32_t pin_mask);
  virtual void pio_sm_set_pins(PIO pio, uint sm, uint32_t pin_values);
  virtual void pio_sm_set_pins_with_mask(PIO pio, uint sm, uint32_t pin_values,
                                         uint32_t pin_mask);
  virtual void pio_sm_set_set_pins(PIO pio, uint sm, uint set_base,
                                   uint set_count);
  virtual void pio_sm_set_sideset_pins(PIO pio, uint sm, uint sideset_base);
  virtual void pio_sm_set_wrap(PIO pio, uint sm, uint wrap_target, uint wrap);
  virtual void pio_sm_unclaim(PIO pio, uint sm);
  virtual void sm_config_set_clkdiv(pio_sm_config *c, float div);
  virtual void sm_config_set_clkdiv_int_frac(pio_sm_config *c, uint16_t div_int,
                                             uint8_t div_frac);
  virtual void sm_config_set_fifo_join(pio_sm_config *c,
                                       enum pio_fifo_join join);
  virtual void sm_config_set_in_pin_base(pio_sm_config *c, uint in_base);
  virtual void sm_config_set_in_pin_count(pio_sm_config *c, uint in_count);
  virtual void sm_config_set_in_pins(pio_sm_config *c, uint in_base);
  virtual void sm_config_set_in_shift(pio_sm_config *c, bool shift_right,
                                      bool autopush, uint push_threshold);
  virtual void sm_config_set_jmp_pin(pio_sm_config *c, uint pin);
  virtual void sm_config_set_mov_status(pio_sm_config *c,
                                        enum pio_mov_status_type status_sel,
                                        uint status_n);
  virtual void sm_config_set_out_pin_base(pio_sm_config *c, uint out_base);
  virtual void sm_config_set_out_pin_count(pio_sm_config *c, uint out_count);
  virtual void sm_config_set_out_pins(pio_sm_config *c, uint out_base,
                                      uint out_count);
  virtual void sm_config_set_out_shift(pio_sm_config *c, bool shift_right,
                                       bool autopull, uint pull_threshold);
  virtual void sm_config_set_out_special(pio_sm_config *c, bool sticky,
                                         bool has_enable_pin,
                                         uint enable_pin_index);
  virtual void sm_config_set_set_pin_base(pio_sm_config *c, uint set_base);
  virtual void sm_config_set_set_pin_count(pio_sm_config *c, uint set_count);
  virtual void sm_config_set_set_pins(pio_sm_config *c, uint set_base,
                                      uint set_count);
  virtual void sm_config_set_sideset(pio_sm_config *c, uint bit_count,
                                     bool optional, bool pindirs);
  virtual void sm_config_set_sideset_pin_base(pio_sm_config *c,
                                              uint sideset_base);
  virtual void sm_config_set_sideset_pins(pio_sm_config *c, uint sideset_base);
  virtual void sm_config_set_wrap(pio_sm_config *c, uint wrap_target,
                                  uint wrap);
  virtual void gpio_acknowledge_irq(uint gpio, uint32_t event_mask);
  virtual void gpio_add_raw_irq_handler(uint gpio, irq_handler_t handler);
  virtual void gpio_add_raw_irq_handler_masked(uint32_t gpio_mask,
                                               irq_handler_t handler);
  virtual void gpio_add_raw_irq_handler_masked64(uint64_t gpio_mask,
                                                 irq_handler_t handler);
  virtual void gpio_add_raw_irq_handler_with_order_priority(
      uint gpio, irq_handler_t handler, uint8_t order_priority);
  virtual void gpio_add_raw_irq_handler_with_order_priority_masked(
      uint32_t gpio_mask, irq_handler_t handler, uint8_t order_priority);
  virtual void gpio_add_raw_irq_handler_with_order_priority_masked64(
      uint64_t gpio_mask, irq_handler_t handler, uint8_t order_priority);
  virtual void gpio_assign_to_ns(uint gpio, bool ns);
  virtual void gpio_clr_mask(uint32_t mask);
  virtual void gpio_clr_mask64(uint64_t mask);
  virtual void gpio_clr_mask_n(uint n, uint32_t mask);
  virtual void gpio_debug_pins_init(void);
  virtual void gpio_deinit(uint gpio);
  virtual void gpio_disable_pulls(uint gpio);
  virtual bool gpio_get(uint gpio);
  virtual uint32_t gpio_get_all(void);
  virtual uint64_t gpio_get_all64(void);
  virtual uint gpio_get_dir(uint gpio);
  virtual enum gpio_drive_strength gpio_get_drive_strength(uint gpio);
  virtual gpio_function_t gpio_get_function(uint gpio);
  virtual uint32_t gpio_get_irq_event_mask(uint gpio);
  virtual bool gpio_get_out_level(uint gpio);
  virtual enum gpio_slew_rate gpio_get_slew_rate(uint gpio);
  virtual void gpio_init(uint gpio);
  virtual void gpio_init_mask(uint gpio_mask);
  virtual bool gpio_is_dir_out(uint gpio);
  virtual bool gpio_is_input_hysteresis_enabled(uint gpio);
  virtual bool gpio_is_pulled_down(uint gpio);
  virtual bool gpio_is_pulled_up(uint gpio);
  virtual void gpio_pull_down(uint gpio);
  virtual void gpio_pull_up(uint gpio);
  virtual void gpio_put(uint gpio, bool value);
  virtual void gpio_put_all(uint32_t value);
  virtual void gpio_put_all64(uint64_t value);
  virtual void gpio_put_masked(uint32_t mask, uint32_t value);
  virtual void gpio_put_masked64(uint64_t mask, uint64_t value);
  virtual void gpio_put_masked_n(uint n, uint32_t mask, uint32_t value);
  virtual void gpio_remove_raw_irq_handler(uint gpio, irq_handler_t handler);
  virtual void gpio_remove_raw_irq_handler_masked(uint32_t gpio_mask,
                                                  irq_handler_t handler);
  virtual void gpio_remove_raw_irq_handler_masked64(uint64_t gpio_mask,
                                                    irq_handler_t handler);
  virtual void gpio_set_dir(uint gpio, bool out);
  virtual void gpio_set_dir_all_bits(uint32_t values);
  virtual void gpio_set_dir_all_bits64(uint64_t values);
  virtual void gpio_set_dir_in_masked(uint32_t mask);
  virtual void gpio_set_dir_in_masked64(uint64_t mask);
  virtual void gpio_set_dir_masked(uint32_t mask, uint32_t value);
  virtual void gpio_set_dir_masked64(uint64_t mask, uint64_t value);
  virtual void gpio_set_dir_out_masked(uint32_t mask);
  virtual void gpio_set_dir_out_masked64(uint64_t mask);
  virtual void gpio_set_dormant_irq_enabled(uint gpio, uint32_t event_mask,
                                            bool enabled);
  virtual void gpio_set_drive_strength(uint gpio,
                                       enum gpio_drive_strength drive);
  virtual void gpio_set_function(uint gpio, gpio_function_t fn);
  virtual void gpio_set_function_masked(uint32_t gpio_mask, gpio_function_t fn);
  virtual void gpio_set_function_masked64(uint64_t gpio_mask,
                                          gpio_function_t fn);
  virtual void gpio_set_inover(uint gpio, uint value);
  virtual void gpio_set_input_enabled(uint gpio, bool enabled);
  virtual void gpio_set_input_hysteresis_enabled(uint gpio, bool enabled);
  virtual void gpio_set_irq_callback(gpio_irq_callback_t callback);
  virtual void gpio_set_irq_enabled(uint gpio, uint32_t event_mask,
                                    bool enabled);
  virtual void gpio_set_irq_enabled_with_callback(uint gpio,
                                                  uint32_t event_mask,
                                                  bool enabled,
                                                  gpio_irq_callback_t callback);
  virtual void gpio_set_irqover(uint gpio, uint value);
  virtual void gpio_set_mask(uint32_t mask);
  virtual void gpio_set_mask64(uint64_t mask);
  virtual void gpio_set_mask_n(uint n, uint32_t mask);
  virtual void gpio_set_oeover(uint gpio, uint value);
  virtual void gpio_set_outover(uint gpio, uint value);
  virtual void gpio_set_pulls(uint gpio, bool up, bool down);
  virtual void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew);
  virtual void gpio_xor_mask(uint32_t mask);
  virtual void gpio_xor_mask64(uint64_t mask);
  virtual void gpio_xor_mask_n(uint n, uint32_t mask);
  virtual bool check_sys_clock_hz(uint32_t freq_hz, uint *vco_freq_out,
                                  uint *post_div1_out, uint *post_div2_out);
  virtual bool check_sys_clock_khz(uint32_t freq_khz, uint *vco_freq_out,
                                   uint *post_div1_out, uint *post_div2_out);
  virtual bool clock_configure(clock_handle_t clock, uint32_t src,
                               uint32_t auxsrc, uint32_t src_freq,
                               uint32_t freq);
  virtual bool clock_configure_gpin(clock_handle_t clock, uint gpio,
                                    uint32_t src_freq, uint32_t freq);
  virtual void clock_configure_int_divider(clock_handle_t clock, uint32_t src,
                                           uint32_t auxsrc, uint32_t src_freq,
                                           uint32_t int_divider);
  virtual void clock_configure_undivided(clock_handle_t clock, uint32_t src,
                                         uint32_t auxsrc, uint32_t src_freq);
  virtual uint32_t clock_get_hz(clock_handle_t clock);
  virtual void clock_gpio_init(uint gpio, uint src, float div);
  virtual void clock_gpio_init_int_frac(uint gpio, uint src, uint32_t div_int,
                                        uint8_t div_frac);
  virtual void clock_set_reported_hz(clock_handle_t clock, uint hz);
  virtual void clock_stop(clock_handle_t clock);
  virtual void clocks_enable_resus(resus_callback_t resus_callback);
  virtual uint32_t frequency_count_khz(uint src);
  virtual float frequency_count_mhz(uint src);
  virtual void set_sys_clock_48mhz(void);
  virtual bool set_sys_clock_hz(uint32_t freq_hz, bool required);
  virtual bool set_sys_clock_khz(uint32_t freq_khz, bool required);
  virtual void set_sys_clock_pll(uint32_t vco_freq, uint post_div1,
                                 uint post_div2);
  virtual int64_t absolute_time_diff_us(absolute_time_t from,
                                        absolute_time_t to);
  virtual absolute_time_t absolute_time_min(absolute_time_t a,
                                            absolute_time_t b);
  virtual alarm_id_t add_alarm_at(absolute_time_t time,
                                  alarm_callback_t callback, void *user_data,
                                  bool fire_if_past);
  virtual alarm_id_t add_alarm_in_ms(uint32_t ms, alarm_callback_t callback,
                                     void *user_data, bool fire_if_past);
  virtual alarm_id_t add_alarm_in_us(uint64_t us, alarm_callback_t callback,
                                     void *user_data, bool fire_if_past);
  virtual bool add_repeating_timer_ms(int32_t delay_ms,
                                      repeating_timer_callback_t callback,
                                      void *user_data, repeating_timer_t *out);
  virtual bool add_repeating_timer_us(int64_t delay_us,
                                      repeating_timer_callback_t callback,
                                      void *user_data, repeating_timer_t *out);
  virtual alarm_id_t alarm_pool_add_alarm_at(alarm_pool_t *pool,
                                             absolute_time_t time,
                                             alarm_callback_t callback,
                                             void *user_data,
                                             bool fire_if_past);
  virtual alarm_id_t alarm_pool_add_alarm_at_force_in_context(
      alarm_pool_t *pool, absolute_time_t time, alarm_callback_t callback,
      void *user_data);
  virtual alarm_id_t alarm_pool_add_alarm_in_ms(alarm_pool_t *pool, uint32_t ms,
                                                alarm_callback_t callback,
                                                void *user_data,
                                                bool fire_if_past);
  virtual alarm_id_t alarm_pool_add_alarm_in_us(alarm_pool_t *pool, uint64_t us,
                                                alarm_callback_t callback,
                                                void *user_data,
                                                bool fire_if_past);
  virtual bool alarm_pool_add_repeating_timer_ms(
      alarm_pool_t *pool, int32_t delay_ms, repeating_timer_callback_t callback,
      void *user_data, repeating_timer_t *out);
  virtual bool alarm_pool_add_repeating_timer_us(
      alarm_pool_t *pool, int64_t delay_us, repeating_timer_callback_t callback,
      void *user_data, repeating_timer_t *out);
  virtual bool alarm_pool_cancel_alarm(alarm_pool_t *pool, alarm_id_t alarm_id);
  virtual uint alarm_pool_core_num(alarm_pool_t *pool);
  virtual alarm_pool_t *alarm_pool_create(uint timer_alarm_num,
                                          uint max_timers);
  virtual alarm_pool_t *alarm_pool_create_on_timer(alarm_pool_timer_t *timer,
                                                   uint timer_alarm_num,
                                                   uint max_timers);
  virtual alarm_pool_t *alarm_pool_create_on_timer_with_unused_hardware_alarm(
      alarm_pool_timer_t *timer, uint max_timers);
  virtual alarm_pool_t *alarm_pool_create_with_unused_hardware_alarm(
      uint max_timers);
  virtual void alarm_pool_destroy(alarm_pool_t *pool);
  virtual alarm_pool_t *alarm_pool_get_default(void);
  virtual alarm_pool_timer_t *alarm_pool_get_default_timer(void);
  virtual uint alarm_pool_hardware_alarm_num(alarm_pool_t *pool);
  virtual void alarm_pool_init_default(void);
  virtual int32_t alarm_pool_remaining_alarm_time_ms(alarm_pool_t *pool,
                                                     alarm_id_t alarm_id);
  virtual int64_t alarm_pool_remaining_alarm_time_us(alarm_pool_t *pool,
                                                     alarm_id_t alarm_id);
  virtual uint alarm_pool_timer_alarm_num(alarm_pool_t *pool);
  virtual alarm_pool_timer_t *alarm_pool_timer_for_timer_num(uint timer_num);
  virtual bool best_effort_wfe_or_timeout(absolute_time_t timeout_timestamp);
  virtual bool cancel_alarm(alarm_id_t alarm_id);
  virtual bool cancel_repeating_timer(repeating_timer_t *timer);
  virtual absolute_time_t delayed_by_ms(const absolute_time_t t, uint32_t ms);
  virtual absolute_time_t delayed_by_us(const absolute_time_t t, uint64_t us);
  virtual absolute_time_t get_absolute_time(void);
  virtual bool is_at_the_end_of_time(absolute_time_t t);
  virtual bool is_nil_time(absolute_time_t t);
  virtual absolute_time_t make_timeout_time_ms(uint32_t ms);
  virtual absolute_time_t make_timeout_time_us(uint64_t us);
  virtual int32_t remaining_alarm_time_ms(alarm_id_t alarm_id);
  virtual int64_t remaining_alarm_time_us(alarm_id_t alarm_id);
  virtual void runtime_init_default_alarm_pool(void);
  virtual void sleep_ms(uint32_t ms);
  virtual void sleep_until(absolute_time_t target);
  virtual void sleep_us(uint64_t us);
  virtual uint32_t to_ms_since_boot(absolute_time_t t);
  virtual uint32_t us_to_ms(uint64_t us);
  virtual int getchar_timeout_us(uint32_t timeout_us);
  virtual int putchar_raw(int c);
  virtual int puts_raw(const char *s);
  virtual bool stdio_deinit_all(void);
  virtual void stdio_filter_driver(stdio_driver_t *driver);
  virtual void stdio_flush(void);
  virtual int stdio_get_until(char *buf, int len, absolute_time_t until);
  virtual int stdio_getchar(void);
  virtual int stdio_getchar_timeout_us(uint32_t timeout_us);
  virtual bool stdio_init_all(void);
  virtual int __printflike(1, 0) stdio_printf(const char *format, ...);
  virtual int stdio_put_string(const char *s, int len, bool newline,
                               bool cr_translation);
  virtual int stdio_putchar(int);
  virtual int stdio_putchar_raw(int c);
  virtual int stdio_puts(const char *s);
  virtual int stdio_puts_raw(const char *s);
  virtual void stdio_set_chars_available_callback(void (*fn)(void *),
                                                  void *param);
  virtual void stdio_set_driver_enabled(stdio_driver_t *driver, bool enabled);
  virtual void stdio_set_translate_crlf(stdio_driver_t *driver, bool translate);
  virtual int stdio_vprintf(const char *format, va_list va);

};  // class SdkWrapper

#include "mocksdkwrapper.hpp"
};  // namespace rpp_driver

#endif  // PICO_DRIVER_SRC_SDK_SDKWRAPPER_HPP_
