#include <Arduino.h>
#include <stdio.h>
#include "log.h"

LogLibrary logger(DEBUG);

void setup() {
  Serial.begin(115200);
}

void loop() {
  logger.log(DEBUG, "This is a debug message");
  logger.log(INFO, "This is an info message");
  logger.log(WARNING, "This is a warning message");
  logger.log(ERROR, "This is an error message");

  delay(1000);
}