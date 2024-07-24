/*
 * ep_soil.c: Creates the greenhouse endpoint.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#define EP_SOIL_ID 30

#define EP_SOIL_TEMP_SENSOR_MIN_VALUE   -60.0
#define EP_SOIL_TEMP_SENSOR_MAX_VALUE   80.0

#define EP_SOIL_MOISTURE_MIN_VALUE   0.0
#define EP_SOIL_MOISTURE_MAX_VALUE   100.0

extern esp_zb_cluster_list_t *create_soil_ep();
