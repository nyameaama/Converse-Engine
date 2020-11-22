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

#include "ecu_xx_time.h"

//increments a 32 bit counter at every tick.
void SysTick_Handler(){

}

uint32_t millis(){
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    uint32_t desired_freq_for_timer = 1000; // <- For (ms)
    (void)SysTick_Config(RCC_Clocks.HCLK_Frequency / desired_freq_for_timer);
    
}

//sets a timer to run for 'x' milliseconds
void startTimer (unsigned long millisToTime){
  _startTime = millis();
  _stopTime = _startTime + millisToTime;
}

//Returns true if the timer is still active. False otherwise
uint8_t timerStatus (){
  if ( (millis() >= _startTime) && (millis() <= _stopTime) )
    return true;
  else
    return false;
}

//Returns the elapsed time since the timer was started. 
unsigned long timeElapsed ()
{
  return millis() - _startTime;
}

//A sleep without delay function
void millisToSleep (unsigned long sleepTime)
{
  unsigned long wakeupTime = millis() + sleepTime;
  
  while(1)
  {
    if (millis() >= wakeupTime)
      break;
  }
}