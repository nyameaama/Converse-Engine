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

#ifndef PID
#define PID

//#include<Arduino.h>
//#include"../../Utility/definitions.h"
//#include"ErrorDump.h"

typedef unsigned char uint8_t;

//#include<stdio.h>

//Different instances of PID computation will be called from this class so each unique process will
//need to have constants stored so individual processes can be continued after end of class call


uint8_t dt;


void updateConstants(char* Process);

double getProportional();

double getIntegral();

double getDerivative();

uint8_t compare(char* x, char* y);

uint8_t checkforInstance(char* tag);

double PID_MAIN(char* Process,double rocketPos,double setpoint);

void createPIDinstance(char* tag,double kp,double ki,double kd);



#endif