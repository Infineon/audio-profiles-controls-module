/*
 * $ Copyright Cypress Semiconductor $
 */
/** @file
*
* MP3 Decoder Header File
*
* This file provides definitions and function prototypes for MP3 decoder module
*
*/

#pragma once
//=================================================================================================
//  Includes
//=================================================================================================
#include "wiced.h"
#include "wiced_rtos.h"

//=================================================================================================
//  Macros and Literal Definitions
//=================================================================================================

//=================================================================================================
//  Type Definitions and Enums
//=================================================================================================
/** MP3 Audio Frame Sampling Rate (Hz) */
typedef enum wiced_bt_mp3_sampling_rate
{
    WICED_BT_MP3_SAMPLING_RATE_44100    = 0,
    WICED_BT_MP3_SAMPLING_RATE_48000    = 1,
    WICED_BT_MP3_SAMPLING_RATE_32000    = 2,
    WICED_BT_MP3_SAMPLING_RATE_RESERVED = 3,
} wiced_bt_mp3_sampling_rate_t;

/** MP3 Audio Frame Channel. */
typedef enum wiced_bt_mp3_channel
{
    WICED_BT_MP3_CHANNEL_STEREO         = 0,
    WICED_BT_MP3_CHANNEL_JOINT_STEREO   = 1,
    WICED_BT_MP3_CHANNEL_DUAL           = 2,
    WICED_BT_MP3_CHANNEL_MONO           = 3,
} wiced_bt_mp3_channel_t;

/**
 * MP3 Audio Frame information.
 */
typedef struct
{
    wiced_bt_mp3_sampling_rate_t    sampling_rate;
    wiced_bt_mp3_channel_t          channel;
    void                            *data;
} wiced_bt_mp3_decoder_audio_frame_into_t;

/**
 * Callback function when the MP3 audio frame information is changed.
 *
 * @param p_audio_info  : Audio frame information
 */
typedef void wiced_bt_mp3_decoder_audio_info_update_cb(wiced_bt_mp3_decoder_audio_frame_into_t *p_audio_info);

//=================================================================================================
//  Structure
//=================================================================================================
/**
 * MP3 Decoder Configuration
 */
typedef struct
{
    uint32_t                                        buf_len_mp3_data;   // length (in bytes) of buffer that stores the MP3 source data
    wiced_bt_mp3_decoder_audio_info_update_cb       *p_audio_info_update_cb;
} wiced_bt_mp3_decoder_config_t;

//=================================================================================================
//  Function Declaration
//=================================================================================================
/**
 * wiced_bt_mp3_decoder_init
 *
 * Initialize the MP3 Decoder module
 *
 * @param   p_config[in]    : Configuration
 *
 * @return  WICED_TRUE  : Success
 *          WICED_FALSE : Fail
 */
wiced_bool_t wiced_bt_mp3_decoder_init(wiced_bt_mp3_decoder_config_t *p_config);

/**
 * wiced_bt_mp3_decoder_reset
 *
 * Reset the MP3 decoder module.
 *
 * Note: The user application shall call this utility once a new MP3 file is ready to
 *       be sent to the decoder module for decoding.
 */
void wiced_bt_mp3_decoder_reset(void);

/**
 * wiced_bt_mp3_decoder_source_data_add
 *
 * Add MP3 data to the decoder module.
 *
 * @param[in]   p_src   : pointer to the MP3 source data to be added to the decoder module
 * @param[in]   src_len : length of MP3 source data to be added to the decoder module
 *
 * @return  length of source data that has been added to the decoder module
 */
uint32_t wiced_bt_mp3_decoder_source_data_add(uint8_t *p_src, uint32_t src_len);

/**
 * wiced_bt_mp3_decoder_source_data_available_space_get
 *
 * Get the available space in the MP3 source data buffer.
 *
 * @return  Available space in bytes
 */
uint32_t wiced_bt_mp3_decoder_source_data_available_space_get(void);

/**
 * wiced_bt_mp3_decoder_pcm_samples_generate
 *
 * Generate the PCM samples.
 *
 * User application shall use wiced_bt_mp3_decoder_source_data_add utility to feed the MP3
 * source data (this call be MP3 files or MP3 Audio Frames) into the MP3 Decoder Module before
 * call this utility to generate the PCM samples
 */
void wiced_bt_mp3_decoder_pcm_samples_generate(void);

/**
 * wiced_bt_mp3_decoder_pcm_data_get
 *
 * Get the decoded PCM data from the decoder module.
 *
 * @param[in]   len     : data length to be get
 * @param[in]   p_out   : pointer to the output buffer where the decoded PCM data shall be copied to
 *
 * @return      actual PCM data length that has been copied
 */
uint32_t wiced_bt_mp3_decoder_pcm_data_get(uint32_t len, uint8_t *p_out);

/**
 * wiced_bt_mp3_audio_frame_info_get
 *
 * Get current audio frame information
 *
 * @return  audio frame information
 */
wiced_bt_mp3_decoder_audio_frame_into_t *wiced_bt_mp3_audio_frame_info_get(void);

//=================================================================================================
//	End of File (wiced_bt_mp3_decoder.h)
//=================================================================================================
