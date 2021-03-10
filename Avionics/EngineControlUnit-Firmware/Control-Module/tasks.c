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

//Engine Startup Task - !! Separate timer from opening sequence !!
void (engineStartup)(void){
    log("EVENT-ENGINE-STARTUP",time(),"-");
    //Open Gas flow route <- Tank computer
    //Open Main Fuel Valve
    valveState(FUEL_VALVE_BASE_ID,OPEN);
    //Open Main Oxidizer Valve
    valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    //Timing for igniter start dependent on mass flow and pipe distance
    //See igniter docs
    //Activate Igniter
    chamberIgniter(CHAMBER_IGNITER_BASE_ID,OPEN);
}

//Engine Shutdown Task
void (engineShutdown)(void){
    //Log Event
    log("EVENT-ENGINE-SHUTDOWN",time(),"-");
    //Shutdown Procedure
    //Close fuel valve
    valveState(FUEL_VALVE_BASE_ID,CLOSE);
    //Close oxidizer valve
    valveState(OXYGEN_VALVE_BASE_ID,CLOSE);
}

//Engine Pre-Purging
//Purging of the main feed lines (Igniter Tap Off Line purged)
void enginePurge(void){
    log("EVENT-ENGINE-PURGE",time(),"-");
    //Request gas tank valve open
    //Open purge inlet valve
    valveState(PURGE_VALVE_BASE_ID,OPEN);
    //Delay
    //Open all feed valves
    valveState(FUEL_VALVE_BASE_ID,OPEN);
    valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    valveState(TAP_OFF_A_VALVE_BASE_ID,OPEN);
    //Delay
    //Purge tap-off line seq
    //Close tap-off A and open tap-Off B valve
     valveState(TAP_OFF_A_VALVE_BASE_ID,CLOSE);
     valveState(TAP_OFF_B_VALVE_BASE_ID,OPEN);
     //Delay
    //Open the tap-off line valve
     valveState(TAP_OFF_LINE_VALVE_BASE_ID,OPEN);
     //Delay
}

//Engine Chill
void engineChill(void){
    log("EVENT-ENGINE-CHILL",time(),"-");
    //LOX
    //Melting Point = -114
    //Boiling Point
    //Open Oxidizer Valves for --- time
    double kp,kd,ki;
    createPIDinstance("LOX-CHILL",kp,ki,kd);
    //PID_MAIN("LOX-CHILL,")
}


//Safe Engine - Post-Purge residual fuel
void safeEngine(void){
    log("EVENT-ENGINE-SAFE",time(),"-");
    //Vent gas tank and propellant tanks
    //Open purge inlet valve
   valveState(PURGE_VALVE_BASE_ID,OPEN);
    //Delay
    //Open all feed valves
    valveState(FUEL_VALVE_BASE_ID,OPEN);
    valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    valveState(TAP_OFF_A_VALVE_BASE_ID,OPEN);
    //Delay
    //Purge tap-off line seq
    //Close tap-off A and open tap-Off B valve
     valveState(TAP_OFF_A_VALVE_BASE_ID,CLOSE);
     valveState(TAP_OFF_B_VALVE_BASE_ID,OPEN);
     //Delay
    //Open the tap-off line valve
     valveState(TAP_OFF_LINE_VALVE_BASE_ID,OPEN);
     //Delay
}