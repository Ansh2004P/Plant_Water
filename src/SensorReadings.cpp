#include "SensorReadings.h"
#include <Arduino.h>

DHT dht(DHTPIN, DHTTYPE);

void setupSensors() {
    pinMode(SOIL_SENSOR_PIN, INPUT);
    dht.begin();
}

int readSoilMoisture() {
    return analogRead(SOIL_SENSOR_PIN);
}

void readTemperatureHumidity(float &temperature, float &humidity) {
    // Try multiple times if the sensor gives NaN
    for (int i = 0; i < 5; i++) {  
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();

        if (!isnan(temperature) && !isnan(humidity)) {
            return; // Exit loop if valid values received
        }
        delay(500); // Wait and retry
    }

    // If NaN persists, set default values
    temperature = -1;
    humidity = -1;
}
