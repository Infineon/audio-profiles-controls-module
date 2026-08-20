/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 */
#include "wiced.h"
#include "wiced_rtos.h"
#include "wiced_hal_gpio.h"
#include "wiced_bt_trace.h"
#include "platform_audio_device.h"
#include "platform_audio_codec.h"
#include "platform.h"

#define PLATFORM_AUDIO_DEVICE_TOTAL platform_audio_device_count()

/** Initialize an audio codec  device.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @return @ref   wiced result type error codes
 */
wiced_result_t  platform_audio_device_init ( const platform_audio_device_id_t device_id )
{
	uint16_t i;

	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_init(platform_audio_device_list[i]->device_port);
		}
	}
	return WICED_NOT_FOUND;
}

/** Configure the audio device for a specific audio configuration.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in/out] config : Pointer to the audio configuration to use.
 * 						   in case result is NOT equal to WICED_SUCCESS,
 *                         valid supported configuration will be updated in the config argument
 *
 * @return @ref wiced_result_t ,
 */
wiced_result_t platform_audio_device_configure ( const platform_audio_device_id_t device_id, platform_audio_config_t* config )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_configure(NULL,config);
		}
	}
	return WICED_NOT_FOUND;
}

/** Set the sample rate for the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]       sr        : sample rate.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_sr ( const platform_audio_device_id_t device_id, int32_t sr )
{
    uint16_t i;
    WICED_BT_TRACE("platform_audio_device_set_sr : %ld\n", sr);
    for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
    {
        if(platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_sr (NULL,sr);
        }
    }
    return WICED_NOT_FOUND;
}

/** Set the output device for the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in]     sink        : output device.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_output_device ( const platform_audio_device_id_t device_id, platform_audio_io_device_t sink )
{
    uint16_t i;
    WICED_BT_TRACE("platform_audio_device_set_output_device : %d\n", sink);
    for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
    {
        if(platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_sink (NULL,sink);
        }
    }
    return WICED_NOT_FOUND;
}

/** Set the volume for the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in] volume : volume to set in db.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_volume ( const platform_audio_device_id_t device_id, int32_t volume_level )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_set_volume (NULL,volume_level);
		}
	}
	return WICED_NOT_FOUND;
}


/** Set the volume for the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[in] volume : volume to set in db.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_set_mic_gain ( const platform_audio_device_id_t device_id, int32_t volume_level )
{
    uint16_t i;
    for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
    {
        if(platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_mic_gain (NULL,volume_level);
        }
    }
    return WICED_NOT_FOUND;
}

/** Get the volume set for the audio device stream driver.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[out] volume : Set volume.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_get_volume ( const platform_audio_device_id_t device_id, int32_t *volume_level )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_get_volume(NULL,volume_level);
		}
	}
	return WICED_NOT_FOUND;
}

/** Get the volume range for the audio device stream.
 *
 * @note The audio volume range is dependent on the audio device being used.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 * @param[out] min_volume_in_db : Returned minimum volume for the audio device.
 * @param[out] max_volume_in_db : Returned maximum volume for the audio device.
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_get_volume_range ( const platform_audio_device_id_t device_id, int32_t *min_volume_level, int32_t *max_volume_level )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_get_volume_range(NULL,min_volume_level,max_volume_level);
		}
	}
	return WICED_NOT_FOUND;
}

/** De-initialize the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_deinit ( const platform_audio_device_id_t device_id )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_deinit(NULL);
		}
	}
	return WICED_NOT_FOUND;

}

/** Start the audio device stream.
 *
 * @param[in]     device_id   : The id of the audio device.(defined in platform_audio_device.h)
 *
 * @return @ref wiced_result_t
 */
wiced_result_t platform_audio_device_start ( const platform_audio_device_id_t device_id )
{
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_start_streaming(NULL);
		}
	}
	return WICED_NOT_FOUND;
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
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_stop_streaming(NULL);
		}
	}
	return WICED_NOT_FOUND;

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
	uint16_t i;
	for(i=0; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++ )
	{
		if(platform_audio_device_list[i]->device_id == device_id)
		{
			return platform_audio_device_list[i]->device_ops->audio_device_ioctl(NULL,cmd,cmd_data);
		}
	}
	return WICED_NOT_FOUND;


}
