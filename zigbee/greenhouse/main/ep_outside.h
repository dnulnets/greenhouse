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
#define EP_OUTSIDE_ILLUMINANCE_VALUE       15000.0

extern esp_zb_cluster_list_t *create_outside_ep();
