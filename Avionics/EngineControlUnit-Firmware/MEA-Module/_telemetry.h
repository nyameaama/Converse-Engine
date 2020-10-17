#ifndef TELEMETRY_
#define TELEMETRY_

#include"../libs/EngineMath/EngineMath.h"
#include"../Utility/definitions.h"

uint32_t TELEMETRY_FEED(uint32_t*(*compiledData)(void));

uint32_t LOG_THRUST();

uint32_t LOG_FUEL_MASS_FLOW();

uint32_t LOG_OXIDIZER_MASS_FLOW();


#endif //TELEMETRY_