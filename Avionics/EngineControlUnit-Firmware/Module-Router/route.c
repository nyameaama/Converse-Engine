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

//Function to return pressure 
uint32_t returnPressure(){

}

//Function to return pressure 
uint32_t returnTemp(){

}

//Fuel Pump task function (ON, OFF)
uint8_t FuelPump_task(uint8_t task){
    //Pump init
}

//Liquid Oxygen Pump task function (ON, OFF)
uint8_t LOXPump_task(uint8_t task){
    //Pump Init
}

//Main Fuel Valve task function (OPEN, CLOSED)
uint8_t MFV_task(uint8_t task){
    //Valve GPIO Pin
    uint8_t FuelValvePin; // <- Valve Pin
    //valve init
    if(task == OPEN){
        valveState(FuelValvePin, OPEN);
    }else if(task == CLOSE){
        valveState(FuelValvePin,CLOSE);
    }
    return 0;
}

//Main Oxygen Valve function (OPEN, CLOSED)
uint8_t MOV_task(uint8_t task){
    //Valve GPIO Pin
    uint8_t OxygenValvePin; // <- Valve Pin
    //valve init
    if(task == OPEN){
        valveState(OxygenValvePin, OPEN);
    }else if(task == CLOSE){
        valveState(OxygenValvePin,CLOSE);
    }
    return 0;
}

//Chamber Igniter function (ON, OFF)
uint8_t igniter_task(uint8_t task){
    
}