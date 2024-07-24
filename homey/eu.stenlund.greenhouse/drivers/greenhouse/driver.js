/*
 * driver.js: zigbee device driver for the greenhouse
 *
 * License: CC-BY-4.0
 * Copyright:2024, Tomas Stenlund
 * 
 */

'use strict';

const { Driver } = require('homey');
const { ZigBeeDriver } = require('homey-zigbeedriver');

const OutsideDevice = require("./device_outside.js");
const InsideDevice = require("./device_inside.js");

class GreenhouseDriver extends ZigBeeDriver {

    onMapDeviceClass(device) {

        if (device.getData().subDeviceId === "inside") {
          return InsideDevice;
        } else {
          return OutsideDevice;
        }
    }

}

module.exports = GreenhouseDriver;
