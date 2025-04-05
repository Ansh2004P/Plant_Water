#ifndef PIR_BUZZER_H
#define PIR_BUZZER_H

#include <Arduino.h>

// Define pin numbers
#define PIR_PIN 7
#define BUZZER_PIN 9

// Function declarations
void setupPIRBuzzer();
void checkMotion();

#endif
