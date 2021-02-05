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

#ifndef AETS_
#define AETS_

#include"../../Utility/definitions.h"
#include"../../Utility/ecu_xx_flash.h"

typedef uint8_t AETS_FLAG;
#define NO_FLAG (uint8_t) 0
#define FLAG (uint8_t) 1

#define PRESSURE_RANGE_LOW 0
#define PRESSURE_RANGE_HIGH 0
#define TEMP_RANGE_LOW 0
#define TEMP_RANGE_HIGH 0

//AETS VERSION 1

//AETS V1 prog wil be based on monitoring test data 
//ranges without continuous assesment of all data
// AETS will check if (data) < thresh: 

uint32_t measuredData[50][50]; // Data stored in heap is temporary. Will overflow if not chnaged

//AETS driver
//+1 Overload
uint8_t aets(uint8_t dataChannel,uint32_t data, uint32_t time);

uint8_t aets();

//Function to lookup simulated data for channel and return data array
uint32_t *lookup(uint8_t dataChannel);

//From simulation data array, get simulation data at timestamp 
uint8_t *separateDataTimestamp(uint8_t *dataArray,uint32_t timestamp);

//Function to compare channel data
AETS_FLAG compare(uint32_t data_1, uint32_t timestamp_1, uint32_t data_2, uint32_t timestamp_2);

//Function to check if measured value is in nominal bounds
uint8_t check_if_in_range(uint32_t actual_value,uint32_t rangeLow,uint32_t rangeHigh);


#endif