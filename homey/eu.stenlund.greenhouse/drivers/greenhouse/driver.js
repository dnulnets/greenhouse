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

class MyDriver extends ZigBeeDriver {

}

module.exports = MyDriver;
