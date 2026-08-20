/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * This is the public interface file for the handsfree profile Audio Gateway(AG) subsystem of
 * HCI_CONTROL application.
 */
#ifndef HFP_AG_H
#define HFP_AG_H

#include "wiced_bt_dev.h"
#include "wiced_bt_sdp.h"
#include "wiced_bt_rfcomm.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_sco.h"
#include "wiced_bt_hfp_ag.h"
#include "wiced_bt_cfg.h"
#include "wiced_timer.h"
#include "wiced_bt_utils.h"

/******************************************************
 *                     Constants
 ******************************************************/
////// TEMP for compiling
#ifndef BTM_SCO_PKT_TYPES_MASK_HV1
#define BTM_INVALID_SCO_INDEX           0xFFFF
#define BTM_SCO_LINK_ALL_PKT_MASK       0x003F
#define BTM_SCO_LINK_ONLY_MASK          0x0007
#define BTM_SCO_PKT_TYPES_MASK_HV3      0x0004
#define BTM_SCO_PKT_TYPES_MASK_EV3      0x0008
#define BTM_SCO_PKT_TYPES_MASK_EV4      0x0010
#define BTM_SCO_PKT_TYPES_MASK_EV5      0x0020
#define BTM_SCO_PKT_TYPES_MASK_NO_2_EV3 0x0040
#define BTM_SCO_PKT_TYPES_MASK_NO_3_EV3 0x0080
#define BTM_SCO_PKT_TYPES_MASK_NO_2_EV5 0x0100
#define BTM_SCO_PKT_TYPES_MASK_NO_3_EV5 0x0200
#define BTM_ESCO_RETRANS_POWER          1
#define BTM_ESCO_RETRANS_QUALITY        2
#endif

#define HFP_RFCOMM_SCN                  1
#define HSP_RFCOMM_SCN                  2
#define HFP_DEVICE_MTU                  255

#define BTA_AG_SCO_PKT_TYPES    ( BTM_SCO_PKT_TYPES_MASK_HV3 | \
                                 BTM_SCO_PKT_TYPES_MASK_EV3 | \
                                 BTM_SCO_PKT_TYPES_MASK_EV4 | \
                                 BTM_SCO_PKT_TYPES_MASK_EV5 | \
                                 BTM_SCO_PKT_TYPES_MASK_NO_3_EV3 | \
                                 BTM_SCO_PKT_TYPES_MASK_NO_3_EV5 )

#define WICED_BUFF_MAX_SIZE             360

/* special handle values used with APIs */
#define HFP_HF_HANDLE_NONE      0
#define HFP_HF_HANDLE_ALL       0xFFFF

/* Flags to mark rfcomm data callback or rfcomm control callback */
enum
{
    HFP_FLAG_RFCOMM_DATA,
    HFP_FLAG_RFCOMM_CONTROL,
};

/* data associated with AG_OPEN_EVT */
typedef struct
{
    BD_ADDR             bd_addr;
    uint8_t             status;
} hfp_ag_open_t;

/* data associated with AG_CONNECTED_EVT */
typedef struct
{
    uint32_t   peer_features;
} hfp_ag_connect_t;

/* AT command */
typedef struct
{
    uint8_t *cmd_ptr;
    uint8_t cmd_len;
} hfp_ag_at_cmd_t;

/* data associated with HCI_CONTROL_AG_EVENT_AUDIO_OPEN */
typedef struct
{
    uint8_t wbs_supported;
    uint8_t wbs_used;
} hfp_audio_open_t;

/* union of data associated with AG callback */
typedef union
{
    hfp_ag_open_t    open;
    hfp_ag_connect_t conn;
    hfp_ag_at_cmd_t  at_cmd;
    hfp_audio_open_t audio_open;
} hfp_ag_event_t;


/*****************************************************************************
**  External Function Declarations
*****************************************************************************/
/* Audio Gateway Configuration */
extern uint32_t ag_features;

/* SDP functions */
extern void     hfp_ag_sdp_init(void);
extern void     hfp_ag_sdp_start_discovery( hfp_ag_session_cb_t *p_scb );

/* RFCOMM functions */
extern void     hfp_ag_rfcomm_start_server( hfp_ag_session_cb_t *p_scb );
extern void     hfp_ag_rfcomm_do_close( hfp_ag_session_cb_t *p_scb );

/* SCO functions */
extern void     hfp_ag_sco_create( hfp_ag_session_cb_t *p_scb, BOOLEAN is_orig );
extern void     hfp_ag_sco_close( hfp_ag_session_cb_t *p_scb );
extern void     hfp_cn_timeout ( uint32_t scb );

/* scb utility functions */
extern hfp_ag_session_cb_t *hfp_ag_find_scb_by_sco_index( uint16_t sco_idx );
extern hfp_ag_session_cb_t *hfp_ag_find_scb_by_rfc_handle( uint16_t rfc_handle, uint8_t flag );
extern hfp_ag_session_cb_t *hfp_ag_find_scb_by_app_handle( uint16_t app_handle );

extern void     hfp_ag_service_level_up(hfp_ag_session_cb_t *p_scb);

/* UART interface */
extern void     hfp_ag_hci_send_ag_event( uint16_t evt, uint16_t handle, hfp_ag_event_t *p_data );

/* AT functions */
extern void     hfp_ag_parse_AT_command (hfp_ag_session_cb_t *p_scb);

#endif /* HFP_AG_H */
