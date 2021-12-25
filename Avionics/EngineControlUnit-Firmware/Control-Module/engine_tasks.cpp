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

#include"engine_tasks.hpp"

//Engine Startup Task - !! Separate timer from opening sequence !!
void ENGINE_TASKS::engineStartup(void){
    //Module Router class object
    MODULE_ROUTER *MR_obj = new MODULE_ROUTER();
    //logCHAR("EVENT-ENGINE-STARTUP",millis(),"-",0);
    //Open Gas flow route <- Tank computer
    //Open Main Fuel Valve
    MR_obj -> valveState(FUEL_VALVE_BASE_ID,OPEN);
    //Open Main Oxidizer Valve
    MR_obj -> valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    //Timing for igniter start dependent on mass flow and pipe distance
    //See igniter docs
    //Activate Igniter
    MR_obj -> chamberIgniter(CHAMBER_IGNITER_BASE_ID,OPEN);
    //free
    delete MR_obj;
}

//Engine Shutdown Task
void ENGINE_TASKS::engineShutdown(void){
    //Module Router class object
    MODULE_ROUTER *MR_obj = new MODULE_ROUTER();
    //Log Event
    //logCHAR("EVENT-ENGINE-SHUTDOWN",millis(),"-",0);
    //Shutdown Procedure
    //Close fuel valve
    MR_obj -> valveState(FUEL_VALVE_BASE_ID,CLOSE);
    //Close oxidizer valve
    MR_obj -> valveState(OXYGEN_VALVE_BASE_ID,CLOSE);
    //free
    delete MR_obj;
}

//Engine Pre-Purging
//Purging of the main feed lines (Igniter Tap Off Line purged)
void ENGINE_TASKS::enginePurge(void){
    //Module Router class object
    MODULE_ROUTER *MR_obj = new MODULE_ROUTER();
    //logCHAR("EVENT-ENGINE-PURGE",millis(),"-",0);
    //Request gas tank valve open
    
    //Open purge inlet valve
    MR_obj -> valveState(PURGE_VALVE_BASE_ID,OPEN);
    //Delay
    //Open all feed valves
    MR_obj -> valveState(FUEL_VALVE_BASE_ID,OPEN);
    MR_obj -> valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    MR_obj -> valveState(TAP_OFF_A_VALVE_BASE_ID,OPEN);
    //Delay
    //Purge tap-off line seq
    //Close tap-off A and open tap-Off B valve
    MR_obj -> valveState(TAP_OFF_A_VALVE_BASE_ID,CLOSE);
    MR_obj -> valveState(TAP_OFF_B_VALVE_BASE_ID,OPEN);
     //Delay
    //Open the tap-off line valve
    MR_obj -> valveState(TAP_OFF_LINE_VALVE_BASE_ID,OPEN);
     //Delay

     //free
    delete MR_obj;
}

//Engine Chill
void ENGINE_TASKS::engineChill(void){
    //logCHAR("EVENT-ENGINE-CHILL",millis(),"-",0);
    //LOX
    //Melting Point = -114
    //Boiling Point
    //Open Oxidizer Valves for --- time
    double kp,kd,ki;
    //createPIDinstance("LOX-CHILL",kp,ki,kd);
    //PID_MAIN("LOX-CHILL,")
}


//Safe Engine - Post-Purge residual fuel
void ENGINE_TASKS::safeEngine(void){
    //Module Router class object
    MODULE_ROUTER *MR_obj = new MODULE_ROUTER();
    //logCHAR("EVENT-ENGINE-SAFE",millis(),"-",0);
    //Vent gas tank and propellant tanks
    //Open purge inlet valve
    MR_obj -> valveState(PURGE_VALVE_BASE_ID,OPEN);
    //Delay
    //Open all feed valves
    MR_obj -> valveState(FUEL_VALVE_BASE_ID,OPEN);
    MR_obj -> valveState(OXYGEN_VALVE_BASE_ID,OPEN);
    MR_obj -> valveState(TAP_OFF_A_VALVE_BASE_ID,OPEN);
    //Delay
    //Purge tap-off line seq
    //Close tap-off A and open tap-Off B valve
    MR_obj -> valveState(TAP_OFF_A_VALVE_BASE_ID,CLOSE);
    MR_obj -> valveState(TAP_OFF_B_VALVE_BASE_ID,OPEN);
     //Delay
    //Open the tap-off line valve
    MR_obj -> valveState(TAP_OFF_LINE_VALVE_BASE_ID,OPEN);
     //Delay

     //free
    delete MR_obj;
}