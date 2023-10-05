#include <Arduino.h>
#line 1 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
#include "sensor_control.h"
#define POWER_BTN_PIN 25

#line 4 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void setup();
#line 8 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void loop();
#line 4 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void setup() {
    Serial.begin(115200);
}

void loop() {
    sensor_control panel = sensor_control(25, 13, 4, 4, 2);
    Serial.println("Hello");
}
