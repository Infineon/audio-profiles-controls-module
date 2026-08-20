/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Host SDP functions
 *
 */

#pragma once

#include "wiced_bt_lrac_int.h"

/*
 * Definitions
 */

/*
 * Types
 */

/*
 * Globals
 */

/*
 * wiced_bt_lrac_sdp_init
 */
wiced_result_t wiced_bt_lrac_sdp_init(void);

/*
 * wiced_bt_lrac_sdp_discover
 */
wiced_result_t wiced_bt_lrac_sdp_discover(wiced_bt_device_address_t bdaddr);
