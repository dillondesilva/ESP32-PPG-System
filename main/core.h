#ifndef  __CORE__

class core {
    public:
        void update_threshold(int raw_ppg_value);
        bool update_pulse_train(int raw_ppg_value);
        int get_bpm();

        int min_sensor_val = 4095; 
        int max_sensor_val = 0;
        int threshold = (min_sensor_val + max_sensor_val) / 2;
        unsigned long pulse_period = 0;
        unsigned long prev_pulse_train_transition = 0;
        bool prev_pulse_train_state = false;
};

#define __CORE__
#endif