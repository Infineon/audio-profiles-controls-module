/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED LRAC Lite Host Wrapper
 *
 */

#include "wiced_bt_lrac_int.h"
#include "lite_host_lrac.h"

#ifdef CYW20721B2
wiced_result_t wiced_bt_lrac_lite_host_init(lite_host_lrac_callback_t *p_callback)
{
    BOOL32 ret = lite_host_lrac_init(p_callback);

    return (ret == TRUE) ? WICED_BT_SUCCESS : WICED_BT_ERROR;
}
#endif
