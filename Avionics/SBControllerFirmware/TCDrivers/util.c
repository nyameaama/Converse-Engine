#ifndef UTIL
#define UTIL

size_t timeSinceStartupMs(){
    return HAL_GetTick();
}

size_t timeSinceStartupScs(){
    return HAL_GetTick() / 1000;
}



#endif