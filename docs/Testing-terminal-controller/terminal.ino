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

#include"functions.h"

/*
Simple state machine for terminal controller consisting of three states
- idle
- setup
- active

* Active takes commands
*/

//Global for controller Mode
char* input;
#include"functions.h"

String taskstable[3] = {"cmd idle","cmd setup","cmd active"};
//N = Undefined | C = Command | T = telemetry
String Mode;

#define STATE 0

void setup(){
    Serial.begin(9600);	  // Serial Communication
    //if (!driver.init())
      //  Serial.println("init failed");
      
  //reserve 200 bytes for the inputString:
  inputString.reserve(1000);
}

void loop(){
    if(serialevent){
      //Search input string against tasks table and switch state
      uint8_t index = search(inputString,taskstable);
      Serial.println(index);
      #undef STATE
      #define STATE index
      serialevent = false; 
    }

    #if STATE == 0
    //INIT - IDLE
    Serial.println("IDLE");

    //IDLE MODE = Slow Blinking
    LED_STATE(1);
    delay(250);
    LED_STATE(0);

    #endif

    #if STATE == 1
    //SETUP = Rapid Blinking
    LED_STATE(1);
    delay(50);
    LED_STATE(0);
    //Determine "Command" Mode or "Telemetry" Mode
    //prompt
    if(Mode.equals("N"){
      // Set mode
      Mode = prompt("Set Mode");
    }else{
      // Use assigned mode / Change mode
      
    }

    #endif

     #if STATE == 2
    //ACTIVE = Constant LED On
    LED_STATE(1);
    //
     if(Mode == "C"){
        //Route telemetry to storage

      }else if(Mode = "T" ){
        //Route telemetry to Serial

        //Send Commands if prompted
      }
     #endif
    //Serial.print(prompt());
    
}