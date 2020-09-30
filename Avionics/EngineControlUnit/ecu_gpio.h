#ifndef ECU_GPIO_
#define ECU_GPIO_

#include "libs/stm32/spl/variants/stm32f4/src/stm32f4xx_gpio.c"

//0x1
#define CLOCK_A (uint32_t)
//0x2
#define CLOCK_B ((uint32_t)0x00000002)
//0x4
#define CLOCK_C ((uint32_t)0x00000004)
//0x8
#define CLOCK_D ((uint32_t)0x00000008)


void SET_ECU_GPIO_HIGH(uint8_t PIN,CLOCK_A _clock_);

void SET_ECU_GPIO_LOW(uint8_t PIN);



#endif //ECU_GPIO