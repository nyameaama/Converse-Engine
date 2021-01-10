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

#include"_telemetry.h"

void LOG_THRUST(){

}

void LOG_FUEL_MASS_FLOW(double inletPressure, double pressure2, uint32_t timestamp){
    double cd;
    double ethanol_density;
    double orfice_area;
    double mdot = LiquidMassFlow(cd,ethanol_density,inletPressure,pressure2,orfice_area);
    //Store in flash

    //Send to terminal controller
}
void LOG_OXIDIZER_MASS_FLOW(double inletPressure, double pressure2, uint32_t timestamp){
    double cd;
    double LOX_density;
    double orfice_area;
    double mdot = LiquidMassFlow(cd,LOX_density,inletPressure,pressure2,orfice_area);
    //Store in flash

    //Send to terminal controller
} 

void LOG_GAS_MASS_FLOW(double inletPressure, double pressure2,double outlettemp, uint32_t timestamp){
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

void LOG_TEMP_1(double reading, uint32_t timestamp){
    //Store in flash

    //Send to terminal controller
}

void LOG_TEMP_2(double reading, uint32_t timestamp){
    //Store in flash

    //Send to terminal controller
}

void LOG_PRESSURE_1(double reading, uint32_t timestamp){
    //Store in flash

    //Send to terminal controller
}

void LOG_PRESSURE_2(double reading, uint32_t timestamp){
    //Store in flash

    //Send to terminal controller
}

char* LOG_COMMANDS(){

}

