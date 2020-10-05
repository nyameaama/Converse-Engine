#ifndef ECU_GPIO_
#define ECU_GPIO_

#include "libs/stm32/spl/variants/stm32f4/src/stm32f4xx_gpio.c"
#include "libs/stm32/cmsis/variants/stm32f4/stm32f4xx.h"

//0x1
#define CLOCK_A (RCC_AHB1Periph_GPIOA)
//0x2
#define CLOCK_B (RCC_AHB1Periph_GPIOB)
//0x4
#define CLOCK_C (RCC_AHB1Periph_GPIOC)
//0x8
#define CLOCK_D (RCC_AHB1Periph_GPIOD)

//Setup Function

void (SETUP_GPIO)(uint8_t PIN,uint32_t _clock_);



void (SET_ECU_GPIO_HIGH)(uint8_t PIN,uint32_t _clock_);

void (SET_ECU_GPIO_LOW)(uint8_t PIN);



#endif //ECU_GPIO