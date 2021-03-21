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

#include"controller_tasks.h"

//Variable noting whether engine has already been prepped
uint8_t prep;
//Variable noting whether engine has been started
uint8_t engineStarted;

//Engine Burn time
double engine_burn_duration_secs;

//Start comms and attach RF interrupt 
void _init_(){
    
    
}

void _IDLE_(){
    //Controller does nothing
}

//Telemetry checks, peripheral checks
//Engine preconditioning
//Purge, Chill
void _PREP_(){
    if(prep != 1){
        //PURGE
        enginePurge();
        //Delay 1 second for possible ground interrupt

        //ENGINE CHILL
        engineChill();
        //CHECKS



        prep = 1;
    }else{
        //Do nothing.
        //Engine already prepped
    }
}

void _ARMED_(){
    //Engine function wrapped in timer
    if(engineStarted == 1){
        //Get seconds since controller start as current time
        double current_time;
        //Log seconds since controller start 
        double start_time;
        if((current_time - start_time) >=  engine_burn_duration_secs){
            engineShutdown();
            //Reset engine started tag
            engineStarted = 0;
        }
    }else{
        //Start engine
        engineStartup();
        //Set engine started tag
        engineStarted = 1;
    }
}

//For manual testing, implement bypass to respond to sensor and valve
//comms without additional processes.
//+1 Overload

//Valve bypass
void _bypass_(char* sbc_id){
    //Open valve
    controllerRequest(sbc_id,1);
    //Close valve
    controllerRequest(sbc_id,0);
}
 //Sensor bypass
void _bypass_(char* sbc_id,uint8_t peripheral_type=1){
    //Request sensor data
    double data = controllerRequest(sbc_id,2);
    transmit_telemetry(data);
}

//CHange state to idle
uint8_t SWITCH2IDLE(){
    //Change variable
    uint8_t change = 0;
    if(compare(recieve_telemetry(),"IDLE")){
        change = 1;
    }
    return change;
}

//CHange state to prep
uint8_t SWITCH2PREP(){
    //Change variable
    uint8_t change = 0;
    if(compare(recieve_telemetry(),"PREP")){
        change = 1;
    }
    return change;
}

//CHange state to armed
uint8_t SWITCH2ARMED(){
    //Change variable
    uint8_t change = 0;
    if(compare(recieve_telemetry(),"ARMED")){
        change = 1;
    }
    return change;
}

//CHange state to bypass
uint8_t SWITCH2BYPASS(){
    //Change variable
    uint8_t change = 0;
    if(compare(recieve_telemetry(),"BYPASS")){
        change = 1;
    }
    return change;
}


//Reset all tags so engine can be preconditioned for another fire
void reset_(){
    //Reset prep tag
    prep = 0;

    //Reset engine started tag
    engineStarted = 0;
}