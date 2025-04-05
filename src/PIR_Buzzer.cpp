#include "PIR_Buzzer.h"

unsigned long motionStartTime = 0;  
bool motionActive = false;          
int buzzerCount = 0;                

void setupPIRBuzzer() {
    pinMode(PIR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void checkMotion() {
    int motionDetected = digitalRead(PIR_PIN);

    if (motionDetected == HIGH) {
        if (!motionActive) {  
            motionStartTime = millis();  
            motionActive = true;  
            buzzerCount = 0;  // Reset buzzer cycle count
        }

        // If motion detected continuously for 25 sec
        if (buzzerCount < 2 && millis() - motionStartTime >= 25000) {  
            Serial.println("Motion Detected for 25 sec! Buzzer ON");
            
            // Buzzer ON for 1 sec
            tone(BUZZER_PIN, 1000);
            delay(1000);
            noTone(BUZZER_PIN);
            Serial.println("Buzzer OFF");

            // 1 sec delay before the second buzzer activation
            delay(1000);

            // Buzzer ON for 1 sec (second time)
            tone(BUZZER_PIN, 1000);
            delay(1000);
            noTone(BUZZER_PIN);
            Serial.println("Buzzer OFF");

            // Reset time after two buzzer activations
            motionStartTime = millis();  
            buzzerCount = 2;  // Prevent further buzzing until next 25 sec cycle
        }
    } else {
        // Reset if no motion
        motionActive = false;
        motionStartTime = millis();  
        buzzerCount = 0;  // Reset buzzer count for next detection
        noTone(BUZZER_PIN);
    }
}
