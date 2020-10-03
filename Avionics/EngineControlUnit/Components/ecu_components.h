#ifndef ECU_COMPONENTS_
#define ECU_COMPONENTS_

#include"../ecu_gpio.h"

//typedef unsigned char uint8_t;

typedef struct {
    //Component driver for pressure transducer
    uint8_t (*pressureTransducer)(void);

}Components;



#endif //ECU_COMPONENTS_