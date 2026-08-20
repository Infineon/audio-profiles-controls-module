/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Control Protocol functions
 *
 */

#pragma once

#include "wiced_bt_lrac_int.h"

/*
 * Definitions
 */

typedef enum
{
    LRAC_OPCODE_REJECT = 0x00,

    LRAC_OPCODE_PING_REQ,
    LRAC_OPCODE_PING_RSP,

    LRAC_OPCODE_VERSION_REQ,
    LRAC_OPCODE_VERSION_RSP,

    LRAC_OPCODE_CONF_REQ,
    LRAC_OPCODE_CONF_RSP,

    LRAC_OPCODE_DATA,

    /* A2DP Synchronization */
    LRAC_OPCODE_A2DP_START_REQ,
    LRAC_OPCODE_A2DP_START_RSP,
    LRAC_OPCODE_A2DP_STOP_REQ,
    LRAC_OPCODE_A2DP_STOP_RSP,
    LRAC_OPCODE_A2DP_STOP_IND,

    /* HFP Synchronization */
    LRAC_OPCODE_HFP_START_REQ,
    LRAC_OPCODE_HFP_START_RSP,
    LRAC_OPCODE_HFP_STOP_REQ,
    LRAC_OPCODE_HFP_STOP_RSP,
    LRAC_OPCODE_HFP_STOP_IND,

    /* Audio Insertion */
    LRAC_OPCODE_AUDIO_INSERT_START_REQ,
    LRAC_OPCODE_AUDIO_INSERT_START_RSP,
    LRAC_OPCODE_AUDIO_INSERT_STOP_REQ,
    LRAC_OPCODE_AUDIO_INSERT_STOP_RSP,

    /* ACL Eavesdropping (for Switch) */
    LRAC_OPCODE_UNUSED_ACL_START_REQ,
    LRAC_OPCODE_UNUSED_ACL_START_RSP,
    LRAC_OPCODE_UNUSED_ACL_STOP_REQ,
    LRAC_OPCODE_UNUSED_ACL_STOP_RSP,

    /* Switch */
    LRAC_OPCODE_SWITCH_REQ,
    LRAC_OPCODE_SWITCH_RSP,
    LRAC_OPCODE_SWITCH_DATA,
    LRAC_OPCODE_SWITCH_HANDSHAKE,
    LRAC_OPCODE_SWITCH_ABORT,

    LRAC_OPCODE_PARSE_ERROR = 0xFF
} wiced_bt_lrac_ctrl_opcode_t;

typedef struct
{
    wiced_bt_lrac_ctrl_opcode_t opcode;
    wiced_result_t error;
} wiced_bt_lrac_ctrl_reject_t;

typedef struct
{
    uint8_t major;
    uint8_t minor;
    uint16_t build;
} wiced_bt_lrac_ctrl_version_req_t;

typedef wiced_bt_lrac_ctrl_version_req_t wiced_bt_lrac_ctrl_version_rsp_t;

typedef struct
{
    uint8_t *p_data;
    uint16_t length;
} wiced_bt_lrac_ctrl_ping_req_t;

typedef wiced_bt_lrac_ctrl_ping_req_t wiced_bt_lrac_ctrl_ping_rsp_t;

typedef struct
{
    wiced_bt_lrac_role_t role;
    wiced_bt_lrac_audio_side_t audio_side;
} wiced_bt_lrac_ctrl_config_req_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_config_rsp_t;

typedef struct
{
    uint16_t first_seq_num;     /* First Sequence Number */
    uint8_t nb_seq_num;         /* Number Sequence numbers */
} wiced_bt_lrac_ctrl_a2dp_packet_get_t;

typedef struct
{
    uint16_t length;
    uint8_t *p_data;
} wiced_bt_lrac_ctrl_a2dp_packet_rx_t;

typedef struct
{
    uint8_t eavesdropping_param_len;
    uint8_t *p_eavesdropping_param;
    uint16_t media_cid;
    wiced_bool_t sync;
    uint16_t cp_type;
    wiced_bt_a2dp_codec_info_t codec_info;
} wiced_bt_lrac_ctrl_a2dp_start_req_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_a2dp_start_rsp_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_a2dp_stop_rsp_t;

typedef struct
{
    uint8_t eavesdropping_param_len;
    uint8_t *p_eavesdropping_param;
    uint8_t wide_band;
} wiced_bt_lrac_ctrl_hfp_start_req_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_hfp_start_rsp_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_hfp_stop_rsp_t;

typedef struct
{
    uint8_t eavesdropping_param_len;
    uint8_t *p_eavesdropping_param;
} wiced_bt_lrac_ctrl_acl_start_req_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_acl_start_rsp_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_acl_stop_rsp_t;

typedef wiced_bt_lrac_rx_data_t wiced_bt_lrac_ctrl_rx_data_t;

typedef struct
{
    uint8_t audio_file_index;
    uint32_t expected_sco_time_seq_num;
} wiced_bt_lrac_ctrl_audio_insert_start_req_t;

typedef wiced_bt_lrac_audio_insert_start_rsp_t wiced_bt_lrac_ctrl_audio_insert_start_rsp_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_audio_insert_stop_rsp_t;

typedef struct
{
    wiced_bt_lrac_role_t new_role;
    wiced_bool_t prevent_glitch;
} wiced_bt_lrac_ctrl_switch_req_t;

typedef struct
{
    wiced_result_t status;
} wiced_bt_lrac_ctrl_switch_rsp_t;

typedef struct
{
    uint8_t last;
    uint8_t *p_data;
    uint16_t length;
} wiced_bt_lrac_ctrl_switch_data_t;

typedef struct
{
    wiced_bt_lrac_switch_result_t status;
    wiced_bool_t fatal_error;
} wiced_bt_lrac_ctrl_switch_abort_t;

typedef union
{
    wiced_bt_lrac_ctrl_reject_t reject;
    wiced_bt_lrac_ctrl_version_req_t version_req;
    wiced_bt_lrac_ctrl_version_rsp_t version_rsp;
    wiced_bt_lrac_ctrl_ping_req_t ping_req;
    wiced_bt_lrac_ctrl_ping_rsp_t ping_rsp;
    wiced_bt_lrac_ctrl_config_req_t config_req;
    wiced_bt_lrac_ctrl_config_rsp_t config_rsp;
    wiced_bt_lrac_ctrl_a2dp_packet_get_t a2dp_packet_get;
    wiced_bt_lrac_ctrl_a2dp_start_req_t a2dp_start_req;
    wiced_bt_lrac_ctrl_a2dp_start_rsp_t a2dp_start_rsp;
    wiced_bt_lrac_ctrl_a2dp_stop_rsp_t a2dp_stop_rsp;
    wiced_bt_lrac_ctrl_hfp_start_req_t hfp_start_req;
    wiced_bt_lrac_ctrl_hfp_start_rsp_t hfp_start_rsp;
    wiced_bt_lrac_ctrl_hfp_stop_rsp_t hfp_stop_rsp;
    wiced_bt_lrac_ctrl_rx_data_t rx_data;
    wiced_bt_lrac_ctrl_audio_insert_start_req_t audio_insert_start_req;
    wiced_bt_lrac_ctrl_audio_insert_start_rsp_t audio_insert_start_rsp;
    wiced_bt_lrac_ctrl_audio_insert_stop_rsp_t audio_insert_stop_rsp;
    wiced_bt_lrac_ctrl_acl_start_req_t acl_start_req;
    wiced_bt_lrac_ctrl_acl_start_rsp_t acl_start_rsp;
    wiced_bt_lrac_ctrl_acl_stop_rsp_t acl_stop_rsp;
    wiced_bt_lrac_ctrl_switch_req_t switch_req;
    wiced_bt_lrac_ctrl_switch_rsp_t switch_rsp;
    wiced_bt_lrac_ctrl_switch_data_t switch_data;
    wiced_bt_lrac_ctrl_switch_abort_t switch_abort;
} wiced_bt_lrac_ctrl_data_t;

/*
 * wiced_bt_lrac_ctrl_init
 */
wiced_result_t wiced_bt_lrac_ctrl_init(void);

/*
 * wiced_bt_lrac_ctrl_rx_parse
 */
wiced_bt_lrac_ctrl_opcode_t wiced_bt_lrac_ctrl_rx_parse(wiced_bt_lrac_ctrl_data_t *p_ctrl_data,
        uint8_t *p_data, uint16_t length);

/*
 * wiced_bt_lrac_ctrl_send_reject
 */
wiced_result_t wiced_bt_lrac_ctrl_send_reject(wiced_bt_lrac_ctrl_opcode_t opcode,
        wiced_result_t error);

/*
 * wiced_bt_lrac_ctrl_send_version_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_version_req(void);

/*
 * wiced_bt_lrac_ctrl_send_version_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_version_rsp(void);

/*
 * wiced_bt_lrac_ctrl_send_ping_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_ping_req(uint16_t size);

/*
 * wiced_bt_lrac_ctrl_send_ping_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_ping_rsp(uint8_t *p_data, uint16_t size);

/*
 * wiced_bt_lrac_ctrl_send_configure_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_configure_req(wiced_bt_lrac_role_t peer_role,
        wiced_bt_lrac_audio_side_t peer_audio_side);

/*
 * wiced_bt_lrac_ctrl_send_configure_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_configure_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_a2dp_start_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_a2dp_start_req(uint8_t eavesdropping_param_len,
        uint8_t *p_eavesdropping_param, uint16_t media_cid,
        wiced_bt_a2dp_codec_info_t *p_codec_info, uint16_t cp_type,
        wiced_bool_t sync);

/*
 * wiced_bt_lrac_ctrl_send_a2dp_start_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_a2dp_start_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_a2dp_stop_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_a2dp_stop_req(void);

/*
 * wiced_bt_lrac_ctrl_send_a2dp_stop_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_a2dp_stop_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_a2dp_stop_ind
 */
wiced_result_t wiced_bt_lrac_ctrl_send_a2dp_stop_ind(void);

/*
 * wiced_bt_lrac_ctrl_send_hfp_start_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_hfp_start_req(uint8_t eavesdropping_param_len,
        uint8_t *p_eavesdropping_param, wiced_bool_t wide_band);

/*
 * wiced_bt_lrac_ctrl_send_hfp_start_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_hfp_start_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_hfp_stop_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_hfp_stop_req(void);

/*
 * wiced_bt_lrac_ctrl_send_hfp_stop_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_hfp_stop_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_hfp_stop_ind
 */
wiced_result_t wiced_bt_lrac_ctrl_send_hfp_stop_ind(void);

/*
 * wiced_bt_lrac_ctrl_tx_data
 */
wiced_result_t wiced_bt_lrac_ctrl_tx_data(uint8_t *p_data, uint16_t length);

/*
 * wiced_bt_lrac_ctrl_send_audio_insert_start_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_audio_insert_start_req(uint8_t audio_file_index,
        uint32_t expected_sco_time_seq_num);

/*
 * wiced_bt_lrac_ctrl_send_audio_insert_start_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_audio_insert_start_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_audio_insert_stop_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_audio_insert_stop_req(void);

/*
 * wiced_bt_lrac_ctrl_send_audio_insert_stop_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_audio_insert_stop_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_switch_req
 */
wiced_result_t wiced_bt_lrac_ctrl_send_switch_req(wiced_bt_lrac_role_t new_role,
        wiced_bool_t prevent_glitch);

/*
 * wiced_bt_lrac_ctrl_send_switch_rsp
 */
wiced_result_t wiced_bt_lrac_ctrl_send_switch_rsp(wiced_result_t status);

/*
 * wiced_bt_lrac_ctrl_send_switch_data
 */
wiced_result_t wiced_bt_lrac_ctrl_send_switch_data(uint8_t last, uint8_t *p_data,
                uint16_t length);

/*
 * wiced_bt_lrac_ctrl_send_switch_handshake
 */
wiced_result_t wiced_bt_lrac_ctrl_send_switch_handshake(void);

/*
 * wiced_bt_lrac_ctrl_send_switch_abort
 */
wiced_result_t wiced_bt_lrac_ctrl_send_switch_abort(wiced_bt_lrac_switch_result_t status,
        wiced_bool_t fatal_error);
