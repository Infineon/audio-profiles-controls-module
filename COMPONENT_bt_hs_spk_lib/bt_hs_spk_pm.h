/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */


/** @file
 *
 * This file provides the interface definitions for power management
 *
 */
#pragma once
#include "wiced_result.h"
#include "bt_hs_spk_control.h"

wiced_result_t bt_hs_spk_pm_init(bt_hs_spk_control_config_sleep_t *p_config);
wiced_result_t bt_hs_spk_pm_deinit(void);
void bt_hs_spk_pm_enable(void);
void bt_hs_spk_pm_disable(void);
