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

#ifndef MAIN_
#define MAIN_


#include"interrupts.h"

void _init_();
void _IDLE_();
void _PREP_();
void _ARMED_();

//Interrupts will change engine state flags
//RF interrupt -> handler -> parse RF data -> change flag according go data instruction

#define ENGINE_STATE 0

int main(){
    _init_();
    while(1){
        #if ENGINE_STATE == 0 // IDLE
        _IDLE_();
        if(/*  rf_connect()  */1){
            #undef ENGINE_STATE
            #define ENGINE_STATE 1
        }
        #endif

        #if ENGINE_STATE == 1 // PREP
        _init_();
        _PREP_();
        if(/*  interrup */1){
            #undef ENGINE_STATE
            #define ENGINE_STATE 2
        }
        #endif

        #if ENGINE_STATE == 2 // ARMED
        _ARMED_();
        if(/*  rf_connect()  */1){
            #undef ENGINE_STATE
            #define ENGINE_STATE 0
        }
        #endif

    }
}

void _init_(){
    //Attach RF interrupt 
}

void _IDLE_(){
    //IDLE -> NO PROCESS | init terminal connection

}

void _PREP_(){

}

void _ARMED_(){

}


#endif // MAIN_