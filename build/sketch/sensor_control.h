#line 1 "/Users/dillon/projects/esp32-ppg-system/main/sensor_control.h"
/*
Authors: Dillon de Silva
Description: 
*/
#include "switch.h"
#ifndef  __sensor_control__

class sensor_control {
    public:
        Switch* _power_btn;
        Switch* _warning_btn;
        uint8_t _pulse_rate_led;
        uint8_t _warning_led;
        uint8_t _ppg_sensor;
        sensor_control(uint8_t power_btn_pin, uint8_t warning_btn_pin, uint8_t pulse_rate_led_pin, uint8_t warning_light_pin, uint8_t ppg_sensor_pin);
        void ppg_device_on_off(bool switch_value);
        void led_pulse_rate_on_off();
        void read_pulse_sensor();
};
#define __sensor_control__
#endif