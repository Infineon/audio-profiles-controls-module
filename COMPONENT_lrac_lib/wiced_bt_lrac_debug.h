/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Debug functions
 *
 */
#pragma once

#include "wiced_bt_lrac_int.h"
#include "wiced_memory.h"

/*
 * l2cap ready error structure
 */
typedef struct
{
    uint16_t    status;
    uint16_t    handle;
    uint32_t    info;
} l2c_lrac_sync_ready_err_t;
extern l2c_lrac_sync_ready_err_t l2c_lrac_sync_ready_err;

/*
 * wiced_bt_lrac_debug_init
 */
wiced_result_t wiced_bt_lrac_debug_init(void);

/*
 * wiced_bt_lrac_debug_a2dp_start
 */
wiced_result_t wiced_bt_lrac_debug_a2dp_start(void);

/*
 * wiced_bt_lrac_debug_a2dp_stop
 */
wiced_result_t wiced_bt_lrac_debug_a2dp_stop(void);

/*
 * wiced_bt_lrac_debug_a2dp_missed_packets
 */
void wiced_bt_lrac_debug_a2dp_missed_packets(uint16_t first_seq_num, uint16_t a2dp_missed_packets);

/*
 * wiced_bt_lrac_debug_a2dp_tx_packets
 */
void wiced_bt_lrac_debug_a2dp_tx_packets(uint16_t seq_num, uint16_t length);

/*
 * wiced_bt_lrac_debug_a2dp_rx_packet
 */
void wiced_bt_lrac_debug_a2dp_rx_packet(uint16_t length);

/*
 * wiced_bt_lrac_debug_trace_print
 */
void wiced_bt_lrac_debug_trace_print(wiced_bt_lrac_trace_level_t trace_level, ...);

/*
 * wiced_bt_lrac_debug_lite_host_trace
 */
void wiced_bt_lrac_debug_lite_host_trace(lite_host_lrac_event_debug_t *p_debug_info);
