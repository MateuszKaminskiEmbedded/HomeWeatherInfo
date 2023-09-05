#include <Arduino.h>
#include <stdio.h>
#include "log.h"
#include <Wire.h>

#include "system_config.h"
#include "types.h"

#define I2C_TEMP_HUM_ADDRESS 0x38

#if (SYSTEM_LOG == STD_ON)
  LogLibrary logger(DEBUG);
#endif

void setup() {

#if (SERIAL_PORT == STD_ON)
  Serial.begin(SERIAL_BAUDRATE);
#endif

  Wire.begin();

 }

void loop() {
  logger.log(DEBUG, "This is a debug message");
  logger.log(INFO, "This is an info message");
  logger.log(WARNING, "This is a warning message");
  logger.log(ERROR, "This is an error message");

   byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }

  delay(1000);
}