/******************************************************************************
* File Name:   gpio_button.h
*
* Description: GPIO-based Button APIs
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

#include "cyhal_gpio.h"

/*******************************************************************************
*        Macro Definitions
*******************************************************************************/

/*******************************************************************************
*        Structure/Enum Definitions
*******************************************************************************/
typedef enum
{
    GPIO_BUTTON_ACTIVE_STATE_LOW    = 0,    /**< ACTIVE LOW */
    GPIO_BUTTON_ACTIVE_STATE_HIGH   = 1,    /**< ACTIVE HIGH */
} gpio_button_active_state_t;

typedef struct
{
    cyhal_gpio_t                gpio;
    gpio_button_active_state_t  polarity;
    cyhal_gpio_event_t          trigger;
} gpio_button_t;

typedef void (*gpio_button_state_change_callback_t)(gpio_button_t *button, bool new_state);

/*******************************************************************************
*        External Variable Declarations
*******************************************************************************/

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
cy_rslt_t   gpio_button_deinit(const gpio_button_t *button);
cy_rslt_t   gpio_button_disable(const gpio_button_t *button);
cy_rslt_t   gpio_button_enable(const gpio_button_t *button);
bool        gpio_button_get_value(const gpio_button_t *button);
cy_rslt_t   gpio_button_init(const gpio_button_t *button);
cy_rslt_t   gpio_button_register_state_change_callback(gpio_button_state_change_callback_t callback);

#ifdef __cplusplus
} /*extern "C" */
#endif

/* [] END OF FILE */
