/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include <wiced_bt_cfg.h>

typedef enum
{
    HANDLE_HSENS_GATT_SERVICE = 0x1, // service handle

    HANDLE_HSENS_GAP_SERVICE = 0x14, // service handle
        HANDLE_HSENS_GAP_SERVICE_CHAR_DEV_NAME, // characteristic handl
        HANDLE_HSENS_GAP_SERVICE_CHAR_DEV_NAME_VAL, // char value handle

        HANDLE_HSENS_GAP_SERVICE_CHAR_DEV_APPEARANCE, // characteristic handl
        HANDLE_HSENS_GAP_SERVICE_CHAR_DEV_APPEARANCE_VAL,// char value handle


    HANDLE_HSENS_SERVICE = 0x28,
        HANDLE_HSENS_SERVICE_CHAR_NOTIFY, // characteristic handl
        HANDLE_HSENS_SERVICE_CHAR_NOTIFY_VAL, // char value handle
        HANDLE_HSENS_SERVICE_CHAR_CFG_DESC, // charconfig desc handl

        HANDLE_HSENS_SERVICE_CHAR_BLINK, // characteristic handl
        HANDLE_HSENS_SERVICE_CHAR_BLINK_VAL, // char value handle

        HANDLE_HSENS_SERVICE_CHAR_LONG_MSG, // characteristic handl
        HANDLE_HSENS_SERVICE_CHAR_LONG_MSG_VAL, //long  char value handl

    HANDLE_HSENS_DEV_INFO_SERVICE = 0x40,
        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_MFR_NAME, // characteristic handle
        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_MFR_NAME_VAL,// char value handle

        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_MODEL_NUM, // characteristic handl
        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_MODEL_NUM_VAL,// char value handle

        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_SYSTEM_ID, // characteristic handl
        HANDLE_HSENS_DEV_INFO_SERVICE_CHAR_SYSTEM_ID_VAL,// char value handle

    HANDLE_HSENS_BATTERY_SERVICE = 0x60, // service handle
        HANDLE_HSENS_BATTERY_SERVICE_CHAR_LEVEL, // characteristic handl
        HANDLE_HSENS_BATTERY_SERVICE_CHAR_LEVEL_VAL, // char value andle


    HANDLE_AMA_SERVICE = 0x70,
       HANDLE_AMA_SERVICE_CHAR_TX,
       HANDLE_AMA_SERVICE_CHAR_TX_VAL,
       HANDLE_AMA_SERVICE_CHAR_RX,
       HANDLE_AMA_SERVICE_CHAR_RX_VAL,
       HANDLE_AMA_SERVICE_CHAR_RX_CFG_DESC,

       // Client Configuration
       HDLD_CURRENT_TIME_SERVICE_CURRENT_TIME_CLIENT_CONFIGURATION,

}hello_sensor_db_tags;


void ama_le_post_init(const wiced_bt_cfg_settings_t *settings);
