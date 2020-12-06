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

//#include <RH_ASK.h>
//#include <SPI.h> // Not actually used but needed to compile

#define LED_PIN LED_BUILTIN
#define SILENT 0 

String inputString = "";         // a String to hold incoming data
bool serialevent = false;

uint8_t outputted = false;

/*RH_ASK driver;

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
*/
uint8_t search(String x, String *arr){
  for(uint8_t i = 0; i < 3;++i){
    if (x.equals(arr[i])){return i;}
  }
}

//Function to change LED state
void LED_STATE(uint8_t state){
    pinMode(LED_PIN,OUTPUT);
    switch(state){
        case 0:
        digitalWrite(LED_PIN,LOW);
        break;
        
        case 1:
        digitalWrite(LED_PIN,HIGH);
        break;
    }
}

//Function to read from the serial monitor 
//+1 Overload
String prompt(String text){
   Serial.println(text);  
    String command = Serial.readString(); //Reading the Input string from Serial port.
    return command;
}
String prompt(uint8_t x){
  inputString = Serial.readString(); //Reading the Input string from Serial port.
}

void serialEvent(){
  serialevent = true;
  prompt(SILENT);
}

void outputOnce(char* data){
    if(outputted == 0){
        Serial.println(data);
        outputted = 1;
    }else if(outputted != 0){
        //Do nothing
    }
}

void AppendToStorage(uint8_t telemetry){
    
}

#endif //FUNCTIONS