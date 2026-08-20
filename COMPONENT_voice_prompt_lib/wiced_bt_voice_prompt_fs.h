/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt File System
 *
 */

#pragma once

#include "wiced.h"
#include "wiced_bt_voice_prompt_int.h"

/*
 * Definitions
 */
#define VPFS_FILE_FORMAT_VPC_8K             1       /* VP Codec 8kHz */
#define VPFS_FILE_FORMAT_PCM_8K_S16_MONO    2       /* Raw PCM */
#define VPFS_FILE_FORMAT_ADPCM              3       /* ADPCM */

/*
 * wiced_bt_voice_prompt_fs_init
 */
wiced_result_t wiced_bt_voice_prompt_fs_init(wiced_bt_voice_prompt_config_t *p_config);

/*
 * wiced_bt_voice_prompt_fs_open
 */
wiced_result_t wiced_bt_voice_prompt_fs_open(uint8_t file_index, uint32_t *p_file_format);

/*
 * wiced_bt_voice_prompt_fs_close
 */
wiced_result_t wiced_bt_voice_prompt_fs_close(void);

/*
 * wiced_bt_voice_prompt_fs_read
 */
uint32_t wiced_bt_voice_prompt_fs_read(void *p_buffer, uint32_t length);
