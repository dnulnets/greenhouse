#include <nvs_flash.h>
#include <esp_zigbee_core.h>
#include <esp_check.h>
#include <nwk/esp_zigbee_nwk.h>
#include <ha/esp_zigbee_ha_standard.h>

#include "greenhouse.h"
#include "convert.h"
#include "cluster.h"

esp_zb_attribute_list_t *create_basic_cluster()
{
    /* Create the basic cluster */
    esp_zb_basic_cluster_cfg_t basic_cfg = {
        .zcl_version = ESP_ZB_ZCL_BASIC_ZCL_VERSION_DEFAULT_VALUE,
        .power_source = 0x01 /* Mains (single phase)*/
    };
    esp_zb_attribute_list_t *basic_cluster = esp_zb_basic_cluster_create(&basic_cfg);
    ESP_ERROR_CHECK(esp_zb_basic_cluster_add_attr(basic_cluster, ESP_ZB_ZCL_ATTR_BASIC_MANUFACTURER_NAME_ID, CLUSTER_BASIC_MANUFACTURER_NAME));
    ESP_ERROR_CHECK(esp_zb_basic_cluster_add_attr(basic_cluster, ESP_ZB_ZCL_ATTR_BASIC_MODEL_IDENTIFIER_ID, CLUSTER_BASIC_MODEL_IDENTIFIER));
    return basic_cluster;
}

esp_zb_attribute_list_t *create_identify_cluster()
{
    /* Create the basic cluster */
    esp_zb_identify_cluster_cfg_t identify_cfg = {
        .identify_time = ESP_ZB_ZCL_IDENTIFY_IDENTIFY_TIME_DEFAULT_VALUE
    };

    esp_zb_attribute_list_t *identify_cluster = esp_zb_identify_cluster_create(&identify_cfg);
    return identify_cluster;
}

esp_zb_attribute_list_t *create_temperature_cluster(float min, float max)
{
    /* Create the temperature measurement cluster */
    esp_zb_temperature_meas_cluster_cfg_t temp_meas_cfg = {
        .min_value = temperature_to_s16(min),
        .max_value = temperature_to_s16(max)
    };
    esp_zb_attribute_list_t *temp_meas_cluster = esp_zb_temperature_meas_cluster_create(&temp_meas_cfg);
    return temp_meas_cluster;
}

esp_zb_attribute_list_t *create_illuminance_cluster (float min, float max)
{
    esp_zb_illuminance_meas_cluster_cfg_t ic = { 
        .min_value = illuminance_to_u16(min), 
        .max_value = illuminance_to_u16(max),
        .measured_value = 0x0000 /* Default value */
    };

    esp_zb_attribute_list_t *icl = esp_zb_illuminance_meas_cluster_create(&ic);
    uint8_t light_sensor_type = CLUSTER_ILLUMINANCE_SENSOR_TYPE;
    ESP_ERROR_CHECK(esp_zb_illuminance_meas_cluster_add_attr(icl, ESP_ZB_ZCL_ATTR_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_ID, &light_sensor_type));
    return icl;
}

