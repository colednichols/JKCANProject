#ifndef CANUTILS_H
#define CANUTILS_H

#include <Arduino.h>
#include "mcp2515_can.h"

// Define your SPI chip select pin here or pass it via constructor
#define CAN_CS_PIN 9

class CANUtils {
public:
    CANUtils(byte csPin = CAN_CS_PIN);

    bool begin(uint32_t speed = CAN_500KBPS);
    byte checkReceive();
    byte readMsgBuf(byte *len, byte *buf);
    byte sendMsgBuf(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf, bool wait_sent = true);

private:
    mcp2515_can mcpCan;
};

#endif
