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

#include "requests.hpp"

//Function executes request for communication with a controller
double REQUESTS::controllerRequest(char* baseID,uint8_t control_assignment){
    /*System request for communication with a controller
      Retrieval of base ID of destination controller 
      Appending of control assignment to base ID to create "Working ID"
      Sending of Working ID to destination controller*/
    char* WorkingID;
    if(verifyBaseID(baseID) == 0){
        WorkingID = createWorkingID(baseID,control_assignment);
    }else{
        //Error Handling
    }
    transmitWorkingID(WorkingID);
    //Return

}

//Interrupt handler for comms passthrough
double REQUESTS::dPassthroughInterrupt(){
    //interrupt

    //data sent to transmission queue

    //hold until data transmission process (general process-batch)
}

//Interrupt handler for general comms
double REQUESTS::controllerReceiveInterrupt(){
    //interrupt

    //checksum

    //decode
    char* dec = {""};

    //data sent to PTAM
    
    //hold until General receiving data process parses Information 

}

//Function verifies base ID.
//Return 0 = Verified | Return 1 = failed
uint8_t REQUESTS::verifyBaseID(char* baseID){
    //The base ID's consist of two parts. The "SBC" tag and the number preceeding it.
    //The SBC is used to indicate the ECU that it is a sub controller and the 
    //numbers preceeding it indicate the unique number corresponding to the controller.
    uint8_t failed = 0; 
    //Validate Length
    uint8_t baseLength = strlen(baseID);
    if(baseLength != 6){return 0;}

    //Verify existence
    //Search ID data structure for base ID
    /*for(uint8_t i = 0; i < ID_LEN;++i){
        if(IDS[i][1]!= baseID){
            failed = 1;
        }else{break;}
    }*/
    return failed;
}

//Function creates Working ID
char* REQUESTS::createWorkingID(char* baseID, char* control_assignment){
    // The control assignment is appended to the base ID
    char* WorkingID = baseID;
    strcat(WorkingID,control_assignment);
    return WorkingID;
}

//Function executes sending of Working ID to destination controller
char* REQUESTS::transmitWorkingID(char* WorkingID){
    //Log transmission
    //log("Sub Controller Comm send-time",time(),WorkingID);
}
