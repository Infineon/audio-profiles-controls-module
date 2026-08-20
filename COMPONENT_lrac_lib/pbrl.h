/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 *
 *  pbrle.h: Pretty Basic Run Length Compression/Decompression utility functions.
 *
 */

#include <stdint.h>

#pragma once

/*
 * pbrl_compress
 * Compress the Source Buffer (p_src/src_size) into the Destination Buffer (p_dst/dst_size)
 * The size of the Destination buffer must be bigger than the Source Buffer by one byte (worst case)
 * Returns the size of the Compressed buffer.
 */
int pbrl_compress(uint8_t *p_dst, int dst_size, const uint8_t *p_src, int src_size);

/*
 * pbrl_decompress
 * Decompress the Source Buffer (p_src/src_size) into the Destination Buffer (p_dst/dst_size)
 * Returns the size of the Decompressed buffer.
 */
int pbrl_decompress(uint8_t *p_dst, int dst_size, const uint8_t *p_src, int src_size);
