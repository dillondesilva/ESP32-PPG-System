#include "sensor_control.h"
#define POWER_BTN_PIN 25

void setup() {
    Serial.begin(115200);
}

void loop() {
    sensor_control panel = sensor_control(25, 13, 4, 4, 2);
    Serial.println("Hello");
}