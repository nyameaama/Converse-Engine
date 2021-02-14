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

//Raw Data sent to memory and measured data sent to ground

#ifndef TELEMETRY_
#define TELEMETRY_

#include"../libs/EngineMath/EngineMath.h"
#include"../Utility/definitions.h"

//+2 Overload 
//Raw telemetry data logged and sent to memory
void log(char* label,char* timestamp,char* data);

void log(char* label,char* timestamp,int data);

void log(char* label,char* timestamp,double data);

void TELEMETRY_FEED(uint32_t*(*compiledData)(void));

//Thrust calculation function
void log_thrust();

//Function to measure Engine Chamber Pressure and send to ground
void log_chamber_pressure();

//Function to log inlet oxygen pressure and send to ground
void log_inlet_lox_pressure();

//Function to measure ethanol mass flow and send to ground
//using inlet and pre chamber transducer data
void log_fuel_mass_flow(double inletPressure, double pressure2, uint32_t timestamp);

//Function to measure oxygen mass flow and send to ground
//using inlet and pre chamber transducer data
void log_oxidizer_mass_flow(double inletPressure, double pressure2, uint32_t timestamp);

void log_gas_mass_flow(double inletPressure, double pressure2,double outlettemp, uint32_t timestamp);




#endif //TELEMETRY_