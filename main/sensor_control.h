/*
Authors: Dillon de Silva
Description: 
*/
#include "switch.h"
#ifndef  __sensor_control__

class sensor_control {
    public:
        Switch* _led_pulse_btn;
        Switch* _warning_btn;
        uint8_t _pulse_rate_led;
        uint8_t _warning_led;
        uint8_t _ppg_sensor;
        sensor_control(uint8_t power_btn_pin, uint8_t warning_btn_pin, uint8_t pulse_rate_led_pin, uint8_t warning_light_pin, uint8_t ppg_sensor_pin);
        bool get_power_state();
        void flash_pulse_rate(bool is_changeable);
        void led_pulse_rate_on_off();
        void warning_led_on();
        void warning_led_off();
        int read_pulse_sensor();
};
#define __sensor_control__
#endif
