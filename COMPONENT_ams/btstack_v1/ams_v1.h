/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * ams_v1.h
 * This file is applicable for all devices with BTSTACK version lower than 3.0, i.e. 20xxx and 43012C0
 *
 */
#ifndef _AMS_H_
#define _AMS_H_

#include "wiced_memory.h"
#include "ams_client.h"

/******************************************************
 *               defines
 ******************************************************/

/******************************************************
 *               typedef
 ******************************************************/

/******************************************************
 *               Function Definitions
 ******************************************************/
wiced_bt_gatt_status_t ams_client_entity_update_write(uint8_t index, uint8_t entity_id, uint8_t *p_attributes, int num_attributes);

/******************************************************
 *               Macro Function Definitions
 ******************************************************/
//#define ancs_create_pool( size, count ) wiced_bt_create_pool( size, count )
//#define DISCOVERY_TYPE disc_type
#define wiced_bt_gatt_client_send_discover(id, type, param) wiced_bt_gatt_send_discover(id, type, param)


/******************************************************
 *               extern variables
 ******************************************************/

#endif // _AMS_H_
