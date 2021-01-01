/*
 Title: ThermoTemp.cpp
  Author/Date: gNSortino@yahoo.com / 2012-05-05
  Description: This library will take the input from a 
    K type thermocouple sensor and return the following
    values as an array:
		[0] raw interval
		[1] voltage (in milivolts)
		[2] temperature in Celsius
		[3] temperature in Kelvin
		[4] temperature in Fahrenheit
		[5] temperature in Rankine
	Additionally this library has some handy methods 
	to calculate Kelvin, Fahrenheit, and Rankine given
	a Celsius measurement.
    Note that this library will not setup any pins. It
	is expected that these will be defined by the calling 
	program.
*/

#include "ThermoTemp.h"

/*
	Note that the array tempsF is passed by reference so
	the calling function should use this to view results.
*/
void getTemps (int analogSignalF, double tempsF[]){
  tempsF[0] = analogSignalF;
  tempsF[1] = getVoltage (tempsF[0]);  
  tempsF[2] = getCelsius (tempsF[1]);
  tempsF[3] = getKelvin (tempsF[2]);
  tempsF[4] = getFahrenheit (tempsF[2]);
  tempsF[5] = getRankine (tempsF[2]);
}

double getVoltage (double analogSignal){
  double voltage = ((5.0 * analogSignal) / 1024.0);
  return voltage;
}

double getCelsius (double voltage){
  double celsius = (voltage * 100);
  return celsius;
}

double getKelvin (double celsius){
  double kelvin = (celsius + 273.15);
  return kelvin;
}

double getFahrenheit (double celsius){
  double fahrenheit = (((celsius * 9) / 5.0) + 32);
  return fahrenheit;
}

double getRankine (double celsius){
  double rankine = (9.0 / 5.0) * (celsius + 273.15 );
  return rankine;
}