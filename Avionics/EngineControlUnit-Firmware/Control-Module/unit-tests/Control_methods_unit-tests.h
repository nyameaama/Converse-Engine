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

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>

typedef uint8_t AETS_FLAG;
#define NO_FLAG (uint8_t) 0
#define FLAG (uint8_t) 1

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