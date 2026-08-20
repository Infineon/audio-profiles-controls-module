/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include <wiced_bt_ama.h>

typedef void (*bt_audio_record_data_callback_t)(const void *data, uint32_t size);

typedef struct bt_audio_record_config {
    bt_audio_record_data_callback_t data_callback;
    uint8_t (*encoder_creator)(bt_audio_record_data_callback_t data_callback);
    void (*pre_start_callback)(wiced_bool_t is_hfp_active);
    void (*post_stop_callback)(wiced_bool_t is_hfp_active);
} bt_audio_record_config_t;

wiced_result_t bt_audio_record_init(const bt_audio_record_config_t *config);
wiced_bt_ama_speech_audio_format_t bt_audio_record_encoder_audio_format_get(void);
wiced_result_t bt_audio_record_start(wiced_bool_t is_hfp_active);
wiced_result_t bt_audio_record_stop(void);
wiced_bool_t bt_audio_record_is_active(void);
uint32_t bt_audio_record_encoder_packet_size(void);
uint32_t bt_audio_record_encoder_packet_size_in_us(void);
uint8_t bt_audio_record_encoder_create_opus_32kbps(bt_audio_record_data_callback_t data_callback);
uint8_t bt_audio_record_encoder_create_opus_16kbps(bt_audio_record_data_callback_t data_callback);
uint8_t bt_audio_record_encoder_create_msbc(bt_audio_record_data_callback_t data_callback);
void bt_audio_record_hfp_mic_handler(int16_t *pcm_buffer, uint32_t sample_count);
