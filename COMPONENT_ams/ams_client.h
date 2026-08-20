/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* Header file for Bluetoth Low Energy (LE) Client for Apple Notification Center Service (ANCS)
*
*/
#ifndef __AMS_CLIENT_H_
#define __AMS_CLIENT_H_

#include "wiced_bt_ams.h"
#include "wiced_bt_trace.h"

#if (AMS_CLIENT_DEBUG_ENABLE != 0)
#define AMS_CLIENT_TRACE(format, ...) \
        WICED_BT_TRACE(format, ##__VA_ARGS__)
#else
#define AMS_CLIENT_TRACE(...)
#endif

// service discovery states
enum
{
    AMS_CLIENT_STATE_IDLE                                           = 0x00,
    AMS_CLIENT_STATE_DISCOVER_ENTITY_UPDATE_CCCD                    = 0x01,
    AMS_CLIENT_STATE_WRITE_ENTITY_UPDATE_CCCD                       = 0x02,
    AMS_CLIENT_STATE_WRITE_ENTITY_UPDATE_PLAYER                     = 0x03,
    AMS_CLIENT_STATE_WRITE_ENTITY_UPDATE_QUEUE                      = 0x04,
    AMS_CLIENT_STATE_WRITE_ENTITY_UPDATE_TRACK                      = 0x05,
};

/******************************************************
 *                     Structures
 ******************************************************/
typedef struct t_AMS_CLIENT
{
    uint8_t   state;
    uint16_t  conn_id;
    uint16_t  ams_e_handle;
    uint16_t  remote_control_char_hdl;
    uint16_t  remote_control_val_hdl;
    uint16_t  entity_update_char_hdl;
    uint16_t  entity_update_val_hdl;
    uint16_t  entity_update_cccd_hdl;
    uint16_t  entity_attribute_char_hdl;
    uint16_t  entity_attribute_val_hdl;

    uint8_t   playback_status;

    wiced_bt_ams_client_event_handler_t *p_app_cb;
} AMS_CLIENT;

extern AMS_CLIENT  *ams_client;

#endif // __AMS_CLIENT_H_
