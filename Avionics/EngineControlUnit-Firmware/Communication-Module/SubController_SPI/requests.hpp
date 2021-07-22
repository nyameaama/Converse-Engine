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

#ifndef REQ
#define REQ

#include"../../Utility/definitions.hpp"
#include"../../MEA-Module/_telemetry.hpp"
#include<string.h>

//Main

class REQUESTS {
        public:
        //Function executes request for communication with a controller
        double controllerRequest(char* baseID,uint8_t control_assignment);

        //Interrupt handler for comms passtrhrough
        double dPassthroughInterrupt();

        //Interrupt handler for general comms
        double controllerReceiveInterrupt();


        //Trans + rec

        //private:
        //Function verifies base ID. Return 0 = Verified | Return 1 = failed
        uint8_t verifyBaseID(char* baseID);

        //Function creates Working ID (See comms doc)
        char* createWorkingID(char* baseID, char* control_assignment);

        //Function decodes Working ID (See comms doc)
        char* decWorkingID(char* workingID);

        //Function executes sending of Working ID to destination controller
        char* transmitWorkingID(char* WorkingID);

        //FUnction executes checksum
        char* checksum(char* data);


};



#endif