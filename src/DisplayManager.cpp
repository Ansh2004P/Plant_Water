#include "DisplayManager.h"
#include <Arduino.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setupDisplay() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    Serial.begin(9600); // Initialize Serial Monitor
}

void displayData(float temperature, float humidity, int soilMoisture) {
    lcd.clear();
    
    Serial.print("Temp: ");
    Serial.print(temperature, 1);
    Serial.print("C | Humidity: ");
    Serial.print(humidity, 0);
    Serial.print("% | Moisture: ");
    Serial.println(soilMoisture);

    if (soilMoisture < 600) {  
        lcd.setCursor(0, 0);
        lcd.print("T:");
        lcd.print(temperature, 1);
        lcd.print("C");

        lcd.setCursor(8, 0);
        lcd.print("H:");
        lcd.print(humidity, 0);
        lcd.print("%");

        lcd.setCursor(0, 1);
        lcd.print("Moist:");
        lcd.print(soilMoisture);
    } else {
        lcd.setCursor(3, 0);
        lcd.print("Water");
        lcd.setCursor(3, 1);
        lcd.print("Needed!");

        Serial.println("🚰 Water Needed!");
    }
}
