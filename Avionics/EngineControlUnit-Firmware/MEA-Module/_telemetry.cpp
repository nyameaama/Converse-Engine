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

#include"_telemetry.hpp"

//+2 Overload 
//Raw telemetry data logged and sent to memory
void TELEMETRY::log(char* label,char* timestamp,char* data,uint8_t data_destination){
    switch (data_destination)
    {
    case 1:
        //Log to memory only

        break;
    case 2:
        //Log to memory and ground

        break;
    default:
        //Log to memory only
        break;
    }
    //Package Data

}

void TELEMETRY::log(char* label,char* timestamp,int data,uint8_t data_destination){

}

void TELEMETRY::log(char* label,char* timestamp,double data,uint8_t data_destination){
    
}

//Thrust calculation function
void TELEMETRY::LOG_THRUST(){

}

//Function to measure ethanol mass flow and send to ground
//using inlet and pre chamber transducer data
void TELEMETRY::LOG_FUEL_MASS_FLOW(char* timestamp){
    PTAM *ptamObj = new PTAM();
    double cd;
    double ethanol_density;
    double orfice_area;
    //Get inletPressure, pre chamber pressure
    double inletPressure = ptamObj -> PTAM_RETRIEVE_BASE_DOUBLE("SBC07");
    double pre_chamber_pressure = ptamObj -> PTAM_RETRIEVE_BASE_DOUBLE("SBC09");
    double mdot = LiquidMassFlow(cd,ethanol_density,inletPressure,pre_chamber_pressure,orfice_area);
    delete ptamObj;
    //Store in flash
    log("FUEL_MASS_FLOW",timestamp,mdot,0);
    //Send to terminal controller
    transmit_telemetry(mdot);
}

//Function to measure oxygen mass flow and send to ground
//using inlet and pre chamber transducer data
void TELEMETRY::LOG_OXIDIZER_MASS_FLOW(char* timestamp){
    PTAM *ptamObj = new PTAM();
    double cd;
    double LOX_density;
    double orfice_area;
    //Get inletPressure, pre chamber pressure
    double inletPressure = ptamObj -> PTAM_RETRIEVE_BASE_DOUBLE("SBC08");
    double pre_chamber_pressure = ptamObj -> PTAM_RETRIEVE_BASE_DOUBLE("SBC10");
    double mdot = LiquidMassFlow(cd,LOX_density,inletPressure,pre_chamber_pressure,orfice_area);
    delete ptamObj;
    //Store in flash
    log("OX_MASS_FLOW",timestamp,mdot,0);
    //Send to terminal controller
    transmit_telemetry(mdot);
} 

void TELEMETRY::LOG_GAS_MASS_FLOW(double inletPressure, double pressure2,double outlettemp, char* timestamp){
    double cd;
    double gravity;
    double ratioSpecificHeats;
    double GasCompressabilityFactor;
    double molecularMass;
    double orficeArea;
    double mdot = GasMassFlow(cd,gravity,ratioSpecificHeats,GasCompressabilityFactor,outlettemp,molecularMass,inletPressure,pressure2,orficeArea);
    //Store in flash

    //Send to terminal controller
}

