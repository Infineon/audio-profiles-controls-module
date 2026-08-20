/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#include "wiced.h"
#include "wiced_bt_audio_record.h"

typedef enum
{
    PDM_AUDIO_RECORD_EVENT_RX_PCM = 0,
} pdm_audio_record_event_t;


#define PDM_AUDIO_RECORD_FIFO_STATUS_OVERLAP   0x01
#define PDM_AUDIO_RECORD_FIFO_STATUS_FULL      0x02
typedef uint8_t pdm_audio_record_fifo_status_t;


typedef struct
{
    uint8_t channel;                         /**< Microphone channel (0 or 1) */
    uint8_t *p_data;                         /**< Pointer on PCM samples */
    uint32_t length;                         /**< Number of bytes in the p_data buffer */
    pdm_audio_record_fifo_status_t status; /**< Status */
} pdm_audio_record_rx_pcm_t;


typedef union
{
    pdm_audio_record_rx_pcm_t rx_pcm;
} pdm_audio_record_event_data_t;


typedef void (pdm_audio_record_callback_t)(pdm_audio_record_event_t event,
        pdm_audio_record_event_data_t *p_data);


wiced_bool_t pdm_aud_record_init(wiced_bt_audio_record_callback_t *p_callback);

wiced_result_t pdm_aud_record_enablePdmAudioRecord(uint8_t enable, uint32_t *p_sample_rate, uint8_t dB);

wiced_result_t pdm_aud_record_select_pads(uint32_t data_pin, uint32_t clock_pin);
#define wiced_bt_audio_record_select_pdm_pads(data_pin,clk_pin) pdm_aud_record_select_pads(data_pin,clk_pin)
