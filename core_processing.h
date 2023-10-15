#include <queue>
#ifndef __CORE_PROCESSING__

class core_processing {
    public:
        void update_ppg_data(uint8_t new_value);
        void display_warning_light();
        void get_pulse_rate();
    private:
        queue<uint8_t> raw_ppg_buffer;
        uint8_t pulse_train_state;
        uint8_t last_pt_change;
        void update_maf();
}

#define __CORE_PROCESSING__
#endif