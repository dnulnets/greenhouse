/*
 * device_water.js: zigbee device for the greenhouse watering control
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

'use strict';

const { ZigBeeDevice } = require('homey-zigbeedriver');
const { debug } = require("zigbee-clusters");
const { CLUSTER } = require("zigbee-clusters");

// Enable debug logging of all relevant Zigbee communication
debug(true);

class WaterDevice extends ZigBeeDevice {

  async onNodeInit({ zclNode }) {

    this.registerCapability("onoff", CLUSTER.ON_OFF, {
      reportOpts: {
        configureAttributeReporting: {
          minInterval: 0, // No minimum reporting interval
          maxInterval: 300, // Maximally every ~16 hours
          minChange: 10, // Report when value changed by 10
        },
      },
      endpoint: 40
    });

    this.registerCapability("alarm_water", CLUSTER.BINARY_INPUT, {
      reportOpts: {
        configureAttributeReporting: {
          minInterval: 0, // No minimum reporting interval
          maxInterval: 300, // Maximally every ~16 hours
          minChange: 10, // Report when value changed by 10
        },
      },
      endpoint: 40
    });

    this.log('WaterDevice has been node initialized');
  }

}

module.exports = WaterDevice;