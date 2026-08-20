/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt
 *
 */

#pragma once

#include <stdint.h>
#include <wiced.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Definitions
 */
/* Voice Prompt Configuration (File System for the moment) */
typedef struct
{
    uint32_t file_system_offset;
    uint32_t file_system_length;
} wiced_bt_voice_prompt_config_t;

/* Signed PCM, 16 bits sample */
typedef int16_t pcm_s16_t;

/*
 * wiced_bt_voice_prompt_init
 */
wiced_result_t wiced_bt_voice_prompt_init(wiced_bt_voice_prompt_config_t *p_config);

/*
 * wiced_bt_voice_prompt_open
 */
wiced_result_t wiced_bt_voice_prompt_open(uint8_t file_index);

/*
 * wiced_bt_voice_prompt_close
 */
wiced_result_t wiced_bt_voice_prompt_close(void);

/*
 * wiced_bt_voice_prompt_frequency_set
 */
wiced_result_t wiced_bt_voice_prompt_frequency_set(uint16_t frequency);

/*
 * wiced_bt_voice_prompt_samples_generate
 *
 * Generate the specified PCM samples according to the configured frequency.
 *
 * It's recommended that the user application calls this utility each time the
 * PCM samples are acquired (via wiced_bt_voice_prompt_samples_get utility).
 *
 * Note: 1. The frequency shall be set before this operation.
 *       2. This utility shall be called in WiCED APP Task (MPAF) to avoid unexpected race condition.
 */
void wiced_bt_voice_prompt_samples_generate(void);

/*
 * wiced_bt_voice_prompt_samples_get
 */
uint32_t wiced_bt_voice_prompt_samples_get(pcm_s16_t *p_pcm, uint16_t samples_nb,
        wiced_bool_t *p_end_of_file, wiced_bool_t stereo);

#ifdef __cplusplus
}
#endif
