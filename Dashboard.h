#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <Arduino.h>
#include "CANUtils.h"

class Dashboard {
public:
    Dashboard(CANUtils &can);

    // Send specific 0x6A0 messages
    void sendDiagnosticSessionControl();
    void sendDashIllumination(byte illumination); // illumination from 0x00 to 0xC8
    void sendTesterPresent();
private:
    CANUtils& canBus;
};

#endif
