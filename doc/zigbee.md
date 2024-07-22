# Zigbee Model
The current approach to the zigbee device is to have one endpoint for each group of sensors and actuators that have a high degree of relationship.
## Endpoint description
### Generic clusters and settings
#### Basic Cluster
Homey App requires the basic cluster for each endpoint to include manufacturing name and model id, otherwise it will not register the device.
The basic cluster has two mandatory attributes, i.e. the **ZCLVersion** and **PowerSource**.
* ZCLVersion: **ESP_ZB_ZCL_BASIC_ZCL_VERSION_DEFAULT_VALUE** Currently the ESP supports revision 8.
* PowerSource: **Mains (single phase)**
* ManufacturerName: **Stenlund**
* ModelIdentifier: **Greenhouse-00**
### List of endpoints
#### Outside environment (EndpointId 10)
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
Cluster list:
* temperature measurement (0x0402), soil temperature
* soil moisture measurement (0x0408), soil moisture
* flow measurement (0x0404), water flow
* pump on/off (0x0006), water pump
### Roof ventilation windows (EndpointId 40)
Cluster list:
* level control (0x0008), opeing of the roof hatchets
