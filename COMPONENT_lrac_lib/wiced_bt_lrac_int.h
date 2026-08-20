/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 *
 */

/** @file
 *
 * WICED LRAC Internal definitions
 *
 */
#pragma once

#include <string.h>

#include "wiced.h"
#include "wiced_bt_types.h"
#include "wiced_bt_a2dp_defs.h"
#include "hcidefs.h"
#include "bt_types.h"
#include "lite_host_lrac.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_lrac.h"
#include "wiced_bt_lrac_con.h"
#include "wiced_bt_lrac_sdp.h"
#include "wiced_bt_lrac_hci.h"
#include "wiced_bt_lrac_ctrl.h"
#include "wiced_bt_lrac_core.h"
#include "wiced_bt_lrac_pri.h"
#include "wiced_bt_lrac_sec.h"
#include "wiced_bt_lrac_debug.h"
#include "wiced_bt_lrac_switch.h"

/*
 * Definitions
 */
/* Enable this compile option to enable LRAC Debug & Statistics */
#define LRAC_DEBUG
#define LRAC_FW_STATISTICS
#define LRAC_FW_STATISTICS_PERIOD       10   /* FW Statistics every 10 seconds */

/* Indicate if the Primary must be central of the PS Link (required for the moment) */
#define PRIMARY_CENTRAL

/* Define default value (1) for LRAC, Debug, Error and "Todo" traces */
#if !defined(LRAC_TRACE_DBG_ENABLED)
#define LRAC_TRACE_DBG_ENABLED  1
#endif
#if !defined(LRAC_TRACE_ERR_ENABLED)
#define LRAC_TRACE_ERR_ENABLED  1
#endif
#if !defined(LRAC_TRACE_TODO_ENABLED)
#define LRAC_TRACE_TODO_ENABLED 1
#endif

/* An intermediate Macro is needed to add the function's name and prefix */
#define _LRAC_TRACE(level, fmt, ...) \
        wiced_bt_lrac_debug_trace_print(level, fmt, ##__VA_ARGS__)

/* LRAC Trace macro(s) */

/* LRAC_TRACE_DBG can be enabled/disabled */
#if (LRAC_TRACE_DBG_ENABLED != 0)
#define LRAC_TRACE_DBG(format, ...) \
        _LRAC_TRACE(WICED_BT_LRAC_TRACE_LEVEL_DEBUG, format, ##__VA_ARGS__)
#else
#define LRAC_TRACE_DBG(...)
#endif

/* LRAC_TRACE_ERR can be enabled/disabled */
#if (LRAC_TRACE_ERR_ENABLED != 0)
#define LRAC_TRACE_ERR(format, ...) \
        _LRAC_TRACE(WICED_BT_LRAC_TRACE_LEVEL_ERROR, "ERR: %s: " format, __FUNCTION__, ##__VA_ARGS__)
#else
#define LRAC_TRACE_ERR(format, ...)
#endif

/* LRAC_TRACE_TODO can be enabled/disabled */
#if (LRAC_TRACE_TODO_ENABLED != 0)
#define LRAC_TRACE_TODO(format, ...) \
        _LRAC_TRACE(WICED_BT_LRAC_TRACE_LEVEL_ERROR, "TODO: %s: " format, __FUNCTION__, ##__VA_ARGS__)
#else
#define LRAC_TRACE_TODO(format, ...)
#endif

#define LRAC_BDCPY(dst_bdaddr, src_bdaddr) memcpy(dst_bdaddr, src_bdaddr, BD_ADDR_LEN);

#define LRAC_CON_CTRL_MTU_SIZE       1021

/*
 * Structures
 */
typedef struct
{
    wiced_bt_lrac_callback_t *p_callback;
    wiced_bt_device_address_t bdaddr;
    wiced_bool_t connected;
    wiced_bt_dev_power_mgmt_status_t power_mode;
    uint16_t sniff_interval;
    wiced_bt_lrac_trace_level_t trace_level;
    wiced_bool_t power_mgmt_processing;
} wiced_bt_lrac_cb_t;

/*
 * Global variables
 */
extern wiced_bt_lrac_cb_t wiced_bt_lrac_cb;
