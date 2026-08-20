/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * This file implements the utility functions for handsfree
 */

#include <stdlib.h>
#include <string.h>
#include "wiced_audio_manager.h"
#include "bt_hs_spk_handsfree.h"


/**
 *
 * Volume levels passed from the application to Audio Manager should be in the range 0 to 10
 * calculating from 0 to 15 levels to 0 to 10 levels
 *
 * @param           int32_t  : vol from app.
 *
 * @return          volume in AM level
 */
int32_t bt_hs_spk_handsfree_utils_hfp_volume_to_am_volume(int32_t vol)
{
    uint32_t remainder;
    int32_t am_level;

    am_level    = (vol * AM_VOL_LEVEL_HIGH) / HFP_VOLUME_HIGH;
    remainder   = (vol * AM_VOL_LEVEL_HIGH) % HFP_VOLUME_HIGH;

    if (remainder >= AM_VOL_LEVEL_HIGH)
    {
        am_level++;
    }

    return am_level;
}
