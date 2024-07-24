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
        return TEMPERATURE_VALUE_UNKNOWN;
    /* Too high ?*/
    if (temperature > 327.67)
        return TEMPERATURE_VALUE_UNKNOWN;
    /* Convert to signed int */
    return (int16_t)(temperature * 100);
}

uint16_t illuminance_to_u16(float illuminance)
{
    /* Too low to be measured? */
    if (illuminance < 1.0)
        return ILLUMINANCE_VALUE_TOO_LOW;
    /* Too high to be measured? */
    if (illuminance > 3.576e6)
        return ILLUMINANCE_VALUE_INVALID;
    /* Convert to unsigned int */
    return (uint16_t)(10000.0 * log10 (illuminance) + 1.0);
}

uint16_t water_content_to_u16(float water_content)
{
    /* Too low => Unknown */
    if (water_content < 0.0)
        return HUMIDITY_VALUE_UNKNOWN;
    /* Too high => Unknown */
    if (water_content > 100.0)
        return HUMIDITY_VALUE_UNKNOWN;
    /* Covnert it */
    return (uint16_t)(water_content * 100.0);
}

int16_t pressure_to_s16(float pressure)
{
    /* Too low ? */
    if (pressure < -3276.7)
        return PRESSURE_VALUE_UNKNOWN;
    /* Too high ?*/
    if (pressure > 3276.7)
        return PRESSURE_VALUE_UNKNOWN;
    /* Convert to signed int */
    return (int16_t)(pressure * 10);
}
