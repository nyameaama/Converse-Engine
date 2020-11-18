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

#include"tasks.h"


/* PROG_CYCLE represents the full feedback cycle of engine control. PROG_CYCLE
 runs the module router tasks and AETS. AETS is first checked to determine
 engine state. If engine is nominal, operations run, if false, PROG_CYCLE returns
 fasle to main which terminates engine */

uint8_t RUN_PROG_CYCLE(){
   // -COMPILE SENSOR DATA 
    uint32_t *sensorData = COMPILE_SENSOR_DATA();
    //-DIRECT FEED COMPILED DATA TO TELEMETRY/ANALYSIS MODULE
    TELEMETRY_FEED(COMPILE_SENSOR_DATA);
   // -MOVE DATA TO CONTROL - AETS MODULE

   // -NOMINAL? -> RETURN TRUE TO MAIN | ELSE -> RETURN FALSE

}

//Function to compile sensor data from (driver functions)
uint32_t *compile_sensor_data(){
    const uint8_t transducerPin;
    const uint8_t thermocouplePin;
    uint32_t compiled[5]; // <- CHANGE TO SENSOR SUITE NUMBER
    //Pressure
    compiled[0] = (pressureTransducer)(transducerPin);
    //Thermocouple
    compiled[1] = (readThermocouple)(thermocouplePin);
    return compiled;
}

//Engine Startup Task 
uint8_t (engineStartup)(uint32_t duration_secs){
    //
}

//Engine Shutdown Task
uint8_t (engineShutdown)(void){

}