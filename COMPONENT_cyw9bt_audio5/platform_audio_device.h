/******************************************************************************
* File Name:   platform_audio_device.h
*
* Description: AIROC audio interface header
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

#include "wiced_result.h"

/*******************************************************************************
*        Macro Definitions
*******************************************************************************/

/*******************************************************************************
*        Structure/Enum Definitions
*******************************************************************************/
typedef enum
{
    PLATFORM_DEVICE_PLAY,
    PLATFORM_DEVICE_PLAY_RECORD,
    PLATFORM_DEVICE_CAPTURE,
    PLATFORM_DEVICE_MAX,
    PLATFORM_DEVICE_INVALID = PLATFORM_DEVICE_MAX,  /*use to mark an invalid device*/
} platform_codec_device_id_t;

/**
 * AIROC audio output type
 */
typedef enum
{
    SPEAKERS,
    HEADPHONES,
    LINEOUT,
    ANALOGMIC,
    DIGIMIC,
    LINEIN,
    AUDIO_IO_MAX,   /*Not a device, just max device count*/
} platform_audio_io_device_t;

/**
* AIROC audio configuration
*/
typedef struct
{
   uint32_t                     sample_rate;        /**< The rate at which the samples are captured or played back, measured in Hertz (Hz)(e.g. 48000, 96000, etc) */
   uint8_t                      bits_per_sample;    /**< The number of bits in each audio sample (16, 24, 32)                                                      */
   uint8_t                      channels;           /**< The number of audio channels (e.g. 2 for stereo)                                                          */
   uint8_t                      volume;             /**< Attenuation (gain) - 0 to 100 scale where 0 is off and 100 is max gain                                    */
   uint8_t                      mic_gain;
   platform_audio_io_device_t   io_device;          /**< Audio source/sink device (can be extended to OR to select multiple devices) */
} platform_audio_config_t;

/**
* AIROC audio device ioctl interface
*/
typedef enum
{
   PLATFORM_AUDIO_IOCTL_SETPARAM = 0,
   PLATFORM_AUDIO_IOCTL_GETPARAM,
   PLATFORM_AUDIO_IOCTL_MAX,
} platform_audio_device_ioctl_t;

/*******************************************************************************
*        Type Definitions
*******************************************************************************/
/* audio device ID type */
typedef uint16_t platform_audio_device_id_t;

typedef union
{
    void    *ioctl_data;
} platform_audio_device_ioctl_data_t;

/*******************************************************************************
*        External Variable Declarations
*******************************************************************************/

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

/**************************************************************************************************
* Function Name: platform_audio_device_init
***************************************************************************************************
* Summary:
*   Initialize an audio device.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_init(const platform_audio_device_id_t device_id);

/**************************************************************************************************
* Function Name: platform_audio_device_configure
***************************************************************************************************
* Summary:
*   Configure the audio device for a specific audio configuration.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   platform_audio_config_t *config         : Pointer to the audio configuration to use.
*                                             in case result is NOT equal to WICED_SUCCESS,
*                                             valid supported configuration will be updated in the config argument
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_configure(const platform_audio_device_id_t device_id, platform_audio_config_t *config);

/**************************************************************************************************
* Function Name: platform_audio_device_set_output_device
***************************************************************************************************
* Summary:
*   Set the output device for the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   platform_audio_io_device_t sink         : output device.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_set_output_device(const platform_audio_device_id_t device_id, platform_audio_io_device_t sink);

/**************************************************************************************************
* Function Name: platform_audio_device_set_sr
***************************************************************************************************
* Summary:
*   Set the output device for the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t sr                              : sample rate.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_set_sr(const platform_audio_device_id_t device_id, int32_t sr);

/**************************************************************************************************
* Function Name: platform_audio_device_set_volume
***************************************************************************************************
* Summary:
*   Set the volume for the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t volume_in_db                    : volume lev el to be set
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_set_volume(const platform_audio_device_id_t device_id, int32_t volume_in_db);

/**************************************************************************************************
* Function Name: platform_audio_device_set_mic_gain
***************************************************************************************************
* Summary:
*   Set the mic gain for the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t volume_in_db                    : volume to set in db.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_set_mic_gain(const platform_audio_device_id_t device_id, int32_t volume_in_db);

/**************************************************************************************************
* Function Name: platform_audio_device_get_volume
***************************************************************************************************
* Summary:
*   Get the volume set for the audio device stream driver.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t *volume_in_db                   : Set volume.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_get_volume(const platform_audio_device_id_t device_id, int32_t *volume_in_db);

/**************************************************************************************************
* Function Name: platform_audio_device_get_volume_range
***************************************************************************************************
* Summary:
*   Get the volume range for the audio device stream.
*   @note The audio volume range is dependent on the audio device being used.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t *min_volume_in_db               : Returned minimum volume for the audio device.
*   int32_t *max_volume_in_db               : Returned maximum volume for the audio device.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_get_volume_range(const platform_audio_device_id_t device_id, int32_t *min_volume_in_db, int32_t *max_volume_in_db);

/**************************************************************************************************
* Function Name: platform_audio_device_deinit
***************************************************************************************************
* Summary:
*   De-initialize the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*   int32_t *min_volume_in_db               : Returned minimum volume for the audio device.
*   int32_t *max_volume_in_db               : Returned maximum volume for the audio device.
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_deinit(const platform_audio_device_id_t device_id);

/**************************************************************************************************
* Function Name: platform_audio_device_start
***************************************************************************************************
* Summary:
*   Start the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_start(const platform_audio_device_id_t device_id);

/**************************************************************************************************
* Function Name: platform_audio_device_stop
***************************************************************************************************
* Summary:
*   Stop the audio device stream.
*    @note After an underrun event, the audio driver must be stopped and started again.
*
* Parameters:
*   platform_audio_device_id_t device_id    : The id of the audio device.(defined in platform_audio_device.h)
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_stop(const platform_audio_device_id_t device_id);

/**************************************************************************************************
* Function Name: platform_audio_device_ioctl
***************************************************************************************************
* Summary:
*   Start the audio device stream.
*
* Parameters:
*   platform_audio_device_id_t device_id            : The id of the audio device.(defined in platform_audio_device.h)
*   platform_audio_device_ioctl_t cmd               : the IOCTL command sent directly to the audio device driver @ref wiced_audio_device_ioctl_t
*   platform_audio_device_ioctl_data_t *cmd_data    :Data associated with the IOCTL command @ref wiced_audio_device_ioctl_data_t
*
* Return:
*   wiced_result_t: See possible status codes in wiced_result.h
*
**************************************************************************************************/
extern wiced_result_t platform_audio_device_ioctl(const platform_audio_device_id_t device_id, platform_audio_device_ioctl_t cmd, platform_audio_device_ioctl_data_t* cmd_data);

#ifdef __cplusplus
} /*extern "C" */
#endif

/* [] END OF FILE */
