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

#include "ecu_xx_gpio.h"

 //Pin number in port
 //GPIO_InitTypeDef is a structure defined in gpio header file
GPIO_InitTypeDef GPIO_STRUCT;

//Set GPIO Pin register to HIGH
void (SET_ECU_GPIO_HIGH)(uint8_t PIN,uint32_t _clock_){
    SET_GPIO_MODE(PIN,OUT,_clock_);
    //SET HIGH
    GPIO_WriteBit(_clock_,PIN,Bit_SET);
}

//Set GPIO Pin register to LOW
void (SET_ECU_GPIO_LOW)(uint8_t PIN,uint32_t _clock_){
    SET_GPIO_MODE(PIN,OUT,_clock_);
    //SET LOW
    GPIO_WriteBit(_clock_,PIN,Bit_RESET);
}

void (GPIO_READ_DIGITAL)(uint8_t PIN,uint32_t _clock_){
    SET_GPIO_MODE(PIN,IN,_clock_);
    //GPIO_ReadInputData()

}

void (GPIO_READ_ANALOG)(uint8_t PIN,uint32_t _clock_){

}

void (GPIO_WRITE)(uint8_t PIN,uint32_t _clock_){

}

//Set GPIO-Mode (IN,OUT,Analog,Alternate function)
void (SET_GPIO_MODE)(uint8_t PIN,uint8_t mode,uint32_t _clock_){
    //Decide Port
    //Provide clock to the specific port being used.
    //Parameter refernece
    RCC_AHB1PeriphClockCmd(_clock_,ENABLE);
    //SETUP_GPIO();
    //Specifies the GPIO pins to be configured.
    GPIO_STRUCT.GPIO_Pin = PIN;
    //Configure it as output pin.
    GPIO_STRUCT.GPIO_Mode = mode;
    //GPIO speed and Push Pull configuration - configure speed of  GPIO and Push pull register of the pin
    GPIO_STRUCT.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_STRUCT.GPIO_PuPd=GPIO_OType_PP;
    //GPIO Initialization
    GPIO_Init(GPIOD,&GPIO_STRUCT);
}