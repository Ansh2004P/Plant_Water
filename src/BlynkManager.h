#define BLYNK_TEMPLATE_ID "TMPL3Yne3nTs6"
#define BLYNK_TEMPLATE_NAME "plant water"
#define BLYNK_AUTH_TOKEN "t_Yx5DhL6BGFDl0OU1KgyI-20THJCF2t"

#ifndef BLYNK_MANAGER_H
#define BLYNK_MANAGER_H

void setupBlynk();
void sendToBlynk(float temperature, float humidity, int soilMoisture);
void runBlynk();  

#endif
