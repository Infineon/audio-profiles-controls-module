/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * This file contains utility functions for Handsfree.
 */

#include "wiced_bt_types.h"


/*******************************************************************************
** Function         wiced_bt_hfp_hf_utils_str2uint16
** Description      This utility function converts a character string to an
**                  uint16_t value.  Acceptable values in string are 0-9.  If invalid
**                  string or string value too large, -1 is returned.  Leading
**                  spaces are skipped.
** Returns          Integer value or -1 on error.
*******************************************************************************/
int32_t wiced_bt_hfp_hf_utils_str2uint16(const char *p_s)
{
    int32_t val = 0;

    for (;*p_s == ' ' && *p_s != 0; p_s++);

    if (*p_s == 0) return -1;

    for (;;)
    {
        if ((*p_s < '0') || (*p_s > '9')) return -1;

        val += (int32_t) (*p_s++ - '0');

        if (val > 0xFFFF)
            return -1;

        if (*p_s == 0)
            return val;
        else
            val *= 10;
    }
}
