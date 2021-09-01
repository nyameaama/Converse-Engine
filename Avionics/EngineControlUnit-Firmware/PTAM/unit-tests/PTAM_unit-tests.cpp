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

#include"PTAM_unit-tests.hpp"

/* Methods Tested:
    uint8_t PTAM_ADD_BASE_DOUBLE(char* baseID,double data);
    double PTAM_RETRIEVE_BASE_DOUBLE(char* baseID);
    uint8_t PTAM_ADD_BASE_32(char* baseID,uint32_t data);
    uint32_t PTAM_RETRIEVE_BASE_32(char* baseID);
    uint8_t PTAM_ADD_BASE_CHAR(char* baseID,char* data);
    char* PTAM_RETRIEVE_BASE_CHAR(char* baseID);
*/
/*
int main(){
    //Test 
    testValueAddRetrieveCHAR();
    //testValueAddRetrieveFLOAT();
    //testValueAddRetrieveINT();
}

void testOutput(char* method,char* result, bool status){
    printf("%s\n","UNIT TEST - Control methods");
    printf("%s", "METHOD:");
    printf("%s\n", method);
    printf("%s", "RESULT:");
    printf("%s\n", result);
    printf("%s", "STATUS:");
    if(status){printf("%s", "PASS");}else{printf("%s", "UNDEF");}
}

void testValueAddRetrieveCHAR(){
    char* data = "test";
    PTAM_ADD_BASE_CHAR("1",data);
    if(PTAM_RETRIEVE_BASE_CHAR("1") == data){
        testOutput("testValueAddRetrieveCHAR","GOOD",true);
    }else{
        testOutput("testValueAddRetrieveCHAR","BAD",false);
    }
}

void testValueAddRetrieveFLOAT(){
    double data = 5.05;
    PTAM_ADD_BASE_DOUBLE("1",data);
    if(PTAM_RETRIEVE_BASE_DOUBLE("1") == data){
        testOutput("testValueAddRetrieveFLOAT","GOOD",true);
    }else{
        testOutput("testValueAddRetrieveFLOAT","BAD",false);
    }
}

void testValueAddRetrieveINT(){
    uint32_t data = 5;
    PTAM_ADD_BASE_32("1",data);
    if(PTAM_RETRIEVE_BASE_32("1") == data){
        testOutput("testValueAddRetrieveINT","GOOD",true);
    }else{
        testOutput("testValueAddRetrieveINT","BAD",false);
    }
}
*/