/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * WICED BT Voice Prompt Internal definitions
 *
 */

#pragma once

#include "wiced.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_voice_prompt.h"
#include "wiced_bt_voice_prompt_pcb.h"
#include "wiced_bt_voice_prompt_fs.h"
#include "wiced_bt_voice_prompt_eflash.h"
#include "wiced_bt_voice_prompt_resample.h"


/* Enable/Disable APP Traces */
/* #define VOICE_PROMPT_TRACE_ENABLED */

/* Debug Trace macro(s) */
#ifdef VOICE_PROMPT_TRACE_ENABLED
/* VOICE_PROMPT_TRACE_DBG can be enabled/disabled */
#define VOICE_PROMPT_TRACE_DBG(format, ...) \
    do { \
        WICED_BT_TRACE("%s " format, __FUNCTION__, ##__VA_ARGS__); \
    } while(0)
#else
#define VOICE_PROMPT_TRACE_DBG(format, ...)
#endif

/* VOICE_PROMPT_TRACE_ERR is always enabled */
#define VOICE_PROMPT_TRACE_ERR(format, ...)  WICED_BT_TRACE("Err: %s " format, __FUNCTION__, ##__VA_ARGS__)

#ifndef NB_ELEMENTS
#define NB_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))
#endif
