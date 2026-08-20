/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/**
 * @file
 *
 * Platform definition header
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "wiced.h"
#include "wiced_rtos.h"
#include "platform_audio_codec.h"

uint32_t platform_audio_device_count(void);
uint32_t platform_audio_effects_count(void);
extern platform_audio_device_interface_t *platform_audio_device_list[];


#ifdef __cplusplus
} /*extern "C" */
#endif
