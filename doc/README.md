# System architecture description
## Overview
The system solution consists of software for the sparkfun device and the homey-controller. Electronics for the sparkfun device and the sensors and actuators.

```mermaid
flowchart OV
    a1-->Sparkfun
    ep10-->temperature1
    ep20-->temperature2
    subgraph Homey
    a1
    subgraph Sparkfun
    ep10
    ep20
    ep30
    ep40
    subgraph Sensors
    temperature1
    temperature2
    end

```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
