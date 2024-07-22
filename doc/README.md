# System architecture description
## Overview
The system solution consists of software for the sparkfun device and the homey-controller. Electronics for the sparkfun device and the sensors and actuators.

```mermaid
flowchart TB
    h-->sf
    subgraph Homey [h]
    a1
    subgraph Sparkfun [sf]
    ep10-->temperature1
    subgraph Sensors [se]
    ep10-->temperature1
    end

```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
