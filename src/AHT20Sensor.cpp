#include "AHT20Sensor.h"
#include "system_config.h"
#include "log.h"
#include "DFRobot_AHT20.h"

DFRobot_AHT20 aht20;

void AHT20_Init(void){
  while(aht20.begin() != 0){
    #if(SYSTEM_LOG == STD_ON)
      log(ERROR, "AHT20 sensor initialization failed");
    #endif
    delay(1);
  }
  #if(SYSTEM_LOG == STD_ON)
    log(INFO, "AHT20 sensor initialization successful");
  #endif
}

AHT20_values AHT20getValue(void){

  AHT20_values values;

  if(aht20.startMeasurementReady(/* crcEn = */true)){
    #if(SYSTEM_LOG == STD_ON)
      log(INFO, "AHT20 sensor measurement start");
    #endif
    // Get temp in Celsius (℃), range -40-80℃
    values.temperature = aht20.getTemperature_C();
    // Get relative humidity (%RH), range 0-100℃
    values.humidity = aht20.getHumidity_RH();

    #if(SYSTEM_LOG == STD_ON)
      log(INFO, "AHT20 sensor get values successful");
    #endif
  }else{
    #if(SYSTEM_LOG == STD_ON)
      log(INFO, "AHT20 sensor measurement not ready");
    #endif
  }

  return values;
}