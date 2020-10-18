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

#include"ecu_components.h"

//Component driver for pressure transducer
uint8_t (pressureTransducer)(uint8_t transducerPin){

}

//Component driver for solenoid valve (Open, close)
uint8_t (valveState)(uint8_t valvePin, uint8_t state){
    //PinMode
    //Digitial Write To PIN
    //HIGH or LOW
    switch(state){
        case OUT:
            SET_ECU_GPIO_HIGH(valvePin,CLOCK_A); //<- Assume CLOCK PORT A - CHANGE
        case IN:
            SET_ECU_GPIO_LOW(valvePin,CLOCK_A); //<- Assume CLOCK PORT A - CHANGE
    }
    return 0;
}

//Component driver for thermocouple
uint8_t (readThermocouple)(uint8_t thermocouplePin){

}