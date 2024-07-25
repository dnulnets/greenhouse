/*
 * cluster.c: Create clusters and sets the up with default values based on the hardware. Used
 * to create endpoints for the Zigbee device.
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

static const char *TAG = "cluster.c";

/**
 * @brief Creates a basic cluster.
 *
 * This function creates a basic cluster and returns a pointer to the attribute list.
 *
 * @return Pointer to the attribute list of the basic cluster.
 */
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

/**
 * @brief Creates an identify cluster.
 *
 * This function creates and returns an identify cluster attribute list.
 *
 * @return A pointer to the created identify cluster attribute list.
 */
esp_zb_attribute_list_t *create_identify_cluster()
{
    /* Create the basic cluster */
    esp_zb_identify_cluster_cfg_t identify_cfg = {
        .identify_time = ESP_ZB_ZCL_IDENTIFY_IDENTIFY_TIME_DEFAULT_VALUE
    };

    esp_zb_attribute_list_t *identify_cluster = esp_zb_identify_cluster_create(&identify_cfg);
    return identify_cluster;
}

/**
 * @brief Creates a temperature cluster with the specified minimum and maximum values.
 *
 * This function creates a temperature cluster with the given minimum and maximum values.
 *
 * @param min The minimum temperature value.
 * @param max The maximum temperature value.
 *
 * @return A pointer to the created temperature cluster attribute list.
 */
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

/**
 * @brief Creates an illuminance cluster with the specified minimum and maximum values.
 *
 * This function creates an illuminance cluster with the given minimum and maximum values.
 *
 * @param min The minimum illuminance value.
 * @param max The maximum illuminance value.
 *
 * @return A pointer to the created illuminance cluster attribute list.
 */
esp_zb_attribute_list_t *create_illuminance_cluster(float min, float max)
esp_zb_attribute_list_t *create_illuminance_cluster (float min, float max)
{
    esp_zb_illuminance_meas_cluster_cfg_t ic = { 
        .min_value = illuminance_to_u16(min), 
        .max_value = illuminance_to_u16(max),
        //.measured_value = ILLUMINANCE_VALUE_TOO_LOW /* Default value */
        .measured_value = illuminance_to_u16(15000.0) /* Default value lux */
    };

    esp_zb_attribute_list_t *icl = esp_zb_illuminance_meas_cluster_create(&ic);
    uint8_t light_sensor_type = CLUSTER_ILLUMINANCE_SENSOR_TYPE;
    ESP_ERROR_CHECK(esp_zb_illuminance_meas_cluster_add_attr(icl, ESP_ZB_ZCL_ATTR_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_ID, &light_sensor_type));
    return icl;
}

/**
 * @brief Creates a humidity cluster with the specified minimum and maximum values.
 *
 * This function creates a humidity cluster with the given minimum and maximum values.
 *
 * @param min The minimum humidity value.
 * @param max The maximum humidity value.
 *
 * @return A pointer to the created humidity cluster attribute list.
 */
esp_zb_attribute_list_t *create_humidity_cluster (float min, float max)
{
    esp_zb_humidity_meas_cluster_cfg_t ic = { 
        .min_value = water_content_to_u16(min), 
        .max_value = water_content_to_u16(max),
        //.measured_value = HUMIDITY_VALUE_UNKNOWN /* Default value */
        .measured_value = water_content_to_u16(50.0) /* Default value % */
    };

    esp_zb_attribute_list_t *icl = esp_zb_humidity_meas_cluster_create(&ic);
    return icl;
}

/**
 * @brief Creates a pressure cluster with the specified minimum and maximum values.
 *
 * This function creates a pressure cluster with the given minimum and maximum values.
 *
 * @param min The minimum pressure value.
 * @param max The maximum pressure value.
 *
 * @return A pointer to the created pressure cluster attribute list.
 */
esp_zb_attribute_list_t *create_pressure_cluster(float min, float max)
esp_zb_attribute_list_t *create_pressure_cluster (float min, float max)
{
    esp_zb_pressure_meas_cluster_cfg_t ic = { 
        .min_value = pressure_to_s16(min), 
        .max_value = pressure_to_s16(max),
        //.measured_value = PRESSURE_VALUE_UNKNOWN /* Default value */
        .measured_value = pressure_to_s16(101.325) /* Default value kPA */
    };

    /* We should perhaps move to scaled values */
    esp_zb_attribute_list_t *icl = esp_zb_pressure_meas_cluster_create(&ic);
    return icl;
}

