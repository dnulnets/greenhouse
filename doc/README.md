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
    subgraph EP10
    T1("Temperature")
    P1("Pressure")
    RH1("Humidity")
    I1("Illuminance")
    end
    ep10-->T1
    ep10-->P1
    ep10-->RH1
    ep10-->I1
    app-->zd
```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
