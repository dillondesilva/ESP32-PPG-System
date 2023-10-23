#include <Arduino.h>
#include "arduinoFFT.h"
#include "core.h"

void core::update_data(int raw_pulse_value) {
    if (curr_buffer_len == SAMPLING_RATE) {
        core::raw_ppg_buffer.pop();
    }

    core::raw_ppg_buffer.push(raw_ppg_buffer);
}

bool core::update_pulse_train(int raw_ppg_value) {
    bool current_pulse_train_state = raw_ppg_value > core::threshold;

    if ((current_pulse_train_state == false) && (current_pulse_train_state != core::prev_pulse_train_state)) {
        // Just exited a pulse - we should log the time here
        unsigned long current_millis = millis();
        core::pulse_period = current_millis - core::prev_pulse_train_transition;
        core::prev_pulse_train_state = current_pulse_train_state;
        core::prev_pulse_train_transition = current_millis;
    }

    core::prev_pulse_train_state = current_pulse_train_state;
    return current_pulse_train_state;
}

int core::fft_bpm() {
    double real_points = core::raw_ppg_real_buff;
    double im_points = core::raw_ppg_im_buff;
    arduinoFFT FFT = arduinoFFT(real_points, im_points, MAX_PPG_BUFFER_SIZE, SAMPLING_RATE);
    FFT.Compute();
}

int core::get_bpm() {
    int heart_rate = 60000.0 / core::pulse_period;
    return heart_rate;
}