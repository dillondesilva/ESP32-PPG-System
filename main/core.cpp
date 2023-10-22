#include <Arduino.h>
#include "core.h"

void core::update_threshold(int raw_ppg_value) {
    if (raw_ppg_value < min_sensor_val) 
    {
        core::min_sensor_val = raw_ppg_value;
    } else if (raw_ppg_value > max_sensor_val) 
    {
        core::max_sensor_val = raw_ppg_value;
    }

    core::threshold = (core::min_sensor_val + core::max_sensor_val) / 2;
}

bool core::update_pulse_train(int raw_ppg_value) {
    bool current_pulse_train_state = raw_ppg_value > core::threshold;
    bool pulse_train_changed = false;
    if (current_pulse_train_state != prev_pulse_train_state) 
    {
        pulse_train_changed = true;
        unsigned long current_millis = millis();
        core::pulse_period = current_millis - core::prev_pulse_train_transition;
        core::prev_pulse_train_transition = current_millis;
    }

    core::prev_pulse_train_state = current_pulse_train_state;
    return pulse_train_changed;
}

int core::get_bpm() {
    int heart_rate = 60000.0 / core::pulse_period;
    return heart_rate;
}