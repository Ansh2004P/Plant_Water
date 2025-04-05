#include "PumpController.h"
#include <Arduino.h>

bool pumpState = false;  // Track pump ON/OFF

// You can tweak these values as needed


void setupPump() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);  // Pump OFF initially
}

void controlPump(int soilMoisture) {
    if (!pumpState && soilMoisture < TURN_ON_THRESHOLD) {
        digitalWrite(RELAY_PIN, HIGH);  // Turn pump ON
        pumpState = true;
    }
    else if (pumpState && soilMoisture > TURN_OFF_THRESHOLD) {
        digitalWrite(RELAY_PIN, LOW);   // Turn pump OFF
        pumpState = false;
    }
}
