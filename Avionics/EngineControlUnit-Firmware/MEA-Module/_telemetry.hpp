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
#include"../Utility/definitions.hpp"
#include"../Communication-Module/External_RF/g_comms.h"
#include"../PTAM/temp_access_mem.hpp"

class TELEMETRY {
    public:
        //+2 Overload 
        //Raw telemetry data logged
        //Log to memory only (data_destination = 1)
        //Log to memory and ground (data_destination = 2)
        void log(char* label,char* timestamp,char* data,uint8_t data_destination);

        void log(char* label,char* timestamp,int data,uint8_t data_destination);

        void log(char* label,char* timestamp,double data,uint8_t data_destination);

        void TELEMETRY_FEED(uint32_t*(*compiledData)(void));

        //Thrust calculation function
        void LOG_THRUST();

        //Function to measure Engine Chamber Pressure and send to ground
        void LOG_CHAMBER_PRESSURE();

        //Function to measure ethanol mass flow and send to ground
        //using inlet and pre chamber transducer data
        void LOG_FUEL_MASS_FLOW(char* timestamp);

        //Function to measure oxygen mass flow and send to ground
        //using inlet and pre chamber transducer data
        void LOG_OXIDIZER_MASS_FLOW(char* timestamp);

        void LOG_GAS_MASS_FLOW(double inletPressure, double pressure2,double outlettemp, char* timestamp);

};


#endif //TELEMETRY_