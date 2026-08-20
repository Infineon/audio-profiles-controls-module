/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt Embedded Flash Driver
 *
 */

#pragma once

#include "wiced.h"
#include "wiced_bt_voice_prompt_int.h"

/*
 * wiced_bt_voice_prompt_eflash_init
 */
uint32_t wiced_bt_voice_prompt_eflash_init(void);

/*
 * wiced_bt_voice_prompt_ef_read
 */
wiced_result_t wiced_bt_voice_prompt_eflash_read(uint32_t offset, void *p_buffer, uint32_t length);
