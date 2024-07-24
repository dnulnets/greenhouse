/*
 * ep_outside.c: Creates the outside endpoint.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#define EP_OUTSIDE_ID 10

#define EP_OUTSIDE_TEMP_SENSOR_MIN_VALUE   -60.0
#define EP_OUTSIDE_TEMP_SENSOR_MAX_VALUE   80.0

#define EP_OUTSIDE_ILLUMINANCE_MIN_VALUE   1.0
#define EP_OUTSIDE_ILLUMINANCE_MAX_VALUE   30000.0

#define EP_OUTSIDE_HUMIDITY_MIN_VALUE   0.0
#define EP_OUTSIDE_HUMIDITY_MAX_VALUE   100.0

#define EP_OUTSIDE_PRESSURE_MIN_VALUE   80.0
#define EP_OUTSIDE_PRESSURE_MAX_VALUE   110.0

extern esp_zb_cluster_list_t *create_outside_ep();
