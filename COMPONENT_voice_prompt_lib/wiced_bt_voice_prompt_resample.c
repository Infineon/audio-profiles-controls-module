/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Resampling functions
 *
 */

#include "wiced.h"
#include "wiced_bt_voice_prompt_int.h"

/*
 * Global variable
 */
static pcm_s16_t saved_sample;

/*
 * wiced_bt_voice_prompt_resample_reset
 */
void wiced_bt_voice_prompt_resample_reset(void)
{
    saved_sample = 0;
}

/*
 * wiced_bt_voice_prompt_resample_up_2
 */
uint32_t wiced_bt_voice_prompt_resample_up_2(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples)
{
    int i;
    pcm_s16_t sample;
    int delta;

    if (nb_src_samples == 0)
    {
        VOICE_PROMPT_TRACE_ERR("No source samples\n");
        return 0;
    }

    /* Check if the destination buffer is big enough */
    if (nb_dst_samples < (nb_src_samples * 2))
    {
        VOICE_PROMPT_TRACE_ERR("Destination buffer too small\n");
        return 0;
    }

    /* Calculate the delta with the previous (saved) sample and the first one */
    delta = (*p_src - saved_sample) / 2;
    /* Write these upsampled samples */
    *p_dst++ = saved_sample;
    *p_dst++ = saved_sample + delta;

    /* If the Source buffer contains one single sample (should not happen) */
    if (nb_src_samples == 1)
    {
        return 2;
    }

    /* For every Sample from the Source buffer (excepted the last one) */
    for (i = 0 ; i < nb_src_samples - 1; i++)
    {
        /* Read the sample */
        sample = *p_src++;
        /* Calculate the delta with the next sample and divide it by 2 */
        delta = (*p_src - sample) / 2;
        /* Write the original sample in the destination buffer */
        *p_dst++ = sample;
        /* Write the intermediate (extrapolated) sample */
        *p_dst++ = sample + delta;
    }

    /* For the last sample, as we don't know the next Sample, save it for next time */
    saved_sample = *p_src;

    return nb_src_samples * 2;
}

/*
 * wiced_bt_voice_prompt_resample_up_4
 */
uint32_t wiced_bt_voice_prompt_resample_up_4(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples)
{
    int i;
    pcm_s16_t sample;
    int delta;

    if (nb_src_samples == 0)
    {
        VOICE_PROMPT_TRACE_ERR("No source samples\n");
        return 0;
    }

    /* Check if the destination buffer is big enough */
    if (nb_dst_samples < (nb_src_samples * 4))
    {
        VOICE_PROMPT_TRACE_ERR("Destination buffer too small\n");
        return 0;
    }

    /* Calculate the delta with the previous (saved) sample and the first one */
    sample = saved_sample;
    delta = (*p_src - sample) / 4;
    /* Write these upsampled samples */
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample;

    /* If the Source buffer contains one single sample (should not happen) */
    if (nb_src_samples == 1)
    {
        return 4;
    }

    /* For every Sample from the Source buffer (excepted the last one) */
    for (i = 0 ; i < nb_src_samples - 1; i++)
    {
        /* Read the sample */
        sample = *p_src++;
        /* Calculate the delta with the next sample and divide it by 6 */
        delta = (*p_src - sample) / 4;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample;
    }

    /* For the last sample, as we don't know the next Sample, save it for next time */
    saved_sample = *p_src;

    return nb_src_samples * 4;
}

/*
 * wiced_bt_voice_prompt_resample_up_6
 */
uint32_t wiced_bt_voice_prompt_resample_up_6(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples)
{
    int i;
    pcm_s16_t sample;
    int delta;

    if (nb_src_samples == 0)
    {
        VOICE_PROMPT_TRACE_ERR("No source samples\n");
        return 0;
    }

    /* Check if the destination buffer is big enough */
    if (nb_dst_samples < (nb_src_samples * 6))
    {
        VOICE_PROMPT_TRACE_ERR("Destination buffer too small\n");
        return 0;
    }

    /* Calculate the delta with the previous (saved) sample and the first one */
    sample = saved_sample;
    delta = (*p_src - sample) / 6;
    /* Write these upsampled samples */
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample;

    /* If the Source buffer contains one single sample (should not happen) */
    if (nb_src_samples == 1)
    {
        return 6;
    }

    /* For every Sample from the Source buffer (excepted the last one) */
    for (i = 0 ; i < nb_src_samples - 1; i++)
    {
        /* Read the sample */
        sample = *p_src++;
        /* Calculate the delta with the next sample and divide it by 6 */
        delta = (*p_src - sample) / 6;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample;
    }

    /* For the last sample, as we don't know the next Sample, save it for next time */
    saved_sample = *p_src;

    return nb_src_samples * 6;
}

/*
 * wiced_bt_voice_prompt_resample_up_11
 */
uint32_t wiced_bt_voice_prompt_resample_up_11(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples)
{
    int i;
    pcm_s16_t sample;
    int delta;

    if (nb_src_samples == 0)
    {
        VOICE_PROMPT_TRACE_ERR("No source samples\n");
        return 0;
    }

    /* Check if the destination buffer is big enough */
    if (nb_dst_samples < (nb_src_samples * 11))
    {
        VOICE_PROMPT_TRACE_ERR("Destination buffer too small\n");
        return 0;
    }

    /* Calculate the delta with the previous (saved) sample and the first one */
    sample = saved_sample;
    delta = (*p_src - sample) / 11;
    /* Write these upsampled samples */
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample; sample += delta;
    *p_dst++ = sample;

    /* If the Source buffer contains one single sample (should not happen) */
    if (nb_src_samples == 1)
    {
        return 11;
    }

    /* For every Sample from the Source buffer (excepted the last one) */
    for (i = 0 ; i < nb_src_samples - 1; i++)
    {
        /* Read the sample */
        sample = *p_src++;
        /* Calculate the delta with the next sample and divide it by 11 */
        delta = (*p_src - sample) / 11;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample; sample += delta;
        *p_dst++ = sample;
    }

    /* For the last sample, as we don't know the next Sample, save it for next time */
    saved_sample = *p_src;

    return nb_src_samples * 11;
}

/*
 * wiced_bt_voice_prompt_resample_down_2
 */
uint32_t wiced_bt_voice_prompt_resample_down_2(pcm_s16_t *p_dst, uint32_t nb_dst_samples,
        const pcm_s16_t *p_src, uint32_t nb_src_samples)
{
    int i;
    pcm_s16_t sample;
    int increment;

    if (nb_src_samples == 0)
    {
        VOICE_PROMPT_TRACE_ERR("No source samples\n");
        return 0;
    }

    /* Check if the destination buffer is big enough */
    if (nb_dst_samples < (nb_src_samples / 2))
    {
        VOICE_PROMPT_TRACE_ERR("Destination buffer too small\n");
        return 0;
    }

    /* For every Sample from the Source buffer */
    for (i = 0 ; i < nb_src_samples / 2; i++)
    {
        /* Copy one sample */
        *p_dst++ = *p_src++;

        /* Ignore one sample from the source */
        p_src++;
    }

    return nb_src_samples / 2;
}
