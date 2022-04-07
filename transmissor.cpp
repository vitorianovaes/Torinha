#include <RH_ASK.h> //library for transmission control
#include <SD.h> //library for SD card management
#include <SPI.h> 

// Arduino                     Transmitter
//  GND--------------------------GND
//  D8--------------------------Data
//  5V---------------------------VCC

#define BTNSEND A0
#define LEDSTATE 7
#define TRANSPIN 9

RH_ASK driver(2000, 2, TRANSPIN); // speed, rxPin, txPin

void setup() {
    Serial.begin(9600); // Initilizate serial in 9600 bauds 

    // LED configuration
    pinMode(LEDSTATE, OUTPUT);
    digitalWrite(LEDSTATE, LOW);

    // BTN setup
    pinMode(BTNSEND, INPUT_PULLUP);

    // disable w5100 while setting up SD
    pinMode(10,OUTPUT);
    digitalWrite(10,HIGH);
    Serial.print("Starting SD..");
    if(!SD.begin(4)) Serial.println("SD init failed");

    if (!driver.init()) Serial.println("RH Driver init failed");
}

void loop() {
    if(digitalRead(BTNSEND)==LOW){
        digitalWrite(LEDSTATE,HIGH); // light signal sending activated

        File myFile = SD.open("BOB.TXT");

        if (myFile) {
            byte clientBuf[64];
            int clientCount = 0;

            while(myFile.available()){
                clientBuf[clientCount] = myFile.read();
                clientCount++;

                if(clientCount > 63){
                    // Serial.println("Packet");
                    driver.send(clientBuf, 64);
                    driver.waitPacketSent();
                    clientCount = 0;     
                }
            }

            //final <64 byte cleanup packet
            if(clientCount > 0) {
                driver.send(clientBuf, clientCount);
                driver.waitPacketSent();
            }

            driver.send("\r", 1); // end of package signal
            
            // close the file:
            myFile.close();
            delay(500);
            digitalWrite(LEDSTATE,LOW);
            delay(750);
            digitalWrite(LEDSTATE,HIGH);
            delay(750);
            digitalWrite(LEDSTATE,LOW);
            delay(750);
            digitalWrite(LEDSTATE,HIGH);
            delay(300);
        }
    }
}