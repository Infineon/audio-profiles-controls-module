/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 *
 */

#pragma once

#include <string.h>

#include "wiced.h"
#include "wiced_bt_types.h"

#ifdef CYW20721B2
/*
 * wiced_bt_lrac_lite_host_init
 */
wiced_result_t wiced_bt_lrac_lite_host_init(lite_host_lrac_callback_t *p_callback);
#endif
