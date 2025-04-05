#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27

void setupDisplay();
void displayData(float temperature, float humidity, int soilMoisture);

#endif
