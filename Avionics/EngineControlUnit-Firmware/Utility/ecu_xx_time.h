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


#ifndef StopWatch_h
#define StopWatch_h

#include"../libs/stm32/cmsis/variants/stm32f4/system_stm32f4xx.h"

#define true 1
#define false 0

#define SECS_MICROS 0
#define SECS_MILLIS 1


typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

unsigned long _startTime;
unsigned long _stopTime;

//increments a 32 bit counter at every tick.
void SysTick_Handler();


//Returns 
uint32_t millis();

//Sets a timer to run for 'x' milliseconds
void startTimer(unsigned long millisToTime);

//Returns true if the timer is still active. False otherwise
uint8_t timerStatus();

//Returns the elapsed time since the timer was started. 
unsigned long timeElapsed();

//A sleep without delay function
void millisToSleep(unsigned long sleepTime);
		
//Overload + 1
//Utility friendly program time function
uint32_t time(uint8_t unit);

uint32_t time();

#endif