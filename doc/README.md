# System architecture description
## Overview
The system solution consists of software for the sparkfun device and the homey-controller. Electronics for the sparkfun device and the sensors and actuators.

```mermaid
block-beta
  columns 1
    block:HOMEY
        A[Greenhouse App]
    end
    space
    block:SPARKFUN
        EP10
        EP20
        EP30
        EP40    
    end
    HOMEY --> SPARKFUN
```
## Electronics
## Zigbee model
[The zigbee model](zigbee.md)
## Software
### Homey application
### ESP32-C6 application
