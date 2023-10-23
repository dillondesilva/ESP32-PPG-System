#include <iostream>

#ifndef  __CORE__

using namespace std;

#define SAMPLING_RATE 50
#define MAX_PPG_BUFFER_SIZE 15

class core {
    public:
        void update_data(int raw_pulse_value);
        bool update_pulse_train(int raw_ppg_value);
        int get_bpm();
        int fft_bpm();

        int min_sensor_val = 4095; 
        int max_sensor_val = 0;
        int threshold = 4000;
        unsigned long pulse_period = 0;
        unsigned long prev_pulse_train_transition = 0;
        bool prev_pulse_train_state = false;

    private:
        double raw_ppg_real_buff[MAX_PPG_BUFFER_SIZE];
        double raw_ppg_im_buff[MAX_PPG_BUFFER_SIZE] = { 0 };
};

#define __CORE__
#endif