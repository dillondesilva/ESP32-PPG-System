#line 1 "/Users/dillon/projects/esp32-ppg-system/main/sensor_control.cpp"
/*
Authors: Dillon de Silva
Description: 
*/
#include <Arduino.h>
#include "sensor_control.h"
#include "switch.h"

#define DEBOUNCE_CNT 5 

sensor_control::sensor_control(uint8_t led_pulse_btn_pin, uint8_t warning_btn_pin, uint8_t pulse_rate_led_pin, uint8_t warning_light_pin, uint8_t ppg_sensor_pin)
{
    pinMode(pulse_rate_led_pin, OUTPUT);
    pinMode(warning_light_pin, OUTPUT);
    pinMode(led_pulse_btn_pin, INPUT);
    pinMode(warning_btn_pin, INPUT);

    static Switch led_pulse_btn(led_pulse_btn_pin, 5);
    static Switch warning_btn(warning_btn_pin, 10);
    _led_pulse_btn = &(led_pulse_btn);
    _warning_btn = &(warning_btn);
    _pulse_rate_led = pulse_rate_led_pin;
    _warning_led = warning_light_pin;
    _ppg_sensor = ppg_sensor_pin;
}

bool sensor_control::get_power_state() {
    // bool curr_power_state = sensor_control::_power_btn->state();
    // uint8_t switch_value = digitalRead(sensor_control::_power_btn->id());
    // if (sensor_control::_power_btn->update(switch_value)) {
    //     switch (curr_power_state) {
    //         case 1:
    //             sensor_control::_warning_btn->update(1); // LED on
    //         case 0:
    //             sensor_control::_warning_btn->update(0); // LED off
    //     }
    // }

    // curr_power_state = sensor_control::_power_btn->state();
    // return curr_power_state;
}

void sensor_control::flash_pulse_rate(bool is_on) {
    int pin = sensor_control::_pulse_rate_led;
    digitalWrite(pin, is_on);
}

void sensor_control::led_pulse_rate_on_off() {
    uint8_t switch_value = digitalRead(sensor_control::_led_pulse_btn->id());
    sensor_control::_led_pulse_btn->update(switch_value);
}

void sensor_control::warning_led_on() {
    int pin = sensor_control::_warning_led;
    digitalWrite(pin, HIGH);
}

void sensor_control::warning_led_off() {
    uint8_t switch_value = digitalRead(sensor_control::_warning_btn->id());
    if (_warning_btn->update(switch_value)) {
        Serial.println("Warning LED Button was pressed");
        int pin = sensor_control::_warning_led;
        digitalWrite(pin, LOW);
    }
}

int sensor_control::read_pulse_sensor() {
    return int(analogRead(sensor_control::_ppg_sensor));
}