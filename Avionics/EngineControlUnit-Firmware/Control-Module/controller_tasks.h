#ifndef CONTROLLER_TASKS
#define CONTROLLER_TASKS

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

#include"../Utility/definitions.h"
#include"../Communication-Module/External_RF/g_comms.h"
#include"engine_tasks.h"
#include"../Module-Router/route.h"
#include"../Communication-Module/SubController_SPI/requests.h"

//Start comms and attach RF interrupt 
void _init_();

void _IDLE_();

//Telemetry checks, peripheral checks
//Engine preconditioning
//Purge, Chill
void _PREP_();

void _ARMED_();

//For manual testing, implement bypass to respond to sensor and valve
//comms without additional processes.
//+1 Overload
void _bypass_(char* sbc_id);
void _bypass_(char* sbc_id,uint8_t peripheral_type=1);

//Controller loop statemachine change functions

//Change state to idle
uint8_t SWITCH2IDLE();

//Change state to prep
uint8_t SWITCH2PREP();

//Change state to armed
uint8_t SWITCH2ARMED();

//Change state to bypass
uint8_t SWITCH2BYPASS();

//Change engine state definition 
//Used for interrupt handlers to change engine state
void CHANGE_STATE_DEFINITON();

//Utility

//Reset all tag so engine can be preconditioned for another fire
void reset_();

//If output = 1, strings match
uint8_t compare(char* a, char* b);

#endif