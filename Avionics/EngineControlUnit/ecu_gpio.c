#include "ecu_gpio.h"

struct SETUP s_obj;
s_obj.SET_ECU_GPIO_HIGH = SET_ECU_GPIO_HIGH;

 //Pin number in port
 //GPIO_InitTypeDef is a structure defined in gpio header file
GPIO_InitTypeDef GPIO_STRUCT;

void SET_ECU_GPIO_HIGH(uint8_t PIN,uint32_t _clock_){
    //Decide Port
   
    //Provide clock to the specific port being used.
    //Parameter refernece
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
    //SETUP_GPIO();
   
}

void SET_ECU_GPIO_LOW(uint8_t PIN){

}