/**
 * @cond
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 * @endcond
 *
 * @file
 * Define utility APIs for handsfree
 */
#pragma once


/**
 *
 * Volume levels passed from the application to Audio Manager should be in the range 0 to 10
 * calculating from 0 to 15 levels to 0 to 10 levels
 *
 * @param           int32_t  : vol from app.
 *
 * @return          volume in AM level
 */
int32_t bt_hs_spk_handsfree_utils_hfp_volume_to_am_volume(int32_t vol);
