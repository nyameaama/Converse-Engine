/*MIT License

Copyright (c) 2020 Nyameaama Gambrah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#ifndef FUNCTIONS
#define FUNCTIONS

#include <RadioHead-master/RH_ASK.h>
//#include <SPI.h> // Not actually used but needed to compile

#define LED_PIN 0

uint8_t outputted = false;

RH_ASK driver;

typedef unsigned char uint8_t;

//Function to transmit data 
void transmit(const char* msg){
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
}

//Function to parse received data
void receive(){
    //Buffer to hold received data
    uint8_t buf[12];
    //Length
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Data: ");
      Serial.println((char*)buf); 
    }    
}

//Function to change LED state
void LED_STATE(uint8_t state){
    switch(state){
        case 0:
        digitalWrite(LED_PIN,LOW);

        case 1:
        digitalWrite(LED_PIN,HIGH);
    }
}

//Function to read from the serial monitor 
char *prompt(){
    char comm_byte;
    char comm_str[32];
    //Call prompt
    //Read characters from Serial Monitor
    uint8_t comm_index;
    while(comm_byte != '\n'){
        if (Serial.available() > 0) {  
            comm_byte = Serial.read();// get the character
        }
        if (comm_byte != '\n') {
        // a character of the string was received
        comm_str[comm_index] = comm_byte;
        comm_index++;
        }
        else{
      
        }
    }                   
    return comm_str;
}

void outputOnce(char* data){
    if(outputted == 0){
        Serial.println(data);
        outputted = 1;
    }else if(outputted != 0){
        //Do nothing
    }
}

#endif //FUNCTIONS