#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_SENSOR_PIN A0

void setupSensors();
int readSoilMoisture();
void readTemperatureHumidity(float &temperature, float &humidity);

#endif
