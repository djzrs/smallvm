/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// Copyright 2018 John Maloney, Bernat Romagosa, and Jens Mönig

#include "mem.h"
#include "interp.h"
#include "persist.h"

#ifdef ESP8266
  #include "websocket.h"
#endif

void setup() {
#ifdef ARDUINO_NRF52_PRIMO
  sd_softdevice_disable();
#endif
#ifdef ESP8266
  websocketInit();
#endif

  hardwareInit();
  memInit(1800); // 1800 words = 7200 bytes
  outputString("Welcome to MicroBlocks!");
  restoreScripts();
  startAll();
}

void loop() {
  vmLoop();
}
