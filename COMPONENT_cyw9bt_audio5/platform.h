/******************************************************************************
* File Name:   platform.h
*
* Description: Platform definition header
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
#include <stdint.h>

#include "platform_audio_codec.h"

#ifndef PLATFORM_AUDIO_DEBUG
#define PLATFORM_AUDIO_DEBUG 0
#endif // PLATFORM_AUDIO_DEBUG

#if (PLATFORM_AUDIO_DEBUG != 0)
#include <stdio.h>
#define PLATFORM_AUDIO_TRACE(format, ...) printf(format, ##__VA_ARGS__)
#else
#define PLATFORM_AUDIO_TRACE(...)
#endif

/*******************************************************************************
*        Macro Definitions
*******************************************************************************/

/*******************************************************************************
*        External Variable Declarations
*******************************************************************************/

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

uint32_t platform_audio_device_count(void);
uint32_t platform_audio_effects_count(void);
extern platform_audio_device_interface_t *platform_audio_device_list[];

#ifdef __cplusplus
} /*extern "C" */
#endif

/* [] END OF FILE */
