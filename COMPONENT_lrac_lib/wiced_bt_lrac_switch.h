/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Switch functions
 *
 */
#pragma once

#include "wiced_bt_lrac_int.h"

/* Enable this compile option to enable LRAC Switch Debug traces */
//#define LRAC_SWITCH_TRACE_ENABLED

/* LRAC Switch Trace macro(s) */
#ifdef LRAC_SWITCH_TRACE_ENABLED
/* LRAC_SWITCH_TRACE_DBG can be enabled/disabled */
#define LRAC_SWITCH_TRACE_DBG(format, ...)  WICED_BT_TRACE("%s: " format, __FUNCTION__, ##__VA_ARGS__)
#else
#define LRAC_SWITCH_TRACE_DBG(...)
#endif

#define WICED_BT_LRAC_SWITCH_TAG_FW_START           0x7A
#define WICED_BT_LRAC_SWITCH_TAG_FW_END             0x7F
#define WICED_BT_LRAC_SWITCH_TAG_FW_NUM             (WICED_BT_LRAC_SWITCH_TAG_FW_END - WICED_BT_LRAC_SWITCH_TAG_FW_START + 1)
#define WICED_BT_LRAC_SWITCH_TAG_COMPRESSED         0x80

/* duration of the timer to wait for L2CAP to be ready to switch */
#define WICED_BT_LRAC_SWITCH_L2CAP_WAIT_DURATION    200

/* duration of the wait pending replacement timer and max retry counts */
#define WICED_BT_LRAC_SWITCH_PENDING_REPLACEMENT_WAIT_DURATION      10
#define WICED_BT_LRAC_SWITCH_MAX_PENDING_REPLACEMENT_RETRY_COUNT    10

/* duration of maximum PS-SWITCH ready time */
#define LRAC_MAX_PS_SWITCH_READY_TIME_US    60000   /* 60 ms */

typedef void (wiced_bt_lrac_switch_l2cap_ready_callback_t)(wiced_bool_t l2cap_ready);

/*
 * wiced_bt_lrac_switch_init
 */
wiced_result_t wiced_bt_lrac_switch_init(void);

/*
 * wiced_bt_lrac_switch_is_ready
 */
wiced_bool_t wiced_bt_lrac_switch_is_ready(void);

/*
 * wiced_bt_lrac_switch_data_collect
 */
wiced_result_t wiced_bt_lrac_switch_data_collect(void);

/*
 * wiced_bt_lrac_switch_data_apply
 */
wiced_result_t wiced_bt_lrac_switch_data_apply(uint8_t tag, uint8_t *p_data, uint16_t length);

/*
 * wiced_bt_lrac_switch_get_set_tag
 */
uint8_t wiced_bt_lrac_switch_get_set_tag(void *p_opaque);

/*
 * wiced_bt_lrac_switch_l2cap_wait
 */
wiced_bool_t wiced_bt_lrac_switch_l2cap_wait(
        wiced_bt_lrac_switch_l2cap_ready_callback_t *p_callback, uint32_t timer_duration_ms,
        wiced_bool_t force);

/*
 * wiced_bt_lrac_switch_disconnected
 */
void wiced_bt_lrac_switch_disconnected(void);
