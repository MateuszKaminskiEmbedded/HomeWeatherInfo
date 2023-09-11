#ifndef AHT20SENSOR_H
#define AHT20SENSOR_H

typedef struct{
  float temperature;
  float humidity;
} AHT20_values;

void AHT20_Init(void);
AHT20_values AHT20getValue(void);

#endif /*AHT20SENSOR_H*/