# Zigbee Model
The current approach to the zigbee device is to have multiple endpoints
## Endpoints
### Outside environment (10)
Cluster temperature measurement (0x0402), barometric pressure (0x0403, extended set), relative humidity measurement (0x0405), illuminance measurement (0x0400)
### Greenhouse environment (20)
Cluster temperature measurement (0x0402), relative humidity measurement (0x0405), illuminance measurement (0x0400)
### Soil environment (30)
Cluster temperature measurement (0x0402), soil moisture measurement (0x0408), flow measurement (0x0404), pump on/off (0x0006)
### Roof ventilation windows (40)
Cluster level control (0x0008)
