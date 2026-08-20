/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Resampling functions
 *
 */

#include <stdint.h>
#include "wiced.h"

/*
 * wiced_bt_voice_prompt_resample_reset
 */
void wiced_bt_voice_prompt_resample_reset(void);

/*
 * wiced_bt_voice_prompt_resample_up_2
 * This function resamples UP a PCM buffer to a factor 2 (e.g. 8 kHz to 16 kHz).
 * The Destination buffer must be, at least, 2 times bigger than the Source buffer.
 * A basic, linear, interpolation algorithm is implemented.
 * Returns the number of samples written in the Destination buffer.
 */
uint32_t wiced_bt_voice_prompt_resample_up_2(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples);

/*
 * wiced_bt_voice_prompt_resample_up_6
 * This function resamples UP a PCM buffer to a factor 6 (e.g. 8 kHz to 48 kHz).
 * The Destination buffer must be, at least, 6 times bigger than the Source buffer.
 * A basic, linear, interpolation algorithm is implemented.
 * Returns the number of samples written in the Destination buffer.
 */
uint32_t wiced_bt_voice_prompt_resample_up_6(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples);

/*
 * wiced_bt_voice_prompt_resample_up_11
 * This function resamples UP a PCM buffer to a factor 11 (e.g. 8 kHz to 88 kHz).
 * The Destination buffer must be, at least, 11 times bigger than the Source buffer.
 * A basic, linear, interpolation algorithm is implemented.
 * Returns the number of samples written in the Destination buffer.
 */
uint32_t wiced_bt_voice_prompt_resample_up_11(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples);


/*
 * wiced_bt_voice_prompt_resample_down_2
 */
uint32_t wiced_bt_voice_prompt_resample_down_2(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples);
