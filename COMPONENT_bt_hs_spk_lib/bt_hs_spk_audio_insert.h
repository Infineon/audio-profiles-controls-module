/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include "wiced.h"

#pragma once

/*
 * bt_hs_spk_audio_insert_init
 */
wiced_result_t bt_hs_spk_audio_insert_init(void);

/*
 * bt_hs_spk_audio_insert_stop
 */
wiced_result_t bt_hs_spk_audio_insert_stop(void);

/*
 * bt_hs_spk_audio_insert_state_check
 *
 * Check if the audio insertion is ongoing
 *
 * @param[in]   sco: Set to TRUE to check the SCO audio insert state
 *
 * @return  WICED_TRUE: audio insertion is ongoing
 */
wiced_bool_t bt_hs_spk_audio_insert_state_check(wiced_bool_t sco);
