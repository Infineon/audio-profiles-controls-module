/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED AK4679 control driver
 */
#pragma once

#include "platform_audio_device.h"

/**
 * @addtogroup  wicedbt_ak4679          AK4679
 * @ingroup     wicedbt
 *
 * AK4679 codec support
 *
 * @{
 */

/**
 * Write AK4679 register
 *
 * @param[in] reg_addr register address
 * @param[in] reg_data data to write to the register
 */
void ak4679_write_reg(uint8_t reg_addr, uint8_t reg_data);

/**
 * Start DAC for audio Sink applications
 *
 * @param[in]       pdn_gpio : pin number connected to PDN
 * @param[in]       scl_i2c : pin number connected to SCL i2c control pin
 * @param[in]       sdl_i2c : pin number connected to SDA i2c control pin
 */
void wiced_bt_ak4679_init(uint32_t pdn_gpio, uint32_t scl_i2c, uint32_t sda_i2c);

/**
 * Start DAC for audio Sink applications
 *
 * @param[in]       sample_freq : Sample frequency in samples per second
 */
void wiced_bt_ak4679_start_dac(uint32_t sample_freq);

/**
 * Start ADC and DAC for hands free applications
 *
 * @param[in]       sample_freq : Sample frequency in samples per second
 */
void wiced_bt_ak4679_start_adc_and_dac(uint32_t sample_freq);

/**
 * Start capture for audio source applications
 *
 * @param[in]       sample_freq : Sample frequency in samples per second
 */
void wiced_bt_ak4679_start_capture(uint32_t sample_freq);

/**
 * Set codec sink configurations
 *
 * @param[in]       sink : sink device to which output has to be routed.
 */
void wiced_bt_ak4679_set_sink_device(platform_audio_io_device_t sink);

/**
 * Stop ADC and DAC.  Put in low power mode.
 */
void wiced_bt_ak4679_stop(void);

/**
 * Mute AK4679 DAC output
 *
 * @param[in]       dac_mute  : set to 1 to mute DAC, set to 0 to unmute
 */
void wiced_bt_ak4679_softmute_dac(uint8_t mute);

/**
 * Set DAC analog output gain for LINEOUT
 *
 * @param[in]       vol : analog volume out in dB, according to table in DS
 */
void wiced_bt_ak4679_set_line_out_volume(int8_t vol);

/**
 * Set mic gain
 *
 * @param[in]       left_vol : Set left ADC gain in dB. Gain Range is -6 to 24dB in 3 dB steps.
 *                  Odd values will be truncated.
 * @param[in]       right_vol : Set right ADC gain in dB. Gain Range is -6 to 24dB in 3 dB steps.
 *                  Odd values will be truncated.
 */
void wiced_bt_ak4679_set_mic_gain(int8_t left_vol, int8_t right_vol);

/**
 * Set digital output volume used by HP and LINEOUT
 *
 * @param[in]       left_vol : Set left ADC gain in dB. Gain Range is from -57.5dB to +6dB in steps of .5dB
 *                  NOTE: -58 == MUTE. See datasheet for conversion table
 * @param[in]       right_vol : Set right ADC gain in dB. Gain Range is from -57.5dB to +6dB in steps of .5dB
 *                  NOTE: -58 == MUTE. See datasheet for conversion table
 */
void wiced_bt_ak4679_set_output_volume(float left_vol, float right_vol);

/**
 * Set digital input volume used by ALC
 *
 * @param[in]       left_vol : Set left ADC gain in dB. Gain Range is from -54dB to +36dB in steps of .375dB
 *                  NOTE: -54.375 == MUTE. See datasheet for conversion table
 * @param[in]       right_vol : Set right ADC gain in dB. Gain Range is from -54dB to +36dB in steps of .375dB
 *                  NOTE: -54.375 == MUTE. See datasheet for conversion table
 */
void wiced_bt_ak4679_set_input_volume(float left_vol, float right_vol);

/**
 * Set HP port volume
 *
 * @param[in]       vol : Set HP gain in dB. Gain Range is -62dB to 6dB in 2dB steps.
 *                  Odd values will be truncated.
 */
void wiced_bt_ak4679_set_hp_volume(int8_t vol);

/**
 * Write script to the registers of the
 *
 * @param[in]       ak_reg_script : lenx2 array with register_addr in [x][0] and
 *                  corresponding reg_value in [x][1]
 * @param[in]       len : number of registers to write, size of array: [len][2]
 */
void wiced_bt_ak4679_write_reg_script( uint8_t ak_reg_script[][2], uint32_t len );


/** @} wicedbt_ak4679 */
