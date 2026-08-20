/******************************************************************************
* File Name:   platform_button.h
*
* Description: DSP board platform button definition
*
* Related Document: None
*
*******************************************************************************
* $ Copyright 2021-YEAR Cypress Semiconductor $
*******************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
*        Header Files
*******************************************************************************/
#include <stdbool.h>

#include "cy_result.h"
#include "wiced_platform.h"
#include "wiced.h"

/*******************************************************************************
*        Macro Definitions
*******************************************************************************/
/**
 * Macro to determine the element index in an array from the element address
 */
#define ARRAY_POSITION(array, element_pointer)  (((uint32_t) element_pointer - (uint32_t) array) / sizeof(array[0]))

typedef void (*platform_button_state_change_callback_t)(platform_button_t id, wiced_bool_t new_state);

/*******************************************************************************
*        External Variable Declarations
*******************************************************************************/

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
cy_rslt_t   platform_button_deinit(platform_button_t button);
cy_rslt_t   platform_button_disable(platform_button_t button);
cy_rslt_t   platform_button_enable(platform_button_t button);
bool        platform_button_get_value(platform_button_t button);
cy_rslt_t   platform_button_init(platform_button_t button);
cy_rslt_t   platform_button_register_state_change_callback(platform_button_state_change_callback_t callback);

#ifdef __cplusplus
} /*extern "C" */
#endif

/* [] END OF FILE */
