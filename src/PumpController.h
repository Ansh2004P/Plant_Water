#ifndef PUMP_CONTROLLER_H
#define PUMP_CONTROLLER_H

#define TURN_ON_THRESHOLD 300
#define TURN_OFF_THRESHOLD 400

#define RELAY_PIN 4          // Set to the digital pin connected to the relay

void setupPump();
void controlPump(int soilMoisture);

#endif
