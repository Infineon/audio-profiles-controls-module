/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include "wiced.h"

typedef struct
{
    // The total number of HCI ACL Data Packets that can be stored in the data buffers of the Controller.
    uint8_t host_claim_host_to_device_count;

    // The number of buffers for host to device ACL traffic.
    uint8_t host_to_device_count;

    // The number of buffers for device to host ACL traffic.
    uint8_t device_to_host_count;
} wiced_pre_init_acl_buffer_t;

extern const wiced_pre_init_acl_buffer_t wiced_pre_init_acl_buffer;

typedef struct
{
    // The total number of HCI ACL Data Packets that can be stored in the data buffers of the Controller.
    uint8_t host_claim_host_to_device_count;

    // The number of buffers for host to device ACL traffic.
    uint8_t host_to_device_count;

    // The number of buffers for device to host ACL traffic.
    uint8_t device_to_host_count;
} wiced_pre_init_ble_buffer_t;

// Structure for each of the pools in FOUNDATION_CONFIG_ITEM_ID_DYNAMIC_MEMORY.
#pragma pack(1)
typedef struct
{
    // The size of each block in this pool.
    uint16_t size;

    // The number of blocks in this pool.
    uint8_t count;

    // The number of blocks in this pool that are reserved for dynamic_memory_AllocateOrDie calls.
    // This number of reserved blocks cannot be consumed by calls to
    // dynamic_memory_AllocateOrReturnNULL, which will return NULL if the block count is below the
    // die_reserve threshold.
    uint8_t die_reserve;
} FOUNDATION_CONFIG_DYNAMIC_MEMORY_POOL_t;
#pragma pack()

// Structure for FOUNDATION_CONFIG_ITEM_ID_DYNAMIC_MEMORY.
#pragma pack(1)
typedef struct
{
    // The number of pools that are to be created from the general pools.  The default value is
    // DYNAMIC_MEMORY_NUM_POOLS, but we reserve an extra pool control block, in case we need to add
    // a block size category from configuration data.  Unless we need to add a new block size
    // category pool, config data (.ags, .cgx) should probably just use DYNAMIC_MEMORY_NUM_POOLS
    // as a named value for this field.
    uint8_t num_pools;

    //$ DEFINE num_pools: DYNAMIC_MEMORY_NUM_POOLS

    // Info on the size, count, and blocks reserved for dynamic_memory_AllocateOrDie in each pool.
    FOUNDATION_CONFIG_DYNAMIC_MEMORY_POOL_t pools[DYNAMIC_MEMORY_NUM_POOLS+1];
} FOUNDATION_CONFIG_DYNAMIC_MEMORY_t;
#pragma pack()

extern const wiced_pre_init_ble_buffer_t wiced_pre_init_ble_buffer;

extern const uint8_t wiced_pre_init_ble_con_max;

extern const FOUNDATION_CONFIG_DYNAMIC_MEMORY_t wiced_pre_init_foundation_config_DynamicMemory;

/*
 * wiced_pre_init_is_done
 */
wiced_bool_t wiced_pre_init_is_done(void);
