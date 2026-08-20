/******************************************************************************
* File Name:   platform_rev1.c
*
* Description: shield board configuration for supported peripherals like buttons,
*              codec, etc,..
*
* Related Document:
*
*
*******************************************************************************
* $ Copyright 2021-YEAR Cypress Semiconductor $
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "gpio_button.h"
#include "platform_audio_codec.h"
#include "platform_audio_effects.h"
#include "cyhal_gpio.h"
#include "wiced_platform.h"

/*******************************************************************************
*        Structure/Enum Definitions
*******************************************************************************/

/*******************************************************************************
* Macros
********************************************************************************/
#ifndef PLATFORM_BUTTON_CUSTOM
#if defined(CYW55500A1)
#define PLATFORM_BUTTON_CUSTOM      (LHL_GPIO_6)
#else
#define PLATFORM_BUTTON_CUSTOM      (BT_GPIO_16)
#endif
#endif // PLATFORM_BUTTON_CUSTOM

#ifndef PLATFORM_BUTTON_VOL_UP
#define PLATFORM_BUTTON_VOL_UP      (BT_GPIO_4)
#endif // PLATFORM_BUTTON_VOL_UP

#ifndef PLATFORM_BUTTON_VOL_DOWN
#define PLATFORM_BUTTON_VOL_DOWN    (BT_GPIO_5)
#endif // PLATFORM_BUTTON_VOL_DOWN

#define SPI_FREQ_24MHZ              (1000000) /* 24 MHz */

/*******************************************************************************
* Global Variables
********************************************************************************/
gpio_button_t platform_gpio_buttons[] =
{
    /* Button: CUSTOM */
    [PLATFORM_BUTTON_1] =
    {
        .polarity   = GPIO_BUTTON_ACTIVE_STATE_LOW,
        .gpio       = PLATFORM_BUTTON_CUSTOM,
        .trigger    = CYHAL_GPIO_IRQ_BOTH,
    },

    /* Button: VOL+ */
    [PLATFORM_BUTTON_2] =
    {
        .polarity   = GPIO_BUTTON_ACTIVE_STATE_LOW,
        .gpio       = PLATFORM_BUTTON_VOL_UP,
        .trigger    = CYHAL_GPIO_IRQ_BOTH,
    },

    /* Button: VOL- */
    [PLATFORM_BUTTON_3] =
    {
        .polarity   = GPIO_BUTTON_ACTIVE_STATE_LOW,
        .gpio       = PLATFORM_BUTTON_VOL_DOWN,
        .trigger    = CYHAL_GPIO_IRQ_BOTH,
    },
};

extern platform_audio_device_ops cs47l35_play_ops;
extern platform_audio_device_ops cs47l35_play_rec_ops;
extern platform_audio_device_ops cs47l35_capture_ops;
/*platform SPI/I2S pin configs for supported codec*/
extern platform_audio_port cs47l35_audio_port;

/*platform SPI/I2S pin configs for supported codec*/
platform_audio_port cs47l35_audio_port =
{
    .spi_speed  = SPI_FREQ_24MHZ,
    .i2s_mode   = I2S_SLAVE,
};

/* A2DP Sink (Render) device for platform */
platform_audio_device_interface_t cs47l35_play =
{
    .device_id      = PLATFORM_DEVICE_PLAY,
    .device_ops     = &cs47l35_play_ops,
    .device_port    = &cs47l35_audio_port,
};

/* HFP device for platform */
platform_audio_device_interface_t cs47l35_rec =
{
    .device_id      = PLATFORM_DEVICE_PLAY_RECORD,
    .device_ops     = &cs47l35_play_rec_ops,
    .device_port    = &cs47l35_audio_port,
};

/* A2DP Source (Capture) device for platform */
platform_audio_device_interface_t cs47l35_capture =
{
    .device_id      = PLATFORM_DEVICE_CAPTURE,
    .device_ops     = &cs47l35_capture_ops,
    .device_port    = &cs47l35_audio_port,
};

/*list of all devices supported by platform
 * you add all supported devices but assign only one PLATFORM_DEVICE_PLAY_RECORD
 * and PLATFORM_DEVICE_PLAY, rest of the devices 'device_id' should be marked as
 * PLATFORM_DEVICE_INVALID*/
platform_audio_device_interface_t *platform_audio_device_list[] =
{
    &cs47l35_play,
    &cs47l35_rec,
    &cs47l35_capture,
};

/*******************************************************************************
* Function Prototypes
********************************************************************************/

/*******************************************************************************
* Global Function Definitions
*******************************************************************************/
uint32_t platform_audio_device_count(void)
{
    return sizeof(platform_audio_device_list)/sizeof(platform_audio_device_interface_t*);
}

/*list of all platform effects*/
const platform_audio_effect_list *platform_aud_effect_list[] =
{
};

/* returns platform total effects count*/
uint32_t platform_audio_effects_count(void)
{
    return sizeof(platform_aud_effect_list)/sizeof(platform_aud_effect_list[0]);
}

/*******************************************************************************
* Static Function Definitions
*******************************************************************************/


/* [] END OF FILE */
