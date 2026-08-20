/*
 *  $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include "stdint.h"
#include "wiced_bt_a2dp_defs.h"

/*
 * I2S AUD RECORD Event definitions
 */
typedef enum
{
    I2S_AUD_RECORD_EVT_EMPTY_FIFO   = 3, /* i2s aud record request to empty hardware FIFO */
    I2S_AUD_RECORD_EVT_AUDIO_INFO   = 4, /* i2s aud record indicates the sample rate for the pending audio recording */
    /* ... Add other events here */
} i2s_aud_record_event_t;

/* Data associated with I2S_AUD_RECORD_EVT_FILL_FIFO event */
typedef struct
{
    int16_t *p_source;                      /* Decoded data from A2DP stream */
    uint16_t bufferSize;                    /* size of the buffer that needs to be filled */
} i2s_aud_record_event_empty_fifo_t;

/* Data associated with I2S_AUD_RECORD_EVT_AUDIO_INFO event */
typedef struct
{
    uint16_t sampleRate;                     /* Sample rate for pending audio injection */
    uint16_t bufferSize;                     /* size of the buffer that needs to be filled */
} i2s_aud_record_event_audio_info_t;

typedef union
{
    i2s_aud_record_event_empty_fifo_t   record_samples;
    i2s_aud_record_event_audio_info_t   record_info;
    /* Add other event data structures here ... */
} i2s_aud_record_event_data_t;

typedef void (i2s_aud_record_callback_t)(i2s_aud_record_event_t event,
        i2s_aud_record_event_data_t *p_data);

/*
 * i2s_aud_inject_init
 */
wiced_bool_t i2s_aud_record_init(i2s_aud_record_callback_t *p_callback);

/*
 * i2s_aud_inject_enableI2SAudioInject
 */
wiced_result_t i2s_aud_record_enableI2SAudioRecord(uint8_t enable, uint32_t *sampleRate);
