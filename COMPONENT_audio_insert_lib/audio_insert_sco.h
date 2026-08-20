/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include "wiced_bt_audio_insert.h"

/*
 * audio_insert_sco_init
 */
void audio_insert_sco_init(void);

/*
 * audio_insert_sco_start
 */
void audio_insert_sco_start(wiced_bool_t mic, wiced_bool_t spk, wiced_bt_audio_insert_data_sco_t *p_insert_data);

/*
 * audio_insert_sco_stop
 */
void audio_insert_sco_stop(wiced_bool_t mic, wiced_bool_t spk);

/*
 * audio_insert_sco_in_data_latest_time_sequence_number_get
 */
uint32_t audio_insert_sco_in_data_latest_time_sequence_number_get(void);

/*
 * audio_insert_sco_advanced_control_utility_install
 */
void audio_insert_sco_advanced_control_utility_install(wiced_bt_audio_insert_advanced_control_config_sco_t *p_config);
