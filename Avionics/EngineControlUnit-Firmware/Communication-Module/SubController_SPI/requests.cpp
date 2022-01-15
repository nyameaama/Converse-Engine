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
    char* CA_converted;
    itoa(control_assignment,CA_converted,10);
    //Appending of control assignment to base ID to create "Working ID
    WorkingID = createWorkingID(baseID,CA_converted);
    //Sending of Working ID to destination controller
    //
    //transmitWorkingID(WorkingID,);
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

//Function executes sending of Working ID to destination controller | returns data response
char* REQUESTS::transmitWorkingID(char* WorkingID,uint8_t destination_controller_no){
    //Log transmission
    uint8_t nextDestination = shortestPath(destination_controller_no);
    //log("Sub Controller Comm send-time",time(),WorkingID);
    //SEND
    //receiving controller pin / neighbor controller
    uint8_t recContPin = 0;
    //Enable slave arduino with setting the SlaveSelection pin to 0Volt
    digitalWrite(recContPin, LOW);
    // Wait for a moment 
    delay(10);
    //We sent the data here and wait for the response from devic
    char* dataSent = WorkingID;
    SPI.transfer(dataSent, sizeof(WorkingID));
    //In case of buffer transfers the received data is stored in the buffer in-place (the old data is replaced with the data received).
    char* receivedValue = dataSent;
    //Disable slave arduino with setting the SlaveSelection pin to 5Volt
    digitalWrite(recContPin, HIGH);
}


uint8_t REQUESTS::shortestPath(uint8_t destination_controller_no){
    //1 -> Set Origin as anchor (Get controller info from config data)
    uint8_t anchor = CONTROLLER_ID;
    //2 -> Set Goal (Parse transmission for destination controller) 
    uint8_t goal = destination_controller_no;
    //3 -> Get neighbouring pairs (Config data)
    int pair[2] = {controllerPairs[anchor][0],controllerPairs[anchor][1]};
    //4 -> For each number in pair
    uint8_t diff1,diff2;
    for(uint8_t i = 0; i < 2;i++){
        //Calculate difference with goal
        diff1 = (i == 0) ? goal - pair[i] : diff1;
        diff2 = (i == 1) ? goal - pair[i] : diff2;
    }
    //5 -> Return smallest difference
    uint8_t smallest = (diff1 > diff2) ? diff2 : diff1;
    return smallest;
}