// Woodpecker_CAN_Debugger.ino - Smarter CAN Bus Debugging and Test Sketch for Seeed Studio mcp2515_can library

#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 9;
mcp2515_can CAN(SPI_CS_PIN);

const int LED_PIN = 13;
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 1000; // send every 1 second

unsigned char testPacket[8] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x00, 0x00, 0x00};

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  while (CAN_OK != CAN.begin(CAN_500KBPS)) {
    Serial.println("CAN BUS Shield init fail");
    Serial.println("Retrying...");
    delay(500);
  }
  Serial.println("CAN BUS Shield init ok!");
  Serial.println("Type 'h' for help commands.");
}

void loop() {
  if (millis() - lastSendTime >= sendInterval) {
    sendTestPacketWithRetry();
    lastSendTime = millis();
  }

  if (Serial.available()) {
    char cmd = Serial.read();
    handleSerialCommand(cmd);
  }
}

void sendTestPacketWithRetry() {
  const int maxRetries = 3;
  int attempts = 0;
  byte sndStat = 1;

  while (attempts < maxRetries && sndStat != CAN_OK) {
    sndStat = CAN.sendMsgBuf(0x123, 0, 8, testPacket);
    if (sndStat == CAN_OK) {
      Serial.println("Test packet sent successfully.");
      blinkLED();
      return;
    }
    attempts++;
    delay(50);
  }

  Serial.print("Error sending test packet after ");
  Serial.print(attempts);
  Serial.println(" attempts.");
}

void handleSerialCommand(char cmd) {
  switch (cmd) {
    case 't':
      sendTestPacketWithRetry();
      break;
    case 'h':
      printHelp();
      break;
    default:
      Serial.println("Unknown command. Type 'h' for help.");
      break;
  }
}

void printHelp() {
  Serial.println("\nAvailable Commands:");
  Serial.println("t - Send test CAN frame");
  Serial.println("h - Show help");
}

void blinkLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
}