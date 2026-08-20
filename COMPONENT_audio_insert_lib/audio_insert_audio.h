/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

/*
 * audio_insert_audio_init
 *
 */
void audio_insert_audio_init(void);

/*
 * audio_insert_audio_start
 */
void audio_insert_audio_start(uint32_t *p_sample_rate, wiced_bt_audio_insert_data_audio_t *p_insert_data);

/*
 * audio_insert_audio_stop
 */
void audio_insert_audio_stop(void);

/*
 * audio_insert_audio_advanced_control_utility_install
 */
void audio_insert_audio_advanced_control_utility_install(wiced_bt_audio_insert_advanced_control_config_audio_t *p_config);
