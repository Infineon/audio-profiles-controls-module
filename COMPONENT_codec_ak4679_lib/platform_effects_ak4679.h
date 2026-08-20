/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * This file enumerates dsp control registers and
 * the individual bits of some of the key
 * configuration bits of the AK4679 DSP
 */
#pragma once

#include "akm4679_dsp_pram.h"
#include "akm4679_dsp_cram.h"

/*DSP register map*/

typedef enum
{
    AK4679_DSP_PCON0 = 0xD0,
    AK4679_DSP_PCON1,
    AK4679_DSP_CONT0 = 0xC0,
    AK4679_DSP_CONT1,
    AK4679_DSP_CONT2,
    AK4679_DSP_CONT3,
    AK4679_DSP_CONT4,
    AK4679_DSP_CONT5,
    AK4679_DSP_CONT6,
    AK4679_DSP_CONT7,
    AK4679_DSP_CONT8,
} ak4679_dsp_reg_map;

/*AK4679_INT_POWERSUPPLY_CONTROL*/
#define AK4679_SOCFG                (0x01 << 4)
#define AK4679_PWSW                 (0x01 << 0)
#define AK4679_MRSTN                (0x01 << 0)

#define I2C_AK4679_DSP_ADDR (0x30>>1)
