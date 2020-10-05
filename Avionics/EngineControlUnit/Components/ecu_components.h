#ifndef ECU_COMPONENTS_
#define ECU_COMPONENTS_

#include"../ecu_gpio.h"

#define OPEN (uint8_t) 1
#define CLOSE (uint8_t) 1

//typedef unsigned char uint8_t;

//Component driver for pressure transducer
uint8_t (pressureTransducer)(uint8_t transducerPin);

//Component driver for solenoid valve (Open, close)
uint8_t (valveState)(uint8_t valvePin, uint8_t state);

//Component driver for thermocouple
uint8_t (readThermocouple)(uint8_t thermocouplePin);




#endif //ECU_COMPONENTS_