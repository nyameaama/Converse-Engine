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
#include"../MEA-Module/_telemetry.h"
#include"../Utility/ecu_gpio.h"
#include"../Utility/definitions.h"
#include"../Communication-Module/SubController_SPI/requests.h"

#define OPEN (uint8_t) 1
#define CLOSE (uint8_t) 0

#define READ (uint8_t) 2


/*Function to return AETS to module router
This data is moved to main */
uint8_t return_AETS_state();

uint8_t telemetry_send();

char* call(char* methodID);

/////////////////////////////////

//Component driver for pressure transducer
double (pressureTransducer)(char* controllerID);

//Component driver for solenoid valve (Open, close)
void (valveState)(char* controllerID, uint8_t state);

//Component driver for thermocouple
double (readThermocouple)(char* controllerID);

//Component driver for chamber igniter
uint8_t (chamberIgniter)(char* controllerID, uint8_t state);

///////////////EF////////////////

//Fuel Pump task function (ON, OFF)
uint8_t FuelPump_task(uint8_t task);

//Liquid Oxygen Pump task function (ON, OFF)
uint8_t LOXPump_task(uint8_t task);


#endif //MODULE_ROUTER