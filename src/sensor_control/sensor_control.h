/*
Authors: Dillon de Silva
Description: 
*/
class sensor_control {
    private:
        int _power_btn;
        int _warning_btn;
        int _pulse_rate_led;
        int _warning_led;
        int _ppg_sensor;
    public:
        sensor_control(int power_btn_pin, int warning_btn_pin, int pulse_rate_led_pin, int warning_light_pin, int ppg_sensor_pin);
        void ppg_device_on_off();
        void led_pulse_rate_on_off();
        void read_pulse_sensor();
};