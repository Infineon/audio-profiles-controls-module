/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Secondary State Machine
 *
 */
#pragma once

/*
 * wiced_bt_lrac_sec_init
 */
wiced_result_t wiced_bt_lrac_sec_init(void);

/*
 * wiced_bt_lrac_sec_ctrl_handler
 */
void wiced_bt_lrac_sec_ctrl_handler(wiced_bt_lrac_ctrl_opcode_t opcode,
        wiced_bt_lrac_ctrl_data_t *p_ctrl_data);

/*
 * wiced_bt_lrac_sec_hci_handler
 */
void wiced_bt_lrac_sec_hci_handler (wiced_bt_lrac_hci_evt_t event,
        wiced_bt_lrac_hci_evt_data_t *p_data);

/*
 * wiced_bt_lrac_sec_disconnected
 * This function is called when the LRAC Internal connection is disconnected.
 */
void wiced_bt_lrac_sec_disconnected(void);

/*
 * wiced_bt_lrac_sec_switch_req
 */
wiced_result_t wiced_bt_lrac_sec_switch_req(wiced_bool_t prevent_glitch);

/*
 * wiced_bt_lrac_sec_switch_rsp
 */
wiced_result_t wiced_bt_lrac_sec_switch_rsp(wiced_result_t rsp_status,
        wiced_bool_t prevent_glitch);

/*
 * wiced_bt_lrac_sec_switch_execute
 */
wiced_result_t wiced_bt_lrac_sec_switch_execute(uint8_t seq, uint8_t *p_data, uint16_t length);

/*
 * wiced_bt_lrac_sec_switch_abort
 */
void wiced_bt_lrac_sec_switch_abort(void);

/*
 * wiced_bt_lrac_sec_switch_is_ready
 */
wiced_bool_t wiced_bt_lrac_sec_switch_is_ready(void);

/*
 * wiced_bt_lrac_sec_switch_get
 */
wiced_result_t wiced_bt_lrac_sec_switch_get(void *p_opaque, uint16_t *p_sync_data_len);

/*
 * wiced_bt_lrac_sec_switch_set
 */
wiced_result_t wiced_bt_lrac_sec_switch_set(void *p_opaque, uint16_t sync_data_len);

/*
 * wiced_bt_lrac_sec_ctrl_error_handler
 */
void wiced_bt_lrac_sec_ctrl_error_handler(wiced_result_t error, wiced_bt_lrac_ctrl_opcode_t opcode);

/*
 * wiced_bt_lrac_sec_power_mode_handler
 */
void wiced_bt_lrac_sec_power_mode_change_handler(wiced_bt_power_mgmt_notification_t *p_mgmt);

/*
 * wiced_bt_lrac_sec_state_store
 */
void wiced_bt_lrac_sec_state_store(void);

/*
 * wiced_bt_lrac_sec_state_restore
 */
void wiced_bt_lrac_sec_state_restore(void);
