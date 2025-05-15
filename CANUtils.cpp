#include "CANUtils.h"

CANUtils::CANUtils(byte csPin)
    : mcpCan(csPin)  // initialize mcp2515_can with chip select pin
{}

bool CANUtils::begin(uint32_t speed) {
    byte res = mcpCan.begin(speed, MCP_16MHz);
    return (res == CAN_OK);
}

byte CANUtils::checkReceive() {
    return mcpCan.checkReceive();
}

byte CANUtils::readMsgBuf(byte *len, byte *buf) {
    return mcpCan.readMsgBuf(len, buf);
}

byte CANUtils::sendMsgBuf(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf, bool wait_sent) {
    return mcpCan.sendMsgBuf(id, ext, rtrBit, len, buf, wait_sent);
}
