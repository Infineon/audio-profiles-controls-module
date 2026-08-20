/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include <wiced.h>

wiced_bool_t ama_hci_control_command_handler(uint32_t *status, uint16_t command, const void* payload, uint32_t payload_length);
