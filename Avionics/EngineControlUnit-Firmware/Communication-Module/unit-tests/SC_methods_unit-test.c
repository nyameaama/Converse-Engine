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

#include"SC_methods_unit-test.h"

/* Methods Tested:
    char* createWorkingID(char* baseID, char* control_assignment);

    uint8_t verifyBaseID(char* baseID);
*/

void testOutput(char* method,char* result, bool status);
bool testWorkingID();
bool testVerifyBaseID();


int main(){
    //Test
    testWorkingID();
    //testVerifyBaseID();
    return 0;
}

void testOutput(char* method,char* result,bool status){
    printf("%s\n","UNIT TEST - SubController_SPI methods");
    printf("%s", "METHOD:");
    printf("%s\n", method);
    printf("%s", "RESULT:");
    printf("%s\n", result);
    printf("%s", "STATUS:");
    if(status){printf("%s", "PASS");}else{printf("%s", "FAIL");}
}

bool testWorkingID(){
    //Method NAme
    char* method = "createWorkingID";
    //Test data
    char* test_baseID = "baseTEST";
    char* test_control_assignment = "10";
    char* test_result_true = "baseTEST10";
    //Method test
    char* methodTest = createWorkingID(test_baseID,test_control_assignment);
    bool status;
    if(methodTest != test_result_true){status = false;}else{status = true;}
    //Output
    testOutput(method,methodTest,status);
}

bool testVerifyBaseID(){

}