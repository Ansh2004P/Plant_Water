#include "BlynkManager.h"
#include <SoftwareSerial.h>
#include <BlynkSimpleStream.h>

#define WIFI_SSID "ansh"
#define WIFI_PASS "987654321"

SoftwareSerial espSerial(2, 3);  // D2 = RX, D3 = TX (ESP8266)

// Function to send AT commands to ESP8266
void sendATCommand(const char* cmd, int waitTime) {
    espSerial.println(cmd);
    delay(waitTime);
    while (espSerial.available()) {
        Serial.write(espSerial.read());  // Print response to Serial Monitor
    }
}

void setupBlynk() {
    Serial.begin(9600);
    espSerial.begin(115200);
    Serial.println("Initializing ESP8266...");

    sendATCommand("AT", 1000);  // Check if ESP8266 is responding
    sendATCommand("AT+CWMODE=1", 1000);  // Set to Station Mode
    sendATCommand("AT+CWJAP=\"" WIFI_SSID "\",\"" WIFI_PASS "\"", 5000);  // Connect WiFi

    Serial.println("Connecting to Blynk...");
    Blynk.config(espSerial, BLYNK_AUTH_TOKEN);
    Serial.println("Blynk Ready!");
}

void sendToBlynk(float temperature, float humidity, int soilMoisture) {
    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Blynk.virtualWrite(V2, soilMoisture);
}

void runBlynk() {
    Blynk.run();
}

