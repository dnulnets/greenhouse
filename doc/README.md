# System architecture description
## Overview
The system solution consists of software for the sparkfun device and the homey-controller. Electronics for the sparkfun device and the sensors and actuators.

```mermaid
flowchart LR
    subgraph Homey Pro
    app("Greenhouse App")
    end
    subgraph Sparkfun ESP32-C6
    zd("Z-Device")
    zd-->ep10("Endpoint Outside")
    zd-->ep20("Endpoint Greenhouse")
    zd-->ep30("Endpoint Soil")
    zd-->ep40("Endpoint Ventilation")
    end
    app-->zd
```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
