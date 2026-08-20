/**
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 * Audio effects API is a high level interface for applications to use platform audio effects capabilities.
 */

#include <wiced_audio_manager.h>
#include <wiced_bt_trace.h>
#include <platform_audio_device.h>
#include "audio_effects.h"

int32_t *audio_effect_type_list;
platform_audio_effect_descrip_t *audio_effect_desc_list;
uint32_t total_no_effects = 0;

int32_t audio_effect_init(uint32_t effect_type, void *args, uint32_t *effect_id)
{
#ifdef AUDIO_EFFECTS_ENABLE
    if(WICED_SUCCESS != platform_audio_effect_init((platform_audio_effect_type_t)effect_type, (platform_audio_effect_config_t *)args, effect_id))
        return -1;
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning with no error as effects are not supported for this codec.*/
#endif
    return 0;
}

int32_t audio_effect_deinit(int32_t effect_id)
{
#ifdef AUDIO_EFFECTS_ENABLE
    if(WICED_SUCCESS != platform_audio_effect_deinit((uint32_t)effect_id))
        return -1;
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning with no error as effects are not supported for this codec.*/
#endif
    return 0;

}

int32_t audio_effect_process(int32_t effect_id, uint32_t in_size, uint8_t *in_buf,uint32_t *out_size,uint8_t *out_buf,uint32_t ref_size,uint8_t *ref_buf )
{
#ifdef AUDIO_EFFECTS_ENABLE
    if(WICED_SUCCESS != platform_audio_effect_process((uint32_t) effect_id,
                                                in_size,in_buf,
                                                ref_size,ref_buf,
                                                out_size,out_buf))
    {
        return -1;
    }
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning with no error as effects are not supported for this codec.*/
#endif
    return 0;
}

int32_t* audio_effect_get_effects( int32_t *num_of_effects)
{

#ifdef AUDIO_EFFECTS_ENABLE
    audio_effect_type_list = platform_audio_effect_get_effects_type(&total_no_effects);

    if(audio_effect_type_list != NULL )
    {
        *num_of_effects = total_no_effects;
        return audio_effect_type_list;
    }
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning NULL pointer as effects are not supported for this codec.*/
#endif
    return NULL;
}

audio_effect_desc_t* audio_effect_get_effects_descriptor(int32_t effect_type)
{
#ifdef AUDIO_EFFECTS_ENABLE
    return platform_audio_effect_get_effects_descriptor((platform_audio_effect_type_t)effect_type);
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning NULL pointer as effects are not supported for this codec.*/
#endif
    return NULL;
}

int32_t audio_effect_ioctl(int32_t effect_id, audio_effect_ioctl_t cmd, audio_effect_ioctl_data *cmd_data)
{
#ifdef AUDIO_EFFECTS_ENABLE
    if(WICED_SUCCESS != platform_audio_effect_ioctl(effect_id, cmd, cmd_data))
        return -1;
#else
    WICED_BT_TRACE("Audio effects not supported with this codec \n");
    /* returning with no error as effects are not supported for this codec.*/
#endif
    return 0;
}
