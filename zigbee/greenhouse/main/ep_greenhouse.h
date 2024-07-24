/*
 * ep_greenhouse.c: Creates the greenhouse endpoint.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#define EP_GREENHOUSE_ID 20

#define EP_GREENHOUSE_TEMP_SENSOR_MIN_VALUE   -60.0
#define EP_GREENHOUSE_TEMP_SENSOR_MAX_VALUE   80.0

#define EP_GREENHOUSE_ILLUMINANCE_MIN_VALUE   1.0
#define EP_GREENHOUSE_ILLUMINANCE_MAX_VALUE   30000.0

#define EP_GREENHOUSE_HUMIDITY_MIN_VALUE   0.0
#define EP_GREENHOUSE_HUMIDITY_MAX_VALUE   100.0

extern esp_zb_cluster_list_t *create_greenhouse_ep();
