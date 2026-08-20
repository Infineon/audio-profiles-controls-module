/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 */
#include "wiced.h"
#include "platform_audio_device.h"

#include "hci_control_api.h"
#include "wiced_transport.h"

/** Initialize an audio codec  device.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @return @ref   wiced result type error codes
 */
wiced_result_t platform_audio_device_init(const platform_audio_device_id_t device_id)
{
    return WICED_SUCCESS;
}

/** Configure the audio device for a specific audio configuration.
 *
 * @param[in]     device_id : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in/out] config    : Pointer to the audio configuration to use.
 *                            in case result is NOT equal to WICED_SUCCESS,
 *                            valid supported configuration will be updated in the config argument
 *
 * @return @ref wiced_result_t ,
 */
wiced_result_t platform_audio_device_configure(const platform_audio_device_id_t device_id, platform_audio_config_t* config)
{
    uint8_t data[sizeof(config->sample_rate) +
                 sizeof(config->bits_per_sample) +
                 sizeof(config->channels) +
                 sizeof(config->volume)];
    uint8_t *p_data;

    /* Check parameter. */
    if (!config)
    {
        return WICED_BADARG;
    }

    /* Transmit information to host device. */
    p_data = &data[0];
    UINT32_TO_STREAM(p_data, config->sample_rate);
    UINT8_TO_STREAM(p_data, config->bits_per_sample);
    UINT8_TO_STREAM(p_data, config->channels);
    UINT8_TO_STREAM(p_data, config->volume);

    wiced_transport_send_data(HCI_CONTROL_HCI_AUDIO_EVENT_STREAM_CONFIG, data, sizeof(data));

    return WICED_SUCCESS;
}

/** Set the sample rate for the audio device stream.
 *
 * @param[in]     device_id : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]     sr        : sample rate.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_sr(const platform_audio_device_id_t device_id, int32_t sr)
{
    return WICED_SUCCESS;
}

/** Set the output device for the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]     sink        : output device.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_output_device(const platform_audio_device_id_t device_id, platform_audio_io_device_t sink)
{
    return WICED_SUCCESS;
}

/** Set the volume for the audio device stream.
 *
 * @param[in]   device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]   volume      : volume level to set.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_volume(const platform_audio_device_id_t device_id, int32_t volume_level)
{
    uint8_t data[sizeof(volume_level)];
    uint8_t *p_data;

    /* Transmit information to host device. */
    p_data = &data[0];
    UINT32_TO_STREAM(p_data, volume_level);

    wiced_transport_send_data(HCI_CONTROL_HCI_AUDIO_EVENT_STREAM_VOLUME, data, sizeof(data));

    return WICED_SUCCESS;
}


/** Set the volume for the audio device stream.
 *
 * @param[in]   device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]   volume      : volume level to set.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_mic_gain(const platform_audio_device_id_t device_id, int32_t volume_level)
{
    uint8_t data[sizeof(volume_level)];
    uint8_t *p_data;

    /* Transmit information to host device. */
    p_data = &data[0];
    UINT32_TO_STREAM(p_data, volume_level);

    wiced_transport_send_data(HCI_CONTROL_HCI_AUDIO_EVENT_STREAM_MIC_GAIN, data, sizeof(data));

    return WICED_SUCCESS;
}

/** Get the volume set for the audio device stream driver.
 *
 * @param[in]   device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[out]  volume      : Set volume.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_get_volume(const platform_audio_device_id_t device_id, int32_t *volume_level)
{
    return WICED_SUCCESS;
}

/** Get the volume range for the audio device stream.
 *
 * @note The audio volume range is dependent on the audio device being used.
 *
 * @param[in]   device_id           : The id of the audio device.(defined in platform_audio_device.h)
 * @param[out]  min_volume_in_db    : Returned minimum volume for the audio device.
 * @param[out]  max_volume_in_db    : Returned maximum volume for the audio device.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_get_volume_range(const platform_audio_device_id_t device_id, int32_t *min_volume_level, int32_t *max_volume_level)
{
    return WICED_SUCCESS;
}

/** De-initialize the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_deinit(const platform_audio_device_id_t device_id)
{
    return WICED_SUCCESS;
}

/** Start the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_start(const platform_audio_device_id_t device_id)
{
    uint8_t param = (uint8_t) device_id;

    wiced_transport_send_data(HCI_CONTROL_HCI_AUDIO_EVENT_STREAM_START, &param, sizeof(param));

    return WICED_SUCCESS;
}

/** Stop the audio device stream.
 *
 * @note After an underrun event, the audio driver must be stopped and started again.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_stop ( const platform_audio_device_id_t device_id )
{
    uint8_t param = 0;

    wiced_transport_send_data(HCI_CONTROL_HCI_AUDIO_EVENT_STREAM_STOP, &param, 1);

    return WICED_SUCCESS;
}

/** Send an ioctl to the audio chip driver.
 *
 * @note Values passed with cmd_data are dependent upon the driver for the audio device being used.
 *
 * @param[in] device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in] cmd  : The IOCTL command sent directly to the audio device driver @ref wiced_audio_device_ioctl_t
 * @param[in] cmd  : Data associated with the IOCTL command @ref wiced_audio_device_ioctl_data_t
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_ioctl ( const platform_audio_device_id_t device_id, platform_audio_device_ioctl_t cmd, platform_audio_device_ioctl_data_t* cmd_data )
{
    return WICED_SUCCESS;
}
