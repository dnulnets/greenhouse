
/* The basic cluster data */
#define CLUSTER_BASIC_MANUFACTURER_NAME "\x08""Stenlund"
#define CLUSTER_BASIC_MODEL_IDENTIFIER "\x0d""Greenhouse-00"

/* Should correspond to the physical device */
#define CLUSTER_ILLUMINANCE_SENSOR_TYPE 0x01 /* Photodiode */

extern esp_zb_attribute_list_t *create_basic_cluster();
extern esp_zb_attribute_list_t *create_identify_cluster();
extern esp_zb_attribute_list_t *create_temperature_cluster(float min, float max);
extern esp_zb_attribute_list_t *create_illuminance_cluster (float min, float max);
