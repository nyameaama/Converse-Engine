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

#include"Control_methods_unit-tests.h"

/* Methods Tested:
    AETS_FLAG compare(uint32_t data_1, uint32_t timestamp_1, uint32_t data_2, uint32_t timestamp_2);

    uint8_t check_if_in_range(uint32_t actual_value,uint32_t rangeLow,uint32_t rangeHigh);


*/

int main(){



}

void testOutput(char* method,char* result,bool status){
    printf("%s\n","UNIT TEST - Control methods");
    printf("%s", "METHOD:");
    printf("%s\n", method);
    printf("%s", "RESULT:");
    printf("%s\n", result);
    printf("%s", "STATUS:");
    if(status){printf("%s", "PASS");}else{printf("%s", "FAIL");}
}