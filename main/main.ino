#include <iostream>
#include <string>
#include "core.h"
#include "communication.h"
#include "sensor_control.h"

#define POWER_BTN_PIN 25
#define PULSE_LED_BTN_PIN 33
#define WARNING_LED_BTN_PIN 32
#define PULSE_LED_PIN 25
#define WARNING_LED_PIN 26

using namespace std;

static communication comms((char *)"AwesomePPG");
static sensor_control sensor_panel(PULSE_LED_BTN_PIN, WARNING_LED_BTN_PIN, PULSE_LED_PIN, WARNING_LED_PIN, 27);
static core core_functions;

void setup() {
    comms.initialize_bluetooth();
    Serial.println("Testing");
}

void loop() {
    // bool curr_power_state = sensor_panel.get_power_state();
    // if (curr_power_state == true)
    // {
        // Serial.println("Log: Device On");
        int pulse_value = sensor_panel.read_pulse_sensor();
        // Serial.println(pulse_value);
        bool is_pt_changed = core_functions.update_pulse_train(pulse_value);
        // Serial.println(pt_value);
        sensor_panel.led_pulse_rate_on_off();
        if (digitalRead(PULSE_LED_BTN_PIN)) {
            sensor_panel.flash_pulse_rate(is_pt_changed);
        }

        int curr_bpm = core_functions.get_bpm();
        if ((curr_bpm < 40) || (curr_bpm > 250)) {
            sensor_panel.warning_led_on();
        }
        sensor_panel.warning_led_off();

        char bpm_data[4];
        sprintf(bpm_data, "%3d\n", curr_bpm);
        // comms.send(bpm_data);

        // char data_packet[5];
        // sprintf(data_packet, "%4d\n", pulse_value);
        // comms.send(data_packet);
        delay(20);
    // }
    // Serial.println("Log: Device Off");
}