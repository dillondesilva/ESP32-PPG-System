#line 1 "/Users/dillon/projects/esp32-ppg-system/main/sensor_control.cpp"
/*
Authors: Dillon de Silva
Description: 
*/

#include "sensor_control.h"
#include "switch.h"

#define DEBOUNCE_CNT 5 

sensor_control::sensor_control(uint8_t power_btn_pin, uint8_t warning_btn_pin, uint8_t pulse_rate_led_pin, uint8_t warning_light_pin, uint8_t ppg_sensor_pin)
{
    Switch _power_btn(5, 10);
    Switch _warning_btn(5, 10);
    _pulse_rate_led = pulse_rate_led_pin;
    _warning_led = warning_light_pin;
    _ppg_sensor = ppg_sensor_pin;
}

void sensor_control::ppg_device_on_off(bool switch_value) {
    bool curr_power_state = sensor_control::_power_btn->state();
    if (sensor_control::_power_btn->update(switch_value)) {
        switch (curr_power_state) {
            case 1:
                sensor_control::_warning_btn->update(1); // Device on
            case 0:
                sensor_control::_warning_btn->update(0); // Device off
        }
    }
}

void sensor_control::led_pulse_rate_on_off() {

}

void sensor_control::read_pulse_sensor() {

}