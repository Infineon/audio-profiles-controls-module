/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * audio effects API interface header
 */

#pragma once

#include "platform_audio_effects.h"

typedef platform_audio_effect_config_t  audio_effect_config_t;
typedef platform_audio_effect_descrip_t audio_effect_desc_t;
typedef platform_audio_effect_type_t audio_effect_type;
typedef platform_audio_effect_ioctl_t audio_effect_ioctl_t;
typedef platform_audio_effect_ioctl_data_t audio_effect_ioctl_data;

int32_t audio_effect_init(uint32_t effect_type, void *args, uint32_t *effect_id);
int32_t audio_effect_deinit(int32_t effect_id);
int32_t audio_effect_process(int32_t effect_id, uint32_t in_size, uint8_t *in_buf,uint32_t *out_size,uint8_t *out_buf,uint32_t ref_size,uint8_t *ref_buf );
int32_t* audio_effect_get_effects(int32_t *num_of_effects);
audio_effect_desc_t * audio_effect_get_effects_descriptor(int32_t effect_id);
int32_t audio_effect_ioctl(int32_t effect_id, audio_effect_ioctl_t cmd, audio_effect_ioctl_data *cmd_data);
