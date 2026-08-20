/******************************************************************************
* File Name:   platform_audio_codec.h
*
* Description: generic audio platform definition
*
* Related Document: None
*
*******************************************************************************
* $ Copyright 2021-YEAR Cypress Semiconductor $
*******************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
*        Header Files
*******************************************************************************/
#include <stdint.h>

#include "platform_audio_device.h"
#include "wiced_result.h"

/*******************************************************************************
*        Macro Definitions
*******************************************************************************/

/*******************************************************************************
*        Structure/Enum Definitions
*******************************************************************************/
/**
 * Platform audio device interface
 */
typedef struct
{
    uint32_t    spi_speed;  /**< speed mode the device operates in */
    uint8_t     spi_pin_clk;
    uint8_t     spi_pin_cs;
    uint8_t     spi_pin_mosi;
    uint8_t     spi_pin_miso;
    uint8_t     i2s_mode;   /**< 0=slave 1=master */
    uint8_t     i2s_pin_sclk;
    uint8_t     i2s_pin_ws;
    uint8_t     i2s_pin_din;
    uint8_t     i2s_pin_dout;
    uint8_t     pin_reset;
} platform_audio_port;

typedef struct
{
    wiced_result_t (*audio_device_init)            ( platform_audio_port* data_port );
    wiced_result_t (*audio_device_deinit)          ( void* device_data );
    wiced_result_t (*audio_device_configure)       ( void* device_data, platform_audio_config_t* config );
    wiced_result_t (*audio_device_start_streaming) ( void* device_data );
    wiced_result_t (*audio_device_stop_streaming)  ( void* device_data );
    wiced_result_t (*audio_device_set_sr)          ( void* device_data, int32_t sr );
    wiced_result_t (*audio_device_set_sink)        ( void* device_data, platform_audio_io_device_t sink );
    wiced_result_t (*audio_device_set_volume)      ( void* device_data, int32_t volume_level );
    wiced_result_t (*audio_device_set_mic_gain)    ( void* device_data, int32_t volume_level );
    wiced_result_t (*audio_device_get_volume)      ( void* device_data, int32_t *volume_level );
    wiced_result_t (*audio_device_get_volume_range)( void* device_data, int32_t* min_volume_levels, int32_t* max_volume_levels);
    wiced_result_t (*audio_device_set_volume_range)( void* device_data, int32_t min_volume_levels, int32_t max_volume_levels);
    wiced_result_t (*audio_device_ioctl)           ( void* device_data, platform_audio_device_ioctl_t cmd, platform_audio_device_ioctl_data_t* cmd_data );
} platform_audio_device_ops;

typedef struct
{
    platform_audio_device_id_t  device_id;
    platform_audio_device_ops   *device_ops;
    platform_audio_port         *device_port;
} platform_audio_device_interface_t;

enum {
    I2S_SLAVE,
    I2S_MASTER,
};

/*******************************************************************************
*        External Variable Declarations
*******************************************************************************/

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif
/* [] END OF FILE */
