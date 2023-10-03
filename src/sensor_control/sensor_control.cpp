/*
Authors: Dillon de Silva
Description: 
*/

#include "sensor_control.h"
#include "switch.h"

#define DEBOUNCE_CNT 5 

sensor_control::sensor_control(int power_btn_pin, int warning_btn_pin, int pulse_rate_led_pin, int warning_light_pin, int ppg_sensor_pin)
{
    _power_btn = power_btn_pin;
    _warning_btn = warning_btn_pin;
    _pulse_rate_led = pulse_rate_led_pin;
    _warning_led = warning_light_pin;
    _ppg_sensor = ppg_sensor_pin;
}

void sensor_control::ppg_device_on_off() {

}

void sensor_control::led_pulse_rate_on_off() {

}

void sensor_control::read_pulse_sensor() {

}

class SensorControl {
    public:
        int power_button;
        int warning_toggle_button;
        int pulse_rate_led;
        int warning_led;
        int ppg_sensor;
        
        SensorControl(int btn1_pin, int btn2_pin, int led1_pin, int led2_pin, int led3_pin) {
            power_button = btn1_pin; 
            warning_toggle_button = btn2_pin; 

            pulse_rate_led = led1_pin; 
            warning_led = led2_pin; 
            ppg_sensor = led3_pin; 
        }

    void ppg_device_on_off() {
        // Method for controlling device on/off
    }

    void led_pulse_rate_on_off() {
        
    }

    void read_pulse_sensor() {
        
    }
};