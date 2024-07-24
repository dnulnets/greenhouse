/*
 * ep_soil.c: Creates the soil endpoint.
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

#include <nvs_flash.h>
#include <esp_zigbee_core.h>
#include <esp_check.h>
#include <nwk/esp_zigbee_nwk.h>
#include <ha/esp_zigbee_ha_standard.h>

#include "convert.h"
#include "cluster.h"
#include "ep_soil.h"

static const char *TAG = "ep_soil.c";

esp_zb_cluster_list_t *create_soil_ep()
{
    /* Create the endpoints list of clusters */
    esp_zb_cluster_list_t *cluster_list = esp_zb_zcl_cluster_list_create();

    /* Create the basic cluster */
    esp_zb_attribute_list_t *basic_cluster = create_basic_cluster();
    ESP_ERROR_CHECK(esp_zb_cluster_list_add_basic_cluster(cluster_list, basic_cluster, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE));

    /* Add the identify cluster */
    esp_zb_attribute_list_t *identify_cluster = create_identify_cluster();
    ESP_ERROR_CHECK(esp_zb_cluster_list_add_identify_cluster(cluster_list, identify_cluster, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE));
    
    /* Add the temperature measurement cluster */
    esp_zb_attribute_list_t *temperature_cluster = create_temperature_cluster(EP_SOIL_TEMP_SENSOR_MIN_VALUE, EP_SOIL_TEMP_SENSOR_MAX_VALUE);
    ESP_ERROR_CHECK(esp_zb_cluster_list_add_temperature_meas_cluster(cluster_list, temperature_cluster, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE));

    esp_zb_attribute_list_t *hcl = create_humidity_cluster(EP_SOIL_MOISTURE_MIN_VALUE, EP_SOIL_MOISTURE_MAX_VALUE);
    ESP_ERROR_CHECK(esp_zb_cluster_list_add_humidity_meas_cluster(cluster_list, hcl, ESP_ZB_ZCL_CLUSTER_SERVER_ROLE));

    return cluster_list;
}
