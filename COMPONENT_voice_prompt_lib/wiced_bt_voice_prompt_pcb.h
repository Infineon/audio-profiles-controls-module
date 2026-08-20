/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt PCM Circular Buffer (PCB)
 *
 */

#pragma once

#include "wiced.h"
#include "wiced_bt_voice_prompt_int.h"

/*
 * wiced_bt_voice_prompt_pcb_init
 */
wiced_result_t wiced_bt_voice_prompt_pcb_init(void);

/*
 *wiced_bt_voice_prompt_pcb_reset
 */
wiced_result_t wiced_bt_voice_prompt_pcb_reset(void);

/*
 * wiced_bt_voice_prompt_pcb_nb_free_get
 * Return the number of free PCM samples (how much can be inserted)
 */
uint32_t wiced_bt_voice_prompt_pcb_nb_free_get(void);

/*
 * wiced_bt_voice_prompt_pcb_nb_samples_get
 * Return the number of PCM samples
 */
uint32_t wiced_bt_voice_prompt_pcb_nb_samples_get(void);

/*
 * wiced_bt_voice_prompt_pcb_insert
 * Returns the number of PCM samples inserted
 */
uint32_t wiced_bt_voice_prompt_pcb_insert(pcm_s16_t *p_pcm, uint32_t nb_samples);

/*
 * wiced_bt_voice_prompt_pcb_extract
 * Returns the number of PCM samples extracted
 */
uint32_t wiced_bt_voice_prompt_pcb_extract(pcm_s16_t *p_pcm, uint32_t nb_samples);
