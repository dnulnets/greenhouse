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
### Temperature greenhouse
This endpoint includes the cluster, basic, identify and temperature sensor and has endpoint identity 10.
### Temperature outside
This endpoint includes the cluster, basic, identify and temperature sensor and has endpoint identity 11.
### Temperature soil
This endpoint includes the cluster, basic, identify and temperature sensor and has endpoint identity 12.
### Humidity greenhouse
### Barometric pressure greenhouse
### Water pump
### Roof vent 1
### Roof vent 2
### Roof vent 3
