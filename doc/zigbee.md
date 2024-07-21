# Zigbee Model
The current approach to the zigbee device is to have one endpoint for each sensor and actuator.

## Basic Cluster
Homey App requires the basic cluster for each endpoint to include manufacturing name and model id, otherwise it will not register the device.
The basic cluster has two mandatory attributes, i.e. the **ZCLVersion** and **PowerSource**.
* ZCLVersion: **ESP_ZB_ZCL_BASIC_ZCL_VERSION_DEFAULT_VALUE**
* PowerSource: **Mains (single phase)**
* ManufacturerName: **Stenlund**
* ModelIdentifier: **Greenhouse-00**

## Endpoints
### Outside environment (10)
Cluster temperature measurement (0x0402), barometric pressure (0x0403, extended set), relative humidity measurement (0x0405), illuminance measurement (0x0400)
### Greenhouse environment (20)
Cluster temperature measurement (0x0402), relative humidity measurement (0x0405), illuminance measurement (0x0400)
### Soil environment (30)
Cluster temperature measurement (0x0402), soil moisture measurement (0x0408), flow measurement (0x0404), pump on/off (0x0006)
### Roof ventilation windows (40)
Cluster level control (0x0008)
