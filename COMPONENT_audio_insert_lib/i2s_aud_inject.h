/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include "stdint.h"
#include "wiced_bt_a2dp_defs.h"

/*
 * I2s Audio Inject Event definitions
 */
typedef enum
{
#if defined(CYW20721B2) || defined(CYW43012C0)
    I2S_AUD_INJECT_EVT_FILL_FIFO    = 1, /* i2s aud inject request to fill hardware FIFO with audio data */
    I2S_AUD_INJECT_EVT_AUDIO_INFO   = 2, /* i2s aud inject indicates the sample rate for the pending audio injection */
    LITE_HOST_EVT_START_SCO_INJECT  = 3, /* Lite Host indicates start SCO audio injection */
    /* ... Add other events here */
#else
    I2S_AUD_INJECT_EVT_FILL_FIFO = 3,/* i2s aud inject request to fill hardware FIFO with audio data */
    I2S_AUD_INJECT_EVT_AUDIO_INFO,   /* i2s aud inject indicates the sample rate for the pending audio injection */
    /* ... Add other events here */
#endif
} i2s_aud_inject_event_t;

/* Data associated with I2S_AUD_INJECT_EVT_FILL_FIFO event */
typedef struct
{
    int16_t *p_source;                      /* Decoded data from A2DP stream */
    int16_t *p_finalOutput;                 /* Pointer to output buffer */
    uint16_t bufferSize;                    /* size of the buffer that needs to be filled */
} i2s_aud_inject_event_fill_fifo_t;

/* Data associated with LITE_HOST_LRAC_EVT_AUDIO_INFO event */
typedef struct
{
    uint16_t sampleRate;                      /* Sample rate for pending audio injection */
    uint16_t bufferSize;                      /* size of the buffer that needs to be filled */
} i2s_aud_inject_event_audio_info_t;

typedef union
{

    i2s_aud_inject_event_fill_fifo_t    a2dp_samples;
    i2s_aud_inject_event_audio_info_t   a2dp_info;
#ifdef CYW20721B2
    i2s_aud_inject_event_audio_info_t   sco_start;
#endif
    /* Add other event data structure here ... */
} i2s_aud_inject_event_data_t;

/*
 * Definition of the I2S Aud Inject Callback (used to send event to the Wiced App/Lib)
 */
typedef void (i2s_aud_inject_callback_t)(i2s_aud_inject_event_t event,
        i2s_aud_inject_event_data_t *p_data);

/*
 * i2s_aud_inject_init
 */
wiced_result_t i2s_aud_inject_init(i2s_aud_inject_callback_t *p_callback);

/*
 * i2s_aud_inject_enableI2SAudioInject
 */

wiced_result_t i2s_aud_inject_enableI2SAudioInject(uint8_t enable, uint32_t *sampleRate);
