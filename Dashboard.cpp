#include "Dashboard.h"
#include <Arduino.h>

static constexpr byte diagSessionCtrl[8] = { 0x02, 0x10, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00 };
static constexpr byte testerPresent[8] = { 0x02, 0x3E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 };

Dashboard::Dashboard(CANUtils &can) : canBus(can) {}

void Dashboard::sendDiagnosticSessionControl() {
    canBus.sendMsgBuf(0x6A0, 0, 0, 8, diagSessionCtrl);
}
void Dashboard::sendDashIllumination(byte illumination) {
    byte data[8] = { 0x04, 0x30, 0x10, 0x07, illumination, 0x00, 0x00, 0x00 };
    canBus.sendMsgBuf(0x6A0, 0, 0, 8, data);
}
void Dashboard::sendTesterPresent() {
    canBus.sendMsgBuf(0x6A0, 0, 0, 8, testerPresent);
}