/*
 Title: EngineMath.h
  Author/Date: gNSortino@yahoo.com / 2012-05-26
  Description: This library is used to calculate properties
	of a rocket engine. Currently it will calculate the following
	properties
		(1) GasMassFlow. 
			-> Returns kg/sec as a float 
		(2) LiquidMassFlow. 
			-> Returns kg/sec as a float 
		(3) MassFlowConvert. Convers kg/sec to:
			-> [0] kg/sec 
			-> [1] kg/min
			-> [2] lbs/sec
			-> [3] lbs/min
    Note that this library will not setup any pins. It
	is expected that these will be defined by the calling 
	program.
*/
#ifndef EngineMath_h
#define EngineMath_h

#include<math.h>

float LiquidMassFlow( 	float cd,   		// Coefficient of Discharge (Dimensionless)
						float den,  	// Liquid Density (kg/m^3)
						float p1,  		// Inlet Pressure (psi) 
						float p2,  		// Outlet Pressure (psi)
						float a);		// Orifice Area (m^2)
			
float GasMassFlow (		float cd,  		// Coefficient of Discharge (Dimensionless)
						float g,    	// Gravity 9.80665 (m/sec2)
						float k,   		// Gas Specific Heat Ratio (Dimensionless)
						float z,    	// Gas Compressability Factor (Dimensionless) 
						float temp, 	// Gas Temperature at inlet (Kelvin)
						float m,    	// Gas Molecular Mass  (mol)
						float p1,  		// Inlet Pressure (psi) 
						float p2,  		// Outlet Pressure (psi)
						float a); 		// Orifice Area (m^2)

void MassFlowConvert (	float mf[]);	// Mass Flow array

float thrustCalc (		float k,		// specific heat ratio for the engine
						float p1PSI, 	// chamber pressure (PSI)
						float p2PSI, 	// exit pressure (PSI)
						float p3PSI, 	// atmospheric pressure (PSI)
						float aExit, 	// Nozzle exit area m^2
						float aThroat);	// Nozzle throat area m^2


//Method for finding square root
/*float sqrt(int x){
	// Base cases 
    if (x == 0 || x == 1) 
    	return x; 
  	// Staring from 1, try all numbers until 
    // i*i is greater than or equal to x. 
    int i = 1, result = 1; 
   	while (result <= x) 
    { 
      	i++; 
      	result = i * i; 
    } 
    return i - 1; 
}

		//Method for finding pow()
		double pow(double x, int y){
			double temp;
    		if (y == 0)
    			return 1;
    		temp = pow(x, y / 2);
    		if ((y % 2) == 0) {
        		return temp * temp;
    		} else {
        		if(y > 0)
            		return x * temp * temp;
        		else
            		return (temp * temp) / x;
    		}
		}
*/

	float LiquidMassFlow ( float cd,   		// Coefficient of Discharge (Dimensionless)
							float den,  	// Liquid Density (kg/m^3)
							float p1,  		// Inlet Pressure (psi) 
							float p2,  		// Outlet Pressure (psi)
							float a);  		// Orifice Area (m^2)
	float GasMassFlow (		float cd,  		// Coefficient of Discharge (Dimensionless)
							float g,    	// Gravity 9.80665 (m/sec2)
							float k,   		// Gas Specific Heat Ratio (Dimensionless)
							float z,    	// Gas Compressability Factor (Dimensionless) 
							float temp, 	// Gas Temperature at inlet (Kelvin)
							float m,    	// Gas Molecular Mass  (mol)
							float p1,  		// Inlet Pressure (psi) 
							float p2,  		// Outlet Pressure (psi)
							float a);  		// Orifice Area (m^2)
	void MassFlowConvert (	float mf[]);	// Mass Flow array
	float thrustCalc (		float k,		// specific heat ratio for the engine
							float p1PSI, 	// chamber pressure (PSI)
							float p2PSI, 	// exit pressure (PSI)
							float p3PSI, 	// atmospheric pressure (PSI)
							float aExit, 	// Nozzle exit area m^2
							float aThroat);	// Nozzle throat area m^2

#endif