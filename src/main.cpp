/************************************************************************
* autor:        Kamiński Mateusz
* project:      HomeWeatherInfo
* purpose:      Project should be helpfull in analize weather parameters
*               and indor air parameters. Dvice should be also give
*               parameters of centrl heatiing system.
* destination:  The project is for home and is development platform
* for peoject   weather station (created simultaneously).
* start date:   08.2023
* version:      001.00b
* 
* @todo add sensors, log library repair
************************************************************************/

/***********************************************************************
  Include section
************************************************************************/
#include <Arduino.h>
#include <stdio.h>
#include "log.h"
#include <Wire.h>
#include "system_config.h"
#include "types.h"
#include "AHT20Sensor.h"

/***********************************************************************
  Global valiables section
************************************************************************/

/***********************************************************************
  Declaration functions section
************************************************************************/

/***********************************************************************
  Define section
************************************************************************/

/***********************************************************************
  Setup function section
************************************************************************/
void setup() {

  #if (SERIAL_PORT == STD_ON)
    Serial.begin(SERIAL_BAUDRATE);
  #endif

  #if (I2CBUS_PORT1 == STD_ON)
    Wire.begin();
  #endif
    
    AHT20_Init();
 }

/***********************************************************************
  Loop function section
************************************************************************/
void loop() {
  #if (SYSTEM_LOG == STD_ON)
    // log(DEBUG, "This is a debug message");
    // log(INFO, "This is an info message");
    // log(WARNING, "This is a warning message");
    // log(ERROR, "This is an error message");
    // log(ERROR, "This is an error message", (float) 100.11);
  #endif

    AHT20getValue();

    delay(1000);
}

/***********************************************************************
  Definition functions section
************************************************************************/