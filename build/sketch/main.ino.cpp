#include <Arduino.h>
#line 1 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
#include "sensor_control.h"
#define POWER_BTN_PIN 25

#line 4 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void setup();
#line 9 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void loop();
#line 4 "/Users/dillon/projects/esp32-ppg-system/main/main.ino"
void setup() {
    Serial.begin(115200);
    Serial.println("Testing");
}

void loop() {
    sensor_control panel = sensor_control(34, 13, 26, 4, 2);
    if (panel.get_power_state())
    {
        uint8_t analog_pulse_value = panel.read_pulse_sensor();
        Serial.println(analog_pulse_value);
    };
}
