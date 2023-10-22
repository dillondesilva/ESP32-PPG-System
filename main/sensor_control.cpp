/*
Authors: Dillon de Silva
Description: 
*/
#include <Arduino.h>
#include "sensor_control.h"
#include "switch.h"

#define DEBOUNCE_CNT 5 

sensor_control::sensor_control(uint8_t power_btn_pin, uint8_t warning_btn_pin, uint8_t pulse_rate_led_pin, uint8_t warning_light_pin, uint8_t ppg_sensor_pin)
{
    static Switch power_btn(power_btn_pin, 5);
    static Switch warning_btn(5, 10);
    _power_btn = &(power_btn);
    _warning_btn = &(warning_btn);
    _pulse_rate_led = pulse_rate_led_pin;
    _warning_led = warning_light_pin;
    _ppg_sensor = ppg_sensor_pin;
}

bool sensor_control::get_power_state() {
    bool curr_power_state = sensor_control::_power_btn->state();
    uint8_t switch_value = digitalRead(sensor_control::_power_btn->id());
    Serial.println(switch_value);
    if (sensor_control::_power_btn->update(switch_value)) {
        switch (curr_power_state) {
            case 1:
                sensor_control::_warning_btn->update(1); // Device on
            case 0:
                sensor_control::_warning_btn->update(0); // Device off
        }
    }

    curr_power_state = sensor_control::_power_btn->state();
    return curr_power_state;
}

void sensor_control::flash_pulse_rate(bool is_changeable) {
    if (is_changeable) {
        int pin = sensor_control::_pulse_rate_led;
        digitalWrite(pin, !digitalRead(pin));
    }
}

void sensor_control::led_pulse_rate_on_off() {

}

int sensor_control::read_pulse_sensor() {
    return int(analogRead(sensor_control::_ppg_sensor));
}