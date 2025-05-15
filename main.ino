#include <SPI.h>
#include "CANUtils.h"
#include "Dashboard.h"

CANUtils canBus;
Dashboard dash(canBus);

unsigned long lastTesterPresent = 0;
const unsigned long testerPresentInterval = 2000; // 2000 ms = 2 seconds

void setup() {
    Serial.begin(115200);
    while (!Serial);

    byte result = canBus.begin(CAN_500KBPS);
    if (result == CAN_OK) {
        Serial.println("CAN init successful");
    } else {
        Serial.print("CAN init failed with code: ");
        Serial.println(result);
    }

    // Initial messages
    delay(50);
    dash.sendDiagnosticSessionControl();
    delay(50);
    dash.sendDashIllumination(0x00); // 0% illumination
}

void loop() {
    unsigned long now = millis();
    if (now - lastTesterPresent >= testerPresentInterval) {
        dash.sendTesterPresent();
        lastTesterPresent = now;
    }
}
