/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt Embedded Flash
 *
 */

#include "wiced_bt_voice_prompt_eflash.h"
#include "wiced_hal_eflash.h"
#include "wiced_vpc_decoder.h"
#include "bt_types.h"

/*
 * Definition
 */
#define VOICE_PROMPT_EFLASH_READ_SIZE_MAX  WICED_VPC_DECODER_INPUT_SIZE_MAX

/*
 * External Functions
 */
extern wiced_bool_t ef_read_enable(void);

/*
 * wiced_bt_voice_prompt_eflash_init
 */
uint32_t wiced_bt_voice_prompt_eflash_init(void)
{
    return wiced_hal_eflash_init();
}

/*
 * wiced_bt_voice_prompt_ef_read
 */
wiced_result_t wiced_bt_voice_prompt_eflash_read(uint32_t offset, void *p_buffer, uint32_t length)
{
    uint32_t read_offset;
    uint32_t read_length;
    uint32_t copy_shift;
    wiced_result_t status;
    uint8_t length_adjust[4] = { 0, 3, 2, 1 };
    uint8_t read_buffer[VOICE_PROMPT_EFLASH_READ_SIZE_MAX + 8];

    if (length > VOICE_PROMPT_EFLASH_READ_SIZE_MAX)
    {
        VOICE_PROMPT_TRACE_ERR("Flash Read size too big (%d/%d)\n", length,
                VOICE_PROMPT_EFLASH_READ_SIZE_MAX);
        return WICED_BT_BADARG;
    }
    /*
     * The Embedded Flash driver has some constraints on Offset and Length parameters which
     * must be 32 bits aligned.
     */
    read_offset = offset & 0xFFFFFFFC;
    copy_shift = offset & 0x3;
    read_length = offset & 0x3;

    read_length += length;
    read_length += length_adjust[read_length & 0x3];

    /* Read the Embedded Flash */
    status = wiced_hal_eflash_read(read_offset, read_buffer, read_length);
    if (status != WICED_SUCCESS)
    {
        VOICE_PROMPT_TRACE_ERR("wiced_hal_eflash_read failed\n");
        return WICED_BT_ERROR;
    }

    memcpy(p_buffer, &read_buffer[copy_shift], length);

    return WICED_BT_SUCCESS;
}
