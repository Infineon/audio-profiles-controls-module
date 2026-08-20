/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include <wiced_bt_ama.h>
#include <wiced_bt_cfg.h>
#include <wiced_bt_hfp_hf.h>
#include <wiced_button_manager.h>


typedef struct ama_config {
    const wiced_bt_cfg_settings_t *settings;
    void (*event_forward_at_command_handler)(const char *at_command);
    void (*event_media_control_handler)(wiced_bt_ama_media_control_t control);
    void (*audio_record_pre_start_handler)(wiced_bool_t is_hfp_active);
    void (*audio_record_post_stop_handler)(wiced_bool_t is_hfp_active);
} ama_config_t;

wiced_result_t ama_init(void);
wiced_result_t ama_post_init(const wiced_bt_cfg_settings_t *settings);
wiced_result_t ama_post_init_hci_based(const ama_config_t *config);
wiced_bool_t ama_button_pre_handler(platform_button_t button, button_manager_event_t event, button_manager_button_state_t state, uint32_t repeat);
wiced_bool_t ama_hfp_pre_handler(wiced_bt_hfp_hf_event_t event, wiced_bt_hfp_hf_event_data_t* p_data);
void ama_gatt_connection_status_handler(wiced_bt_gatt_connection_status_t *status);
uint32_t ama_feature_value_get(wiced_bt_ama_state_feature_id_t id);
void ama_feature_value_set(wiced_bt_ama_state_feature_id_t id, uint32_t value);
wiced_bool_t ama_is_connected(void);
uint16_t ama_get_conn_id(void);
wiced_bool_t ama_ready_to_switch(void);
wiced_result_t ama_suspend(uint32_t timeout);
wiced_result_t ama_resume(void);
void ama_voice_recognize_start(void);
void ama_statistics_update_and_dump(void);
