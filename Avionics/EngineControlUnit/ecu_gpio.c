#include "ecu_gpio.h"


 //Pin number in port
 //GPIO_InitTypeDef is a structure defined in gpio header file
GPIO_InitTypeDef GPIO_STRUCT;


void (SET_ECU_GPIO_HIGH)(uint8_t PIN,uint32_t _clock_){
    //Decide Port

    //Provide clock to the specific port being used.
    //Parameter refernece
    RCC_AHB1PeriphClockCmd(_clock_,ENABLE);
    //SETUP_GPIO();
    //Specifies the GPIO pins to be configured.
    GPIO_STRUCT.GPIO_Pin = PIN;
    //Configure it as output pin.
    GPIO_STRUCT.GPIO_Mode = GPIO_Mode_OUT;
    //GPIO speed and Push Pull configuration. Configuring speed of GPIO 
    //and Push pull register of the pin
    GPIO_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_STRUCT.GPIO_PuPd = GPIO_OType_PP;
    //SET HIGH
     GPIO_WriteBit(GPIOD,PIN,Bit_SET);
   
}

void (SET_ECU_GPIO_LOW)(uint8_t PIN){

}