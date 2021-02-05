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

#include"_AETS.h"

//AETS driver
//+1 Overload
uint8_t aets(uint8_t dataChannel,uint32_t data, uint32_t time){
    //Simulation data array
    uint8_t *dataArray = lookup(dataChannel);
    //get precise 
    uint8_t *pr = separateDataTimestamp(dataArray,time);
    return compare(data,time,pr[0],pr[1]);
}

uint8_t aets(){
    
}

//Function to lookup simulated data for channel and return data array
uint32_t *lookup(uint8_t dataChannel){
    //Shift data from flash to heap (RAM)
    
}

//From simulation data array, get simulation data at timestamp 
uint8_t *separateDataTimestamp(uint8_t *dataArray,uint32_t timestamp){
    //Data Array is 1D and in format .{data[0], timestamp[1]}
    //Array Size 
    uint32_t size;

}

//Function to compare channel data
AETS_FLAG compare(uint32_t data_1, uint32_t timestamp_1, uint32_t data_2, uint32_t timestamp_2){
    //Compare two data sets to their corresponding timestamps
    uint8_t flag = 0;
    //Check timestamps
    uint8_t time_grace;
    uint8_t data_grace;
    //Make sure time difference is acceptable
    
    //Compare
    //Simulation data holds greater weight
    if(data_1 > (data_2 + data_grace) || data_1 < (data_2 - data_grace)){
        //flag
        flag = FLAG;
    }else{
        //no flag. In bounds
    }
    return flag;
}

//Function to check if measured value is in nominal bounds
uint8_t check_if_in_range(uint32_t actual_value,uint32_t rangeLow,uint32_t rangeHigh){
    uint8_t nominal = 1;
    if(actual_value < rangeLow || actual_value > rangeHigh){
        nominal = 0;
    }
    return nominal;
}