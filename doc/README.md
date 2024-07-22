# System architecture description
## Overview
The system solution consists of software for the sparkfun device and the homey-controller. Electronics for the sparkfun device and the sensors and actuators.

```mermaid
flowchart TB
    subgraph homey
    app-->zd
    end
    subgraph sparkfun
    zd
    zd-->ep10
    zd-->ep20
    zd-->ep30
    zd-->ep40
    end
```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
