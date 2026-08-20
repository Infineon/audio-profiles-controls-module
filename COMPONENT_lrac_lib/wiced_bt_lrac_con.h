/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Connection (L2CAP)
 *
 */

#pragma once

#include <stdint.h>
#include "wiced_bt_lrac_int.h"

/* Define the HID Connection Block
*/

typedef enum
{
    WICED_BT_LRAC_CON_CONNECTED,            /* LRAC Connected */
    WICED_BT_LRAC_CON_DISCONNECTED,         /* LRAC Disconnected */
    WICED_BT_LRAC_CON_RX_DATA,              /* LRAC Data Received */
} wiced_bt_lrac_con_event_t;

typedef struct
{
    wiced_bt_device_address_t bdaddr;
    wiced_result_t status;
} wiced_bt_lrac_con_connected_t;

typedef struct
{
    uint16_t reason;
} wiced_bt_lrac_con_disconnected_t;

typedef struct
{
    uint8_t *p_data;
    uint16_t length;
} wiced_bt_lrac_con_rx_data_t;

typedef union
{
    wiced_bt_lrac_con_connected_t connected;
    wiced_bt_lrac_con_disconnected_t disconnected;
    wiced_bt_lrac_con_rx_data_t rx_data;
} wiced_bt_lrac_con_data_t;

/* LRAC Connection Callback */
typedef void (wiced_bt_lrac_con_cback_t) (wiced_bt_lrac_con_event_t event,
        wiced_bt_lrac_con_data_t *p_data);

/* LRAC Duplicate Connection Callback */
typedef void (wiced_bt_lrac_con_duplicate_disconnect_cback_t)(void);

/*
 * wiced_bt_lrac_con_init
 */
wiced_result_t wiced_bt_lrac_con_init(wiced_bt_lrac_con_cback_t *p_cback);

/*
 * wiced_bt_lrac_con_connect
 */
wiced_result_t wiced_bt_lrac_con_connect(wiced_bt_device_address_t bdaddr);

/*
 * wiced_bt_lrac_con_disconnect
 */
wiced_result_t wiced_bt_lrac_con_disconnect(void);

/*
 * wiced_bt_lrac_con_duplicate_disconnect
 */
wiced_result_t wiced_bt_lrac_con_duplicate_disconnect(
        wiced_bt_lrac_con_duplicate_disconnect_cback_t *p_callback);

/*
 * wiced_bt_lrac_con_tx_data
 */
wiced_result_t wiced_bt_lrac_con_tx_data(uint8_t *p_data, uint16_t length);

/*
 * wiced_bt_lrac_con_switch_get
 */
wiced_result_t wiced_bt_lrac_con_switch_get(void *p_opaque, uint16_t *p_sync_data_len);

/*
 * wiced_bt_lrac_con_switch_set
 */
wiced_result_t wiced_bt_lrac_con_switch_set(void *p_opaque, uint16_t sync_data_len);
