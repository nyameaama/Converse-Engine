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

#ifndef VALVE_DRIVERS
#define VALVE_DRIVERS

#define OPEN (uint8_t) 1
#define CLOSE (uint8_t) 1

typedef unsigned char uint8_t;

#include "../libs/stm32/cmsis/variants/stm32f4/stm32f4xx.h"

//0x1
#define CLOCK_A (RCC_AHB1Periph_GPIOA)
//0x2
#define CLOCK_B (RCC_AHB1Periph_GPIOB)
//0x4
#define CLOCK_C (RCC_AHB1Periph_GPIOC)
//0x8
#define CLOCK_D (RCC_AHB1Periph_GPIOD)

#define IN (GPIO_Mode_IN)

#define OUT (GPIO_Mode_OUT)


//Component driver for solenoid valve (Open, close)

uint8_t (valveState)(uint8_t valvePin, uint8_t state);


////////////////////GPIO Drivers////////////////////////

//Set GPIO Pin register to HIGH
void (SET_ECU_GPIO_HIGH)(uint8_t PIN,uint32_t _clock_);

//Set GPIO Pin register to LOW
void (SET_ECU_GPIO_LOW)(uint8_t PIN,uint32_t _clock_);

//
void (GPIO_READ_DIGITAL)(uint8_t PIN,uint32_t _clock_);

//
void (GPIO_READ_ANALOG)(uint8_t PIN,uint32_t _clock_);

//
void (GPIO_WRITE)(uint8_t PIN,uint32_t _clock_);

//Set GPIO-Mode (IN,OUT,Analog,Alternate function)
void (SET_GPIO_MODE)(uint8_t PIN,uint8_t mode,uint32_t _clock_);


#endif