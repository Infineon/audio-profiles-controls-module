/******************************************************************************
* File Name:   platform_button.c
*
* Description: Common Button implementation for platforms that only use GPIO buttons.
*              If a platform has other, non-GPIO based buttons it must override all
*              the functions defined within this file.
*
* Related Document:
*
*
*******************************************************************************
* $ Copyright 2021-YEAR Cypress Semiconductor $
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "platform_button.h"

#include <stdbool.h>
#include <stddef.h>

#include "gpio_button.h"
#include "cy_result.h"
#include "wiced_platform.h"

/*******************************************************************************
* Macros
********************************************************************************/


/*******************************************************************************
* Global Variables
********************************************************************************/
extern gpio_button_t platform_gpio_buttons[PLATFORM_BUTTON_MAX];
static platform_button_state_change_callback_t user_callback = NULL;

/*******************************************************************************
* Function Prototypes
********************************************************************************/
static void platform_button_state_change_callback(gpio_button_t *button, bool new_state);

/*******************************************************************************
* Global Function Definitions
*******************************************************************************/
cy_rslt_t platform_button_init(platform_button_t button)
{
    return gpio_button_init(&platform_gpio_buttons[button]);
}

cy_rslt_t platform_button_deinit(platform_button_t button)
{
    return gpio_button_deinit(&platform_gpio_buttons[button]);
}

cy_rslt_t platform_button_enable(platform_button_t button)
{
    return gpio_button_enable(&platform_gpio_buttons[button]);
}

cy_rslt_t platform_button_disable(platform_button_t button)
{
    return gpio_button_disable(&platform_gpio_buttons[button]);
}

bool platform_button_get_value(platform_button_t button)
{
    return gpio_button_get_value(&platform_gpio_buttons[button]);
}

cy_rslt_t platform_button_register_state_change_callback(platform_button_state_change_callback_t callback)
{
    user_callback = callback;
    return gpio_button_register_state_change_callback(platform_button_state_change_callback);
}

/*******************************************************************************
* Static Function Definitions
*******************************************************************************/
static void platform_button_state_change_callback(gpio_button_t *button, bool new_state)
{
    user_callback((platform_button_t) ARRAY_POSITION(platform_gpio_buttons, button), new_state);
}

/* [] END OF FILE */
