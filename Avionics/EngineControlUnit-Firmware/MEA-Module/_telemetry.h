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

#ifndef TELEMETRY_
#define TELEMETRY_

#include"../libs/EngineMath/EngineMath.h"
#include"../Utility/definitions.h"

void TELEMETRY_FEED(uint32_t*(*compiledData)(void));

void LOG_THRUST();

void LOG_FUEL_MASS_FLOW(double inletPressure, double pressure2, uint32_t timestamp);

void LOG_OXIDIZER_MASS_FLOW(double inletPressure, double pressure2, uint32_t timestamp);

void LOG_GAS_MASS_FLOW(double inletPressure, double pressure2,double outlettemp, uint32_t timestamp);

void LOG_TEMP_1(double reading, uint32_t timestamp);

void LOG_TEMP_2(double reading, uint32_t timestamp);

void LOG_PRESSURE_1(double reading, uint32_t timestamp);

void LOG_PRESSURE_2(double reading, uint32_t timestamp);

char* LOG_COMMANDS();



#endif //TELEMETRY_