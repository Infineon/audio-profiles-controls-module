/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include "wiced_bt_audio_record.h"
#include "wiced_bt_trace.h"

#ifdef AUDIO_RECORD_ON_PDM_INPUT
#include "pdm_aud_record.h"
#define PDM_DB_GAIN 42
#else
#include "i2s_aud_record.h"
#endif

/*
 * wiced_bt_audio_record_init
 */
wiced_result_t wiced_bt_audio_record_init(wiced_bt_audio_record_callback_t * p_callback)
{
    wiced_result_t status = WICED_BT_SUCCESS;
    wiced_bool_t input_interface_status;

    WICED_BT_TRACE("%s: p_callback = 0x%x\n", __func__, p_callback);

#ifdef AUDIO_RECORD_ON_PDM_INPUT
    input_interface_status = pdm_aud_record_init(p_callback);
#else
    /* Call the I2S Audio Record Init function.
     * Note that we can pass the application's callback function because the FW and Wiced
     * APIs use the exact definitions (definitions and structures)
     */
    input_interface_status = i2s_aud_record_init((i2s_aud_record_callback_t *)p_callback);
#endif

    if (input_interface_status == WICED_FALSE)
    {
        status = WICED_BT_ERROR;
        WICED_BT_TRACE("%s: aud_record_init failed\n", __func__);
    }

    return status;
}

/*
 * wiced_bt_audio_record_enable
 */
wiced_result_t wiced_bt_audio_record_enable(uint8_t enable, uint32_t *p_sample_rate)
{
    wiced_result_t status = WICED_BT_SUCCESS;
    wiced_bool_t input_interface_status;

    if ((enable) && (p_sample_rate == NULL))
    {
        WICED_BT_TRACE("ERR: %s: p_sample_rate cannot be NULL when enable is 1\n", __func__);
        return WICED_BT_BADARG;
    }

    if (enable)
        WICED_BT_TRACE("%s: enabled sample_rate = %d\n", __func__, *p_sample_rate);
    else
        WICED_BT_TRACE("%s: disabled\n", __func__);

#ifdef AUDIO_RECORD_ON_PDM_INPUT
    input_interface_status = pdm_aud_record_enablePdmAudioRecord(enable, p_sample_rate, PDM_DB_GAIN);
#else
    input_interface_status = i2s_aud_record_enableI2SAudioRecord(enable, p_sample_rate);
#endif

    if (input_interface_status == WICED_FALSE)
    {
        status = WICED_BT_ERROR;
        WICED_BT_TRACE("ERR: %s: enable audio record failed status:%d\n", __func__, status);
    }

    if ((enable) && (status == WICED_BT_SUCCESS))
    {
        WICED_BT_TRACE("%s: configured sample_rate:%d\n", __func__, *p_sample_rate);
    }

    return status;
}
