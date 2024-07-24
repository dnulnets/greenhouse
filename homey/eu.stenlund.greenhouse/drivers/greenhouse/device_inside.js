/*
 * device.js: zigbee device for the greenhouse driver
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

class InsideDevice extends ZigBeeDevice {

  async onNodeInit({ zclNode }) {

    this.registerCapability("measure_temperature", CLUSTER.TEMPERATURE_MEASUREMENT, {
      reportOpts: {
        configureAttributeReporting: {
          minInterval: 0, // No minimum reporting interval
          maxInterval: 300, // Maximally every ~16 hours
          minChange: 10, // Report when value changed by 10
        },
      },
      endpoint: 20
    });

    this.registerCapability("measure_luminance", CLUSTER.ILLUMINANCE_MEASUREMENT, {
      reportOpts: {
        configureAttributeReporting: {
          minInterval: 0, // No minimum reporting interval
          maxInterval: 300, // Maximally every ~16 hours
          minChange: 10, // Report when value changed by 10
        },
      },
      endpoint: 20
    });

    this.registerCapability("measure_humidity", CLUSTER.RELATIVE_HUMIDITY_MEASUREMENT, {
      reportOpts: {
        configureAttributeReporting: {
          minInterval: 0, // No minimum reporting interval
          maxInterval: 300, // Maximally every ~16 hours
          minChange: 10, // Report when value changed by 10
        },
      },
      endpoint: 20
    });

    this.log('InsideDevice has been node initialized');
  }

}

module.exports = InsideDevice;