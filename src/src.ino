#include "SensorReadings.h"  
#include "DisplayManager.h"  
#include "PIR_Buzzer.h"
#include "BlynkManager.h"
#include "PumpController.h"

void setup() {
    Serial.begin(9600);  
    setupBlynk();
    setupSensors();
    setupDisplay();
    setupPIRBuzzer();
    setupPump();
}

void loop() {
    float temperature, humidity;
    int soilMoisture = readSoilMoisture();
    readTemperatureHumidity(temperature, humidity);
    displayData(temperature, humidity, soilMoisture);
    controlPump(soilMoisture);

    checkMotion();
    
    sendToBlynk(temperature, humidity, soilMoisture);
    runBlynk(); 
    
    delay(3000);

}


