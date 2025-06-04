#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 9;
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin                                  // Set CS pin s


int ch1; // channels
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int ch7;
int ch8;

unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};

unsigned char forward[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char reverse[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char threnable[8] = {0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char thrdisabl[8] = {0x05, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

unsigned char steer20[8] = {0x40, 0xFA, 0xCF, 0x39, 0x00, 0x00, 0x00, 0x00};
unsigned char steer19[8] = {0x40, 0xFA, 0x71, 0x38, 0x00, 0x00, 0x00, 0x00};
unsigned char steer18[8] = {0x40, 0xFA, 0x13, 0x37, 0x00, 0x00, 0x00, 0x00};
unsigned char steer17[8] = {0x40, 0xFA, 0xB5, 0x35, 0x00, 0x00, 0x00, 0x00};
unsigned char steer16[8] = {0x40, 0xFA, 0x57, 0x34, 0x00, 0x00, 0x00, 0x00};
unsigned char steer15[8] = {0x40, 0xFA, 0xF9, 0x32, 0x00, 0x00, 0x00, 0x00};
unsigned char steer14[8] = {0x40, 0xFA, 0x9B, 0x31, 0x00, 0x00, 0x00, 0x00};
unsigned char steer13[8] = {0x40, 0xFA, 0x3D, 0x30, 0x00, 0x00, 0x00, 0x00};
unsigned char steer12[8] = {0x40, 0xFA, 0xDF, 0x2E, 0x00, 0x00, 0x00, 0x00};
unsigned char steer11[8] = {0x40, 0xFA, 0x81, 0x2D, 0x00, 0x00, 0x00, 0x00};
unsigned char steer10[8] = {0x40, 0xFA, 0x23, 0x2C, 0x00, 0x00, 0x00, 0x00};
unsigned char steer9[8] = {0x40, 0xFA, 0xC5, 0x2A, 0x00, 0x00, 0x00, 0x00};
unsigned char steer8[8] = {0x40, 0xFA, 0x67, 0x29, 0x00, 0x00, 0x00, 0x00};
unsigned char steer7[8] = {0x40, 0xFA, 0x09, 0x28, 0x00, 0x00, 0x00, 0x00};
unsigned char steer6[8] = {0x40, 0xFA, 0xAB, 0x26, 0x00, 0x00, 0x00, 0x00};
unsigned char steer5[8] = {0x40, 0xFA, 0x4D, 0x25, 0x00, 0x00, 0x00, 0x00};
unsigned char steer4[8] = {0x40, 0xFA, 0xEF, 0x23, 0x00, 0x00, 0x00, 0x00};
unsigned char steer3[8] = {0x40, 0xFA, 0x91, 0x22, 0x00, 0x00, 0x00, 0x00};
unsigned char steer2[8] = {0x40, 0xFA, 0x33, 0x21, 0x00, 0x00, 0x00, 0x00};
unsigned char steer1[8] = {0x40, 0xFA, 0xD5, 0x1F, 0x00, 0x00, 0x00, 0x00};
unsigned char steer0[8] = {0x40, 0xFA, 0x77, 0x1E, 0x00, 0x00, 0x00, 0x00};
unsigned char steern1[8] = {0x40, 0xFA, 0x19, 0x1D, 0x00, 0x00, 0x00, 0x00};
unsigned char steern2[8] = {0x40, 0xFA, 0xBB, 0x1B, 0x00, 0x00, 0x00, 0x00};
unsigned char steern3[8] = {0x40, 0xFA, 0x5D, 0x1A, 0x00, 0x00, 0x00, 0x00};
unsigned char steern4[8] = {0x40, 0xFA, 0xFF, 0x18, 0x00, 0x00, 0x00, 0x00};
unsigned char steern5[8] = {0x40, 0xFA, 0xA1, 0x17, 0x00, 0x00, 0x00, 0x00};
unsigned char steern6[8] = {0x40, 0xFA, 0x43, 0x16, 0x00, 0x00, 0x00, 0x00};
unsigned char steern7[8] = {0x40, 0xFA, 0xE5, 0x14, 0x00, 0x00, 0x00, 0x00};
unsigned char steern8[8] = {0x40, 0xFA, 0x87, 0x13, 0x00, 0x00, 0x00, 0x00};
unsigned char steern9[8] = {0x40, 0xFA, 0x29, 0x12, 0x00, 0x00, 0x00, 0x00};
unsigned char steern10[8] = {0x40, 0xFA, 0xCB, 0x10, 0x00, 0x00, 0x00, 0x00};
unsigned char steern11[8] = {0x40, 0xFA, 0x6D, 0x0F, 0x00, 0x00, 0x00, 0x00};
unsigned char steern12[8] = {0x40, 0xFA, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00};
unsigned char steern13[8] = {0x40, 0xFA, 0xB1, 0x0C, 0x00, 0x00, 0x00, 0x00};
unsigned char steern14[8] = {0x40, 0xFA, 0x53, 0x0B, 0x00, 0x00, 0x00, 0x00};
unsigned char steern15[8] = {0x40, 0xFA, 0xF5, 0x09, 0x00, 0x00, 0x00, 0x00};
unsigned char steern16[8] = {0x40, 0xFA, 0x97, 0x08, 0x00, 0x00, 0x00, 0x00};
unsigned char steern17[8] = {0x40, 0xFA, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00};
unsigned char steern18[8] = {0x40, 0xFA, 0xDA, 0x05, 0x00, 0x00, 0x00, 0x00};
unsigned char steern19[8] = {0x40, 0xFA, 0x7C, 0x04, 0x00, 0x00, 0x00, 0x00};
unsigned char steern20[8] = {0x40, 0xFA, 0x1E, 0x03, 0x00, 0x00, 0x00, 0x00};


//Accelerator 
unsigned char accel0[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel1[8] = {0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel2[8] = {0x5C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel3[8] = {0x8A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel4[8] = {0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel5[8] = {0xE6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel6[8] = {0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel7[8] = {0x42, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel8[8] = {0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel9[8] = {0x9E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel10[8] = {0xCC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel11[8] = {0xFA, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel12[8] = {0x28, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel13[8] = {0x56, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel14[8] = {0x84, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel15[8] = {0xB2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel16[8] = {0xE0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel17[8] = {0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel18[8] = {0x3C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel19[8] = {0x6A, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel20[8] = {0x98, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel21[8] = {0xC6, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel22[8] = {0xF4, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel23[8] = {0x22, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel24[8] = {0x50, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel25[8] = {0x7E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel26[8] = {0xAC, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel27[8] = {0xDA, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel28[8] = {0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel29[8] = {0x36, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel30[8] = {0x64, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel31[8] = {0x92, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel32[8] = {0xC0, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel33[8] = {0xEE, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel34[8] = {0x1C, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel35[8] = {0x4A, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel36[8] = {0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel37[8] = {0xA6, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel38[8] = {0xD4, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel39[8] = {0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel40[8] = {0x30, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel41[8] = {0x5E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel42[8] = {0x8C, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel43[8] = {0xBA, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel44[8] = {0xE8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel45[8] = {0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char accel46[8] = {0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};



//Brakes
unsigned char brake1[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake2[8] = {0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake3[8] = {0x01, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake4[8] = {0x01, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake5[8] = {0x01, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake6[8] = {0x01, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake7[8] = {0x01, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake8[8] = {0x01, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake9[8] = {0x01, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake10[8] = {0x01, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake11[8] = {0x01, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake12[8] = {0x01, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake13[8] = {0x01, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake14[8] = {0x01, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake15[8] = {0x01, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake16[8] = {0x01, 0x00, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake17[8] = {0x01, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake18[8] = {0x01, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake19[8] = {0x01, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake20[8] = {0x01, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char brake21[8] = {0x01, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00};




void setup() {
     Serial.begin(115200);
     

    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");

  pinMode(0, INPUT); 
  pinMode(19, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(18, INPUT); 

  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2,OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3,OUTPUT);
  digitalWrite(A3,LOW);

}

void loop() {
    
  ch1 = pulseIn(3, HIGH, 30000); // Steering 
  ch2 = pulseIn(4, HIGH, 30000); // Acceleration
  ch3 = pulseIn(5, HIGH, 30000); // Steering2
  ch4 = pulseIn(6, HIGH, 30000); // Throttle and Brake Enable /Disable
  ch5 = pulseIn(0, HIGH, 30000); // Switch1 SF - Power ON/OFF 
  ch6 = pulseIn(7, HIGH, 30000); // Switch2 SG - Forward Reverse switch
  ch7 = pulseIn(A4, HIGH, 30000); // Switch1 SA - Ignition ON/OFF
  ch8 = pulseIn(A5, HIGH, 30000); // Brakes

  Serial.print("Steering: "); 
  Serial.print(ch1);        // Steering
  Serial.print(" | ");
 Serial.print(ch2);       //Acceleration
 Serial.print(": Acceleration");
 Serial.print("| Steering2: "); 
 Serial.print(ch3); 
Serial.print("| ThrottleEnable: "); 
 Serial.print(ch4); 
 Serial.print("| SW1: "); 
Serial.println(ch5); 
Serial.print("| SW3: "); 
 Serial.println(ch7); 
 Serial.print("Brakes: "); 
 Serial.println(ch8);        // Brakes

 
  if (ch4 > 980 && ch4 < 1105) {CAN.sendMsgBuf(0x053, 1, 8, thrdisabl);
                            //    CAN.sendMsgBuf(0x051, 1, 8, threnable);
                                Serial.println("Thr_&_Brk_Disable");
                                };
  if (ch4 > 1900 && ch4 < 2100) {CAN.sendMsgBuf(0x00, 0, 8, threnable);
                             //    CAN.sendMsgBuf(0x050, 1, 8, threnable);
                                 Serial.println("Thr_&_Brk_Enable");
                                };
 

 
  if (ch1 > 980 && ch1 < 1105) {CAN.sendMsgBuf(0x219, 0, 8, steern20);Serial.println(-20);};
  if (ch1 > 1106 && ch1 < 1125) {CAN.sendMsgBuf(0x219, 0, 8, steern19);Serial.println(-19);};
  if (ch1 > 1126 && ch1 < 1145) {CAN.sendMsgBuf(0x219, 0, 8, steern18);Serial.println(-18);};
  if (ch1 > 1146 && ch1 < 1165) {CAN.sendMsgBuf(0x219, 0, 8, steern17);Serial.println(-17);};
  if (ch1 > 1166 && ch1 < 1185) {CAN.sendMsgBuf(0x219, 0, 8, steern16);Serial.println(-16);};
  if (ch1 > 1186 && ch1 < 1205) {CAN.sendMsgBuf(0x219, 0, 8, steern15);Serial.println(-15);};
  if (ch1 > 1206 && ch1 < 1225) {CAN.sendMsgBuf(0x219, 0, 8, steern14);Serial.println(-14);};
  if (ch1 > 1226 && ch1 < 1245) {CAN.sendMsgBuf(0x219, 0, 8, steern13);Serial.println(-13);};
  if (ch1 > 1246 && ch1 < 1265) {CAN.sendMsgBuf(0x219, 0, 8, steern12);Serial.println(-12);};
  if (ch1 > 1266 && ch1 < 1285) {CAN.sendMsgBuf(0x219, 0, 8, steern11);Serial.println(-11);};
  if (ch1 > 1286 && ch1 < 1305) {CAN.sendMsgBuf(0x219, 0, 8, steern10);Serial.println(-10);};
  if (ch1 > 1306 && ch1 < 1325) {CAN.sendMsgBuf(0x219, 0, 8, steern9);Serial.println(-9);};
  if (ch1 > 1326 && ch1 < 1345) {CAN.sendMsgBuf(0x219, 0, 8, steern8);Serial.println(-8);};
  if (ch1 > 1346 && ch1 < 1365) {CAN.sendMsgBuf(0x219, 0, 8, steern7);Serial.println(-7);};
  if (ch1 > 1366 && ch1 < 1385) {CAN.sendMsgBuf(0x219, 0, 8, steern6);Serial.println(-6);};
  if (ch1 > 1386 && ch1 < 1405) {CAN.sendMsgBuf(0x219, 0, 8, steern5);Serial.println(-5);};
  if (ch1 > 1406 && ch1 < 1425) {CAN.sendMsgBuf(0x219, 0, 8, steern4);Serial.println(-4);};
  if (ch1 > 1426 && ch1 < 1445) {CAN.sendMsgBuf(0x219, 0, 8, steern3);Serial.println(-3);};
  if (ch1 > 1446 && ch1 < 1465) {CAN.sendMsgBuf(0x219, 0, 8, steern2);Serial.println(-2);};
  if (ch1 > 1466 && ch1 < 1479) {CAN.sendMsgBuf(0x219, 0, 8, steer0);Serial.println(-1);};
  if (ch1 > 1480 && ch1 < 1505) {CAN.sendMsgBuf(0x219, 0, 8, steer0);Serial.println(0);};
  if (ch1 > 1506 && ch1 < 1525) {CAN.sendMsgBuf(0x219, 0, 8, steer0);Serial.println(1);};
  if (ch1 > 1526 && ch1 < 1545) {CAN.sendMsgBuf(0x219, 0, 8, steer2);Serial.println(2);};
  if (ch1 > 1546 && ch1 < 1565) {CAN.sendMsgBuf(0x219, 0, 8, steer3);Serial.println(3);};
  if (ch1 > 1566 && ch1 < 1585) {CAN.sendMsgBuf(0x219, 0, 8, steer4);Serial.println(4);};
  if (ch1 > 1586 && ch1 < 1605) {CAN.sendMsgBuf(0x219, 0, 8, steer5);Serial.println(5);};
  if (ch1 > 1606 && ch1 < 1625) {CAN.sendMsgBuf(0x219, 0, 8, steer6);Serial.println(6);};
  if (ch1 > 1626 && ch1 < 1645) {CAN.sendMsgBuf(0x219, 0, 8, steer7);Serial.println(7);};
  if (ch1 > 1646 && ch1 < 1665) {CAN.sendMsgBuf(0x219, 0, 8, steer8);Serial.println(8);};
  if (ch1 > 1666 && ch1 < 1685) {CAN.sendMsgBuf(0x219, 0, 8, steer9);Serial.println(9);};
  if (ch1 > 1686 && ch1 < 1705) {CAN.sendMsgBuf(0x219, 0, 8, steer10);Serial.println(10);};
  if (ch1 > 1706 && ch1 < 1725) {CAN.sendMsgBuf(0x219, 0, 8, steer11);Serial.println(11);};
  if (ch1 > 1726 && ch1 < 1745) {CAN.sendMsgBuf(0x219, 0, 8, steer12);Serial.println(12);};
  if (ch1 > 1746 && ch1 < 1765) {CAN.sendMsgBuf(0x219, 0, 8, steer13);Serial.println(13);};
  if (ch1 > 1766 && ch1 < 1785) {CAN.sendMsgBuf(0x219, 0, 8, steer14);Serial.println(14);};
  if (ch1 > 1786 && ch1 < 1805) {CAN.sendMsgBuf(0x219, 0, 8, steer15);Serial.println(15);};
  if (ch1 > 1806 && ch1 < 1825) {CAN.sendMsgBuf(0x219, 0, 8, steer16);Serial.println(16);};
  if (ch1 > 1826 && ch1 < 1845) {CAN.sendMsgBuf(0x219, 0, 8, steer17);Serial.println(17);};
  if (ch1 > 1846 && ch1 < 1865) {CAN.sendMsgBuf(0x219, 0, 8, steer18);Serial.println(18);};
  if (ch1 > 1866 && ch1 < 1885) {CAN.sendMsgBuf(0x219, 0, 8, steer19);Serial.println(19);};
  if (ch1 > 1886 && ch1 < 2005) {CAN.sendMsgBuf(0x219, 0, 8, steer19);Serial.println(20);};

if (ch3 > 1000 && ch3 < 1189) CAN.sendMsgBuf(0x220, 0, 8, steern20);
if (ch3 > 1190 && ch3 < 1209) CAN.sendMsgBuf(0x220, 0, 8, steern19);
if (ch3 > 1210 && ch3 < 1229) CAN.sendMsgBuf(0x220, 0, 8, steern18);
if (ch3 > 1230 && ch3 < 1249) CAN.sendMsgBuf(0x220, 0, 8, steern17);
if (ch3 > 1250 && ch3 < 1269) CAN.sendMsgBuf(0x220, 0, 8, steern16);
if (ch3 > 1270 && ch3 < 1289) CAN.sendMsgBuf(0x220, 0, 8, steern15);
if (ch3 > 1290 && ch3 < 1309) CAN.sendMsgBuf(0x220, 0, 8, steern14);
if (ch3 > 1310 && ch3 < 1329) CAN.sendMsgBuf(0x220, 0, 8, steern13);
if (ch3 > 1330 && ch3 < 1349) CAN.sendMsgBuf(0x220, 0, 8, steern12);
if (ch3 > 1350 && ch3 < 1369) CAN.sendMsgBuf(0x220, 0, 8, steern11);
if (ch3 > 1370 && ch3 < 1389) CAN.sendMsgBuf(0x220, 0, 8, steern10);
if (ch3 > 1390 && ch3 < 1409) CAN.sendMsgBuf(0x220, 0, 8, steern9);
if (ch3 > 1410 && ch3 < 1429) CAN.sendMsgBuf(0x220, 0, 8, steern8);
if (ch3 > 1430 && ch3 < 1449) CAN.sendMsgBuf(0x220, 0, 8, steern7);
if (ch3 > 1450 && ch3 < 1469) CAN.sendMsgBuf(0x220, 0, 8, steern6);
if (ch3 > 1470 && ch3 < 1489) CAN.sendMsgBuf(0x220, 0, 8, steern5);
if (ch3 > 1490 && ch3 < 1509) CAN.sendMsgBuf(0x220, 0, 8, steern4);
if (ch3 > 1510 && ch3 < 1529) CAN.sendMsgBuf(0x220, 0, 8, steern3);
if (ch3 > 1530 && ch3 < 1549) CAN.sendMsgBuf(0x220, 0, 8, steern2);
if (ch3 > 1550 && ch3 < 1569) CAN.sendMsgBuf(0x220, 0, 8, steern1);
if (ch3 > 1570 && ch3 < 1590) CAN.sendMsgBuf(0x220, 0, 8, steer0);
if (ch3 > 1591 && ch3 < 1610) CAN.sendMsgBuf(0x220, 0, 8, steer1);
if (ch3 > 1611 && ch3 < 1630) CAN.sendMsgBuf(0x220, 0, 8, steer2);
if (ch3 > 1631 && ch3 < 1650) CAN.sendMsgBuf(0x220, 0, 8, steer3);
if (ch3 > 1651 && ch3 < 1670) CAN.sendMsgBuf(0x220, 0, 8, steer4);
if (ch3 > 1671 && ch3 < 1690) CAN.sendMsgBuf(0x220, 0, 8, steer5);
if (ch3 > 1691 && ch3 < 1710) CAN.sendMsgBuf(0x220, 0, 8, steer6);
if (ch3 > 1711 && ch3 < 1730) CAN.sendMsgBuf(0x220, 0, 8, steer7);
if (ch3 > 1731 && ch3 < 1750) CAN.sendMsgBuf(0x220, 0, 8, steer8);
if (ch3 > 1751 && ch3 < 1770) CAN.sendMsgBuf(0x220, 0, 8, steer9);
if (ch3 > 1771 && ch3 < 1790) CAN.sendMsgBuf(0x220, 0, 8, steer10);
if (ch3 > 1791 && ch3 < 1810) CAN.sendMsgBuf(0x220, 0, 8, steer11);
if (ch3 > 1811 && ch3 < 1830) CAN.sendMsgBuf(0x220, 0, 8, steer12);
if (ch3 > 1831 && ch3 < 1850) CAN.sendMsgBuf(0x220, 0, 8, steer13);
if (ch3 > 1851 && ch3 < 1870) CAN.sendMsgBuf(0x220, 0, 8, steer14);
if (ch3 > 1871 && ch3 < 1890) CAN.sendMsgBuf(0x220, 0, 8, steer15);
if (ch3 > 1891 && ch3 < 1910) CAN.sendMsgBuf(0x220, 0, 8, steer16);
if (ch3 > 1911 && ch3 < 1930) CAN.sendMsgBuf(0x220, 0, 8, steer17);
if (ch3 > 1931 && ch3 < 1950) CAN.sendMsgBuf(0x220, 0, 8, steer18);
if (ch3 > 1951 && ch3 < 2010) CAN.sendMsgBuf(0x220, 0, 8, steer19);


if (ch2 > 950 && ch2 < 1011){ CAN.sendMsgBuf(0x201, 0, 8, accel1);Serial.println("TH1");}
else if (ch2 > 1012 && ch2 < 1033){ CAN.sendMsgBuf(0x201, 0, 8, accel2);Serial.println("TH2");}
else if (ch2 > 1034 && ch2 < 1055){ CAN.sendMsgBuf(0x201, 0, 8, accel3);Serial.println("TH3");}
else if (ch2 > 1056 && ch2 < 1077){ CAN.sendMsgBuf(0x201, 0, 8, accel4);Serial.println("TH4");}
else if (ch2 > 1078 && ch2 < 1099){ CAN.sendMsgBuf(0x201, 0, 8, accel5);Serial.println("TH5");}
else if (ch2 > 1100 && ch2 < 1121){ CAN.sendMsgBuf(0x201, 0, 8, accel6);Serial.println("TH6");}
else if (ch2 > 1122 && ch2 < 1143){ CAN.sendMsgBuf(0x201, 0, 8, accel7);Serial.println("TH7");}
else if (ch2 > 1144 && ch2 < 1165){ CAN.sendMsgBuf(0x201, 0, 8, accel8);Serial.println("TH8");}
else if (ch2 > 1166 && ch2 < 1187){ CAN.sendMsgBuf(0x201, 0, 8, accel9);Serial.println("TH9");}
else if (ch2 > 1188 && ch2 < 1209){ CAN.sendMsgBuf(0x201, 0, 8, accel10);Serial.println("TH10");}
else if (ch2 > 1210 && ch2 < 1231){ CAN.sendMsgBuf(0x201, 0, 8, accel11);Serial.println("TH11");}
else if (ch2 > 1232 && ch2 < 1253){ CAN.sendMsgBuf(0x201, 0, 8, accel12);Serial.println("TH12");}
else if (ch2 > 1254 && ch2 < 1275){ CAN.sendMsgBuf(0x201, 0, 8, accel13);Serial.println("TH13");}
else if (ch2 > 1276 && ch2 < 1297){ CAN.sendMsgBuf(0x201, 0, 8, accel14);Serial.println("TH14");}
else if (ch2 > 1298 && ch2 < 1319){ CAN.sendMsgBuf(0x201, 0, 8, accel15);Serial.println("TH15");}
else if (ch2 > 1320 && ch2 < 1341){ CAN.sendMsgBuf(0x201, 0, 8, accel16);Serial.println("TH16");}
else if (ch2 > 1342 && ch2 < 1363){ CAN.sendMsgBuf(0x201, 0, 8, accel17);Serial.println("TH17");}
else if (ch2 > 1364 && ch2 < 1385){ CAN.sendMsgBuf(0x201, 0, 8, accel18);Serial.println("TH18");}
else if (ch2 > 1386 && ch2 < 1407){ CAN.sendMsgBuf(0x201, 0, 8, accel19);Serial.println("TH19");}
else if (ch2 > 1408 && ch2 < 1429){ CAN.sendMsgBuf(0x201, 0, 8, accel20);Serial.println("TH20");}
else if (ch2 > 1430 && ch2 < 1451){ CAN.sendMsgBuf(0x201, 0, 8, accel21);Serial.println("TH21");}
else if (ch2 > 1452 && ch2 < 1473){ CAN.sendMsgBuf(0x201, 0, 8, accel22);Serial.println("TH22");}
else if (ch2 > 1474 && ch2 < 1495){ CAN.sendMsgBuf(0x201, 0, 8, accel23);Serial.println("TH23");}
else if (ch2 > 1496 && ch2 < 1517){ CAN.sendMsgBuf(0x201, 0, 8, accel24);Serial.println("TH24");}
else if (ch2 > 1518 && ch2 < 1539){ CAN.sendMsgBuf(0x201, 0, 8, accel25);Serial.println("TH25");}
else if (ch2 > 1540 && ch2 < 1561){ CAN.sendMsgBuf(0x201, 0, 8, accel26);Serial.println("TH26");}
else if (ch2 > 1562 && ch2 < 1583){ CAN.sendMsgBuf(0x201, 0, 8, accel27);Serial.println("TH27");}
else if (ch2 > 1584 && ch2 < 1605){ CAN.sendMsgBuf(0x201, 0, 8, accel28);Serial.println("TH28");}
else if (ch2 > 1606 && ch2 < 1627){ CAN.sendMsgBuf(0x201, 0, 8, accel29);Serial.println("TH29");}
else if (ch2 > 1628 && ch2 < 1649){ CAN.sendMsgBuf(0x201, 0, 8, accel30);Serial.println("TH30");}
else if (ch2 > 1650 && ch2 < 1671){ CAN.sendMsgBuf(0x201, 0, 8, accel31);Serial.println("TH31");}
else if (ch2 > 1672 && ch2 < 1693){ CAN.sendMsgBuf(0x201, 0, 8, accel32);Serial.println("TH32");}
else if (ch2 > 1694 && ch2 < 1715){ CAN.sendMsgBuf(0x201, 0, 8, accel33);Serial.println("TH33");}
else if (ch2 > 1716 && ch2 < 1737){ CAN.sendMsgBuf(0x201, 0, 8, accel34);Serial.println("TH34");}
else if (ch2 > 1738 && ch2 < 1759){ CAN.sendMsgBuf(0x201, 0, 8, accel35);Serial.println("TH35");}
else if (ch2 > 1760 && ch2 < 1781){ CAN.sendMsgBuf(0x201, 0, 8, accel36);Serial.println("TH36");}
else if (ch2 > 1782 && ch2 < 1803){ CAN.sendMsgBuf(0x201, 0, 8, accel37);Serial.println("TH37");}
else if (ch2 > 1804 && ch2 < 1825){ CAN.sendMsgBuf(0x201, 0, 8, accel38);Serial.println("TH38");}
else if (ch2 > 1826 && ch2 < 1847){ CAN.sendMsgBuf(0x201, 0, 8, accel39);Serial.println("TH39");}
else if (ch2 > 1848 && ch2 < 1869){ CAN.sendMsgBuf(0x201, 0, 8, accel40);Serial.println("TH40");}
else if (ch2 > 1870 && ch2 < 1891){ CAN.sendMsgBuf(0x201, 0, 8, accel41);Serial.println("TH41");}
else if (ch2 > 1892 && ch2 < 1913){ CAN.sendMsgBuf(0x201, 0, 8, accel42);Serial.println("TH42");}
else if (ch2 > 1914 && ch2 < 1935){ CAN.sendMsgBuf(0x201, 0, 8, accel43);Serial.println("TH43");}
else if (ch2 > 1936 && ch2 < 1957){ CAN.sendMsgBuf(0x201, 0, 8, accel44);Serial.println("TH44");}
else if (ch2 > 1958 && ch2 < 1979){ CAN.sendMsgBuf(0x201, 0, 8, accel45);Serial.println("TH45");}
else if (ch2 > 1980 && ch2 < 2100){ CAN.sendMsgBuf(0x201, 0, 8, accel46);Serial.println("TH46");}
else { CAN.sendMsgBuf(0x201, 0, 8, accel1);Serial.println("Lost_Connection");};


if (ch8<1550 && ch8>1400){ CAN.sendMsgBuf(0x154, 0, 8, brake1);Serial.println("BR1");};
if (ch8<1399 && ch8>1378){ CAN.sendMsgBuf(0x154, 0, 8, brake2);Serial.println("BR2");};
if (ch8<1377 && ch8>1356){ CAN.sendMsgBuf(0x154, 0, 8, brake3);Serial.println("BR3");};
if (ch8<1355 && ch8>1334){ CAN.sendMsgBuf(0x154, 0, 8, brake4);Serial.println("BR4");};
if (ch8<1333 && ch8>1312){ CAN.sendMsgBuf(0x154, 0, 8, brake5);Serial.println("BR5");};
if (ch8<1311 && ch8>1290){ CAN.sendMsgBuf(0x154, 0, 8, brake6);Serial.println("BR6");};
if (ch8<1289 && ch8>1268){ CAN.sendMsgBuf(0x154, 0, 8, brake7);Serial.println("BR7");};
if (ch8<1267 && ch8>1246){ CAN.sendMsgBuf(0x154, 0, 8, brake8);Serial.println("BR8");};
if (ch8<1245 && ch8>1224){ CAN.sendMsgBuf(0x154, 0, 8, brake9);Serial.println("BR9");};
if (ch8<1223 && ch8>1202){ CAN.sendMsgBuf(0x154, 0, 8, brake10);Serial.println("BR10");};
if (ch8<1201 && ch8>1180){ CAN.sendMsgBuf(0x154, 0, 8, brake11);Serial.println("BR11");};
if (ch8<1179 && ch8>1158){ CAN.sendMsgBuf(0x154, 0, 8, brake12);Serial.println("BR12");};
if (ch8<1157 && ch8>1136){ CAN.sendMsgBuf(0x154, 0, 8, brake13);Serial.println("BR13");};
if (ch8<1135 && ch8>1114){ CAN.sendMsgBuf(0x154, 0, 8, brake14);Serial.println("BR14");};
if (ch8<1113 && ch8>1092){ CAN.sendMsgBuf(0x154, 0, 8, brake15);Serial.println("BR15");};
if (ch8<1091 && ch8>1070){ CAN.sendMsgBuf(0x154, 0, 8, brake16);Serial.println("BR16");};
if (ch8<1069 && ch8>1048){ CAN.sendMsgBuf(0x154, 0, 8, brake17);Serial.println("BR17");};
if (ch8<1047 && ch8>1026){ CAN.sendMsgBuf(0x154, 0, 8, brake18);Serial.println("BR18");};
if (ch8<1025 && ch8>1004){ CAN.sendMsgBuf(0x154, 0, 8, brake19);Serial.println("BR19");};
if (ch8<1003 && ch8>982){ CAN.sendMsgBuf(0x154, 0, 8, brake20);Serial.println("BR20");};
if (ch8<981 && ch8>980){ CAN.sendMsgBuf(0x154, 0, 8, brake21);Serial.println("BR21");};



        if ((ch5 >=1950) && (ch5<= 2050)){
          digitalWrite(A0,HIGH);
         Serial.println("CH5 Power ON");
              } 
         else {
            digitalWrite(A0,LOW);
           Serial.println("CH5 Power OFF");
               }

         if ((ch7 >=1950) && (ch7<= 2050)){
          digitalWrite(A3,HIGH);
         Serial.println("CH7 Power ON");
              } 
         else {
            digitalWrite(A3,LOW);
           Serial.println("CH7 Power OFF");
               }      
          
          if ((ch6 >=950) && (ch6<= 1000)){
         digitalWrite(A1,HIGH);
          Serial.println("CH6 Forward ON");
              } 
          else if ((ch6 >=1950) && (ch6<= 2050)){
         digitalWrite(A2,HIGH);
         Serial.println("CH6 Reverse ON");
               }     
         else {
            digitalWrite(A1,LOW);
            digitalWrite(A2,LOW);
           Serial.println("CH6 FW/REW OFF");
              }


    delay(50);                       // send data per 20ms
  
}
