#include <RH_ASK.h> //library for transmission control
#include <SD.h> //library for SD card management
#include <SPI.h> 

// Arduino                     Transmitter
//  GND--------------------------GND
//  D8--------------------------Data
//  5V---------------------------VCC

#define LEDSTATE 7
#define RESPIN 9

int count = 0;

File myFile = SD.open("BOB"+count+".TXT",FILE_WRITE);

RH_ASK driver(2000, RESPIN, 2); // speed, rxPin, txPin

void setup(){
    Serial.begin(9600)

    // LED configuration 
    pinMode(LEDSTATE, OUTPUT);
    digitalWrite(LEDSTATE, LOW);

    if (!driver.init()) Serial.println("init failed");
}

void loop(){`
    byte buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if(driver.recv(buf,&buflen)){`
        if(buf.indexOf("\r") > 0){
            myFile.write(buf);
            myFile.close();
            digitalWrite(LEDSTATE,HIGH);
            delay(750);
            digitalWrite(LEDSTATE,LOW);
            delay(750);
            digitalWrite(LEDSTATE,HIGH);
            delay(750);
            digitalWrite(LEDSTATE,LOW);
            delay(300);
            count+=1;
            myFile = SD.open("BOB"+count+".TXT",FILE_WRITE);

        }
        myFile.write(buf);
    }
}