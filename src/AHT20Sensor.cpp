#include "AHT20Sensor.h"
#include "system_config.h"
#include "log.h"
#include "DFRobot_AHT20.h"

DFRobot_AHT20 aht20;

void AHT20_Init(void){
    uint8_t status = 0;
    
    while((status = aht20.begin()) != 0){
    log(ERROR, "AHT20 sensor initialization failed. error status : ");
    delay(500);
  }
}

void AHT20getValue(void){
  if(aht20.startMeasurementReady(/* crcEn = */true)){
    // Get temp in Celsius (℃), range -40-80℃
    Serial.print(aht20.getTemperature_C());
    Serial.print(" C, ");
    // Get relative humidity (%RH), range 0-100℃
    Serial.print(aht20.getHumidity_RH());
    Serial.println(" %RH");
  }
}