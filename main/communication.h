#include "communication.h"
#ifndef __COMMUNICATION__

class communication {
    public:
        void communication(string btName);
        uint8_t[] formatPacket(uint8_t raw_ppg_value);
        bool send(string packet);
}

#define __COMMUNICATION__
#endif