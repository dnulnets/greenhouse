'use strict';

const Homey = require('homey');

class Greenhouse extends Homey.App {

  /**
   * onInit is called when the app is initialized.
   */
  async onInit() {
    this.log('Greenhouse has been initialized');
  }

}

module.exports = Greenhouse;
