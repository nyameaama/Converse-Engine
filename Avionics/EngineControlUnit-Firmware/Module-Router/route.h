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

#ifndef MODULE_ROUTER
#define MODULE_ROUTER

#include"../Components-Module/ecu_components.h"
#include"../Communication-Module/_telemetry.h"
#include"../Utility/ecu_gpio.h"
#include"../Utility/definitions.h"

#define OPEN 1
#define CLOSE 0

/*Function to return AETS to module router
This data is moved to main */
uint8_t return_AETS_state();

uint8_t telemetry_send();

/*Module Router Independent functions*/

/////////////////////////////////

//Function to return pressure 
uint32_t returnPressure(char* controllerID);

//Function to return pressure 
uint32_t returnTemp(char* controllerID);

//Chamber Igniter function (ON, OFF)
uint8_t igniter_task(char* controllerID, uint8_t task);


/////////////////////////////////

//Purge Valve task function (OPEN, CLOSED)
uint8_t PV_task(uint8_t task);

//Main Fuel Valve task function (OPEN, CLOSED)
uint8_t MFV_task(uint8_t task);

//Main Oxygen Valve function (OPEN, CLOSED)
uint8_t MOV_task(uint8_t task);

//Oxygen Purge Vent function (OPEN, CLOSED)
uint8_t OPV_task(uint8_t task);

//Fuel Purge Vent function (OPEN, CLOSED)
uint8_t FPV_task(uint8_t task);

///////////////EF////////////////


//Fuel Pump task function (ON, OFF)
uint8_t FuelPump_task(uint8_t task);

//Liquid Oxygen Pump task function (ON, OFF)
uint8_t LOXPump_task(uint8_t task);


#endif //MODULE_ROUTER