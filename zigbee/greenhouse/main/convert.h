/*
 * convert.c: Converts to and from the human readable values to the Zigbee values.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#define TEMPERATURE_VALUE_UNKNOWN 0x8000

#define ILLUMINANCE_VALUE_TOO_LOW 0x0000
#define ILLUMINANCE_VALUE_INVALID 0xffff

#define HUMIDITY_VALUE_UNKNOWN  0xffff

#define PRESSURE_VALUE_UNKNOWN 0x8000

extern int16_t temperature_to_s16(float temperature);
extern uint16_t illuminance_to_u16(float illuminance);
extern uint16_t water_content_to_u16(float water_content);
extern int16_t pressure_to_s16(float pressure);
