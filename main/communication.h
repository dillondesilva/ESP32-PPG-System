#include <iostream>
#include <string>
#include "BluetoothSerial.h"
#ifndef __COMMUNICATION__

using namespace std;

class communication {
    public:
        BluetoothSerial serial_bt;
        communication(char* ptr_bt_name);
        void initialize_bluetooth();
        char* formatPacket(uint8_t raw_ppg_value);
        bool send(char data_packet[]);

    private:
        unsigned long packet_clock;
};

#define __COMMUNICATION__
#endif