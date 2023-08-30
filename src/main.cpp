#include <Arduino.h>
#include <stdio.h>
#include "log.h"
#include "IRcommunication.h"
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

LogLibrary logger(DEBUG);

void setup() {
  Serial.begin(115200);
  ir_init();
}

void loop() {
  // logger.log(DEBUG, "This is a debug message");
  // logger.log(INFO, "This is an info message");
  // logger.log(WARNING, "This is a warning message");
  // logger.log(ERROR, "This is an error message");

  // Przykładowe użycie
    ir_send_cool_frame();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
  delay(100);
}