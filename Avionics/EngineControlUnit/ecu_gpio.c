#include "ecu_gpio.h"

void SET_ECU_GPIO_HIGH(uint8_t PIN,){
    //Decide Port
   
    //Clock for Port
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
    
}

void SET_ECU_GPIO_LOW(uint8_t PIN){

}