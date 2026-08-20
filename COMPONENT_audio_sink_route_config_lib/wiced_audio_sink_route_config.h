/***************************************************************************//**
* \file <wiced_audio_sink_route_config.h>
*
* \brief
* 	Contains Route Config APIs and definitions for Audio Sink.
*
*//*****************************************************************************
* $ Copyright 2016-YEAR Cypress Semiconductor $
*******************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "wiced.h"
#include "wiced_bt_types.h"
#include "wiced_result.h"
#include "wiced_bt_a2dp_defs.h"
#include "wiced_audio_sink.h"
#include "wiced_bt_audio_codec.h"

/******************************************************************************
*                      Macros
******************************************************************************/

/******************************************************************************
*                    Constants
******************************************************************************/

/******************************************************************************
*                   Enumerations
******************************************************************************/

/******************************************************************************
*                 Type Definitions
******************************************************************************/

/******************************************************************************
*                    Structures
******************************************************************************/

/******************************************************************************
*                 Callback Type Definitions
******************************************************************************/

/******************************************************************************
*               Function Declarations
******************************************************************************/

/**
 *
 * Init route configuration library
 *
 * @param[in]       p_param         : audio tuning parameters
 * @param[in]       p_ext_codec     : external codec information
 *
 * @return          wiced_result_t
 */
wiced_result_t wiced_audio_sink_route_config_init(
        wiced_bt_a2dp_sink_audio_tuning_params_t *p_param,
        wiced_bt_a2dp_ext_codec_info_t *p_ext_codec);

/**
 *
 * Set route codec configuration to library
 *
 * @param[in]       audio_route     : type of audio route, @wiced_audio_route_t
 * @param[in]       codec_config    : pointer to the A2DP Codec info
 * @param[in]       handle          : AVDT handle
 * @param[in]       cp_type         : CP type
 * @param[in]       is_master       : TRUE if master side
 *
 * @return          void
 */
void wiced_audio_sink_route_config_set(uint32_t audio_route,
        wiced_bt_a2dp_codec_info_t *codec_config, uint16_t handle,
        uint16_t cp_type, wiced_bool_t is_master);

/**
 *
 * To configure an audio route.
 * Called by the application to configure an audio data route path.
 * The API is called after receiving a WICED_BT_A2DP_SINK_CODEC_CONFIG_EVT event
 *
 * @param[in]       handle          : AVDT handle
 * @param[in]       route_config    : route config paramters
 *
 * @return          wiced_bool_t
 */
wiced_bool_t wiced_audio_sink_route_config_update(uint16_t handle,
        wiced_bt_a2dp_sink_route_config *route_config);

/**
 *
 * Start the audio route for AVDT handle.
 *
 * @param[in]       handle          : AVDT handle
 *
 * @return          wiced_result_t
 */
wiced_result_t wiced_audio_sink_route_config_stream_start(uint16_t handle);

/**
 *
 * Stop the audio route for AVDT handle.
 *
 * @param[in]       handle          : AVDT handle
 *
 * @return          void
 */
wiced_result_t wiced_audio_sink_route_config_stream_stop(uint16_t handle);

/**
 *
 * Switch audio route for AVDT handle. It will stop the existent started
 * streaming then start the assigned one.
 *
 * @param[in]       handle          : AVDT handle
 *
 * @return          wiced_result_t
 */
wiced_result_t wiced_audio_sink_route_config_stream_switch(uint16_t handle);

/**
 *
 * Stop current started streaming and configure route to the target stream.
 * If there is no existent started streaming. the stream route for the
 * specific target will NOT be set.
 *
 * @param[in]       handle          : AVDT handle
 *
 * @return          void
 */
void wiced_audio_sink_route_config_stream_stop_and_switch(uint16_t handle);

/**
 *
 * Close and clear route configuration for AVDT handle.
 *
 * @param[in]       handle          : AVDT handle
 *
 * @return          void
 */
void wiced_audio_sink_route_config_close(uint16_t handle);

#ifdef __cplusplus
} /* extern "C" */
#endif
