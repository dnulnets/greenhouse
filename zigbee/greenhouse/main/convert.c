/*
 * convert.c: Converts to and from the human readable values to the Zigbee values.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#include <stdint.h>
#include <math.h>
#include "convert.h"

static const char *TAG = "convert.c";

int16_t temperature_to_s16(float temperature)
{
    /* Too low ? */
    if (temperature < -273.15)
        return 0x8000;
    /* Too high ?*/
    if (temperature > 327.67)
        return 0x8000;
    /* Convert to signed int */
    return (int16_t)(temperature * 100);
}

uint16_t illuminance_to_u16(float illuminance)
{
    /* Too low to be measured? */
    if (illuminance < 1.0)
        return 0x0000;
    /* Too high to be measured? */
    if (illuminance > 3.576e6)
        return 0xFFFF;
    /* Convert to unsigned int */
    return (uint16_t)(10000.0 * log10 (illuminance) + 1);
}
