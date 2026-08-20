/******************************************************************************
* File Name:   platform_audio_device.c
*
* Description: AIROC audio interface header
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
#include "platform_audio_device.h"

#include <stddef.h>
#include <stdint.h>

#include "platform.h"
#include "platform_audio_codec.h"
#include "wiced_result.h"

/*******************************************************************************
* Macros
********************************************************************************/

#define PLATFORM_AUDIO_DEVICE_TOTAL platform_audio_device_count()

/*******************************************************************************
* Global Variables
********************************************************************************/


/*******************************************************************************
* Function Prototypes
********************************************************************************/

/*******************************************************************************
* Global Function Definitions
*******************************************************************************/

wiced_result_t platform_audio_device_init(const platform_audio_device_id_t device_id)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_init(platform_audio_device_list[i]->device_port);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_configure(const platform_audio_device_id_t device_id, platform_audio_config_t *config)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_configure(NULL,config);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_set_sr(const platform_audio_device_id_t device_id, int32_t sr)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    PLATFORM_AUDIO_TRACE("platform_audio_device_set_sr : %ld\n", sr);
    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_sr (NULL,sr);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_set_output_device(const platform_audio_device_id_t device_id, platform_audio_io_device_t sink)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    PLATFORM_AUDIO_TRACE("platform_audio_device_set_output_device : %d\n", sink);
    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_sink (NULL,sink);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_set_volume(const platform_audio_device_id_t device_id, int32_t volume_level)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;
    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_volume (NULL,volume_level);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_set_mic_gain(const platform_audio_device_id_t device_id, int32_t volume_level)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_set_mic_gain (NULL,volume_level);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_get_volume(const platform_audio_device_id_t device_id, int32_t *volume_level)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_get_volume(NULL,volume_level);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_get_volume_range(const platform_audio_device_id_t device_id, int32_t *min_volume_level, int32_t *max_volume_level)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_get_volume_range(NULL,min_volume_level,max_volume_level);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_deinit(const platform_audio_device_id_t device_id)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_deinit(NULL);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_start(const platform_audio_device_id_t device_id)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_start_streaming(NULL);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_stop(const platform_audio_device_id_t device_id)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_stop_streaming(NULL);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

wiced_result_t platform_audio_device_ioctl(const platform_audio_device_id_t device_id, platform_audio_device_ioctl_t cmd, platform_audio_device_ioctl_data_t *cmd_data)
{
#ifndef DISABLE_PF_AUDIO
    uint16_t i;

    for (i = 0 ; i < PLATFORM_AUDIO_DEVICE_TOTAL ; i++)
    {
        if (platform_audio_device_list[i]->device_id == device_id)
        {
            return platform_audio_device_list[i]->device_ops->audio_device_ioctl(NULL,cmd,cmd_data);
        }
    }

    return WICED_NOT_FOUND;
#else
    return WICED_SUCCESS;
#endif
}

/*******************************************************************************
* Static Function Definitions
*******************************************************************************/


/* [] END OF FILE */
