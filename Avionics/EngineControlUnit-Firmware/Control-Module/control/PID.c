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
SOFTWARE.
*/

#include"PID.h"

uint8_t tagCount, PR_count;
double PID_PR[64][5];
char* tags[12];

//Important for PID process identification
double kp = 0,ki = 0,kd = 0;
double error_previous = 0,error_integral = 0;

double error,processVar;
double derivative,proportional,integral;

double getProportional(){
    proportional = kp * error;
    return proportional;
}

double getIntegral(){
    integral = ki * error_integral;
    return integral;
}

double getDerivative(){
    derivative = kd * derivative;
    return derivative;
}

double PID_MAIN(char* Process,double current,double setpoint){
    updateConstants(Process);
    processVar = current;
	error = setpoint - processVar;
	error_integral += error * dt;
    derivative = (error - error_previous) / dt;
    error_previous = error;
    double dv = getDerivative();
    double it = getIntegral();
    double prop = getProportional();
    double result = proportional + integral + derivative;
    return result;
}

void createPIDinstance(char* tag,double kp,double ki,double kd){ 
    if(checkforInstance(tag) == 0){
        tags[tagCount] = tag;
        tagCount++;
        PID_PR[PR_count][0] = kp;
        PID_PR[PR_count][1] = ki;
        PID_PR[PR_count][2] = kd;
        //Create error variables
        double erPrev = 0,erInteg = 0;
        PID_PR[PR_count][3] = erPrev;
        PID_PR[PR_count][4] = erInteg;
        PR_count++;
    }else{
        //Do nothing
    }
    
}

void updateConstants(char* Process){
    uint8_t index = -1;
    for(uint8_t i = 0; i < tagCount;i++){
        if(compare(tags[i],Process) == 1){
            index = i;
        }
    }
    //ErrorDump sen;
    if(index != -1){
        kp = PID_PR[index][0];
        ki = PID_PR[index][1];
        kd = PID_PR[index][2];
        error_previous = PID_PR[index][3];
        error_integral = PID_PR[index][4];
   }else{
       //sen.ERROR_DUMP("311");
   }
}

uint8_t compare(char* x, char* y){
    if (x != y){
        return 0;
    }
    else{
        return 1;
    }
}

uint8_t checkforInstance(char* tag){
    uint8_t instanceTrue = 0;
    for(uint8_t i = 0; i < tagCount;i++){
        if(compare(tag,tags[i]) == 1){
            instanceTrue = 1;
        }
    }
    return instanceTrue;
}

int main(){
    createPIDinstance("test",1,1,1);
    
}