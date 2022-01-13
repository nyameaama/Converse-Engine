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

#include"drivers/ThermoTemp.h"

//Function prototypes
void _init_();
void SBC_interrupt_handler();
void _SBC();
char* parse_to_packet(double value_most_recent,char* timestamp_recieved,char* timestamp_sent);

//temp in celsius
double therm_data_celsius;

//Telemetry Log
char* time_recieved;
char* time_sent;

int main(){
    _init_();
    while (1){
        //Main Operating Loop
        _SBC();
    }
    return 0;
}

void _init_(){
    //Set up interrupt handler

}

void SBC_interrupt_handler(){
    //Get timestamp recieved
    char* timestamp_recieved;
    
    //Get most recent thermocouple temp
    double temp_most_recent = therm_data_celsius;

    //Get timestamp sent
    char* timestamp_sent;

    //Update telemetry log

    //Parse into packet

    //Send packet back immediately

}

void _SBC(){
    //Get thermocouple data
    double tc_volt_data = getVoltage(thermocoupleAnalog());
    //Overwrite old data
    //Update new value into buffer
    therm_data_celsius = getCelsius(tc_volt_data);
    //Move data into user flash

}

char* parse_to_packet(double value_most_recent,char* timestamp_recieved,char* timestamp_sent){

}