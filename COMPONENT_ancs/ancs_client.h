/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* Header file for Bluetooth Low Energy (LE) Client for Apple Notification Center Service (ANCS)
*
*/
#ifndef __ANCS_CLIENT_H_
#define __ANCS_CLIENT_H_

#include "wiced_bt_trace.h"

#define ANCS_CLIENT_DEBUG_ENABLE        1
//#define ANCS_ADDITIONAL_TRACE           1

#if (ANCS_CLIENT_DEBUG_ENABLE != 0)
#define ANCS_CLIENT_TRACE(format, ...) \
        WICED_BT_TRACE(format, ##__VA_ARGS__)
#else
#define ANCS_CLIENT_TRACE(...)
#endif


#define ANCS_COMMAND_ID_GET_NOTIFICATION_ATTRIBUTES     0
#define ANCS_COMMAND_ID_GET_APP_ATTRIBUTES              1
#define ANCS_COMMAND_ID_PERFORM_NOTIFICATION_ACTION     2


// ANCS event as the library passes to the application
typedef struct
{
    void *p_next;   // pointer to the next event when in the queue
    struct
    {
        wiced_bt_ancs_client_notification_data_basic_t  basic;
        wiced_bt_ancs_client_notification_data_info_t   info;
    } data;
} ancs_client_event_t;

extern uint8_t  ancs_client_notification_attribute[];
extern uint16_t  ancs_client_notification_attribute_length[];
extern char *NotificationAttributeID[];


#endif // __ANCS_CLIENT_H_
