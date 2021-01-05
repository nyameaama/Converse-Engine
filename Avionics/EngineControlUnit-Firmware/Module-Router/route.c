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

#include"route.h"

/*Function to return AETS to module router
This data is moved to main */
uint8_t return_AETS_state(){

}

//Component driver for pressure transducer
//Return peripheral
uint8_t (pressureTransducer)(char* controllerID){
    //Init request to transducer controller
    controllerRequest(controllerID,READ);
    //return value

}

//Component driver for solenoid valve (Open, close)
//Non-return peripheral
void (valveState)(char* controllerID, uint8_t state){
    //Init request to valve controller
    controllerRequest(controllerID,state);
}

//Component driver for thermocouple
//Return peripheral
uint8_t (readThermocouple)(char* controllerID){
    //Init request to thermocouple controller
    controllerRequest(controllerID,READ);
    //return value

}

//Component driver for chamber igniter
uint8_t (chamberIgniter)(char* controllerID, uint8_t state){
    //Init request to igniter controller
    controllerRequest(controllerID,state);
}

