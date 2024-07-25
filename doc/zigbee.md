# Zigbee Model
The current approach to the zigbee device is to have one endpoint for each group of sensors and actuators that have a high degree of relationship and do not have overlapping clusters.
## Endpoint description
### Generic clusters and settings
The following clusters and settings are valid for all endpoints.
#### Basic Cluster
The Homey App requires the basic cluster for each endpoint to include manufacturing name and model id, otherwise it will not register the device.
The basic cluster has two mandatory attributes, i.e. the **ZCLVersion** and **PowerSource**.
* ZCLVersion: **ESP_ZB_ZCL_BASIC_ZCL_VERSION_DEFAULT_VALUE** Currently the ESP supports revision 8.
* PowerSource: **Mains (single phase)**
* ManufacturerName: **Stenlund**
* ModelIdentifier: **Greenhouse-00**
### List of endpoints
### Outside environment (EndpointId 10)
Cluster list:
* temperature measurement (0x0402), outdoor air temperature
* pressure measurement (0x0403), outdoor barometric pressure
* relative humidity measurement (0x0405), outdoor relative humidity
* illuminance measurement (0x0400), outdoor illuminance
### Greenhouse environment (EndpointId 20)
Cluster list:
* temperature measurement (0x0402), greenhouse temperature
* relative humidity measurement (0x0405), greenhouse relative humidity
* illuminance measurement (0x0400), greenhouse illuminance
### Soil environment (EndpointId 30)
This endpoint could perhaps be a separate zigbee physical device on its own to measure the soil in different locations in the greenhouse.
Cluster list:
* temperature measurement (0x0402), soil temperature
* soil moisture measurement (0x0408), soil moisture. Unfortunately espressif has not yet implemented this cluster so I had to use the relative humidity cluster (0x0405) instead.
### Watering (Endpoint 40)
Cluster list:
* flow measurement (0x0404), the water flow for watering the plants
* pump on/off (0x0006), water pump for turning the pump on and off
### Roof ventilation windows (EndpointId 50)
This endpoint could perhaps be a separate zigbee physical device on its own to control each hatch in the greenhouse individually.
Cluster list:
* level control (0x0008), control of the roof hatchets for ventilation
